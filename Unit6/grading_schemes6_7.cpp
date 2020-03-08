// To run this source code, put it in one place along with the header files: grade.h, median.h, Student_info.h
// This portion that read and classified student records depending on whether they did (or did not) do all the homework
// is similar to how we solved in extract_fails6

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

double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Student_info>&),
	const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}

double average(const vector<double>& v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
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

double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

vector<Student_info> extract_didnt(vector<Student_info>& did)
{
	vector<Student_info>::iterator iter;
	iter = stable_partition(did.begin(), did.end(), did_all_hw);
	vector<Student_info> didnt(iter, did.end());
	did.erase(iter, did.end());

	return didnt;
}


int main() {

	vector<Student_info> did, didnt;
	Student_info student;

	// read all the records, separating them based on whether all homework was done
	while (read(cin, student))
		did.push_back(student);

	didnt = extract_didnt(did);

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
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in",
		optimistic_median_analysis, did, didnt);


	return 0;
}



