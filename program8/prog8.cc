/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				November 18, 2019
//	Program Name:			prog8.cc
//
//	Purpose of Program
//		
////////////////////////////////////////////////////////////////////////////

#include "prog8.h"
//#include "/home/cs340/progs/19f/p8/prog8.h"

//template class
template <typename T>
//function definition
void get_list(vector <T>& v, const char* path)
{
	//variable declaration
	T tmp;

	//in stream declaration and open
	ifstream ins(path);

	//if file is open
	if (ins.is_open())
	{
		//while data is being read in
		while (ins >> tmp)
		{
			//put into vector
			v.push_back(tmp);
		}

		//close file
		ins.close();
	}
	//if file is not open
	else
	{
		//inform user that the file can not be opened
		cout << "ERROR: UNABLE TO OPEN FILE" << endl;

		//exit program
		exit(1);
	}
}

//template class
template <typename T, typename P>
//function definition
void construct_heap(vector <T>& v, P pred)
{
	//make_heap function call
	make_heap(v.begin(), v.end(), pred);

	//sort_heap function call
	sort_heap(v.begin(), v.end(), pred);
}

//template calss
template <typename T>
//function definiton
print_list <T>::print_list(const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c)
{
	//initialize variables
	sz = s;
	wid = w;
	len = l;
	cnt = c;
}

//template class
template <typename T>
//function definition
void print_list <T>::operator () (const T& x)
{
	//for printout
	cout.width(wid); cout.precision(2);
	cout << fixed << showpoint;

	//traverse through vector
	for (unsigned i = 0; i < 1; i++)
	{
		//if cnt equals len
		if (cnt == len)
		{
			//print new line
			cout << endl;

			//reset cnt to 0
			cnt = 0;
		}

		//output item
		cout << x;

		//add 1 to cnt
		cnt++;
	}
}

int main ()
{
    vector <int>    v1;   //heap of integers
    vector <float>  v2;   //heap of floating-pt nums
    vector <string> v3;   //heap of strings

    //print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    //first heap
    cout << "first heap - ascending order:\n\n";
    get_list (v1, D1);
    construct_heap (v1, less <int> ());
    print_list <int> print1 (v1.size(), INT_SZ, INT_LN);
    for_each (v1.begin(), v1.end(), print1);

    cout << "first heap - descending order:\n\n";
    get_list (v1, D1);
    construct_heap (v1, greater <int> ());
    for_each (v1.begin(), v1.end(), print1);

    //second heap
    cout << "second heap - ascending order:\n\n";
    get_list (v2, D2);
    construct_heap (v2, less <float> ());
    print_list <float> print2 (v2.size(), FLT_SZ, FLT_LN);
    for_each (v2.begin(), v2.end(), print2);

    cout << "second heap - descending order:\n\n";
    get_list (v2, D2);
    construct_heap (v2, greater <float> ());
    for_each (v2.begin(), v2.end(), print2);

    //third heap
    cout << "third heap - ascending order:\n\n";
    get_list (v3, D3);
    construct_heap (v3, less <string> ());
    print_list <string> print3 (v3.size(), STR_SZ, STR_LN);
    for_each (v3.begin(), v3.end(), print3);

    cout << "third heap - descending order:\n\n";
    get_list (v3, D3);
    construct_heap (v3, greater <string> ());
    for_each (v3.begin(), v3.end(), print3);

    //print termination messag
    cout << "\t\t\t*** end of program execution ***\n\n";

	system("pause");

    return 0;
}