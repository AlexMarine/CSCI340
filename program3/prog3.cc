/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				September 30, 2019
//	Program Name:			prog3.cc
//
//	Purpose of Program:
//		This program creates a set of prime numbers using the Sieve of
//		Eratosthenes algorithm. The user inputs the number at which they
//		want the set to be capped and then the prime numbers are outputted.
////////////////////////////////////////////////////////////////////////////

//include header file
#include "prog3.h"

int main()
{
	//variable declaration
	set <int> s;
	int n;

	//prompt user
	cout << "upper limit for the set of primes: ";
	cin >> n;
	//line break
	cout << endl;

	//function call
	sieve(s, n);
	print_primes(s);

	return 0;
}

//function definition
//sieve of eratosthenes
void sieve(set <int> &s, int n)
{
	//fill set from 2 to n
	for (int i = 2; i < n; i++)
	{
		s.insert(i);
	}

	//erase all prime numbers from set
	for (int m = 2; m < n; m++)
	{
		for (int k = 2; k < n; k++)
		{
			s.erase(m * k);
		}
	}
}

//function definition
//print set
void print_primes(const set <int> &s)
{
	//variable declaration
	int cnt = 1;

	//go through vector
	for (const auto & x : s)
	{
		//left indent - 5 spaces, print number
		cout << right << setw(ITEM_W) << x << " ";

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