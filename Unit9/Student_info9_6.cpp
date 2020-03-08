#include "stdafx.h"
#include "grade9_6.h"
#include "Student_info9_6.h"

using std::istream;		using std::vector;

Student_info::Student_info() : midterm(0), final(0) {}			// Constructor definition: set midterm and final grades to 0, (n & homework are implicitly initialized)

Student_info::Student_info(std::istream& is) { read(is); }			// Constructor definition

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

void Student_info::setFinal_grade() 
{
	final_grade = grade(midterm, final);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.getFinal_grade() > y.getFinal_grade();
}

