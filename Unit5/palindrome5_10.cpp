// This program find all the palindromes in a dictionary and the longest palindromes
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ios>	// use streamsize
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

string lowcase(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}

	return s;
}

bool isPalindrome(const string& s)
{
	string::const_iterator a = s.begin();
	string::const_iterator b = s.end() - 1;

	while ((a <= b) && (a != s.end()))
	{
		if ((*a) != (*b))
		{
			return false;
		} 
		a++;
		b--;
	}
	return true;
}

int main() 
{
	string s;
	vector<string> word_list;
	while (getline(cin, s))
	{
		split(s, back_inserter(word_list));
	}

	// change all word to lowercase
	for (vector<string>::iterator it = word_list.begin(); it != word_list.end(); it++)
	{
		*it = lowcase(*it);
	}
	
	vector<string> palindrome;

	// Test whether a word is palindrome
	for (vector<string>::const_iterator it = word_list.begin(); it != word_list.end(); it++)
	{
		if (isPalindrome(*it))
		{
			palindrome.push_back(*it);
		}
	}

	// print all palindromes
	cout << "\nThese are the palindromes identified: " << endl;
	for (vector<string>::const_iterator it = palindrome.begin(); it != palindrome.end(); it++)
	{
		cout << *it << endl;
	}

	// find longest palindrome
	string longestPalindrome;
	for (vector<string>::size_type i = 0; i != palindrome.size(); i++)
	{
		if (palindrome[i].size() > longestPalindrome.size())
		{
			longestPalindrome = palindrome[i];
		}
	}

	cout << "\nThe longest palindrome is: " << longestPalindrome << endl;

	return 0;
}




