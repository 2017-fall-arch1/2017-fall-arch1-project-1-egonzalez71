#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"


/* Used the demo code that was provided as a template */

int main(){
  BTreeNode *root = BTreeAlloc();
  char *fName = "a";
  char *lName = "b";

  root = insert(root, fName, lName);
  print(root, fName, lName );

}
