
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"


/* Used the demo code that was provided as a template */

int main(){
  BTreeNode *root = NULL;
  char *name = (char *)malloc(50);
  char continueResponse = 'y';

  /* FILE *employee;
  employee = fopen("employees.txt", "r+");

  while(name = fgets(name, 50, employee)){
    char *nameCopy = (char *)malloc(50);
    strcpy(nameCopy,name);
    root = insertNode(root, nameCopy);
    while((getchar())!='\n');
  }*/

  /* Gets user response on what they want to do and then goes
   * to the proper methods to complete them. */
  while(continueResponse == 'y'){
    printf("Insert(i), Delete(d), or Read(r)\n");

    char userResponse = getchar();
    while((getchar())!='\n');

    /* Gets name from user to insert in binary search tree */
    if(userResponse == 'i'){
      printf("Enter name:\n");
      name = fgets(name, 50, stdin);
      char *nameCopy = (char *)malloc(50);
      strcpy(nameCopy,name);
      root = insertNode(root, nameCopy);
    }
    /* Gets name from user to delete from binary search tree */
    if(userResponse == 'd'){
      printf("Enter name:\n");
      name = fgets(name, 50, stdin);
      char *nameCopy = (char *)malloc(50);
      strcpy(nameCopy, name);
      root = deleteNode(root, nameCopy);
    }
    /* Calls printTree to print all employee names */
    if(userResponse == 'r'){
      printTree(root);
    }
    
    printf("Do you want to continue?(y/n)\n");
    continueResponse = getchar();

    while((getchar())!='\n');
  }
}
