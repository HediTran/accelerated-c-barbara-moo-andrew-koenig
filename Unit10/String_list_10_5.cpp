#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>	// use size_t (refer to the size of an array), ptrdiff_t (signed int) (represent the distance between 2 pointers)
#include <iterator>
#include <list>
#include <cstring>	// use size_t
#include "String_list_10_5.h"

using namespace std;

int main()
{
	String_list v;
	string x = "Hello";

	v.push_back(x);

	for (string* i = v.begin(); i != v.end(); i++)
	{
		cout << i << endl;
	}


	return 0;
}

