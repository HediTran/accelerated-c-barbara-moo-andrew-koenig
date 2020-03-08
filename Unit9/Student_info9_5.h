#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <istream>

class Student_info {
public:
	Student_info();					// construct an empty Student_info object (default constructor)
	Student_info(std::istream&);	// construct a Student_info object by reading a stream 
	
	std::string name() const { return n; }

	std::istream& read(std::istream&);

	// Calculate grade -> assign letter P/F
	char grade() const;

private:
	std::string n;		
	double midterm, final;
};

bool compare(const Student_info&, const Student_info&);

