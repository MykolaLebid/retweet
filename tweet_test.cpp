#include <gmock/gmock.h>
#include "tweet.h"

using namespace ::testing;


TEST(TestTweet, CreateEmplyTweet) {
	Tweet tweet;
	ASSERT_THAT(tweet.isDefault(), Eq(true));
};


