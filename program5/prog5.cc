/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				October 21, 2019
//	Program Name:			prog5.cc
//
//	Purpose of Program:
//		This program performs The Josephus Problem. There is a list of
//		strings that are assigned names. The number of names, index for
//		eliminations, and index for printing are inputted by the user.
//		Then, the program goes through the list and will erase values
//		until there is only one survivor remaining.
////////////////////////////////////////////////////////////////////////////

//#include "/home/cs340/progs/19f/p5/prog5.h"
#include "prog5.h"

int main()
{
	//variable declaration
	list <string> L;	//list of strings to hold names
	args in;		//stuct args holds user inputs for N, M, and K
	unsigned cnt = 1;	//counter for printing new lines

	//function call
	init_vals(L, in);	//initializes values in list
	print_list(L, cnt);	//prints out initial list
	cout << endl;		//line break

	//minus one from M
	in.M -= 1;

	//interator for list
	auto j = in.M % L.size();

	//while there is more than 1 value in the list
	while (L.size() > 1)
	{
		//variable declaration
		auto p = L.begin();	//iterator for list

		//goes to Mth spot in vector
		advance(p, j);

		//erases element in list
		L.erase(p);

		//adjust variables
		j += in.M;
		j %= L.size();

		//if print index is meant or there is one value in list
		if ((cnt % in.K == 0) || (L.size() == 1))
		{
			//function call
			print_list(L, cnt);	//print out list
			cout << endl;		//line break
		}

		cnt++;	//add one to counter
	}

	return 0;
}

//function definition
//user initializes values in list
void init_vals(list <string> & L, args & in)
{
	//prompt user
	cin >> in.N;
	cin >> in.M;
	cin >> in.K;

	//inform user
	cout << "Number of people? " << in.N << endl;
	cout << "Index for elimination? " << in.M << endl;
	cout << "Index for printing? " << in.K << endl;
	cout << endl;

	//change size of list to hold N strings
	L.resize(in.N);

	//generate values in string L
	generate(L.begin(), L.end(), SEQ(in.N));
}

//function definition
//print out;ist
void print_list(const list <string> & L, const unsigned & cnt)
{
	//variable declaration
	int i = 1;	//index

	//output for initial group of people
	if (cnt < 2)
	{
		//output to user
		cout << "Initial group of people" << endl;
		cout << "-----------------------------------" << endl;
	}
	//for every other group
	else
	{
		//output to user
		cout << "After eliminating " << cnt << "th person" << endl;
		cout << "-----------------------------------" << endl;
	}

	//print out names in list
	for (const string & x : L)
	{
		//output to user
		cout << x << " ";

		//new line after 12 numbers
		if (i % NO_ITEMS == 0)
		{
			cout << endl;	//line break;
		}

		i++;	//add 1 to counter
	}

	//line break
	cout << endl;
}