// Horizontal Concatenation

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <ios>	// use streamsize
#include <iomanip>	// use srand(time(0)), setprecision, setwidth

using namespace std;

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); i++)
		maxlen = max(maxlen, v[i].size());

	return maxlen;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	// add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;

	// indices to look at elements from left and right respectively
	vector<string>::size_type i = 0, j = 0;

	// continue until we've seen all rows from both pictures
	while (i != left.size() || j != right.size())
	{
		// construct new string to hold characters from both pictures
		string s;

		//copy a row from the left-hand side, if there is one
		if (i != left.size())
			s += left[i++];		// This equal to s += left[i];	i++;
								// This equal to s += left[i];	++i;
								// This does NOT equal to s+= left [++i];	Increments i, returning the incremented value
		
		// pad to full width
		s += string(width1 - s.size(), ' ');

		// copy a row from the right-hand side, if there is one
		if (j != right.size())
			s += right[j++];

		// add s to the picture we're creating
		ret.push_back(s);
	}

	return ret;
}

int main()
{
	vector<string> v1 = { "This is an", "example", "to", "illustrate", "framing" };
	vector<string> v2 = { "**************", "* This is an *", "* example    *", "* to         *", 
		"* illustrate *", "* framing    *", "**************" };
	
	vector<string> concatenate = hcat(v1, v2);

	for (vector<string>::size_type i = 0; i < concatenate.size(); i++)
	{
		cout << concatenate[i] << endl;
	}

	return 0;
}




