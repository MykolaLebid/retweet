#ifndef TWEET
#define TWEET

#include <string>
#include <iostream>

class Tweet {
public:
        Tweet(const std::string & _name = null_name, 
	      const std::string & _text = default_text)
	     : name_(_name), text_(_text){};

	bool isDefault() const {
		return "@NULL_NAME" == name_ &&
		       "DEFAULT" == text_;
	};

private:
	static const std::string null_name;
	static const std::string default_text;
	const std::string name_;
	const std::string text_;
};


#endif

