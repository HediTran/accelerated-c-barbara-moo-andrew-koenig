// source file for the grade function
#include "stdafx.h"
#include <stdexcept>
#include <vector>
#include "grade11_5.h"
#include "median11_5.h"
#include "Student_info11_5.h"

using std::domain_error;
using std::vector;

//compute a student's overall grade from midterm and final exam grades and homework

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

	// compute a student's overall grade from midterm and final exam grades
	// and vector of homework grades.
	// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}
