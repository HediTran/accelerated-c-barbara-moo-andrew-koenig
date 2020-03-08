// Template to find median of an unknown vector

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

template<class T>
T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template<class In, class X>
In find(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
}

/*
template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
while (begin != end)
*dest++ = *begin++;
return dest;
}
*/

template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end)
	{
		if (*beg == x)
			*beg = y;
		++beg;
	}
}

template<class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end)
	{
		// find the midpoint of the range
		Ran mid = begin + (end - begin) / 2;
		// see which part of the range contains x; keep looking only in that part
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		// if we got here, then *mid == x, so we're done
		else return true;
	}
	return false;
}

template<class T>
T zero()
{
	return 0;
}


int main()
{
	vector<int> vecInt = { 1,3,5,7,9,11 };
	vector<double> vecDouble = { 4.4, 4.5, 4.6, 4.7 };

	int x = median(vecInt);
	double y = median(vecDouble);

	cout << "The median of {1, 3, 5, 7, 9, 11} is: " << x << endl;
	cout << "The median of {4.4, 4.5, 4.6, 4.7} is: " << y << endl;

	// input stream iterator (read only)
	cout << "Enter numbers(int): " << endl;
	vector<int> v;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " and "));

	//If the types do not all appear in the argument list, then the caller must qualify the function-name with the actual types
	// that cannot be inferred
	// In this case, instead of y = zero(); , we MUST write zero<double>();
	double y = zero<double>();
	cout << y << endl;

	return 0;
}




