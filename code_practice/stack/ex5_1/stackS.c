#include <stdio.h>
#include "stackS.h"

int top = -1;

int isStackEmpty(void){
    if (top == -1) return 1;
    else return 0;
}

int isStackFull(void){
    if (top == STACK_SIZE - 1) return 1;
    else return 0;
}

void push(element item){
    if (isStackFull()){
        printf("\n\n Stack is Full! \n");
    } 
    else {
        top++;
        stack[top] = item;
    }
}

element pop(void){
    if (isStackEmpty()){
        printf("\n\n Stack is Empty! \n");
        return 0;
    }
    else {
        element item = stack[top];
        top--;
        return item;
    }
}

element peek(void){
    if (isStackEmpty()){
        printf("\n\n Stack is Empty! Nothing to peek! \n");
        return 0;
    }
    else return stack[top];
}

void printStack(void){
    int i;
    printf("\n Stack [ ");
    for (i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf(" ]");
}

int main(void){
    element item;
    printf("\n** Sequential Stack **\n");
    printStack();
    push(1); printStack();
    push(2); printStack();
    push(3); printStack();
    item = peek(); printStack(); printf("peek => %d", item);
    item = pop(); printStack(); printf("\t pop => %d", item);
    item = pop(); printStack(); printf("\t pop => %d", item);
    item = pop(); printStack(); printf("\t pop => %d", item);

    getchar(); return 0;
}
