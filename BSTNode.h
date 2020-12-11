#ifndef BSTNode_H
#define BSTNode_H

class BSTNode
{

public:

	// The key value of this node.
	int key;

	// The left child of this node; defaults to null.
	BSTNode* left;

	// The right child of this node; defaults to null.
	BSTNode* right;

	// A parameterized constructor that accepts a key value.
	BSTNode(const int& key);

	// BSTNode destructor to free up the used resources.
	~BSTNode();

	// Defined operator overload for the '!='. It will return true
	// if the memory address of this BSTNode is not equal to BSTNode,
	// node. And otherwise, false.
	bool operator!=(const BSTNode* node);

	// A defined operator overload for '<' operator. It returns true
	// if the key of this BSTNode is less than the key of the opposing
	// BSTNode. And otherwise, false.
	bool operator<(const BSTNode* node);

	// A defined operator overload for '>' operator. It returns true
	// if the key of this BSTNode is greater than the key of the opposing
	// BSTNode. And otherwise, false.
	bool operator>(const BSTNode* node);

};

#endif


