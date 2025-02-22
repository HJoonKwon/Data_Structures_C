#include <stdio.h>
#include "stackL.h"
#include "testPair.h"

int main(void){
    char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
    printf("%s", express);

    if (testPair(express)==1){
        printf("\n\n The parenthesis test has been passed!");
    }
    else{
        printf("\n\n There's something wrong with the parenthesis!");
    }
    getchar(); return 0;
}