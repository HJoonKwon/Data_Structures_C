#pragma once
typedef char element;

typedef struct QNode{ // for forward declaration
    element data;
    struct QNode* link;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} LQueueType;

LQueueType* createLinkedQueue(void);
int isLinkedQueueEmpty(LQueueType* LQ);
void enLinkedQueue(LQueueType* LQ, element item);
element deLinkedQueue(LQueueType* LQ);
element peekLQ(LQueueType* LQ);
void printLQ(LQueueType* LQ);
