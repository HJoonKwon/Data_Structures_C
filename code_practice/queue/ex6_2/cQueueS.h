#pragma once
#define Q_SIZE 4
typedef char element;

typedef struct{
    element cQueue[Q_SIZE];
    int front, rear;
} QueueType;

QueueType* createCQueue(void);
int isCQueueEmpty(QueueType* cQ);
int isCQueueFull(QueueType* cQ);
void enCQueue(QueueType* cQ, element item);
element deCQueue(QueueType* cQ);
element peekCQ(QueueType* cQ);
void printCQ(QueueType* cQ);
