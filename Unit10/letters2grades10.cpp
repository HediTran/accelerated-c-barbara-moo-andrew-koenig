// convert numeric grades to letter grades

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <istream>
#include <cmath>
#include <cstddef>
#include <cstring>	// use size_t

using namespace std;

string letter_grade(double grade) {

	// range posts for numeric grade
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	// The letters aray is an array of constant pointers to const char
	// equivalent to static const string letters[] = {};
	// since we can convert character pointer to a string
	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	// compute the number of grades given the size of the array
	// and the size of a single element
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

	// given a numeric grade, find and return the associated letter grade
	for (size_t i = 0; i < ngrades; i++)
	{
		if (grade >= numbers[i])
		{
			return letters[i];
		}
	}

	// C++ program should not contain two or more consecutive question marks!
	return "?\?\?";
}

int main() {

	cout << letter_grade(895) << endl;
	cout << letter_grade(95) << endl;
	cout << letter_grade(-6) << endl;

	return 0;
}




