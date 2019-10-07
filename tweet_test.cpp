#include <gmock/gmock.h>
#include "tweet.h"

using namespace testing;


TEST(TestTweet, CreateEmplyTweet) {
	Tweet tweet;
	ASSERT_THAT(tweet.isDefault(), Eq(true));
};

TEST(TestTweet, CreateTweet) {
	Tweet tweet( "@MykolaLebid", "that is the best day!" );
	ASSERT_THAT(tweet.getNameAndTweet(),
		  Eq("@MykolaLebid: that is the best day!"));
};

TEST(TestTweet, BadNameTweetExeptionThrow){
	const std::string wrongName("MykolaLebid@");	
	try{
		Tweet tweet( wrongName, "test");
		FAIL();	
	} catch (MisName& exep) {
		ASSERT_STREQ("MykolaLebid@", exep.what());
	};
};

TEST(TestTweet, EqualTweets) {
	Tweet tweet_1("@Me", "text");
	Tweet tweet_2("@Me", "text");
	ASSERT_THAT(tweet_1, Eq(tweet_2));
};

TEST(TestTweet, LessNameTweets) {
	Tweet tweet_1("@Me_a", "text");
	Tweet tweet_2("@Me_b", "text");
	ASSERT_THAT((tweet_1 < tweet_2), Eq(true));
};

TEST(TestTweet, EqNamesLessTestTweets) {
	Tweet tweet_1("@Me_a", "text_a");
	Tweet tweet_2("@Me_a", "text_b");
	ASSERT_THAT((tweet_1 < tweet_2), Eq(true));
};


