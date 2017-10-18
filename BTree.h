#ifndef BTree_included
#define BTree_included

/* Used code Dr. Freudenthal made for the demo as a template */

typedef struct BTreeNode{
  struct BTreeNode *lChild;
  struct BTreeNode *rChild;
  char *fName;
  char *lName;
}BTreeNode;

BTreeNode *BTreeAlloc();

BTreeNode *insertNode(BTreeNode *tree, char *fN, char *lN);

BTreeNode *deleteNode(BTreeNode *tree, char *fN, char *lN);

BTreeNode *searcNode(BTreeNode *tree, char *fN, char *lN);

void printTree(BTreeNode *tree);

#endif
