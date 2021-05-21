/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				September 30, 2019
//	Program Name:			prog3.h
//
//	Purpose of Program:
//		This program creates a set of prime numbers using the Sieve of
//		Eratosthenes algorithm. The user inputs the number at which they
//		want the set to be capped and then the prime numbers are outputted.
////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef PROG3_H
#define PROG3_H

#include <iostream>
#include <set>
#include <iomanip>

#define NO_ITEMS 16
#define ITEM_W 4

using namespace std;

//function prototypes
void sieve(set <int> &s, int n);
void print_primes(const set <int> &s);

#endif