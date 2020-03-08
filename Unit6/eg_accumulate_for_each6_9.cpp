// Sample.cpp : Defines the entry point for the console application.
// Use a library algorithm to concatenate all the elements of a vector<string>
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>	// use accumulate()

using namespace std;

string currentWord = "Hello";

// template function for_each must call a function -> this is an example function
string concateWord(string newWord)
{
	currentWord += newWord;

	return currentWord;
}

int main()
{
	string s;
	vector<string> v;

	while (cin >> s)
	{
		v.push_back(s);
	}

	// concatenate all the elements of a vector<string> v begin with currentWord - a global function (since funct concateWord is call)
	for_each(v.begin(), v.end(), concateWord);

	cout << currentWord << endl;

	cout << endl;

	// concatenate all the elements of a vector<string> v begin with word in the ""
	// begin with nothing
	// begin with Hehe
	string sentence_1 = accumulate(v.begin(), v.end(), string(""));
	string sentence_2 = accumulate(v.begin(), v.end(), string("Hehe"));
	
	cout << sentence_1 << endl;
	cout << sentence_2 << endl;

	return 0;
}




