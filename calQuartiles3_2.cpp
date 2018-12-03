// This program compute and print the quartiles of a set of integers

#include <algorithm>		
#include <iomanip>
#include <ios>				
#include <iostream>
#include <string>			
#include <vector>

	using namespace std;	     using std::vector; 
	using std::cin;              using std::sort;
	using std::cout;             using std::streamsize;
	using std::endl;             using std::string;
	   

	int quartiles()
	{
		// ask users to enter list of integers
		cout << "Please enter all of the numbers, "
				"followed by end-of-file: " << endl;

		vector<double> list;
		double x;

		// invariant: list contains all the numbers read so far
		while (cin >> x)
		list.push_back(x);

		typedef vector<double>::size_type vec_sz;

		vec_sz size = list.size();

		// check that the user entered some numbers
		if (size == 0) {
		cout << endl << "You must enter your grades. "
						"Please try again." << endl;
		return 1;
		}

		// sort 
		sort(list.begin(), list.end());

		// a variable called mid
		vec_sz mid = size / 2;

		// compute upper & lower quartile
		if (size % 2 == 0) // upper & lower quartile for even size
		{
			vec_sz size_1 = size - mid;
			
			vec_sz mid_1 = size_1 / 2;

			double upQuaE,
				   lowQuaE;

			upQuaE = size_1 % 2 == 0	? (list[mid + mid_1] + list[mid + mid_1 - 1]) / 2 
										: list[mid + mid_1];

			lowQuaE = size_1 % 2 == 0	? (list[mid - mid_1] + list[mid - mid_1 - 1]) / 2 
										: list[mid - mid_1 -1];

			cout << "  Upper quartile is: " << upQuaE << endl;
			cout << "  Lower quartile is: " << lowQuaE << endl;
		}
		else // uper & lower quartile for odd size
		{
			vec_sz size_1 = size - mid - 1;
			
			vec_sz mid_1 = size_1 / 2;

			double	upQuaO,
					lowQuaO;

			upQuaO = size_1 % 2 == 0	? (list[mid + mid_1] + list[mid + mid_1 + 1]) / 2 
							: list[mid + mid_1 + 1];

			lowQuaO = size_1 % 2 == 0	? (list[mid - mid_1] + list[mid - mid_1 - 1]) / 2 
							: list[mid - mid_1 - 1];

			cout << "  Upper quartile is: " << upQuaO << endl;
			cout << "  Lower quartile is: " << lowQuaO << endl;
		}
				
		// compute median 
		double median;
		median = size % 2 == 0 ? (list[mid] + list[mid - 1]) / 2 : list[mid];
		cout << "  Median is: " << median << endl;
		
		return 0;
	}
