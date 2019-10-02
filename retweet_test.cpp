#include <gtest/gtest.h>
#include "tweet_collection.h"
#include <gmock/gmock.h>

using namespace ::testing;

class TestRetweetCollection: public Test {
public:
	TweetCollection collection;
};

TEST_F(TestRetweetCollection, IsEmptyWhenCreated) {
	ASSERT_THAT(collection.isEmpty(), Eq(true));
}



TEST_F(TestRetweetCollection, HasSizeZeroWhenCreated) {
	ASSERT_EQ(collection.size(), 0);
}

TEST_F(TestRetweetCollection, HasNotSizeZeroWhenAdd) {
	
	ASSERT_EQ(collection.size(), 0);
}
