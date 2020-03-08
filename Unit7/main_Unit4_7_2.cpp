// Input:	Smith 93 91 47 90 92 73 100 87 
//			Carpenter 75 90 87 92 93 60 0 98

#include "stdafx.h""
#include "windows.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"

using namespace std;

map<double, char> gradeToLetterMap = {
	{ 100, 'A' },
{ 89.99, 'B' },
{ 79.99, 'C' },
{ 69.99, 'D' },
{ 59.99, 'F' }
};

char convertToLetter(int grade) {
	auto c = lower_bound(gradeToLetterMap.begin(), gradeToLetterMap.end(), pair<const double, char>(grade, 'A'));
	if (c == gradeToLetterMap.end())
	{
		throw runtime_error("can't find");
	}
	return c->second;
}

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

		// map to count how many students got A/B/C/D/F
		map<char, int> counters;

		// compute and write the grade by assigning grade to letter
		try
		{
			double final_grade = grade(students[i]);
			cout << convertToLetter(final_grade);
			++counters[convertToLetter(final_grade)];
		}
		catch (domain_error e)
		{
			cout << e.what();
		}

		cout << endl;

		cout << "There are " << counters['A'] << " student(s) got A" << endl;
		cout << "There are " << counters['B'] << " student(s) got B" << endl;
		cout << "There are " << counters['C'] << " student(s) got C" << endl;
		cout << "There are " << counters['D'] << " student(s) got D" << endl;
		cout << "There are " << counters['F'] << " student(s) got F" << endl;
	}
	return 0;
}

