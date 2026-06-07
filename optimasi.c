#include <stdio.h>
#include <stdlib.h>
#include "optimasi.h"

void initQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, Device d)
{
    QueueNode* temp =
    (QueueNode*)malloc(sizeof(QueueNode));

    temp->data = d;
    temp->next = NULL;

    if(q->rear == NULL)
    {
        q->front = temp;
        q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void processQueue(Queue* q)
{
    printf("\n=== SIMULASI PENGGUNAAN PERANGKAT ===\n");

    while(q->front)
    {
        QueueNode* temp = q->front;

        printf("%s digunakan\n",
               temp->data.name);

        q->front = q->front->next;

        free(temp);
    }

    q->rear = NULL;
}

void optimizeEnergy(Device arr[],
                    int n,
                    int maxPower)
{
    int total = 0;

    printf("\n=== REKOMENDASI PERANGKAT ===\n");

    for(int i=0;i<n;i++)
    {
        if(total + arr[i].power <= maxPower)
        {
            printf("%s (%d Watt)\n",
                   arr[i].name,
                   arr[i].power);

            total += arr[i].power;
        }
    }

    printf("\nTotal Daya Digunakan : %d Watt\n",
           total);

    printf("Batas Daya Rumah     : %d Watt\n",
           maxPower);
}