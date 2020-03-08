// source file for Student_info-related functions
#include "stdafx.h"
#include "Student_info.h"

using std::istream;		using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
		// read and store the students's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);	// read and store all the student's homework grades
	return is;
}

	// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
		/* To return two "return values" at once 
		we give the function a parameter (a reference to an object(This reference must be lvalue))
		for it to place one of its result
		--> common for functions that read input */
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