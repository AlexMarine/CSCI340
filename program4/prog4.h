/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				October 10, 2019
//	Program Name:			prog4.h
//
//	Purpose of Program:
//		This program takes an input from the user, and "cleans" each string
//		entered from any punctuations marks, as well as makes every letter
//		lower case. Then it outputs each unique string and the frequency
//		of its occurence. Finally, the program will output the number of
//		words found in the input stream and then output the number of
//		distinct words found in the output stream.
////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef PROG4_H
#define PROG4_H

#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>

#define NO_ITEMS 3
#define ITEM_W 16

using namespace std;

//function prototypes
void get_words(map <string, int> &);
void print_words(const map <string, int> &);
void clean_entry(const string &, string &);

#endif