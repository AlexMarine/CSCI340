#pragma once

#include "Entry.h"
//#include "/home/cs340/progs/19f/p9/Entry.h"

#ifndef H_HASH_TABLE
#define H_HASH_TABLE

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//class for hash table
class HT
{
public:
	HT(const unsigned& = TBL_SZ);	//constructor
	~HT();							//destructor

	void insert(const Entry&);	//inserts item in hash table
	void search(const string&);	//searches for item

	void hTable_print();	//prints hash table entries
	void pTable_print();	//prints hash table entries in sorted order

private:
	unsigned hsize;	//size of hash table

	vector <list<Entry>>  hTable;	//hash table
	vector <Entry*> pTable;			//ptr table

	int hash(const string&);	//hash function
};

#endif