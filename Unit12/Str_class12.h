#pragma once
#include "stdafx.h"
#include <cstddef>	// use size_t (refer to the size of an array), ptrdiff_t (signed int) (represent the distance between 2 pointers)
#include <cstring>	// use size_t, strlen()
#include <ostream>
#include <iterator>
#include "Vec_class11.h"

class Str {
	friend std::istream& operator>>(std::istream& is, Str& s);		// A 'friend' has the same access rights as a member
	friend std::istream& getline(std::istream& is, Str& Str, char delim);
	friend std::istream& getline(std::istream& is, Str& Str);
	friend bool& operator<(Str& Str1, Str& Str2);
	friend bool& operator>(Str& Str1, Str& Str2);
	friend bool& operator==(Str& Str1, Str& Str2);
	friend bool& operator!=(Str& Str1, Str& Str2);
public:
	typedef Vec<char>::size_type size_type;
	typedef Vec<char>::iterator iterator;
	typedef Vec<char>::const_iterator const_iterator;

	Str() {}														// default constructor; create an empty Str
	Str(size_type n, char c) : data(n, c) {}						// create a Str containing n copies of c

	// create a Str from a null-terminated array of char (data is implicitly initialized as an empty Vec) 
	// Conversion: Convert string literals(type const char*) to Str
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}	   

	// create a Str from the range denoted by iterators b and e (data is implicitly initialized as an empty Vec)
	template<class In> Str(In b, In e)
	{
		std::copy(b, e, std::back_inserter(data));
	}

	/* Return a reference (char& instead of char) -> give write access to the character that it returns */
	char& operator[](size_type i) { return data[i]; }					// can't operate on const Obj
	const char& operator[](size_type i) const { return data[i]; }		// operate on const Obj (use char& eventhough we can't write -> for consistency with the standard string class)

	// Eg: str += str1; -> operates on Obj str
	Str& operator+=(const Str& s) {
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));	// data is member of the Obj we're operating on
		return *this;
	}
	Str& operator+=(const char *p) {
		std::copy(p, p + std::strlen(p), std::back_inserter(data));
		return *this;
	}

	operator bool() {
		bool ret = true;
		if (data.size() == 0)
			ret = false;
		return ret;
	}

	/* (EXERCISE ONLY)
	// create a value of type double from a value of the class type
	operator double() {
		double ret = 0;
		for (Vec<char>::size_type i = 0; i < data.size(); i++)
		{
			ret += data[i];
		}
		return ret;
	}
	*/
	
	size_type size() const { return data.size(); }
	
	bool empty() const { return data.size() == 0; }

	void clear() { data.clear(); }

	iterator begin() { return data.begin(); }
	const_iterator begin() const { return data.begin(); }
	iterator end() { return data.end(); }
	const_iterator end() const { return data.end(); }

private:
	Vec<char> data;
};

std::istream& operator>>(std::istream& is, Str& s)
{
	// obliterate existing value(s)
	s.data.clear();

	// read and discard leading whitespace
	char c;
	while (is.get(c) && isspace(c))
		;	// nothing to do, except testing the condition

			// if still sth to read, do so until next whitespace character
	if (is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c));

		// if we exited the loop because we've encountered a whitespace character (have get whitespace), then put it back on the stream
		if (is)
			is.unget();
	}
	return is;
}


std::ostream& operator<<(std::ostream& os, Str& s)
{
	for (Str::size_type i = 0; i != s.size(); i++)
		os << s[i];
	return os;
} 

/*
void operator<<(std::ostream_iterator<char>& (os), Str& s)
{
	//std::ostream_iterator<char> os(std::cout);
	std::copy(s.begin(), s.end(), os);
	//os << s;
	
	//return os;
} */

// Concatenation is a nonmember function that will create a new Str r
Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}

Str operator+(const Str& s, const char *p) {
	Str r = s;
	r += p;
	return r;
}

inline bool& operator<(Str& Str1, Str& Str2) {
	bool ret;
	if (strcmp(Str1.data.begin(), Str2.data.begin()) < 0)
		ret = true;
	else
		ret = false;
	return ret;
}

inline bool& operator>(Str & Str1, Str & Str2)
{
	bool ret;
	if (strcmp(Str1.data.begin(), Str2.data.begin()) > 0)
		ret = true;
	else
		ret = false;
	return ret;
}

inline bool & operator==(Str & Str1, Str & Str2)
{
	bool ret;
	if (strcmp(Str1.data.begin(), Str2.data.begin()) == 0)
		ret = true;
	else
		ret = false;
	return ret;
}

inline bool & operator!=(Str & Str1, Str & Str2)
{
	bool ret;
	if (strcmp(Str1.data.begin(), Str2.data.begin()) != 0)
		ret = true;
	else
		ret = false;
	return ret;
}

std::istream& getline(std::istream& is, Str& Str, char delim) {
	Str.clear();
	char ch;

	while (is.get(ch) && (ch != delim))
		Str.data.push_back(ch);
	return is;
}
std::istream& getline(std::istream& is, Str& Str) {
	Str.clear();
	char ch;

	while (is.get(ch) && (ch != '\n'))
		Str.data.push_back(ch);
	return is;
}

// 12-9: Use class ostream_iterator to reimplement the Str output operator. WHy didn't we ask you to reimplement the input operator using class istream_iterator?