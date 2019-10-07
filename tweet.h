#ifndef TWEET
#define TWEET

#include <string>
#include <iostream>

class MisName: public std::invalid_argument {
public:
	MisName(const std::string& userName):
		std::invalid_argument(userName){};
};
class Tweet {
public:
 	
        Tweet(const std::string& _name = null_name, 
	      const std::string& _text = null_text)
	      : name_(_name), text_(_text) { 
	      if (!noNameMistake()) throw MisName(_name);    
	}

	bool isDefault() const noexcept {
		return "@NULL_NAME" == name_ &&
		       "DEFAULT" == text_;
	}
	
	std::string getNameAndTweet() const noexcept {
		return name_ + ": " +  text_;
	}
	
	bool noNameMistake() const {
		return name_[0] == '@';
	}

	bool operator==(const Tweet& tweet_2) const {
		return name_ == tweet_2.name_ &&
		       text_ == tweet_2.text_;	
	}
	
	bool operator<(const Tweet& tweet_2) const {
		if (name_ != tweet_2.name_) {
		       	return name_ < tweet_2.name_;
		} else {
			return text_ < tweet_2.text_;
		};
	}

private:
	static const std::string null_name;
	static const std::string null_text;
	const std::string name_;
	const std::string text_;
};

#endif

