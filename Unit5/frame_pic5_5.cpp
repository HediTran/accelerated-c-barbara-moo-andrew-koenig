//This program draw a character-picture: text left-aligned/right-aligned/center
// Input by getline()
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// find the length of the longest string in the vector
string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); i++)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

vector<string> frame_left_aligned(const vector<string>& v) 
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');		// maxlen + ( '*' + Leading space + Ending space + '*' )

										// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		ret.push_back("* " + v[i] +
			string(maxlen - v[i].size(), ' ') + " *");
	}

	// write the bottom border 
	ret.push_back(border);

	return ret;
}

vector<string> frame_right_aligned(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');		// maxlen + ( '*' + Leading space + Ending space + '*' )

										// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		ret.push_back("* " + string(maxlen - v[i].size(), ' ')
						+ v[i] + " *");
	}

	// write the bottom border 
	ret.push_back(border);

	return ret;
}

vector<string> frame_center_aligned(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');		// maxlen + ( '*' + Leading space + Ending space + '*' )

	// write the bottom border
	ret.push_back(border);

	for (vector<string>::size_type i = 0; i < v.size(); i++)
	{
		// "* " + left space + v[i] + (maxlen - v[i] - left space) + " *"
		ret.push_back("* " + string((maxlen - v[i].size()) / 2, ' ') + v[i]
			+ string(maxlen - v[i].size() - ((maxlen - v[i].size()) / 2), ' ') + " *");
	}

	// write the bottom border
	ret.push_back(border);

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

	// left, right, center example. 
	//vector<string> pic = frame_left_aligned(message);
	//vector<string> pic = frame_right_aligned(message);
	vector<string> pic = frame_center_aligned(message);	

	// print results
	for (vector<string>::size_type i = 0; i < pic.size(); i++)
	{
		cout << pic[i] << endl;
	}

	cout << endl;

	return 0;
}

/*
3 functions only differ in the "for" loop -> condensed into 1 funtion which take 1 more parameter named 'align'.
This parameter has string type. Use if/else statement before "for" loop. If (align == "right")... 
If (align == "left")...
*/