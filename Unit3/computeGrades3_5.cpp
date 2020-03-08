// Input: 4 haha(7 grades) 1 2 3 4 5 6 7

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	cout << "Please enter the student name, midterm, final term, and homework grades respectively" << endl;
	cout << "Please enter exact 5 homework grades: ";
	string name;
	vector<string> studentName;

	double midterm;
	double final;
	int	NUMHOMEWORK = 5;
	double x;
	vector<double> homework;

	double gpa = 0;
	vector<double> GPA;

	while (cin >> name)
	{
		studentName.push_back(name);

		cin >> midterm >> final;


		for (int i = 0; i < NUMHOMEWORK; i++)
		{
			cin >> x;
			homework.push_back(x);
		}

		cout << endl;

		typedef vector<double>::size_type vec_sz;
		vec_sz size = homework.size();
		if (size == 0)
		{
			cout << endl << " You must enter 5 homework grades";
			return 1;
		}

		sort(homework.begin(), homework.end());
		vec_sz mid = size / 2;
		double median;
		median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
			: homework[mid];

		gpa = 0.2 * midterm + 0.4 * final + 0.4 * median;
		GPA.push_back(gpa);
	}

	for (int i = 0; i < 4; i++)
		cout << studentName[i] << ": " << GPA[i] << endl;

	return 0;
}




