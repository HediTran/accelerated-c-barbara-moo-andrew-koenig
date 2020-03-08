// Input:	Smith 93 91 47 90 92 73 100 87 
//			Carpenter 75 90 87 92 93 60 0 98

#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;			// the length of the longest name

		// read and store all the students data.
		// Invariant: students contains all the student records read so far
		// maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(record.name.size(), maxlen);
		students.push_back(record);
	}

		// alphabetize the student records
	sort(students.begin(), students.end(), compare);

		// write the names and grades
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); i++)
	{
		// write the name, padded on the right to maxlen + 1 characters
		cout << students[i].name
			<< string(maxlen + 5 - students[i].name.size(), ' ');
	
		// compute and write the grade
		try
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}

