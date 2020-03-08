// This program determines whether a word has any ascenders or descenders

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSpace(const char& c)
{
	return isspace(c);
}

bool not_space(const char& c)
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

bool isAscender(const char& c)
{
	static const string ascender_char = "bdfhklt";

	return find(ascender_char.begin(), ascender_char.end(), c) != ascender_char.end();
}

bool hasAscender(const string& s)
{
	for (string::const_iterator it = s.begin(); it != s.end(); it++)
		if (isAscender(*it))
			return true;
	return false;
}

bool isDescender(const char& c)
{
	static const string descender_char = "gjpqy";

	return find(descender_char.begin(), descender_char.end(), c) != descender_char.end();
}

bool hasDescender(const string& s)
{
	for (string::const_iterator it = s.begin(); it != s.end(); it++)
		if (isDescender(*it))
			return true;
	return false;
}

int main()
{
	cout << "This program determines whether a word has any ascenders or descenders." << endl;

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

	vector<string> ascender;
	vector<string> descender;
	vector<string> bothAscenderAndDescender;
	vector<string> noAscenderAndDescender;

	// Test whether a word has any ascenders/decenders
	for (vector<string>::const_iterator it = word_list.begin(); it != word_list.end(); it++)
	{
		if (hasAscender(*it) && hasDescender(*it))
			bothAscenderAndDescender.push_back(*it);
		else if (hasAscender(*it) && !hasDescender(*it))
			ascender.push_back(*it);
		else if (!hasAscender(*it) && hasDescender(*it))
			descender.push_back(*it);
		else
			noAscenderAndDescender.push_back(*it);
	}

	// print words with both ascenders and descenders (if any)
	if (bothAscenderAndDescender.size() != 0)
	{
		cout << "\nThese are the words that have both ascenders and descenders: " << endl;
		for (vector<string>::const_iterator it = bothAscenderAndDescender.begin(); it != bothAscenderAndDescender.end(); it++)
		{
			cout << *it << endl;
		}
	}

	// print words with only ascenders (if any)
	if (ascender.size() != 0)
	{
		cout << "\nThese are the words that have only ascenders: " << endl;
		for (vector<string>::const_iterator it = ascender.begin(); it != ascender.end(); it++)
		{
			cout << *it << endl;
		}
	}

	// print words with only descenders (if any)
	if (descender.size() != 0)
	{
		cout << "\nThese are the words that have only descenders: " << endl;
		for (vector<string>::const_iterator it = descender.begin(); it != descender.end(); it++)
		{
			cout << *it << endl;
		}
	}

	// print words with neither ascenders nor descenders (if any)
	if (noAscenderAndDescender.size() != 0)
	{
		cout << "\nThese are the words that have neither ascenders nor descenders: " << endl;
		for (vector<string>::const_iterator it = noAscenderAndDescender.begin(); it != noAscenderAndDescender.end(); it++)
		{
			cout << *it << endl;
		}
	}

	// find longest word that has neither ascenders nor descenders (if any)
	if (noAscenderAndDescender.size() != 0)
	{
		string longestWord;
		for (vector<string>::size_type i = 0; i != noAscenderAndDescender.size(); i++)
		{
			if (noAscenderAndDescender[i].size() > longestWord.size())
			{
				longestWord = noAscenderAndDescender[i];
			}
		}

		cout << "\nThe longest word that have neither ascenders nor descenders is: " << longestWord << endl;
	}

	return 0;
}




