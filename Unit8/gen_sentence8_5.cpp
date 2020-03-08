// Note about input at the end of this file
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <istream>
#include <cstdlib>		//use rand()
#include <map>		// use class map
#include <iterator>	// use ostream_iterator

using namespace std;

bool isSpace(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

template <class Out>
void split(const string& str, Out ostream)
{
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), isSpace);

		if (i != str.end())
			*ostream++ = string(i, j);

		i = j;
	}
}

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	// read the input
	while (getline(in, line))
	{
		// split the input into words
		vector<string> entry;
		split(line, back_inserter(entry));
		if (!entry.empty())
		{
			// use the category to store the associated rule
			ret[entry[0]].push_back(
				Rule(entry.begin() + 1, entry.end()));
		}
	}
	return ret;
}

bool bracketed(const string& s) {
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// return a random integer in the range [0, n)
int nrand(int n) {
	if (n <= 0 || n > RAND_MAX)
	{
		throw domain_error("Argument to nrand is out of range");
	}

	const int bucket_size = RAND_MAX / n;
	int r;

	do
	{
		r = rand() / bucket_size;
	} while (r >= n);

	return r;
}

template <class Out>
void gen_aux(const Grammar& g, const string& word, Out os)
{
	if (!bracketed(word))
		*os = word;
	else
	{
		// locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		// from which we select one at random
		const Rule& r = c[nrand(c.size())];

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); i++)
			gen_aux(g, *i, os);
	}
}

template<class Out>
void gen_sentence(const Grammar& g, Out ostr) {
	gen_aux(g, "<sentence>", *ostr);
}

int main() 
{
	/*
	// Storing output in a vector<string>/list<string>

	vector<string> sentence;
	//list<string> sentence;
	gen_sentence(read_grammar(cin), back_inserter(sentence));

	// write the first word, if any
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty())
	{
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while (it != sentence.end())
	{
		cout << " " << *it;
		++it;
	}
	cout << endl;
	*/

	// Attatch output iterator directly to the standard output
	gen_sentence(read_grammar(cin), ostream_iterator<string>(cout, " "));
	
	cout << endl;

	return 0;
}

/*
<noun>		 cat
<noun>		 dog
<noun>		 table
<noun-phrase>	 <noun>
<noun-phrase>	 <adjective> <noun-phrase>
<adjective>		 large
<adjective>		 brown
<adjective>		 absurd
<verb>			 jumps
<verb>			 sits
<location>		 on the stairs
<location>		 wherever it wants
<location>		 over the moon
<sentence>		 the <noun-phrase> <verb> <location>
*/


