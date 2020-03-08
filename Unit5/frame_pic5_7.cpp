#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ios>	// use streamsize
#include <iomanip>	// use srand(time(0)), setprecision, setwidth
#include <stdexcept>

using namespace std;

string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		maxlen = max(maxlen, v[i].size());
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v)
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

int main() {

	vector<string> v;
	v = frame(v);

	// Since v is a empty vector, width fuction return 0, frame write top and bottom border 
	for (vector<string>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}




