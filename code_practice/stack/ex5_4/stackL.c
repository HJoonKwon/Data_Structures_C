#include <stdio.h>
#include <stdlib.h>
#include "stackL.h"

StackNode* top = NULL;

int isStackEmpty(void){
    if (top == NULL) return 1;
    else return 0;
}

void push(element item){
    StackNode* newNode; 
    newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = item;
    newNode->link = NULL;

    if (isStackEmpty())top = newNode;
    else{
        newNode->link = top;
        top = newNode;
    }
}

element pop(void){
    if (isStackEmpty()){
        printf("\n\n Stack is Empty! \n");
        return 0;
    }
    else {
        StackNode* oldNode = top;
        element item = oldNode->data;
        top = oldNode->link;
        free(oldNode);
        return item;
    }
}

element peek(void){
    if (isStackEmpty()){
        printf("\n\n Stack is Empty! Nothing to peek! \n");
        return 0;
    }
    else return top->data;
}

void printStack(void){
    printf("\n Stack [ ");
    StackNode* current = top;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->link;
    }
    printf(" ]");
}
