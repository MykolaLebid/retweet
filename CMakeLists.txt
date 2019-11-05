cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(retweet LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


# download Google Test sources on code project repo 
# at configure time using FetchContent
 include(FetchContent) 
 FetchContent_Declare(
 	googletest
 	GIT_REPOSITORY https://github.com/google/googletest.git
 	GIT_TAG master
 )
# allows the project to check whether a particular dependency has already been 
# populated and also retrieve some directory details
 FetchContent_GetProperties(googletest)
 
 if (NOT googletest_POPULATED)
  message(STATUS "googletest is populating...")
  FetchContent_Populate(googletest)
  
  #adds the targers: gtest, gtest_main, gmock, gmock_main
  add_subdirectory(
 		${googletest_SOURCE_DIR}
 		${googletest_BINARY_DIR}
  )

  # Prevent GoogleTest from overriding our compiler/linker options
  # when building with Visual Studio
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  # Prevent GoogleTest from using PThreads
  set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
  # some changes will be needed for Windows. See CMake Cookbook by Radovan 
  # Bast and Roberti google test installation chapter
 
   # Silence std::tr1 warning on MSVC
   if(MSVC)
     foreach(_tgt gtest gtest_main gmock gmock_main)
       target_compile_definitions(${_tgt}
         PRIVATE
           "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
         )
     endforeach()
   endif()
   message(STATUS "googletest_POPULATED=${googletest_POPULATED}") 
 else()
   message(STATUS "googletest is populated")
 endif()

add_executable(test_retweet "")

target_sources(test_retweet
	PRIVATE
	main_test.cpp
	
	tweet.cpp
	tweet_test.cpp

	tweet_collection.cpp
	tweet_collection_test.cpp
	)

target_link_libraries(test_retweet
	PRIVATE
	gmock_main
	)
enable_testing()

add_test(
	NAME google_test
	COMMAND $<TARGET_FILE:test_retweet>
)
	
