// Input:	Smith 93 91
//			Carpenter 40 40
// This program generates grades for students who take the course for pass/fail credit. (avg midterm + final > 60)
// The report shows all the students who passed, followed by all the students who failed.
#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "grade9_6.h"
#include "Student_info9_6.h"

using namespace std;

int main()
{
	cout << "Please enter student's name, followed by one grade for midterm and one grade for final test." << endl;

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;	

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// calculate the final grade
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i)
	{
		students[i].setFinal_grade();
	}

	// sort the student records: pass students, followed by fail students
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i)
	{
		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ')
			<< students[i].getFinal_grade() << endl;
	}

	return 0;
}

