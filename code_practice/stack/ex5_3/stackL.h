#pragma once 

typedef char element; 
typedef struct StackNode{
    element data;
    struct StackNode* link;
} StackNode;

extern StackNode* top;

int isStackEmpty(void);
int isStackFull(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);