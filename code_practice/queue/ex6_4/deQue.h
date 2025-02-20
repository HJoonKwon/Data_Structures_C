#pragma once
typedef char element;

typedef struct DQNode{ // for forward declaration
    element data;
    struct DQNode* rlink;
    struct DQNode* llink;
} DQNode;

typedef struct {
    DQNode* front;
    DQNode* rear;
} DQueType;

DQueType* createDQue(void);
int isDQueEmpty(DQueType* DQ);
void insertFront(DQueType* DQ, element item);
void insertRear(DQueType* DQ, element item);
element deleteFront(DQueType* DQ);
element deleteRear(DQueType* DQ);
element peakFront(DQueType* DQ);
element peakRear(DQueType* DQ);
void printDQ(DQueType* DQ);
