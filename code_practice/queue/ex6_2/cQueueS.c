#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

QueueType* createCQueue(void){
    QueueType* cQ; // structure pointer
    cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ->rear = 0;
    cQ->front = 0;
    return cQ;
}

int isCQueueEmpty(QueueType* cQ){
    if (cQ->front == cQ->rear){
        printf(" Queue is empty! \n\t ");
        return 1;
    }
    else return 0;
}

int isCQueueFull(QueueType* cQ){
    if ((cQ->rear + 1) % Q_SIZE == cQ->front){
        printf(" Queue is full! \n\t ");
        return 1;
    }
    else return 0;
}

void enCQueue(QueueType* cQ, element item){
    if (isCQueueFull(cQ)) return;
    else{
        cQ->rear = (cQ->rear + 1) % Q_SIZE;
        cQ->cQueue[cQ->rear] = item;
    }
}

element deCQueue(QueueType* cQ){
    if (isCQueueEmpty(cQ)) exit(1);
    else{
        cQ->front = (cQ->front + 1) % Q_SIZE;
        return cQ->cQueue[cQ->front];
    }
}

element peekCQ(QueueType* cQ){
    if (isCQueueEmpty(cQ)) exit(1);
    else{
        return cQ->cQueue[(cQ->front+1) % Q_SIZE];
    }
}

void printCQ(QueueType* cQ){
    int i; 
    printf(" cQueue : [");
    for (i= cQ->front+1; i % Q_SIZE != (cQ->rear+1) % Q_SIZE; i++){
        printf("%3c", cQ->cQueue[i % Q_SIZE]);
    }
    printf(" ]");
}

int main(void){
    QueueType* cQ1 = createCQueue();
    element data;
    printf("\n **** Sequential cQueue **** \n");
    printf("\n Insert A>>"); enCQueue(cQ1, 'A'); printCQ(cQ1);
    printf("\n Insert B>>"); enCQueue(cQ1, 'B'); printCQ(cQ1);
    printf("\n Insert C>>"); enCQueue(cQ1, 'C'); printCQ(cQ1);
    data = peekCQ(cQ1); printf(" peek item: %c \n", data);
    printf("\n Delete >>"); data = deCQueue(cQ1); printCQ(cQ1);
    printf("\t deleted item: %c", data);
    printf("\n Delete >>"); data = deCQueue(cQ1); printCQ(cQ1);
    printf("\t deleted item: %c", data);
    printf("\n Delete >>"); data = deCQueue(cQ1); printCQ(cQ1);
    printf("\t deleted item: %c", data);

    printf("\n Insert D>>"); enCQueue(cQ1, 'D'); printCQ(cQ1);
    printf("\n Insert E>>"); enCQueue(cQ1, 'E'); printCQ(cQ1);
    getchar(); return 0;
}