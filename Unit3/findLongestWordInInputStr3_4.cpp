// This program report the length of the 
//longest and shortest string in its input

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter words: " << endl;
	string
		shortest,
		longest,
		word;
	cin >> word;

	shortest = longest = word;

	while (cin >> word)
	{
		if (word.size() > longest.size())
			longest = word;
		else if (word.size() < shortest.size())
			shortest = word;
	}
				
	cout << "The longest word is: " << longest << endl;
	cout << "The shortest word is: " << shortest << endl;

	return 0;
}