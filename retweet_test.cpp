#include <gtest/gtest.h>
#include "tweet_collection.h"

using namespace ::testing;

class TestRetweetCollection: public Test {
public:
	TweetCollection collection;
};

TEST_F(TestRetweetCollection, IsEmptyWhenCreated) {
	ASSERT_TRUE(collection.isEmpty());
}



TEST_F(TestRetweetCollection, HasSizeZeroWhenCreated) {
	ASSERT_EQ(collection.size(), 0);
}

