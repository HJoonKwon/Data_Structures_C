#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

LQueueType* createLinkedQueue(void){
    LQueueType* LQ; // structure pointer
    LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->rear = NULL;
    LQ->front = NULL;
    return LQ;
}

int isLinkedQueueEmpty(LQueueType* LQ){
    if (LQ->front == NULL){
        printf(" Queue is empty! \n\t ");
        return 1;
    }
    else return 0;
}

void enLinkedQueue(LQueueType* LQ, element item){
    QNode* newNode;
    newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;

    if (isLinkedQueueEmpty(LQ)){
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else{
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

element deLinkedQueue(LQueueType* LQ){
    if (isLinkedQueueEmpty(LQ)) exit(1);
    else{
        QNode* oldNode = LQ->front;
        element oldItem = oldNode -> data;
        LQ->front = LQ->front->link;

        if (LQ->front == NULL) LQ->rear = NULL;
        free(oldNode);
        return oldItem;
    }
}

element peekLQ(LQueueType* LQ){
    if (isLinkedQueueEmpty(LQ)) exit(1);
    else{
        return LQ->front->data;
    }
}

void printLQ(LQueueType* LQ){
    printf(" LinkedQueue : [");
    QNode* current = LQ->front;
    while (current != NULL){
        printf("%3c", current->data);
        current = current->link;
    }
    printf(" ]");
}

int main(void){
    LQueueType* LQ1 = createLinkedQueue();
    element data;
    printf("\n **** LinkedQueue **** \n");
    printf("\n Insert A>>"); enLinkedQueue(LQ1, 'A'); printLQ(LQ1);
    printf("\n Insert B>>"); enLinkedQueue(LQ1, 'B'); printLQ(LQ1);
    printf("\n Insert C>>"); enLinkedQueue(LQ1, 'C'); printLQ(LQ1);
    data = peekLQ(LQ1); printf(" peek item: %c \n", data);
    printf("\n Delete >>"); data = deLinkedQueue(LQ1); printLQ(LQ1);
    printf("\t deleted item: %c", data);
    printf("\n Delete >>"); data = deLinkedQueue(LQ1); printLQ(LQ1);
    printf("\t deleted item: %c", data);
    printf("\n Delete >>"); data = deLinkedQueue(LQ1); printLQ(LQ1);
    printf("\t deleted item: %c", data);

    printf("\n Insert D>>"); enLinkedQueue(LQ1, 'D'); printLQ(LQ1);
    printf("\n Insert E>>"); enLinkedQueue(LQ1, 'E'); printLQ(LQ1);
    getchar(); return 0;
}