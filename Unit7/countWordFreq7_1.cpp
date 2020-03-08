// This program will count how many times a word appear in its input or vector

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>		// use class map
#include <functional>	// use function(std::pair<>, std::pair<>)
#include <set>

using namespace std;

int main() {									
	
	string s;	
	map<string, int> counters; 
	// read the input, keeping track of each word and how often we see it
	while (cin >> s)
	{
		++counters[s];	// m[k] if there's no entry for the given key, a new value - initialized element is created
	}

	// format output so that output will be order by value rather than by key
	typedef function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
	Comparator compFunctor =
		[](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2)
	{
		return elem1.second < elem2.second;
	};

	set<std::pair<std::string, int>, Comparator> setOfWords(
		counters.begin(), counters.end(), compFunctor);
		
	for (std::pair<std::string, int> element : setOfWords)
		std::cout << element.first << "\t" << element.second << std::endl;

	/*
	// write the words and associated counts
	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	} 
	*/

		

	// Count how many times a word appear in a vector
	/*
	map<string, int> counters;	// store each word and an associated counter
	vector<string> s;
	string str;
	while (cin >> str)
	{
		s.push_back(str);
	}

	for (vector<string>::size_type i = 0; i < s.size(); i++)
	{
		++counters[s[i]];
	}

	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	*/

	return 0;
}



