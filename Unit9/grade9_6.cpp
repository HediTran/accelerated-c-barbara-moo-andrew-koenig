// source file for the grade function
#include "stdafx.h"
#include <stdexcept>
#include <vector>
#include "grade9_6.h"
#include "Student_info9_6.h"

using std::domain_error;
using std::vector;

//compute a student's average grade from midterm and final exam grades
bool pgrade(double midterm, double final)
{
	return ((midterm + final) / 2) > 60;
}

	// compute a student's overall grade from midterm and final exam grades
char grade(double midterm, double final)
{
	if (pgrade(midterm, final))
		return 'P';
	else
		return 'F';
}
