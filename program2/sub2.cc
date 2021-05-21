/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				September 19, 2019
//	Program Name:			sub2.cc
//
//	Purpose of Program:
//		This program will implement two search algorithms (a linear search
//		and a binary search) on randomly generated integers stored in
//		vectors.
////////////////////////////////////////////////////////////////////////////

//header file
#include "prog2.h"

//function definition
//fills two vectors with random integers
void Vectors(vector <int> &v1, vector <int> &v2, int s1, int s2)
{
	srand(s1);

	//random number generator fills vector v1
	for (int i = 0; i < ARR_SIZE; i++)
	{
		v1[i] = rand() % (HIGH - LOW + 1) + LOW;
	}

	srand(s2);

	//random number generator fills vector v2
	for (int i = 0; i < TEST_ARR_SIZE; i++)
	{
		v2[i] = rand() % (HIGH - LOW + 1) + LOW;
	}
}

//function definition
//search vector for item x, return true if found, false if not
bool linearSearch(const vector <int> &v, int x)
{
	//return find function if it is true
	return find(v.begin(), v.end(), x) != v.end();
}

//function definition
bool binarySearch(const vector <int> &v, int x)
{
	//return binary search function
	return binary_search(v.begin(), v.end(), x);
}

//function definition
int search(const vector <int> &v1, const vector <int> &v2, bool(*p) (const vector <int> &, int))
{
	//variable declaration
	int cnt = 0;

	//go through vector
	for (size_t i = 0; i < v2.size(); i++)
	{
		//if p function is true, add one to cnt
		if (p(v1, v2[i]) == true)
		{
			cnt++;
		}
	}
	//return cnt
	return cnt;
}

//function definition
//sorts vector
void sortVector(vector <int> &v)
{
	//call sort function
	sort(v.begin(), v.end());
}

//function definition
//prints out vector
void printVector(const vector <int> &v)
{
	//variable declaration
	int cnt = 1;

	//go through vector
	for (size_t i = 0; i < v.size(); i++)
	{
		//left indent - 5 spaces, print number
		cout << right << setw(ITEM_W) << v[i] << " ";

		//new line after 12 numbers
		if (cnt % NO_ITEMS == 0)
		{
			cout << endl;
		}
		cnt++;
	}

	//line break
	cout << endl;
}

//function definition
void printStat(int totalSucCnt, int vectorSz)
{
	//variable declaration
	double prcnt = totalSucCnt * 100.0 / vectorSz;

	//set to two decimal places
	cout << fixed << setprecision(2);

	//right allign, output percent
	cout << right << "Percent of Successful Searches = " << prcnt << "%" << endl;
}