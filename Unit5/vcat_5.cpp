// Vertical Concatenation

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

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	// copy the top picture
	vector<string> ret = top;

	// copy the entire bottom picture
	for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); it++)
	{
		ret.push_back(*it);
	}

	return ret;
}

int main() {

	return 0;
}




