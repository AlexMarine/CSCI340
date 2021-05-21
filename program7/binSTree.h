/////////////////////////////////////////////////////////////////////////////
//							NIU CSCI-340 FALL 2019
//
//	Section Number			1
//	Author:					Alex Marine
//	zID:					z1863905
//	Due Date:				November 8, 2019
//	Program Name:			binSTree.h
//
//	Purpose of Program
//		This header implements a Binary Search Tree that builds off of the
//		Binary Tree class. The class a functions have functions to insert
//		into the tree, search the tree, remove a node, and find out if a
//		node is a leaf or not.
////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef H_BINSTREE
#define H_BINTSREE

#include "binTree.h" 

template <typename T>
class binSTree : public binTree <T>
{
public:
	void insert(const T& x); // inserts node with value x
	bool search(const T& x) const; // searches leaf with value x
	bool remove(const T& x); // removes leaf with value x
private:
	void insert(Node <T>*&, const T&); // private version of insert
	bool search(Node <T>*, const T&) const; // private version of search
	void remove(Node <T>*&, const T&); // private version of remove
	bool leaf(Node <T>* node) const; // checks if node is leaf
};

//template class
template <typename T>
//public function definition
void binSTree <T>::insert(const T& x)
{
	//insert node in tree
	insert(this->root, x);
}

//template class
template <typename T>
//public function definition
bool binSTree <T>::search(const T& x) const
{
	//return result of search
	return search(this->root, x);
}

//template class
template <typename T>
//public function definition
bool binSTree <T>::remove(const T& x)
{
	//if size is greater than one
	if (this->size() > 1)
	{
		//if search of x is true
		if (search(x))
		{
			//remove x from tree
			remove(this->root, x);
		}

		return true;
	}
	//if size is equal to one
	else if (this->size() == 1)
	{
		//set root to null
		this->root = nullptr;

		return false;
	}
	else
	{
		return false;
	}
}
//template class
template <typename T>
//private function definition
void binSTree <T>::insert(Node <T>*& node, const T& x)
{
	//if node is null
	if (node == nullptr)
	{
		//set node to x
		node = new Node<T>(x);
	}
	//if x is less than data in node
	else if (x < node->data)
	{
		//insert node into left tree
		insert(node->left, x);
	}
	//if x is greater than data in node
	else if (x > node->data)
	{
		//insert node itno right tree
		insert(node->right, x);
	}
	else
	{
		//leave function
		return;
	}
}

//template class
template <typename T>
//private function definition
bool binSTree <T>::search(Node <T>* node, const T& x) const
{
	//if node is null
	if (node == nullptr)
	{
		return false;
	}
	else
	{
		//if x is equal to the data in node
		if (x == node->data)
		{
			//if is it a leaf
			if (leaf(node))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//if x is less than the data in node
		else if (x < node->data)
		{
			//return result of search of left tree
			return search(node->left, x);
		}
		else
		{
			//return result of search of right tree
			return search(node->right, x);
		}
	}
}

//template class
template <typename T>
//private function definition
void binSTree <T>::remove(Node <T>*& node, const T& x)
{
	//if node is null
	if (node == nullptr)
	{
		//leave function
		return;
	}

	//if x is less than date in node
	if (x < node->data)
	{
		//set left node to null
		node->left = nullptr;
	}
	//if x is greater than data in node
	else if (x > node->data)
	{
		//set right node to null
		node->right = nullptr;
	}
	else
	{
		//if left node is null
		if (node->left == nullptr)
		{
			//set temp to node right
			Node<T>* temp = node->right;
			//free the node
			free(node);
			//leave function
			return;
		}
		//if right node is null
		else if (node->right == nullptr)
		{
			//set temp to node left
			Node<T>* temp = node->left;
			//free the node
			free(node);
			//leave function
			return;
		}

		//set temp to node left
		Node<T>* temp = node->left;
		//set data in node to date in temp
		node->data = temp->data;
		//set node right to null
		node->right = nullptr;
	}

	//leave function
	return;
}

//template class
template <typename T>
//private function definition
bool binSTree <T>::leaf(Node <T>* node) const
{
	//if both the left and right trees are null
	if (node->left == nullptr && node->right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif