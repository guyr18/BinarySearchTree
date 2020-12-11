// BinarySearchTree.cpp
// @author: Robert Guy
// BinarySearchTree.cpp handles basic test(s) of the functionality
// provided through this library; namely: BSTNode.cpp and BSTObject.cpp.

#include "BSTNode.h"
#include "BSTObject.h"

#include <iostream>
#include <string>
using namespace std;

// BuildString(val) builds a string based on the boolean value, val.
// If val is true, it returns "Yes". And otherwise, will return "No".
string BuildString(bool val)
{

    return val ? "Yes" : "No";

}

// Main() is the execution point of this application.
int main()
{

    cout << "Initializing tree." << endl;
    cout << "Building left subtree.." << endl;
    BSTNode* root = new BSTNode(25);
    root->left = new BSTNode(20);
    root->left->left = new BSTNode(10);
    root->left->right = new BSTNode(22);
    root->left->left->left = new BSTNode(5);
    root->left->left->right = new BSTNode(12);
    root->left->left->right->right = new BSTNode(15);
    root->left->left->left->left = new BSTNode(1);
    root->left->left->left->right = new BSTNode(8);
    cout << "Building right subtree.." << endl;
    root->right = new BSTNode(36);
    root->right->left = new BSTNode(30);
    root->right->right = new BSTNode(40);
    root->right->left->left = new BSTNode(28);
    root->right->right->left = new BSTNode(38);
    root->right->right->right = new BSTNode(48);
    root->right->right->right->left = new BSTNode(45);
    root->right->right->right->right = new BSTNode(50);
    cout << "BST built." << endl;
    BSTObject* obj = new BSTObject(root);
    cout << endl << "Contains(root, x) test sequence: " << endl;
    cout << "Does this tree contain 12? " << BuildString(obj->Contains(obj->GetRoot(), 12)) << endl;
    cout << "Does this tree contain 30? " << BuildString(obj->Contains(obj->GetRoot(), 30)) << endl;
    cout << "Does this tree contain 22? " << BuildString(obj->Contains(obj->GetRoot(), 22)) << endl;
    cout << "Does this tree contain 9000? " << BuildString(obj->Contains(obj->GetRoot(), 9000)) << endl;
    cout << "Does this tree contain 500? " << BuildString(obj->Contains(obj->GetRoot(), 500)) << endl << endl;
    cout << "IsLeafNode(N) check: " << endl;
    cout << "Is the node with key 8 a leaf? " << BuildString(obj->IsLeafNode(obj->Find(obj->GetRoot(), 8))) << endl;
    cout << "Is the node with key 30 a leaf? " << BuildString(obj->IsLeafNode(obj->Find(obj->GetRoot(), 30))) << endl;
    cout << endl << "Height(root, N) check: " << endl;
    unsigned int h1 = obj->Height(obj->GetRoot(), obj->Find(obj->GetRoot(), 25));
    unsigned int h2 = obj->Height(obj->GetRoot(), obj->Find(obj->GetRoot(), 45));
    unsigned int h3 = obj->Height(obj->GetRoot(), obj->Find(obj->GetRoot(), 5));
    cout << "Height of key 25 is = " << h1 << endl;
    cout << "Height of key 45 is = " << h2 << endl;
    cout << "Height of key 5 is = " << h3 << endl;
    cout << endl << "Preorder traversal: " << endl;
    obj->Preorder(obj->GetRoot(), cout);
    cout << endl << "Inorder Traversal: " << endl;
    obj->Inorder(obj->GetRoot(), cout);
    cout << endl << "Postorder traversal: " << endl;
    obj->Postorder(obj->GetRoot(), cout);
    cout << endl << "Delete(root, N) test sequence: " << endl;
    cout << "Deleting a leaf node: 28." << endl;
    obj->Delete(obj->GetRoot(), 28);
    cout << "Leaf node deleted => 28" << endl;
    bool bTest28 = obj->Find(obj->GetRoot(), 28) != nullptr;
    cout << "Does 28 still exist? " << BuildString(bTest28) << endl;
    cout << "Deleting a one child node: 12" << endl;
    obj->Delete(obj->GetRoot(), 12);
    cout << "One child node deleted => 12" << endl;
    bool bTest12 = obj->Find(obj->GetRoot(), 12) != nullptr;
    cout << "Does 12 still exist? " << BuildString(bTest12) << endl;
    cout << "Deleting a two child node: 40" << endl;
    obj->Delete(obj->GetRoot(), 40);
    bool bTest40 = obj->Find(obj->GetRoot(), 40) != nullptr;
    cout << "Does 40 still exist? " << bTest40 << endl;
    cout << "Two child node deleted => 40" << endl;
    cin.get();
    return 0;

}