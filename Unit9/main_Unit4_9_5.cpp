// Input:	Smith 93 91 
//			Carpenter 40 40 
#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "grade9_5.h"
#include "Student_info9_5.h"

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

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i)
	{
		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');

			char final_grade = students[i].grade();
			cout << final_grade << endl;
	}
	return 0;
}

