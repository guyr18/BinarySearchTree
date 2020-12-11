#include "BSTNode.h"
#include <iostream>
using namespace std;

#ifndef BSTObject_H
#define BSTObject_H

class BSTObject
{

	// A pointer to the root node of this BSTObject.
	BSTNode* _root;

public:

	// A parameterized constructor that accepts a key value.
	explicit BSTObject(const int& key);

	// A parameterized constructor that accepts a root node that forms a basis for the BST.
	explicit BSTObject(BSTNode*& root);

	// An explicit destructor that will deallocate all resources from this BSTObject.
	~BSTObject();

	// Insert(root, x) inserts a node with a key of x. The node is
	// inserted by traversing to a leaf node.
	BSTNode* Insert(BSTNode* root, const int& x) noexcept;

	// Delete(root, x) deletes BSTNode, N. It returns true if the 
	// deletion is successful. And otherwise, false.
	void Delete(BSTNode* root, const int& x) noexcept;

	// Clear(root) deallocates all resources from BSTNode, root. This method will
	// end promptly if the specified BSTNode, root, is not the same as the one
	// maintained by this class; (i.e.: It is compared to the memory address).
	//
	// Furthermore, to share the results to the developer: A boolean value is returned.
	// It will return true if the clear is successful. And otherwise, false.
	bool Clear(BSTNode*& root);

	// Find(root, x) performs a lookup for a node with the key value, x.
	// If no such node is found, a null BSTNode is returned. Otherwise,
	// the located BSTNode object is returned.
	BSTNode*& Find(BSTNode*& root, const int& x) noexcept;

	// Contains(root, x) returns true if x is found in this tree. Otherwise,
	// it will return false.
	bool Contains(const BSTNode* root, const int& x) noexcept;

	// GetMinValue(root) will return the smallest value in the tree
	// that starts at BSTNode, root.
	BSTNode* GetMinValue(BSTNode* root) noexcept;

	// GetMaxValue(root) will return the largest value in the tree
	// that starts at BSTNode, root.
	BSTNode* GetMaxValue(BSTNode* root) noexcept;

	// GetInorderSuccessor(root) will return the inorder successor
	// of the provided node, N.
	BSTNode* GetInorderSuccessor(BSTNode* root, BSTNode* N);

	// Height(N) returns the height of BSTNode, N. By definition, the height
	// is the maximum number of edges between a given node, X, and a leaf node.
	unsigned int Height(BSTNode* root, BSTNode* N) noexcept;

	// Preorder(root) performs a preorder traversal of BSTNode, root.
	void Preorder(BSTNode* root, ostream& out) noexcept;

	// Inorder(root) performs a inorder traversal of BSTNode, root.
	void Inorder(BSTNode* root, ostream& out) noexcept;

	// Postorder(root) performs a postorder traversal BSTNode, root.
	void Postorder(BSTNode* root, ostream& out) noexcept;

	// GetRoot() returns a pointer to the memory address of the root node.
	BSTNode*& GetRoot() noexcept;

	// IsLeafNode(N) returns true if BSTNode, N, is a leaf node. And otherwise, false.
	bool IsLeafNode(const BSTNode* N) noexcept;

};

#endif

