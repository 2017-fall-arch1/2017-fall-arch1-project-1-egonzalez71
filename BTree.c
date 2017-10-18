#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "BTree.h"

/* Used Dr. Freudenthal's code as a template */

BTreeNode *BTreeAlloc(){
  BTreeNode *tree = (BTreeNode *)malloc(2*sizeof(BTreeNode));
  tree->lChild=NULL;
  tree->rChild=NULL;
  return tree;
}

BTreeNode *insertNode(BTreeNode *tree, char *fN, char *lN){
  BTreeNode *newNode;
  if(tree->fName == NULL){
    newNode = BTreeAlloc();
    newNode->fName = fN;
    newNode->lName = lN;
    return newNode;
  }else if(strcmp(tree->fName,fN)<0||strcmp(tree->fName,fN)==0){
    newNode = BTreeAlloc();
    tree->lChild = insertNode(newNode, fN, lN);
  }else if(strcmp(tree->fName,fN)>0){
    newNode = BTreeAlloc();
    tree->rChild = insertNode(newNode, fN, lN);
  }
  return tree;
}

BTreeNode *deleteNode(BTreeNode *tree, char *fN, char *lN){

}

BTreeNode *searchNode(BTreeNode *tree, char *fN, char *lN){
  if((tree->fName == fN) && (tree->lName == lN)){

  }else if(!tree->lChild==NULL){
    searchNode(tree->lChild);
  }else if(!tree->rChild==NULL){
    searchNode(tree->rChild);
  }

  printf("Employee not in tree");
}

void printTree(BTreeNode *tree){
  if(!tree->lChild==NULL){
    printTree(tree->lChild);
  }else if(!tree->rChild==NULL){
    printTree(tree->rChild);
  }
  printf("%s\t%s\n",tree->fName, tree->lName);
}
