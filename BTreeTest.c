#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"


/* Used the demo code that was provided as a template */

int main(){
  BTreeNode *root = BTreeAlloc();
  char *fName = "adam";
  char *lName = "smith";
  char *fName2 = "jane";
  char *lName2 = "doe";

  root = insertNode(root, fName, lName);
  root = insertNode(root, fName2, lName2);

  printTree(root);

}
