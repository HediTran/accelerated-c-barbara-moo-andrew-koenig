// This program find palindromes in its input

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
	string s;
	
	while (cin >> s)
	{
		if (is_palindrome(s))
		{
			cout << s << " is a palindrome " << endl;
		}
		else
			cout << s << " is not a palindrome " << endl;

	}
	
	return 0;
}
