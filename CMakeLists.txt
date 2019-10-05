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
	GIT_TAG release-1.8.0
)

if (NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	add_subdirectory(
		${googletest_SOURCE_DIR}
		${googletest_BINARY_DIR}
	)
# some changes will be needed for Windows. See CMake Cookbook by Radovan 
# Bast and Roberti google test installation chapter
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
	gtest_main
	)
enable_testing()

add_test(
	NAME google_test
	COMMAND $<TARGET_FILE:test_retweet>
)
	
