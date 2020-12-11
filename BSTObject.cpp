// BSTObject.cpp
// @author: Robert Guy
// BSTObject.cpp represents a binary search tree. It implements three common
// binary search three functions:
//
//	1. Insertion
//	2. Lookup
//	3. Deletion
//
//	It also includes several miscellaneous methods that can be observed in: BSTObject.h.
//
// BSTObject.cpp attempts to perform these operations in time -> O(logN) on the average case.
// However, this time complexity only holds for a balanced tree. Unbalanced trees, in the 
// worse case, can yield a time complexity of O(|Nodes|) = O(N).

#include "BSTObject.h"
#include "BSTNode.h"

#include <iostream>
#include <algorithm>
using namespace std;

// A parameterized constructor that accepts a root node.
BSTObject::BSTObject(const int& key)
{

	_root = new BSTNode(key);

}

// A parameterized constructor that accepts a root node that forms a basis for the BST.
BSTObject::BSTObject(BSTNode*& root)
{

	_root = root;

}

// An explicit destructor that will deallocate all resources from this BSTObject.
BSTObject::~BSTObject()
{

	//Clear(_root);

}

// Insert(root, x) inserts a node with a key of x. The node is
// inserted by traversing to a leaf node.
BSTNode* BSTObject::Insert(BSTNode* root, const int& x) noexcept
{

	// Is it a leaf node? Or is the tree empty?
	if (root == nullptr)
	{

		root = new BSTNode(x);

	}
	else if(x < root->key) // Is the value we wish to insert is less than the current node?
	{

		// Go left.
		root->left = Insert(root->left, x);

	}
	else // The value is current than the node we wish to insert.
	{

		// Go right.
		root->right = Insert(root->right, x);

	}

	return root;

}

// Delete(root, x) deletes BSTNode, N. It returns true if the 
// deletion is successful. And otherwise, false.
void BSTObject::Delete(BSTNode* root, const int& x) noexcept
{

	BSTNode*& N = Find(root, x);

	if (N != nullptr)
	{

		if (N->left == nullptr && N->right == nullptr)
		{

			delete N;
			N = nullptr;

		}
		else if (N->left != nullptr && N->right != nullptr)
		{

			BSTNode* inorder_successor = GetInorderSuccessor(root, N);

			if (inorder_successor != nullptr)
			{

				BSTNode* temp = N;
				inorder_successor = temp;
				delete N;
				N = nullptr;

			}
		}
		else
		{

			if (N->left != nullptr)
			{

				N->left = N;
				delete N;
				N = nullptr;

			}
			else
			{

				N->right = N;
				delete N;
				N = nullptr;

			}
		}
	}
}

// Clear(root) deallocates all resources from BSTNode, root. This method will
// end promptly if the specified BSTNode, root, is not the same as the one
// maintained by this class; (i.e.: It is compared to the memory address).
//
// Furthermore, to share the results to the developer: A boolean value is returned.
// It will return true if the clear is successful. And otherwise, false.
bool BSTObject::Clear(BSTNode*& root)
{

	// TODO

}

// Find(x) performs a lookup for a node with the key value, x.
// If no such node is found, a null BSTNode is returned. Otherwise,
// the located BSTNode object is returned.
BSTNode*& BSTObject::Find(BSTNode*& root, const int& x) noexcept
{

	// Key, x, is not in this tree. So, return null to indicate that.
	if (root == nullptr || x == root->key)
	{

		return root;

	}
	else if (x < root->key) // Key, x, is less than the value found in the current node. So, lets traverse left.
	{

		// Go left.
		return Find(root->left, x);

	}
	else // Key, x, is greater than the value found in the current node if this branch is executed. So, lets traverse right.
	{

		// Go right.
		return Find(root->right, x);

	}
}

// Contains(root, x) returns true if x is found in this tree. Otherwise,
// it will return false.
bool BSTObject::Contains(const BSTNode* root, const int& x) noexcept
{

	// This tree does not contain key value, x. Return false.
	if (root == nullptr)
	{

		return false;

	}
	else if (x == root->key) // This node has a key value that is equal to x. Return true.
	{

		return true;

	}
	else if (x < root->key) // If x is less than the key value of this node. We should traverse left.
	{

		// Go left.
		return Contains(root->left, x);

	}
	else // X is greater than the key value of this node. Traverse right.
	{

		// Go right.
		return Contains(root->right, x);

	}
}

// GetMinValue(root) will return the smallest value in the tree
// that starts at BSTNode, root.
BSTNode* BSTObject::GetMinValue(BSTNode* root) noexcept
{

	BSTNode* parent = root;

	while (root != nullptr)
	{
		
		// Store a temporary pointer to the parent before we change what it points to.
		parent = root;

		// We should continually traverse left, because the ordering property
		// of BSTs tells us that the left child is always the smallest.
		root = root->left; 
		
	}

	// The parent pointer will be the last observable, non-null BSTNode object. 
	// It contains the minimum value.
	return parent;

}

// GetMaxValue(root) will return the largest value in the tree
// that starts at BSTNode, root.
BSTNode* BSTObject::GetMaxValue(BSTNode* root) noexcept
{

	BSTNode* parent = root;

	while (root != nullptr)
	{

		// Store a temporary pointer to the parent before we change what it points to.
		parent = root;

		// We should continually traverse right, because the ordering property
		// of BSTs tells us that the right child is always the largest.
		root = root->right;

	}

	// The parent pointer will be the last observable, non-null BSTNode object. 
	// It contains the maximum value.
	return parent;

}

// GetInorderSuccessor(root) will return the inorder successor
// of the provided node, N.
BSTNode* BSTObject::GetInorderSuccessor(BSTNode* root, BSTNode* N)
{

	// There is a right subtree. That means the inorder successor
	// is the minimum value found in this subtree.
	if (N->right != nullptr)
	{

		return GetMinValue(N->right);

	}
	else // The right subtree is null. We need to find the parent of the first left child above node, N.
	{

		BSTNode* successor = root;

		while (root != nullptr)
		{

			if(N->key < root->key)
			{
				
				successor = root;
				root = root->left;

			}
			else if (N->key > root->key)
			{

				root = root->right;

			}
			else
			{

				break;

			}
		}

		return successor;

	}
}

// Height(N) returns the height of BSTNode, N. By definition, the height
// is the maximum number of edges between a given node, X, and a leaf node.
unsigned int BSTObject::Height(BSTNode* root, BSTNode* N) noexcept
{

	if (N == nullptr || (N->left == nullptr && N->right == nullptr))
	{

		return 0;

	}
	else
	{

		return 1 + max(Height(root, N->left), Height(root, N->right));

	}
}

// Preorder(root) performs a preorder traversal of BSTNode, root.
void BSTObject::Preorder(BSTNode* root, ostream& out) noexcept
{

	if (root != nullptr)
	{

		out << root->key << " ";
		Preorder(root->left, out);
		Preorder(root->right, out);

	}
}

// Inorder(root) performs a inorder traversal of BSTNode, root.
void BSTObject::Inorder(BSTNode* root, ostream& out) noexcept
{

	if (root != nullptr)
	{

		Inorder(root->left, out);
		out << root->key << " ";
		Inorder(root->right, out);

	}
}

// Postorder(root) performs a postorder traversal BSTNode, root.
void BSTObject::Postorder(BSTNode* root, ostream& out) noexcept
{

	if (root != nullptr)
	{

		Postorder(root->left, out);
		Postorder(root->right, out);
		out << root->key << " ";

	}
}

// GetRoot() returns a pointer to the memory address of the root node.
BSTNode*& BSTObject::GetRoot() noexcept
{

	return _root;

}

// IsLeafNode(N) returns true if BSTNode, N, is a leaf node. And otherwise, false.
bool BSTObject::IsLeafNode(const BSTNode* N) noexcept
{

	if (N == nullptr || (N->left == nullptr && N->right == nullptr))
	{

		return true;

	}
	
	return false;

}