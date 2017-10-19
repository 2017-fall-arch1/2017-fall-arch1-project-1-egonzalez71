#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"


/* Used the demo code that was provided as a template */

int main(){
  BTreeNode *root = NULL;
  char *name = (char *)malloc(50);
  char continueResponse = 'y';


  /* */
  while(continueResponse == 'y'){
    printf("Insert(i), Delete(d), or Read(r)\n");

    char userResponse = getchar();
    while((getchar())!='\n');
    
    if(userResponse == 'i'){
      printf("Enter name:\n");
      name = fgets(name, 50, stdin);
      root = insertNode(root, name);
    }
    if(userResponse == 'd'){
      printf("entered delete\n");
    }
    if(userResponse == 'r'){
      printTree(root);
    }
    
    printf("Do you want to continue?(y/n)\n");
    continueResponse = getchar();

    while((getchar())!='\n');
  }
}
