#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"

BTreeNode *BTreeAlloc(){
  BTreeNode *tree = (BTreeNode *)malloc(sizeof(BTreeNode));
  tree->lChild=NULL;
  tree->rChild=NULL;
  return tree;
}

BTreeNode *insert(BTreeNode *tree, char *fN, char *lN){
  BTreeNode *newNode = BTreeAlloc();
  if(tree == NULL){
    newNode->fName = fN;
    newNode->lName = lN;
    return newNode;
  }else if(strcmp()<0||strcmp()==0){
    tree->lChild = insert(newNode, fN, lN);
  }else if(strcmp()<0){
    tree->rChild = insert(newNode, fN, lN);
  }
  return tree;
}

BTreeNode *delete(){

}

void print(BTreeNode *tree, char *fN, char lN){
  printf("%c\n",tree->fName);
}
