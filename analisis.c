#include <stdio.h>
#include <stdlib.h>
#include "analisis.h"

void merge(Device arr[],
           int left,
           int mid,
           int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Device* L = (Device*)malloc(n1 * sizeof(Device));
    Device* R = (Device*)malloc(n2 * sizeof(Device));

    for(int i=0;i<n1;i++)
        L[i] = arr[left+i];

    for(int j=0;j<n2;j++)
        R[j] = arr[mid+1+j];

    int i=0;
    int j=0;
    int k=left;

    while(i<n1 && j<n2)
    {
        if(L[i].priority >= R[j].priority)
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while(i<n1)
        arr[k++] = L[i++];

    while(j<n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Device arr[],
               int left,
               int right)
{
    if(left < right)
    {
        int mid = left + (right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

BSTNode* insertBST(BSTNode* root,
                   Device d)
{
    if(root == NULL)
    {
        BSTNode* node =
        (BSTNode*)malloc(sizeof(BSTNode));

        node->data = d;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    if(d.power < root->data.power)
        root->left = insertBST(root->left,d);
    else
        root->right = insertBST(root->right,d);

    return root;
}

BSTNode* searchBST(BSTNode* root,
                   int power)
{
    if(root == NULL ||
       root->data.power == power)
        return root;

    if(power < root->data.power)
        return searchBST(root->left,power);

    return searchBST(root->right,power);
}

void inorder(BSTNode* root)
{
    if(root)
    {
        inorder(root->left);

        printf("%s (%d Watt)\n",
               root->data.name,
               root->data.power);

        inorder(root->right);
    }
}
