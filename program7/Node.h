#pragma once

#ifndef H_NODE
#define H_NODE

// definition of node in bin tree

template <typename T> class binTree;  // forward declaration
template <typename T> class binSTree; // forward declaration

template <typename T> class Node 
{
	friend class binTree <T>;             // binTree is friend
	friend class binSTree <T>;            // binSTree is friend
public:
	Node(const T& = T(), Node <T>* = nullptr,
		Node <T>* = nullptr);       // default constructor
private:
	T data;                            // data component
	Node <T> *left, *right;          // left and right links
};

// default constructor
template <typename T>
Node <T> ::Node(const T& x, Node <T>* l, Node <T>* r) :
	data(x), left(l), right(r) { }

#endif
