##  Binary Seach Tree
This is a C++ implementation of a binary search tree that is intended to refine my
knowledge of the data structure. **BinarySearchTree.cpp** is a test class that
was used during development to manually debug and test the included functionality.

## Documentation  
A binary search tree is described by **BSTNode** object(s) each with three properties:  

  1. ```key``` => An integer value that represents the current node.  
  2. ```left``` => A non-contiguous ***BSTNode** that represents the left child of a parent node ```x```.  
  3. ```right``` => A non-contigious **BSTNode** that represents the right child of a parent node ```x```.  
  
 **BSTNode** object(s) are wrapped in a **BSTObject** to provide the appropriate functionality. A **BSTObject**
 supports the following operations:
 
  1. Insertion
  2. Deletion of a particular key
  3. Key lookup
  4. Key validation (is it contained in this particular BST?)
  5. Inorder Successor Retrieval (in accordance with deletion (2))
  6. Locate minimum key 
  7. Locate maximum key
  8. Leaf node validation
  9. Finding the height of the tree
  10. Recursive traversal methodologies (preorder, inorder and postorder)

Below, I will detail instantiation and wrapping in addition to the primary function implementations; operations (1) - (4).  

**Instantiation**  

```c++
#include "BSTNode.cpp";
using namespace std;

cout << "Initializing tree." << endl;
BSTNode* root = new BSTNode(25);
root->left = new BSTNode(2);
root->right = new BSTNode(39);
root->right->right = new BSTNode(75);
```

Here, we include the **BSTNode.cpp** file, the corresponding 'std' namespace and we allocate the properties of tree to the heap.
Next, we need to wrap our root **BSTNode** in a **BSTObject** so that functionality is available.

**Wrapping**  

```c++
BSTObject* obj = new BSTObject(root);
```
Following this, the describe functionality is callable from our **BSTObject** instance.

**Insertion**  

We can achieve insertion by calling the **BSTObject.Insert(root, x)** method. It accepts a root object and a value x that we wish to insert.

```c++
obj->Insert(root, 99);
```

**Deletion**  
Similarly, we deletion a key by calling the **BSTObject.Delete(root, x)** method. It also accepts a root object and a value x that we wish to insert.

```c++
obj->Delete(root, 39);
```

**Key Lookup**  
We can perform a search or lookup operation by calling the **BSTObject.Find(root, x)** method.

```c++
BSTNode* temp1 = obj->Find(root, 5); // returns null
BSTNode* temp2 = obj->Find(root, 39); // returns corresponding BSTNode object
```

**Key Validation**  
Lastly, we validate the existence of a particular key value by invoking the **BSTObject.Contains(root, x)** method.

```c++
bool a = obj->Find(root, 62); // returns false
bool b = obj->Find(root, 75); // returns true
```
