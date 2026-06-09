#ifndef OPTIMASI_H
#define OPTIMASI_H
assholeee
#include "energy.h"

typedef struct QueueNode {
    Device data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, Device d);
void processQueue(Queue* q);

void optimizeEnergy(Device arr[],
                    int n,
                    int maxPower);

#endif
