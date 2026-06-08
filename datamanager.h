#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "energy.h"

typedef struct Node {
    Device data;
    struct Node* next;
} Node;

Node* createNode(Device d);
void insertDevice(Node** head, Device d);
void displayLinkedList(Node* head);
int countDevices(Node* head);
void linkedListToArray(Node* head, Device arr[]);

#endif
