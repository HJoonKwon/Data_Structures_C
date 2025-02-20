#include <stdio.h>
#include <stdlib.h>
#include "queueS.h"

QueueType* createQueue(void){
    QueueType* Q; // structure pointer
    Q = (QueueType*)malloc(sizeof(QueueType));
    Q->rear = -1;
    Q->front = -1;
    return Q;
}

int isQueueEmpty(QueueType* Q){
    if (Q->front == Q->rear){
        printf(" Queue is empty! \n\t ");
        return 1;
    }
    else return 0;
}

int isQueueFull(QueueType* Q){
    if (Q->rear == Q_SIZE - 1){
        printf(" Queue is full! \n\t ");
        return 1;
    }
    else return 0;
}

void enQueue(QueueType* Q, element item){
    if (isQueueFull(Q)) return;
    else{
        Q->rear++;
        Q->queue[Q->rear] = item;
    }
}

element deQueue(QueueType* Q){
    if (isQueueEmpty(Q)) exit(1);
    else{
        Q->front++;
        return Q->queue[Q->front];
    }
}

element peekQ(QueueType* Q){
    if (isQueueEmpty(Q)) exit(1);
    else{
        return Q->queue[Q->front+1];
    }
}

void printQ(QueueType* Q){
    int i; 
    printf(" Queue : [");
    for (i=Q->front+1; i <= Q->rear; i++){
        printf("%3c", Q->queue[i]);
    }
    printf(" ]");
}

int main(void){
    QueueType* Q1 = createQueue();
    element data;
    printf("\n **** Sequential Queue **** \n");
    printf("\n Insert A>>"); enQueue(Q1, 'A'); printQ(Q1);
    printf("\n Insert B>>"); enQueue(Q1, 'B'); printQ(Q1);
    printf("\n Insert C>>"); enQueue(Q1, 'C'); printQ(Q1);
    data = peekQ(Q1); printf(" peek item: %c \n", data);
    printf("\n Delete >>"); data = deQueue(Q1); printQ(Q1);
    printf("\t deleted item: %c", data);
    printf("\n Delete >>"); data = deQueue(Q1); printQ(Q1);
    printf("\t deleted item: %c", data);
    printf("\n Delete >>"); data = deQueue(Q1); printQ(Q1);
    printf("\t deleted item: %c", data);

    printf("\n Insert D>>"); enQueue(Q1, 'D'); printQ(Q1);
    printf("\n Insert E>>"); enQueue(Q1, 'E'); printQ(Q1);
    getchar(); return 0;
}