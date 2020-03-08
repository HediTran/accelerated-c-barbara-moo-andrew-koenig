// This program generate a random number even if that number might be larger than RAND_MAX

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <istream>
#include <cstdlib>		//use rand()
#include <cmath>
#include <stdexcept>
#include <iterator>
#include <time.h>

using namespace std;

int nrand(int n) {

	if (n <= 0)
	{
		throw domain_error("Argument to nrand is out of range");
	}

	int r;
	int randomDriverLimit = RAND_MAX + 1;

	if (n <= randomDriverLimit)
	{
		const int bucket_size = randomDriverLimit / n;
		do
		{
			int bucket = rand() / bucket_size;
			r = bucket;
		} while (r >= n);
	}
	else
	{
		const int bucket_size = ceil(n / randomDriverLimit);
		do
		{
			int bucket = nrand(randomDriverLimit);
			int remainder = nrand(bucket_size);
			r = (bucket*bucket_size) + remainder;
		} while (r >= n);
	}

	return r;
}

int main() {

	srand(time(0));
	long long x = nrand(85184);
	cout << x << endl;

	return 0;
}




