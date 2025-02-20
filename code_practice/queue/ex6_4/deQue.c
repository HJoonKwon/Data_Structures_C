#include <stdio.h>
#include <stdlib.h>
#include "deQue.h"

DQueType* createDQue(void){
    DQueType* DQ; // structure pointer
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->rear = NULL;
    DQ->front = NULL;
    return DQ;
}

int isDQueEmpty(DQueType* DQ){
    if (DQ->front == NULL){
        printf(" Queue is empty! \n\t ");
        return 1;
    }
    else return 0;
}

void insertFront(DQueType* DQ, element item){
    DQNode* newNode;
    newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->rlink = NULL;
    newNode->llink = NULL;

    if (isDQueEmpty(DQ)){
        DQ->front = newNode;
        DQ->rear = newNode;
    }
    else{
        DQ->front->llink = newNode;
        newNode->rlink = DQ->front;
        DQ->front = newNode;
    }
}

void insertRear(DQueType* DQ, element item){
    DQNode* newNode;
    newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->rlink = NULL;
    newNode->llink = NULL;

    if (isDQueEmpty(DQ)){
        DQ->front = newNode;
        DQ->rear = newNode;
    }
    else{
        DQ->rear->rlink = newNode;
        newNode->llink = DQ->rear;
        DQ->rear = newNode;
    }
}

element deleteFront(DQueType* DQ){
    if (isDQueEmpty(DQ)) exit(1);
    else{
        DQNode* oldNode = DQ->front;
        element oldItem = oldNode -> data;
        DQ->front = DQ->front->rlink;

        if (DQ->front == NULL) DQ->rear = NULL;
        else DQ->front->llink = NULL;
        free(oldNode);
        return oldItem;
    }
}

element deleteRear(DQueType* DQ){
    if (isDQueEmpty(DQ)) exit(1);
    else{
        DQNode* oldNode = DQ->rear;
        element oldItem = oldNode -> data;
        DQ->rear = DQ->rear->llink;

        if (DQ->rear == NULL) DQ->front = NULL;
        else DQ->rear->rlink = NULL;
        free(oldNode);
        return oldItem;
    }
}

element peekFront(DQueType* DQ){
    if (isDQueEmpty(DQ)) exit(1);
    else{
        return DQ->front->data;
    }
}

element peekRear(DQueType* DQ){
    if (isDQueEmpty(DQ)) exit(1);
    else{
        return DQ->rear->data;
    }
}

void printDQ(DQueType* DQ){
    printf(" deQueue : [");
    DQNode* current = DQ->front;
    while (current != NULL){
        printf("%3c", current->data);
        current = current->rlink;
    }
    printf(" ]");
}

int main(void){
    DQueType* Q1 = createDQue();
    element data;
    printf("\n **** Linked deQueue **** \n");
    printf("\n Insert A>>"); insertFront(Q1, 'A'); printDQ(Q1);
    printf("\n Insert B>>"); insertFront(Q1, 'B'); printDQ(Q1);
    printf("\n Insert C>>"); insertRear(Q1, 'C'); printDQ(Q1);
    printf("\n Delete Front>>"); data = deleteFront(Q1); printDQ(Q1);
    printf("\t deleted item: %c", data);
    printf("\n Delete Rear>>"); data = deleteRear(Q1); printDQ(Q1);
    printf("\t deleted item: %c", data);

    printf("\n Insert D>>"); insertRear(Q1, 'D'); printDQ(Q1);
    printf("\n Insert E>>"); insertFront(Q1, 'E'); printDQ(Q1);
    printf("\n Insert F>>"); insertFront(Q1, 'F'); printDQ(Q1);
    data = peekFront(Q1); printf("\n peek Front item: %c \n", data);
    data = peekRear(Q1); printf(" peek Rear item: %c \n", data);
    getchar(); return 0;
}