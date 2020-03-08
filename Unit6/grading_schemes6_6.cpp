// To run this source code, put it in one place along with the header files: grade.h, median.h, Student_info.h
// Merge theree analysis functions into a single function

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <istream>
#include <numeric>	// use accumulate()
#include "Student_info.h"
#include "grade.h"
#include "median.h"


using namespace std;

bool did_all_hw(const Student_info& s) {
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade_aux(const Student_info& s) {
	try
	{
		return grade(s);
	}
	catch (domain_error)
	{
		return grade(s.midterm, s.final, 0);
	}
}

template<class T>
void write_analysis(ostream& out, 
					const string& name,
					T gradeScheme(const Student_info&),
					const vector<Student_info>& did, 
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did, gradeScheme) <<
		", median(didnt) = " << analysis(didnt, gradeScheme) << endl;
}

double average(const vector<double>& v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s) {
	vector<double> nonzero;

	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	if (nonzero.empty())
	{
		return grade(s.midterm, s.final, 0);
	}
	else
	{
		return grade(s.midterm, s.final, median(nonzero));
	}
}

template<class T>
T analysis(const vector<Student_info>& students, T gradeScheme(const Student_info&))
{
	vector<T> grades;
	transform(students.begin(), students.end(), back_inserter(grades), gradeScheme);

	return median(grades);
	
}


int main() {

	vector<Student_info> did, didnt;
	Student_info student;

	// read all the records, separating them based on whether all homework was done
	while (read(cin, student))
	{
		if (did_all_hw(student))
		{
			did.push_back(student);
		}
		else
		{
			didnt.push_back(student);
		}
	}

	// verify that the analyses will show us something
	if (did.empty())
	{
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty())
	{
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	// do the analyses
	write_analysis(cout, "median", grade_aux, did, didnt);
	write_analysis(cout, "average", average_grade, did, didnt);
	write_analysis(cout, "median of homework turned in",
		optimistic_median, did, didnt);


	return 0;
}



