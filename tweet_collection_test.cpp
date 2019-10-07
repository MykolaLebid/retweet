#include <gtest/gtest.h>
#include "tweet_collection.h"
#include <gmock/gmock.h>

using namespace ::testing;
class TestRetweetCollection: public Test {
public:
	TweetCollection collection;
};

class TestTweetCollectionOneElement: public Test {
public:
	TweetCollection collection;
	void SetUp() override {
		Tweet tweet;	
		collection.add(tweet);
	};
};

TEST_F(TestRetweetCollection, IsEmptyWhenCreated) {
	ASSERT_THAT(collection.isEmpty(), Eq(true));
}

TEST_F(TestRetweetCollection, HasSizeZeroWhenCreated) {
	ASSERT_EQ(collection.size(), 0);
}

TEST_F(TestTweetCollectionOneElement, HasSizeOneWhenAdd) {
	ASSERT_EQ(collection.size(), 1);
}

TEST_F(TestTweetCollectionOneElement, HasSizeTwoWhenAdd) {
	Tweet tweet("@My", "test");
	collection.add(tweet);
	ASSERT_EQ(collection.size(), 2);
}

TEST_F(TestTweetCollectionOneElement, HasSizeOneWhenAddIdentical) {
	Tweet tweet;
	collection.add(tweet);
	ASSERT_EQ(collection.size(), 1);
}

TEST_F(TestTweetCollectionOneElement, HasSizeOneWhenAddAndEraseTheSameElement) {
	Tweet tweet("@My", "test");
	collection.add(tweet);	
	Tweet tweet_2("@My", "test");
	collection.erase(tweet);	

	ASSERT_EQ(collection.size(), 1);
}

TEST_F(TestTweetCollectionOneElement, HasSizeOneWhenAddAndEraseDifferentEments) {
	Tweet tweet("@My", "test");
	collection.add(tweet);
	Tweet tweet_2("@My_a", "test");
	collection.erase(tweet_2);

	ASSERT_EQ(collection.size(), 2);
}

