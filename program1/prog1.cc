/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				September 10, 2019
//	Program Name:			prog1.cpp
//
//	Purpose of Program:
//		Creates a vector of size 200, that is filled with random integers
//		and sorted in ascending order. There will be 12 numbers per line
//		each allocated with 5 spaces per number.
////////////////////////////////////////////////////////////////////////////

#include "prog1.h"
using namespace std;

//function prototypes
void getRndNums(vector <int> &v, const int s);
void printVec(const vector <int> &v, const int s);

int main()
{
	//variable declaration
	const int vec_size = 200;
	vector <int> v(vec_size);

	//function call
	getRndNums(v, vec_size);

	//sort function
	sort(v.begin(), v.end());

	//function call
	printVec(v, vec_size);

	return 0;
}

//function definition
void getRndNums(vector <int> &v, const int s)
{
	srand(1);

	//random number generator fills vector
	for (int i = 0; i < s; i++)
	{
		v[i] = rand() % 10000 + 1;
	}
}

//function definition
void printVec(const vector <int> &v, const int s)
{
	//variable declaration
	int cnt = 1;

	for (int i = 0; i < s; i++)
	{
		//left indent, 5 spaces//print number
		cout << left << setw(5) << v[i] << " ";

		//new line after 12 numbers
		if (cnt % 12 == 0)
		{
			cout << endl;
		}
		cnt++;
	}
}