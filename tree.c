#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for a node in BST
struct node{
   int strSize;
   struct node *left;
   struct node *right;
   char holder[100];
};

//function to make new node in BST
struct node* newNode(int strSize, char *data){
   struct node* node = (struct node*)malloc(sizeof(struct node));
   node->strSize = strSize;
   node->left = NULL;
   node->right = NULL;
   return node;
}

//function to insert new node
struct node* insert(struct node* node, int strSize, char *data){
   if(node == NULL){
      return newNode(strSize, data);
   }
   if(strSize < node->strSize){
      node->left = insert(node->left, strSize, data);
   }
   else if(strSize > node->strSize){
      node->right = insert(node->right, strSize, data);
   }
   return node;
}
struct node* insertData(struct node* node, int strSize, char *data){
   if(strSize == node->strSize){
      strncat(node->holder, data, sizeof(node->holder));
      strncat(node->holder, " ", 1);
   }
   else if(strSize < node->strSize){
      node->left = insertData(node->left, strSize, data);
   }
   else if(strSize > node->strSize){
      node->right = insertData(node->right, strSize, data);
   }
   return node;
}

struct node* buildTree(FILE *fp){
  char data[100];
  int stringSize;
  struct node* root = NULL;
  fscanf(fp, "%s", data);
  stringSize = strlen(data);
  root = insert(root, stringSize, data);
  insertData(root, stringSize, data);
  while(fscanf(fp, "%s", data)!= EOF){
     stringSize = strlen(data);
     insert(root, stringSize, data);
     insertData(root, stringSize, data);
  }
  return root;
}

void printInorder(struct node *nodeP, int level, FILE *openName){
   if(nodeP != NULL){
      printInorder(nodeP->left, level+1, openName);
      fprintf(openName,"%*c%d %-9s ",level*2,'\0',nodeP->strSize, nodeP->holder);
      fprintf(openName,"\n");
      printInorder(nodeP->right, level+1, openName);
   }
}

void printPreorder(struct node *nodeP, int level,FILE *openName){
   if(nodeP != NULL){
      fprintf(openName,"%*c%d %-9s ", level*2, '\0',nodeP->strSize, nodeP->holder);
      fprintf(openName,"\n");
      printPreorder(nodeP->left, level+1, openName);
      printPreorder(nodeP->right, level+1, openName);
   }
}

void printPostorder(struct node *nodeP, int level, FILE *openName){
   if(nodeP != NULL){
      printPostorder(nodeP->left, level+1, openName);
      printPostorder(nodeP->right, level+1, openName);
      fprintf(openName,"%*c%d %-9s ", level*2, '\0',nodeP->strSize, nodeP->holder);
      fprintf(openName,"\n");
   }
}
