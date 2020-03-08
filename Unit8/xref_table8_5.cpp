// This program tells you which line(s) does a word appear

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <istream>
#include <sstream>	// use ostringstream
#include <map>		// use class map

using namespace std;

bool isSpace(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

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

// find all the lines that refer to each word in the input
map<string, vector<int> > // > > instead of >>
xref(istream& in, vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int>> ret;

	// read the next line
	while (getline(in, line))	//getline(cin, line) still works fine. Why?
	{
		++line_number;

		// break the input line into words
		vector<string> words = find_words(line);

		// remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++)
		{
			ret[*it].push_back(line_number);

			// if a word occur more than once on the same input line -> the program will only report that line only once
			for (vector<int>::size_type i = 0; i < ret[*it].size(); i++)
			{
				if ((i != ret[*it].size() - 1) && (ret[*it][i] == ret[*it][i + 1]))
				{
					ret[*it].erase(ret[*it].begin() + i + 1);
				}
			}
		}
	}
	return ret;
}

int main() {
	// calling xref using split by default
	map<string, vector<int> > ret = xref(cin);

	const string::size_type lineLength = 80;

	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); it++)
	{
		// use outputStream instead of cout for its powerful concatenation properties
		ostringstream outputStream;

		// write the word followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();

		if ((line_it + 1) == it->second.end())
			outputStream << it->first << " occurs on line: ";	// if it appears only on one line
		else
			outputStream << it->first << " occurs on lines: ";

		outputStream << *line_it;	// write the first line number
		++line_it;

		// write the rest of the line number, if any
		while (line_it != it->second.end())
		{
			outputStream << ", " << *line_it;
			++line_it;
		}

		// Break outputStream into multiple lines with max width of lineLength
		string outputLine = outputStream.str();
		for (string::size_type i = 0; i < outputLine.size(); i++)
		{
			if (i % lineLength == 0)
				cout << endl;
			cout << outputLine[i];
		}

		// write a new line to separate each word from the next
		cout << endl;
	}

	return 0;
}

/*
map<string, vector<int> > ret;
xref(cin, split, inserter(ret, ret.begin()));

xref(cin, split, ostream_iterator<pair<string, vector<int> > >(cout, " "));
*/


