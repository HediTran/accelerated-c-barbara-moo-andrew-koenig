// This program compute and print the quartiles of a set of integers

#include <algorithm>					
#include <iostream>
#include <string>			
#include <vector>

using namespace std;	      

vector <double> list;

// function to calculate median
double Median(int poStart, int poEnd)
{
	int size = poEnd - poStart + 1;
	int mid = size / 2;

	double med;
	med = size % 2 == 0 ? (list[poStart + mid - 1] + list[poStart + mid]) / 2 
						: list[poStart + mid];

	return med;
}

int quartiles()
{
	cout << "Please enter all of the numbers, "
		"followed by end-of-file: " << endl;

	int x;

	while (cin >> x)
		list.push_back(x);

	typedef vector<int>::size_type vec_sz;
	vec_sz size = list.size();

	// check that the user entered some numbers
	if (size == 0)
	{
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}

	// sort
	sort(list.begin(), list.end());

	int midList = size / 2;
	
		// check whether the list has odd or even numbers
	if (size % 2 == 0)
	{
		cout << " Lower quartile is: " << Median(0, midList - 1) << endl;
		cout << " Median is: " << Median(0, size - 1) << endl;
		cout << " Uper quartile is: " << Median(midList, size - 1) << endl;
	}
	else
	{
		cout << " Lower quartile is: " << Median(0, midList - 1) << endl;
		cout << " Median is: " << Median(0, size - 1) << endl;
		cout << " Uper quartile is: " << Median(midList + 1, size - 1) << endl;
		
	}

	return 0;
}