// source file for the grade function
#include "stdafx.h"
#include <stdexcept>
#include <vector>
#include <string>
#include "grade10_1.h"
#include "median10_1.h"
#include "Student_info10_1.h"

using namespace std;

// from file letters2grades10 in AdrewKo Unit 10
string letter_grade(double grade) {

	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

	for (size_t i = 0; i < ngrades; i++)
	{
		if (grade >= numbers[i])
			return letters[i];
	}

	return "?\?\?";
}


//compute a student's overall grade from midterm and final exam grades and homework

string grade(double midterm, double final, double homework)
{
	return letter_grade(0.2 * midterm + 0.4 * final + 0.4 * homework);
}

string grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}
