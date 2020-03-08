// This program calculate the squares of int values up to 100
// This program calculate the squares of double from 5 to 6, increment = 0.005.
#include "stdafx.h"
#include <iostream>	
#include <vector>
#include <iomanip>
#include <ios>
#include <algorithm>

using namespace std;

// return the required streamsize to fit a particular integer number
streamsize getStreamWidth(int number) 
{

	streamsize numDigits;

	// initialise numDigits based on whether it has positive/negative value
	// If positive: 1 space as Leading empty space
	// If negative: 2 spaces as Leading empty space + negative sign
	if (number < 0)
	{
		numDigits = 2;
		number *= -1;
	}
	else
		numDigits = 1;

	// numDigits is the number of divisions required to make number approaches zero (plus Leading space & sign)
	// numDigits = total stream width required
	while (number != 0)
	{
		++numDigits;
		number /= 10;
	}

	return numDigits;
}

// return the required streamsize to fit a particular DOUBLE number, given number of decimals
streamsize getStreamWidth(double number, streamsize numDecimals) 
{

	streamsize numDigits = numDecimals;

	// initialise numDigits and number based on whether it has positive/negative value
	// If positive: 1 space as Leading empty space
	// If negative: 2 spaces as Leading empty space + negative sign
	if (number < 0)
	{
		numDigits = 3 + numDecimals;	// (Leading space + negative sign + decimal point) + decimals
		number *= -1;
	}
	else
		numDigits = 2 + numDecimals;	// (Leading space + decimal point) + decimals

	while (number >= 1)	// Eg: 197.125 => stop when number = 0.197125
	{
		++numDigits;
		number /= 10;
	}

	return numDigits;
}

int main()
{
	// Adjust these initial values for different tests
	const double start = 5;		// start of range (inclusive)
	const double end = 6;		// end of range (exclusive)
	const double i = 0.005;		// incremental interval
	const streamsize d = 3;		// number of decimal places

	// find the maxwidth for column 1 and 2
	const streamsize col1Width = max(getStreamWidth(start, d), getStreamWidth(end, d));
	const streamsize col2Width = max(getStreamWidth(start*start, d), getStreamWidth(end*end, d));

	// Compute precision
	// Precision = width - "gap"
	// If involves negative region: precision = width - (Leading space + decimal point + negative sign) = width - 3
	// else, precision = width - (Leading space + decimal point) = width - 2
	streamsize gap;
	if (start < 0 || end < 0)
	{
		gap = 3;	// Leading space + decimal point + negative sign
	}
	else
		gap = 2;	// Leading space + decimal point

	const streamsize col1Precision = col1Width - gap;
	const streamsize col2Precision = col2Width - 2;	// squares is always positive

	// print report
	double y = start;	// increment y over time
	while (y <= end)
	{
		cout << setw(col1Width) << setprecision(col1Precision) << y
			<< setw(col2Width + 10) << setprecision(col2Precision) << (y * y) << endl;
		y += i;
	}

	cout << setw(cout.width()) << setprecision(cout.precision()) << endl;

	// display a summary
	cout << "start = " << start << ", end = " << end << ", increment = " << i << ", decimalPlaces = " << d << endl;
	cout << "Column 1 Width = " << col1Width << " | Column 2 Width = " << col2Width << endl;
	cout << getStreamWidth(start, d) << endl;

	return 0;
}