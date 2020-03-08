#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <istream>

class Student_info {
public:
	// interface goes here
	Student_info();					// construct an empty Student_info object (default constructor)
	Student_info(std::istream&);	// construct a Student_info object by reading a stream 
	
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }

	std::istream& read(std::istream&);

	std::string grade() const;

private:
	// implementation goes here
	std::string n;		// We changed the data member's name from name to n to avoid confusing it with the name of the function
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

std::istream& read_hw(std::istream&, std::vector<double>&);
