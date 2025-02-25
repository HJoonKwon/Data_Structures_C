#include <stdio.h>
#include "stackL.h"
#include "evalPostfix.h"

int main(void){
    char* express = "35*62/-"; // postfix 
    printf("postfix: %s", express);

    int result;
    result = evalPostfix(express);
    printf("\n\n Result: %d \n", result);

    getchar(); return 0;
}