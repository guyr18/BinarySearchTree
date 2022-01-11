##  Binary Seach Tree
This is a C++ implementation of a binary search tree that is intended to refine my
knowledge of the data structure. **BinarySearchTree.cpp** is a test class that
was used during development to manually debug and test the included functionality.

## Documentation
A binary search tree is described by **BSTNode** object(s) each with three properties:  

  1. ```key``` => An integer value that represents the current node.  
  2. ```left``` => A non-contiguous ***BSTNode** that represents the left child of a parent node ```x```.  
  3 ```right``` => A non-contigious **BSTNode** that represents the right child of a parent node ```x```.  
  
 *BSTNode* object(s) are wrapped in a **BSTObject** to provide the appropriate functionality. A **BSTObject**
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
  
 
