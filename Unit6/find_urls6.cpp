// This program would find all the URLs in its input

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

int main() {

	string s;
	vector<string> urls;

	while (getline(cin, s))
	{
		urls = find_urls(s);
	}

	cout << "This is all urls found in the input: " << endl;

	for (vector<string>::const_iterator it = urls.begin(); it != urls.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}