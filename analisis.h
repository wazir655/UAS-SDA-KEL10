#ifndef ANALISIS_H
#define ANALISIS_H

#include "energy.h"

void mergeSort(Device arr[],
               int left,
               int right);

typedef struct BSTNode {
    Device data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* insertBST(BSTNode* root,
                   Device d);

BSTNode* searchBST(BSTNode* root,
                   int power);

void inorder(BSTNode* root);

#endif
