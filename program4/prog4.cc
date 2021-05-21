/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				October 10, 2019
//	Program Name:			prog4.cc
//
//	Purpose of Program:
//		This program takes an input from the user, and "cleans" each string
//		entered from any punctuations marks, as well as makes every letter
//		lower case. Then it outputs each unique string and the frequency
//		of its occurence. Finally, the program will output the number of
//		words found in the input stream and then output the number of
//		distinct words found in the output stream.
////////////////////////////////////////////////////////////////////////////

//include header file
#include "prog4.h"

//main function
int main()
{
	//variable declaration
	map<string, int> words;

	//function call
	get_words(words);
	print_words(words);

	return 0;
}

//function definition
void get_words(map <string, int> & m)
{
	//variable declaration
	string clean, dirty;

	//while there is an input
	while (cin)
	{
		//get user input
		cin >> dirty;

		//function call
		clean_entry(dirty, clean);

		//if size is greater than 0
		if (clean.size() > 0)
		{
			//add to map
			m[clean]++;
		}
	}
}

//function definition
void print_words(const map <string, int> & m)
{
	//variable declaration
	int cnt = 1;		//counter
	int distinct = 0;	//number of strings in output stream

	//print map's contents
	for (const pair <string, int> & x : m)
	{
		//left indent - 5 spaces, print number
		cout << left << setw(ITEM_W) << x.first << "\t" << ": " << x.second;
		cout << "     ";

		//new line after 12 numbers
		if (cnt % NO_ITEMS == 0)
		{
			cout << endl;
		}
		cnt++;	//add 1 to counter
		distinct += x.second;	//add 1 to distinct
	}

	//output to user
	cout << endl;
	cout << "no of words in input stream  : " << distinct << endl;
	cout << "no of words in output stream : " << m.size() << endl;
}

//function definition
void clean_entry(const string & a, string & b)
{
	//iterator declaration
	auto start = a.begin();
	auto last = a.begin();

	//start is set to the first alpha numeric character
	start = find_if(a.begin(), a.end(), [](char c) {return (isalnum(c) > 0); });
	
	//last is set to the first non alpha numeric character after the last one
	last = find_if(a.begin(), a.end(), [](char c) {return ((!isalnum(c)) > 0); });

	//isolate the characters wanted from the string
	b = a.substr(start - a.begin(), last - start);

	//make all characters lowercase
	transform(b.begin(), b.end(), b.begin(), [](unsigned char c) { return tolower(c); });
}