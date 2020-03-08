// This program find the median of a vector

#include <algorithm>	// to get the declaration of sort
#include <stdexcept>	// to get the declaration of domain_error
#include <vector>		// to get the declaration of vector

using namespace std;

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
			/* execution stops in the part of the program in which the "throw" appear 
			passes to another part of the program 
			along with an EXCEPTION OBJECT (caller can use this to act on the exception*/
	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
	/* We eliminate the variable median because we no longer need it. 
		We "return" the median as soon as we've calculated it */
}
