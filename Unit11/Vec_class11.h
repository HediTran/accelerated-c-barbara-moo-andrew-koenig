// Vec class is similar to vector class -> understand how to design and implement classes\
// LESSON LEARNED: Constructor definition must be in the same file as class definition! Member functs can be defined in a source file
#pragma once
#include "stdafx.h"
#include <string>
#include <iterator>
#include <algorithm>
#include <cstddef>	// use size_t (refer to the size of an array), ptrdiff_t (signed long long) (represent the distance between 2 pointers)
#include <memory>	// has class allocator<T>		// Note about class allocator at the end of this source file

// Vec is a template class, with a single type parameter named T
template<class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	Vec() { create(); }		// default constructor: When we return from create, both data and limit is set to zero
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }	// constructor
	/* The keyword 'explicit' makes sense only in the def of a constructor that takes a single argument. When we say that a constructor is
	explicit, we're saying that the compiler will use the constructor only in contexts in which the user expressly invokes the constructor.*/
	Vec(const Vec& v) { create(v.begin(), v.end()); }	// Copy Constructor
	/* Copy Constructor exists to INITIALIZE a new Obj as a copy of an existing OBj of the same type: Eg: pass by value in function call
	When we use '=' to give an initial value to a variable, we are invoking the copy constructor. Eg: Vec<string> v = split(line); */
	Vec& operator=(const Vec&);			// Assignment Operator
	~Vec() { uncreate(); }			// Destructor

	T& operator[](size_type i) { return data[i]; }			// index operator
	const T& operator[](size_type i) const { return data[i]; }
	/* The two above operators can be overloaded even though they have the same argument lists because each of those operators takes
	an implicit parameter, which is the object on which it operates. Because the operations differ regarding whether that object is
	const, we can overload the operation*/

	void push_back(const T& val)
	{
		if (avail == limit)		// get space if needed
			grow();
		unchecked_append(val);	// append the new element
	}

	iterator erase(iterator it)
	{
		for (iterator i = it; i != avail; i++)
		{
			alloc.destroy(i);
			if ((i + 1) != avail)
				alloc.construct(i, *(i + 1));
		}

		avail--;

		return it;
	}

	void clear() {
		uncreate();
	}

	size_type size() const { return avail - data; }		// Member function to calculate size

	// Member functions to return iterators
	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }
private:
	iterator data;		// pointer that point to the first element in the Vec
	iterator avail;		// pointer to (one past) the last constructed element in the Vec
	iterator limit;		// pointer that point to (one past) the allocated memory

	// facilities for memory allocation
	std::allocator<T> alloc;	// Obj to handle memory allocation

	// allocate and initialize the underlying array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// destroy the elements in the array and free the memory
	void uncreate();

	// support functions for push_back()
	void grow();
	void unchecked_append(const T&);
};

template<class T>
void Vec<T>::create()
{
	data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

template<class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = uninitialized_copy(i, j, data);
	/* Constructs copies of the elements in the range [first, last) into a range
	beginning at result and returns an iterator to the	LAST ELEMENT in the destination range */
}

// Inside the class def, we can omit the type: Vec& operator=(const Vec&)
// rhs stands for right-hand side
template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)		
{
	/* This direct self-assignment check is not universal, nor is it the best approach. 
	The important point is to handle self-assignment correctly. How to do so is a matter of tactics. */
	if (&rhs != this)		// 'this' keyword is valid only inside a member funct. It denotes a pointer to the Obj on which the member funct is operating
	{
		uncreate();			// free the array in the left-hand side

		create(rhs.begin(), rhs.end());		// copy elements from the right-hand to the left-hand side
	}
	return *this;
}

template<class T>
void Vec<T>::uncreate()
{
	// If data is zero, there's no work to do
	if (data) {
		// destroy (in reverse order) the elements that were constructed
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// return all the space that was allocated
		alloc.deallocate(data, limit - data);
		/* The alloc.deallocate function requires a nonzero pointer, even if no memoery is being freed
		Unlike alloc.deallocate, executing delete on a zero pointer is harmless */
	}
	// reset pointers to indicate that the Vec is empty again
	data = limit = avail = 0;
}

template<class T>
void Vec<T>::grow()
{
	// when growing, allocate twice as much space as currently in use
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));			// use max here because Vec might currently be empty

	// allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);

	// return the old space
	uncreate();

	// reset pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// assumes avail points at allocated, but uninitialized space. Since we call grow before calline this funct -> assumption is always true
template<class T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

/* WHAT DOES ALLOCATOR CLASS LOOK LIKE? (PARTIAL PICTURE)
template<class T> class allocator {
public:
T * allocate(size_t);
void deallocate(T*, size_t);
void construct(T*, const T&);
void destroy(T*);
};

template<class Out, class T> void uninitialized_fill(Out, Out, const T&);
template<class In, class Out> Out uninitialized_copy(In, In, Out);

*/


/* Why we defined value_type as a synonym for type T -> we don't use value_type? */
/* Project -> Sample Properties -> Configuration Properties -> C/C++ -> Advanced -> Disable Specific Warnings */
////stdext::make_checked_array_iterator(data, (j - i));
// stdext::make_checked_array_iterator(new_data, new_size);
 