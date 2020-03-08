// This program break a line of input into words
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <list>


using namespace std;

bool isSpace(const char& c)
{
	return isspace(c);
}

bool not_space(const char& c)
{
	return !isspace(c);
}

// Split and return a vector contain words
vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), isSpace);
		ret.push_back(string(i, j));
		i = j;
	}

	return ret;
}

// Out: output iterator. We can use split with any kind of iterator (forward, bidirectional, random-access iterators)
// EXCEPT a pure Input iterator such as istream_iterator
template <class Out>
void split(const string& str, Out os)
{
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), isSpace);
		
		if (i != str.end())
			*os++ = string(i, j);

		i = j;
	}
}

int main() {
	
	string s;
	
	/*
	// Write words into almost any kind of container + use different types of iterators
	// This example append the words after split function to a list called word_list
	list<string> word_list;

	while (getline(cin, s))
	{
		split(s, back_inserter(word_list));
		//split(s, front_inserter(word_list));

		for (list<string>::iterator it = word_list.begin(); it != word_list.end(); it++)
			cout << *it << endl;
	}
	*/
	

	// Seperate the input line into separate words, and writes those words onto the standard output
	while (getline(cin, s))
	{
		split(s, ostream_iterator<string>(cout, "\n"));
	}
	

	return 0;
}