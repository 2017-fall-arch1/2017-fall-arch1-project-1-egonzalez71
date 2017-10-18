#ifndef BTree_included
#define BTree_included

typedef struct BTreeNode{
  struct BTreeNode *lChild;
  struct BTreeNode *rChild;
  char *fName;
  char *lName;
}BTreeNode;

/*typedef struct{
  BTreeNode *root;
}BTree;*/

BTreeNode *BTreeAlloc();

BTreeNode *insert(BTreeNode *tree, char *fN, char *lN);
BTreeNode *delete();
void print(BTreeNode *tree, char *fN, char *lN);

#endif
