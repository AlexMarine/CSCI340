/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				September 19, 2019
//	Program Name:			prog2.h
//
//	Purpose of Program:
//		This program will implement two search algorithms (a linear search
//		and a binary search) on randomly generated integers stored in
//		vectors.
////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef prog2_H
#define prog2_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

#define ARR_SIZE 200
#define TEST_ARR_SIZE 100
#define LOW 1
#define HIGH 1000
#define NO_ITEMS 16
#define ITEM_W 4
#define SEED1 1
#define SEED2 3

using namespace std;

//function prototypes
void Vectors(vector <int> &v1, vector <int> &v2, int s1, int s2);
bool linearSearch(const vector <int> &v, int x);
bool binarySearch(const vector <int> &v, int x);
int search(const vector <int> &v1, const vector <int> &v2, bool(*p) (const vector <int> &, int));
void sortVector(vector <int> &v);
void printVector(const vector <int> &v);
void printStat(int totalSucCnt, int vectorSz);

#endif