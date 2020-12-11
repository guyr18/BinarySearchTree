// BSTNode.cpp
// @author: Robert Guy
// 
// BSTNode.cpp represents a node in a binary search tree. Every BSTNode
// holds three fundamental properties:
//
//	1. key -> The key value contained within this node. For simplicity,
//			  the primitive type, integer, is the only accepted data type.
//			  This could easily be extended by implementing a Comparable type
//			  object that implements boolean conditional operators.
//
//	2. left -> The left child of this BSTNode; also a BSTNode.
//
//	3. right -> The right child of this BSTNode; also a BSTNode.

#include "BSTNode.h"
#include <iostream>
using namespace std;

// A parameterized constructor that accepts a key value.
BSTNode::BSTNode(const int& key)
{

	this->key = key;
	this->left = nullptr;
	this->right = nullptr;

}

// BSTNode destructor to free up the used resources.
BSTNode::~BSTNode()
{

	cout << "BSTNode destruct." << endl;

}

// Defined operator overload for the '!='. It will return true
// if the memory address of this BSTNode is not equal to BSTNode,
// node. And otherwise, false.
bool BSTNode::operator!=(const BSTNode* node)
{

	return this != node;

}

// A defined operator overload for '<' operator. It returns true
// if the key of this BSTNode is less than the key of the opposing
// BSTNode. And otherwise, false.
bool BSTNode::operator<(const BSTNode* node)
{

	return this->key < node->key;

}

// A defined operator overload for '>' operator. It returns true
// if the key of this BSTNode is greater than the key of the opposing
// BSTNode. And otherwise, false.
bool BSTNode::operator>(const BSTNode* node)
{

	return this->key > node->key;

}