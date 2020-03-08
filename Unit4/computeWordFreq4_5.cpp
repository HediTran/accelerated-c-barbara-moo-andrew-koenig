// This program count how many times each distinct word appears in its input
// This version use function with type bool instead of int -> save more memory on disk
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


int main()
{
	cout << "This program count how many times each distinct word appears in its input.	" << endl << endl;
	cout << "Please enter a list of words you want to compute: " << endl;

	map<string, int> wordFreq;
	string word;
	vector<string> words;
	while (cin >> word)
		words.push_back(word);

	for (size_t i = 0; i < words.size(); i++)
		wordFreq[words[i]]++;

	for (map<string, int>::iterator it = wordFreq.begin(); it != wordFreq.end(); it++)
		cout << it->first << " appear(s) " << it->second << " times." << endl;
	

	return 0;
}