// Sample.cpp : Defines the entry point for the console application.
// Visual Studio includes function reverse -> overloaded reverse function.
//If we want to test our template function reverse, we use C++ online compile GDB
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// We can function swap rather than exchange the values of *beg and *end directly because we don't know what types 
// *beg and *end might have. Using function swap allow us to exchange value of any types
template<class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end)
		{
			//swap(*begin++, *end);
			int temp = *begin;
			*begin = *end;
			*end = temp;
			begin++;
		}
	}
}


int main()
{
	vector<int> vInt;
	int x;
	while (cin >> x)
	{
		vInt.push_back(x);
	}

	reverse(vInt.begin(), vInt.end());

	for (vector<int>::size_type i = 0; i < vInt.size(); i++)
	{
		cout << vInt[i] << " ";
	}

	return 0;
}




