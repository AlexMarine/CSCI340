#pragma once

#include "Entry.h"
//#include "/home/cs340/progs/19f/p9/Entry.h"

#ifndef H_PROG9
#define H_PROG9

#define BUF_SZ 80	//input buffer size

//routines to read records
void read_rec1(Entry&);
void read_rec2(Entry&);

//routine to print records
void prnt_rec1(const Entry&);

#endif