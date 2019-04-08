#include <stdio.h>
#ifndef TREE_H
#define TREE_H

struct node;
struct node* buildTree(FILE *fp);
void printInorder(struct node *nodeP, int level, FILE *openName);
void printPreorder(struct node *nodeP, int level, FILE *openName);
void printPostorder(struct node *nodeP, int level, FILE *openName);
#endif
