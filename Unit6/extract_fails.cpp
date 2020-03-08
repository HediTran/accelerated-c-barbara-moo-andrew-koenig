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

// use vector and index
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	while (i != students.size())
	{
		if (fgrade(students[i]))
		{
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
			++i;
	}
	return fail;
}

// 5_6: Use emplace()
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	int initialNumStudent = students.size();

	vector<Student_info>::size_type i = 0;

	while ((i != students.size()))
	{
		if (!fgrade(students[i]))
		{
			students.emplace(students.begin(), students[i]);
		}
		
		++i;
	}

	students.resize(students.size() - initialNumStudent);

	return students;
}

// use vector and iterator
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
	while (iter != students.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	return fail;
}

// a two-pass solution
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);

	students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
	return fail;
}

// a single-pass solution
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info>::iterator iter;
	iter = stable_partition(students.begin(), students.end(), pgrade);

	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());
	return fail;
}




