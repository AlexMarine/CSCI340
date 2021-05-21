/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				November 8, 2019
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
	unsigned size() const; // returns size of tree
	unsigned height() const; //returns height of tree
	virtual void insert(const T&); //inserts node in tree
	void inorder(void(*p) (const T&)); //inorder traversal of tree
protected:
	Node <T>* root; //root of tree
private:
	unsigned size(Node < T >*) const; // private version of size ( )
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

template <class T>
unsigned binTree <T>::size() const
{
	return size(root);
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
void binTree <T>::insert(const T& x)
{
	//insert node in tree
	insert(root, x);
}

//template class
template <class T>
//function definition
void binTree <T>::inorder(void(*p) (const T&))
{
	//inorder traversal of tree
	inorder(root, p);
}

template <class T>
unsigned binTree <T>::size(Node < T >* node) const
{
	//if size is empty
	if (!node)
	{
		//return 0
		return 0;
	}
	//if size is not empty
	else
	{
		//max of height of left and height of right, plus one for root
		return 1 + max(size(node->left), size(node->right));
	}
}

//template class
template <class T>
//function definition
unsigned binTree <T>::height(Node <T>* node) const
{
	//if height is empty
	if (!node)
	{
		//return 0
		return 0;
	}
	//if height is not empty
	else
	{
		//max of height of left and height of right, plus one for root
		return 1 + max(height(node->left), height(node->right));
	}
}

//template class
template <class T>
//function defintion
void binTree <T>::insert(Node <T>*& node, const T& x)
{
	//if node is empty
	if (!node)
	{
		//variable declaration
		Node <T>* temp;	//temp variable

		//set temp to t
		temp = new Node <T>(x);

		//set x to temp
		node = temp;
	}
	//if node is not empty
	else
	{
		//if rnd is equal to the left side
		if (rnd() == left_side)
		{
			//insert on the left
			insert(node->left, x);
		}
		//if rnd is not equal to the left
		else
		{
			//insert on the right
			insert(node->right, x);
		}
	}
}

//template class
template <class T>
//function definition
void binTree <T>::inorder(Node <T>* node, void(*p) (const T&))
{
	//if node is not empty
	if (node)
	{
		//inorder of left
		inorder((node->left), p);

		//print data
		p(node->data);

		//inordder of right
		inorder((node->right), p);
	}
}

#endif