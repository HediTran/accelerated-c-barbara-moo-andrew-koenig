#include "stdafx.h"
#include "grade9_5.h"
#include "Student_info9_5.h"

using std::istream;		using std::vector;

Student_info::Student_info() : midterm(0), final(0) {}			// Constructor definition: set midterm and final grades to 0, (n & homework are implicitly initialized)

Student_info::Student_info(std::istream& is) { read(is); }			// Constructor definition

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

char Student_info::grade() const
{
	return ::grade(midterm, final);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

