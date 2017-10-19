#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "BTree.h"

/* Used Dr. Freudenthal's code as a template */

/* Creates a new node for the binary search tree */
BTreeNode *BTreeAlloc(){
  BTreeNode *tree = (BTreeNode *)malloc(sizeof(BTreeNode));
  tree->lChild=NULL;
  tree->rChild=NULL;
  return tree;
}

/* Adds a new node to the tree, checking whether the tree is empty
 * or if the new data is smaller or larger */
BTreeNode *insertNode(BTreeNode *tree, char *n){
  if(tree==NULL){
    BTreeNode *newNode = BTreeAlloc();
    newNode->name = n;
    return newNode;
  }
  int c = strcmp(tree->name,n);
  printf("%d\n",c);
  if(c<0 || c==0){
    tree->lChild = insertNode(tree->lChild, n);
  }else if(c > 0){
    tree->rChild = insertNode(tree->rChild, n);
  }
  return tree;
}

BTreeNode *deleteNode(BTreeNode *tree, char *n){


}

BTreeNode *searchNode(BTreeNode *tree, char *n){

}

/* Prints out all the employee names from the binary search tree  */
void printTree(BTreeNode *tree){
  if(tree==NULL){
    return;
  }
  printTree(tree->lChild);
  printf("%s\n",tree->name);
  printTree(tree->rChild);
}
