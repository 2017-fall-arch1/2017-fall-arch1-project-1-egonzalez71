#ifndef BTree_included
#define BTree_included

/* Used code Dr. Freudenthal made for the demo as a template */

typedef struct BTreeNode{
  struct BTreeNode *lChild;
  struct BTreeNode *rChild;
  char *name;
}BTreeNode;

/* Creates a new node for the list  */
BTreeNode *BTreeAlloc();

/* Inserts a new employee in the binary search tree */
BTreeNode *insertNode(BTreeNode *tree, char *n);

/* Deletes an employee from the binary search tree */
BTreeNode *deleteNode(BTreeNode *tree, char *n);

BTreeNode *searcNode(BTreeNode *tree, char *n);

/* Prints all the employee names from the tree */
void printTree(BTreeNode *tree);

#endif
