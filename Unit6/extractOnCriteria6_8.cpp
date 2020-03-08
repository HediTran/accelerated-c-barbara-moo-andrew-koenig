// Create a single (more generic) extractOnCriteria function that is capable to parse predicate such as
// fgrade (to extract failed students) and did_all_hw(to extract students who did all their homeworks).
// The idea is to generalise and minimise number of source codes to maintain in long run.

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

bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
	return !fgrade(s);
}

bool did_all_hw(const Student_info& s) {
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

bool didnt_do_all_hw(const Student_info& s) {
	return !did_all_hw(s);
}

// original extract_fails function
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info>::iterator iter;
	iter = stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());

	return fail;
}

// original extract_didnt function
vector<Student_info> extract_didnt(vector<Student_info>& did)
{
	vector<Student_info>::iterator iter;
	iter = stable_partition(did.begin(), did.end(), did_all_hw);
	vector<Student_info> didnt(iter, did.end());
	did.erase(iter, did.end());

	return didnt;
}

// extractOnCriteria function: more generic than extract_fails & extract_didnt function
vector<Student_info> extractOnCriteria(vector<Student_info>& students, bool criteria(const Student_info& s))
{
	vector<Student_info>::iterator iter;
	iter = stable_partition(students.begin(), students.end(), criteria);
	vector<Student_info> extracted(students.begin(), iter);

	return extracted;
}

int main()
{
	Student_info student;

	// vector to hold all students'information
	vector<Student_info> students;

	vector<Student_info> pass, fail, did, didnt;

	// read all the records, separating them based on whether all homework was done
	while (read(cin, student))
		students.push_back(student);

	
	// extract all students who fail
	fail = extractOnCriteria(students, fgrade);
	pass = extractOnCriteria(students, pgrade);

	cout << "Students who pass are: " << endl;
	for (vector<Student_info>::const_iterator it = pass.begin(); it != pass.end(); it++)
	{
		cout << it->name << endl;
	}

	cout << "Students who fail are: " << endl;
	for (vector<Student_info>::const_iterator it = fail.begin(); it != fail.end(); it++)
	{
		cout << it->name << endl;
	}
	
	
	// extract all students who did all homework
	did = extractOnCriteria(students, did_all_hw);
	didnt = extractOnCriteria(students, didnt_do_all_hw);

	cout << "Students who did all hw are: " << endl;
	for (vector<Student_info>::const_iterator it = did.begin(); it != did.end(); it++)
	{
		cout << it->name << endl;
	}

	cout << "Students who did not do all hw are: " << endl;
	for (vector<Student_info>::const_iterator it = didnt.begin(); it != didnt.end(); it++)
	{
		cout << it->name << endl;
	}
	

	return 0;
}