#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <sys/stat.h>
extern int errno;
int main(int argc, char* argv[]){
  int keyboardFlag = 0;
  if(argc > 2){
     printf("%s\n", argv[1]);
     printf("Error: too many arguments\n");
     exit(EXIT_FAILURE);
  }
  FILE *fp;
  char newBase[100];
  if(argc == 2){
     strncpy(newBase, argv[1], sizeof(newBase));
     char *base = argv[1];
     char *baseTag = ".sp19";
     strncat(base, baseTag, 5);
     fp = fopen(base, "r");
     if(fp == NULL){
	fprintf(stderr, "Error: %s\n", strerror( errno ));
        exit(EXIT_FAILURE);
     }
     struct stat stat_record;
     if(stat(argv[1], &stat_record)){
        fprintf(stderr, "Error:File does not exist!\n");
	exit(EXIT_FAILURE);
	}
     else if(stat_record.st_size <= 1){
        fprintf(stderr, "Error: File is Empty!\n");
	exit(EXIT_FAILURE);
     }
     
  }
  else if(argc == 1){
     fp = stdin;
     keyboardFlag = 1;
  } 
 
 char fo[100];
 if(keyboardFlag == 1){
   strncpy(fo, "out", 3);
 }
 else{
   strncpy(fo, newBase, sizeof(fo));
 }
 struct node *root = buildTree(fp);
 
 char buf[100];
 snprintf(buf, sizeof(buf), "%s.inorder", fo);
 FILE *openName = fopen(buf, "a+");
 printInorder(root,0, openName);
 fclose(openName);

 snprintf(buf, sizeof(buf), "%s.preorder", fo);
 openName = fopen(buf, "a+");
 printPreorder(root,0, openName);
 fclose(openName);

 snprintf(buf, sizeof(buf), "%s.postorder", fo);
 openName = fopen(buf, "a+");
 printPostorder(root,0, openName);
 fclose(openName);
 return 0;
} 
