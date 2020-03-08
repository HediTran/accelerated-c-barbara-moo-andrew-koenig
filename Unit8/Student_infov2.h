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

	double grade() const;

private:
	// implementation goes here
	std::string n;		// We changed the data member's name from name to n to avoid confusing it with the name of the function
	double midterm, final;
	std::vector<double> homework;
};

Student_info::Student_info() : midterm(0), final(0) {}			// Constructor definition: set midterm and final grades to 0, (n & homework are implicitly initialized)

Student_info::Student_info(istream& is) { read(is); }			// Constructor definition

bool compare(const Student_info& x, const Student_info& y);

std::istream& read_hw(std::istream&, std::vector<double>&);
