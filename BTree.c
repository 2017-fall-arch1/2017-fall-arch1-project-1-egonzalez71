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
  int c = strcasecmp(tree->name,n);
  if(c > 0 || c == 0){
    tree->lChild = insertNode(tree->lChild, n);
  }else if(c < 0){
    tree->rChild = insertNode(tree->rChild, n);
  }
  return tree;
}

/* Deletes an employee from the binary search tree */
BTreeNode *deleteNode(BTreeNode *tree, char *n){
  int c = strcasecmp(tree->name, n);
  if(tree == NULL){
    return tree;
  }else if(c < 0){
    tree->lChild = deleteNode(tree->lChild, n);
  }else if(c > 0){
    tree->rChild = deleteNode(tree->rChild, n);
  }else if(c == 0){
    BTreeNode *treeCopy = BTreeAlloc();
    /* Deletes node if it has no child */
    if(tree->lChild == NULL && tree->rChild == NULL){
      free(tree);
      return tree;
    }
    /* Deletes node and replaces with leftmost child */
    else if(tree->rChild == NULL){
      treeCopy = searchMinNode(tree->lChild);
      free(tree);
      return treeCopy;
    }
    /* Deletes node and replaces with rightmost child */
    else if(tree->lChild == NULL){
      treeCopy = searchMaxNode(tree->rChild);
      free(tree);
      return treeCopy;
    }
    else if(tree->lChild && tree->rChild){
      treeCopy = searchMinNode(tree->lChild);
      treeCopy->rChild = searchMaxNode(tree->rChild);
      free(tree);
      return treeCopy;
    }
  }
}

/* Finds the node with the highest value */
BTreeNode *searchMaxNode(BTreeNode *tree){
  if(tree == NULL){
    return tree;
  }else if(tree->rChild == NULL){
    return tree;
  }
  return searchMaxNode(tree->rChild);
}

/* Finds the node with the lowest value */
BTreeNode *searchMinNode(BTreeNode *tree){
  if(tree == NULL){
    return tree;
  }else if(tree->lChild == NULL){
    return tree;
  }
  return searchMinNode(tree->lChild);
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
