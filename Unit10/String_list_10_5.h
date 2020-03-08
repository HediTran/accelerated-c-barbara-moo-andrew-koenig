#pragma once
#include <string>

class String_list
{
public:
	String_list();

	std::string* begin() { return first; }
	std::string* end() { return last; }
	
	void push_back(const std::string& val)
	{
		*last = val;
		last++;
	}

private:
	std::string* first;
	std::string* last;
};

String_list::String_list()
{
	new std::string[10];
}
