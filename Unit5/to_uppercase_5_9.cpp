// This program write the lowercase words in the input followed by the uppercase words

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>	// use srand(time(0)), setprecision, setwidth
#include <stdexcept>

using namespace std;

bool isSpace(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

bool has_upper_case_character(string s) {
	for (string::size_type i = 0; i < s.size(); i++)
	{
		if (isupper(s[i]))
		{
			return true;
		}
		else
			return false;
	}
}

template <class Out>
void split(const string& str, Out os)
{
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), isSpace);

		// copy the character [i, j)
		if (i != str.end())
		{
			*os++ = string(i, j);
		}

		i = j;
	}
}

int main() {

	cout << "Please enter a sentence with both lowercase and uppercase word: " << endl;

	string s;
	vector<string> word_list;
	while (getline(cin, s))
	{
		split(s, back_inserter(word_list));
	}

	vector<string> lowercase_list;
	vector<string> uppercase_list;

	for (vector<string>::const_iterator it = word_list.begin(); it != word_list.end(); it++)
	{
		if (has_upper_case_character(*it))
		{
			uppercase_list.push_back(*it);
		}
		else
			lowercase_list.push_back(*it);
	}

	// print all the lowercase words
	for (vector<string>::const_iterator it = lowercase_list.begin(); it != lowercase_list.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	// print all the uppercase words
	for (vector<string>::const_iterator it = uppercase_list.begin(); it != uppercase_list.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}




