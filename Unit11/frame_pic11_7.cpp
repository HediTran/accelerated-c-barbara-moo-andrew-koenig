//This program draw a character-picture: text left-aligned/right-aligned/center
// Input by getline()
#include "stdafx.h"
#include <iostream>
#include "Vec_class11.h"
#include <string>
#include <algorithm>

using namespace std;

// find the length of the longest string in the vector
string::size_type width(const Vec<string>& v) {
	string::size_type maxlen = 0;
	for (Vec<string>::size_type i = 0; i != v.size(); i++)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

Vec<string> frame_aligned(const Vec<string>& v, const string& allign_type) 
{
	Vec<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');		// maxlen + ( '*' + Leading space + Ending space + '*' )

	ret.push_back(border);

	if (allign_type == "left" || allign_type == "Left")
	{
		for (Vec<string>::size_type i = 0; i != v.size(); i++)
			ret.push_back("* " + v[i] +
				string(maxlen - v[i].size(), ' ') + " *");
	}
	else if (allign_type == "right" || allign_type == "Right")
	{
		for (Vec<string>::size_type i = 0; i != v.size(); i++)
			ret.push_back("* " + string(maxlen - v[i].size(), ' ')
				+ v[i] + " *");
	}
	else if (allign_type == "center" || allign_type == "Center")
	{
		for (Vec<string>::size_type i = 0; i < v.size(); i++)
			// "* " + left space + v[i] + (maxlen - v[i] - left space) + " *"
			ret.push_back("* " + string((maxlen - v[i].size()) / 2, ' ') + v[i]
				+ string(maxlen - v[i].size() - ((maxlen - v[i].size()) / 2), ' ') + " *");
	}

	ret.push_back(border);

	return ret;
}

int main() 
{
	cout << "What type of allignment do you want? left/right/center? " << endl;
	string type_of_allign;
	cin >> type_of_allign;

	cout << endl;

	string s;
	Vec<string> message;

	while (getline(cin, s))
		message.push_back(s);
	message.push_back(" ");

	Vec<string> pic = frame_aligned(message, type_of_allign);

	// print results
	for (Vec<string>::size_type i = 0; i < pic.size(); i++)
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