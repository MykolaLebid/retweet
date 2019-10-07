#ifndef TWEET_COLLECTION
#define TWEET_COLLECTION

#include "tweet.h"
#include <set>

class TweetCollection {
public:
	bool isEmpty() const {
	 	return tweet_collection.size() == 0;
	}

	unsigned int size() const {
		return tweet_collection.size();
	}
	
	void add(const Tweet tweet) {
		tweet_collection.insert(tweet);
	}

	void erase(const Tweet tweet) {
		tweet_collection.erase(tweet);
	}
private:
	std::set<Tweet> tweet_collection;
};
#endif
