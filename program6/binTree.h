/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				October 31, 2019
//	Program Name:			binTree.h
//
//	Purpose of Program:
//		This program implements a class for binary trees that deals with asdbs
//		variety of data types. The class has functions to find the height of
//		the binary tree, insert nodes into the tree, and can perform inorder
//		traversal of the tree.
////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef H_BINTREE
#define H_BINTREE

#include <string>
#include "Node.h"

typedef enum { left_side, right_side } SIDE;	//define two enum types
SIDE rnd() { return rand() % 2 ? right_side : left_side; }	//used to decide random placement of nodes, either left or giht side

//template class
template <class T>
//class definition
class binTree 
{
public:
	binTree(); //default constructor
	unsigned height() const; //returns height of tree
	virtual void insert(const T&); //inserts node in tree
	void inorder(void(*p) (const T&)); //inorder traversal of tree
protected:
	Node <T>* root; //root of tree
private:
	unsigned height(Node < T >*) const; //private version of height ( )
	void insert(Node <T>*&, const T&); //private version of insert ( )
	void inorder(Node <T>*, void(*p) (const T&)); //private version of inorder ( )
};

//template class
template <class T>
//function definition
binTree <T>::binTree()
{
	//set root to nullptr
	root = nullptr;
}

//template class
template <class T>
//function definition
unsigned binTree <T>::height() const
{
	//return height of tree
	return height(root);
}

//template class
template <class T>
//function definition
void binTree <T>::insert(const T& t)
{
	//insert node in tree
	insert(root, t);
}

//template class
template <class T>
//function definition
void binTree <T>::inorder(void(*p) (const T&))
{
	//inorder traversal of tree
	inorder(root, p);
}

//template class
template <class T>
//function definition
unsigned binTree <T>::height(Node <T>* x) const
{
	//if height is empty
	if (!x)
	{
		//return 0
		return 0;
	}
	//if height is not empty
	else
	{
		//max of height of left and height of right, plus one for root
		return 1+ max(height(x->left), height(x->right));
	}
}

//template class
template <class T>
//function defintion
void binTree <T>::insert(Node <T>*& x, const T& t)
{
	//if node is empty
	if (!x)
	{
		//variable declaration
		Node <T>* temp;	//temp variable

		//set temp to t
		temp = new Node <T>(t);

		//set x to temp
		x = temp;
	}
	//if node is not empty
	else
	{
		//if rnd is equal to the left side
		if (rnd() == left_side)
		{
			//insert on the left
			insert(x->left, t);
		}
		//if rnd is not equal to the left
		else
		{
			//insert on the right
			insert(x->right, t);
		}
	}
}

//template class
template <class T>
//function definition
void binTree <T>::inorder(Node <T>* x, void(*p) (const T&))
{
	//if node is not empty
	if (x)
	{
		//inorder of left
		inorder((x->left), p);

		//print data
		p(x->data);

		//inordder of right
		inorder((x->right), p);
	}
}

#endif