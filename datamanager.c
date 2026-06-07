#include <stdio.h>
#include <stdlib.h>
#include "datamanager.h"

Node* createNode(Device d)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = d;
    newNode->next = NULL;

    return newNode;
}

void insertDevice(Node** head, Device d)
{
    Node* newNode = createNode(d);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void displayLinkedList(Node* head)
{
    while (head)
    {
        printf("%s | %d Watt | %d Jam/Hari | Priority %d\n",
       head->data.name,
       head->data.power,
       head->data.hoursPerDay,
       head->data.priority);

        head = head->next;
    }
}

int countDevices(Node* head)
{
    int count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

void linkedListToArray(Node* head, Device arr[])
{
    int i = 0;

    while (head)
    {
        arr[i++] = head->data;
        head = head->next;
    }
}
