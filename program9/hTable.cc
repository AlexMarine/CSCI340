/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				December 2, 2019
//	Program Name:			hTable.cc
//
//	Purpose of Program
//		This program creates, searches, prints, and sorts an item inventory
//			using hash tables and pointer tables.
////////////////////////////////////////////////////////////////////////////

#ifndef H_TABLE
#define H_TABLE

#include "hTable.h"
//#include "/home/cs340/progs/19f/p9/hTable.h"

#include <iostream>
using namespace std;

//constructor
HT::HT(const unsigned& hs)
{
	//initialize values
	hTable.resize(hs);
	pTable.resize(hs);
	hsize = hs;
}

//destrcutor
HT::~HT()
{
	//empty
}

//function definition
void HT::insert(const Entry& e)
{
	//variable declaration
	string hold;

	//variable declaration and set to item
	int i = hash(e.key);

	//check size
	i %= hsize;

	//list declaration and set to item
	list <Entry>& l = hTable[i];

	//if there is a duplicate key
	if (find_if(l.begin(), l.end(), [hold](const Entry& e) {return hold == e.key;}) != l.cend())
	{
		//do nothing
		cout << "Duplicate key." << endl;
	}
	//else, insert item to front of table and print entry
	else
	{
		//push to front of list
		l.push_front(e);

		//create new item
		Entry* item = new Entry(e.key, e.desc, e.num);

		//push to back of pointer table
		pTable.push_back(item);

		//output item
		cout << " Item: " << i << endl;
	}
}

//function definition
void HT::search(const string& key)
{
	//iterator declaration
	list<Entry>::iterator it;

	//set variable to key
	int i = hash(key);

	//check size
	i %= hsize;

	//list declaration and set to item
	list <Entry>& l = hTable[i];

	//set iterator to position of key
	it = find_if(l.begin(), l.end(), [key](Entry e) {return key == e.key; });

	//if the iterator does not equal the end of the list
	if (it != l.cend())
	{
		//output the number and description of the position of the iterator
		cout << " Number: " << it->key << " Desc: " << it->desc << endl;
	}
	else
	{
		//do nothing
		cout << "The item was not found." << endl;
	}
}

//function definition
void HT::hTable_print()
{
	//variable declaration
	Entry item;

	//go through size of hash table
	for (unsigned int i = 0; i < hsize; i++)
	{
		//list declaration and set to item
		list <Entry>& l = hTable[i];

		//iterator declaration
		list<Entry>::iterator it;

		//go through start of list to end
		for (it = l.begin(); it != l.end(); it++)
		{
			//output the key, description, and number of the position of the iterator
			cout << i << ": " << it->key << " Desc: " << it->desc << " Num: " << it->num << endl;
		}
	}
}

//function definition
void HT::pTable_print()
{
	//sort the pointer table alphabetically
	sort(pTable.begin(), pTable.end(), [](Entry* p, Entry* q) {if (p->key < q->key) return true;  else return false; });

	//iterator declaration
	vector<Entry*>::iterator it;

	//go through start of pointer table to end
	for (it = pTable.begin(); it != pTable.end(); it++)
	{
		//output pointers and dereference
		cout << (*it)->key << " Num: " << (*it)->num << " Desc: " << (*it)->desc << endl;
	}
}

#endif