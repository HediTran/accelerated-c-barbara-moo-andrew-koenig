// source file for Student_info-related functions
#include "stdafx.h"
#include "Student_infov2.h"

using std::istream;		using std::vector;

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
		/*  Once we have failed to read from a stream, all further attempts to read from
		that stream will fail until we reset the stream
		This statement reset the error state inside "in",
		which tells the library that input can continue despite the failure
		*/
	}
	return in;
}