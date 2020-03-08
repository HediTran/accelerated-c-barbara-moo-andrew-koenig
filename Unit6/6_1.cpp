//This program draw a character-picture - use iterators
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// find the length of the longest string in the vector
string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		maxlen = max(maxlen, it->size());
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');		// maxlen + ( '*' + Leading space + Ending space + '*' )

										// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		ret.push_back("* " + *it +
			string(maxlen - it->size(), ' ') + " *");
	}

	// write the bottom border 
	ret.push_back(border);
	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	// add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;

	// iterators to look at elements from left and right respectively
	vector<string>::const_iterator i = left.begin(), j = right.begin();

	// continue until we've seen all rows from both pictures
	while (i != left.end() || j != right.end())
	{
		// construct new string to hold characters from both pictures (one line only)
		string s;

		//copy a row from the left-hand side, if there is one
		if (i != left.end())
			s += *i++;		// The increment operators have the same precedence as *, so *(i++) has same meaning as *i++

		s += string(width1 - s.size(), ' ');

		// copy a row from the right-hand side, if there is one
		if (j != right.end())
			s += *j++;

		// add s to the picture we're creating
		ret.push_back(s);
	}

	return ret;
}

int main() 
{
	string s;

	//vector<string> message = { "LUCK", "Is what happens", "When", "Preparation meets Opportunity!" };
	vector<string> message;

	// Take input by get line
	while (getline(cin, s))
	{
		message.push_back(s);
	}

	vector<string> pic = frame(message);

	// print results
	for (vector<string>::size_type i = 0; i < pic.size(); i++)
	{
		cout << pic[i] << endl;
	}

	cout << endl;

	cout << "Below is an example to illustrate horizontal concatenation by using iterators" << endl;

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