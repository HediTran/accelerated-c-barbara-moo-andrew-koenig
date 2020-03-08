// Input:	Smith 93 91 47 90 92 73 100 87 
//			Carpenter 75 90 87 92 93 60 0 98
// This source code go with all v2 files
#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "gradev2.h"
#include "Student_infov2.h"

using namespace std;

int main()
{
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

		if (students[i].valid())
		{
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		else
			cout << "Student has done no homework." << endl;
	}
	return 0;
}

