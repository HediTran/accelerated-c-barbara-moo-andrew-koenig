// This median fuction allows containers of any arithmetic type
// Calling median does not change the order of the elements in the container
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>	// use size_t (refer to the size of an array), ptrdiff_t (signed int) (represent the distance between 2 pointers)
#include <list>
#include <stdexcept>
#include <cstring>	// use size_t

using namespace std;

template<class T, class Iterator>
T median(Iterator begin, Iterator end)
{
	if (begin == end)
		throw domain_error("Median of an empty container!");

	vector<T> temp;

	while (begin != end) {
		temp.push_back(*begin);
		begin++;
	}

	sort(temp.begin(), temp.end());

	size_t mid = temp.size() / 2;

	if (temp.size() % 2 == 0)
		return (temp[mid] + temp[mid - 1]) / 2;
	else
		return temp[mid];
}

int main()
{
	int ar[] = { 3, 5, 7, 9, 1 };
	vector<int> v = { 5, 7, 9, 11, 3 };
	list<int> l = { 3, 5, 7, 9, 1 };
	vector<double> v_error;

	int m = median<int>(v.begin(), v.end());
	cout << "Median of vector v = { 5, 7, 9, 11, 3 } is: " << m << endl;

	cout << "Elements in the vector after calculating median is: ";
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";

	cout << endl << endl;

	int n = median<int>(ar, ar + 5);
	cout << "Median of array ar[] = { 3, 5, 7, 9, 1 } is: " << n << endl;

	cout << "Elements in the array after calculating median is: ";
	for (size_t i = 0; i < 5; i++)
		cout << ar[i] << " ";

	return 0;
}

// [FAIL VERSION]: Order of elements changes after calculating median
/*
template<class T, class Iterator>
T median(Iterator first, Iterator last)
{
size_t size = last - first;

if (size == 0)
throw domain_error("Median of an empty container!");

sort(first, last);		// FAIL

size_t mid = size / 2;

if (size % 2 == 0)
return (*(first + mid) + *(first + mid - 1)) / 2;
else
return *(first + mid);
}

int main() 
{
int ar[] = { 1, 3, 5, 7, 9, 0 };

double m = median<double>(ar, ar + 5);
cout << m << endl;
return 0;
}
*/
