// This program would find all the URLs in its input and write all the lines on which each distinct URL occurs

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

bool not_url_char(char c)
{
	static const string url_ch = ";/?:@=&$-_.+!*'(),";

	return !(isalnum(c) ||
		find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";

	typedef string::const_iterator iter;

	iter i = b; /* b is currently equal s.begin() */

	while ((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		if (i != b && i + sep.size() != e)
		{
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
			{
				--beg;
			}

			if (beg != i && !not_url_char(i[sep.size()]))
			{
				return beg;
			}
		}
		i += sep.size();
	}
	return e;
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;

	iter b = s.begin();
	iter e = s.end();

	while (b != e)
	{
		b = url_beg(b, e);

		if (b != e)
		{
			iter after = url_end(b, e);
			ret.push_back(string(b, after));

			b = after;
		}
	}
	return ret;
}

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
	// calling xref using find_urls instead of split by default
	map<string, vector<int> > ret = xref(cin, find_urls);

	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); it++)
	{

		// write the word followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();

		if ((line_it + 1) == it->second.end())
		{
			cout << it->first << " occurs on line: ";	// if it appears only on one line
		}
		else
		{
			cout << it->first << " occurs on line(s): ";
		}

		cout << *line_it;	// write the first line number

		++line_it;
		// write the rest of the line number, if any
		while (line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;
		}

		// write a new line to separate each word
		cout << endl;
	}

	return 0;
}