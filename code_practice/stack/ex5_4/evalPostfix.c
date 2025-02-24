#include <string.h>
#include "stackL.h"
#include "evalPostfix.h"

element evalPostfix(char* exp){
    char symbol;
    int opr1, opr2, value, i = 0; 
    top = NULL; 
    int length = strlen(exp);

    for (i = 0; i < length; i++){
        symbol = exp[i];

        if (
            (symbol != '+' && symbol != '-' && symbol != '/' && symbol != '*')
        ){
            value = symbol - '0';
            push(value);
        }
        else{
            opr2 = pop();
            opr1 = pop();
            switch (symbol){
                case '+': push(opr1 + opr2); break;
                case '-': push(opr1 - opr2); break;
                case '/': push(opr1 / opr2); break;
                case '*': push(opr1 * opr2); break;
            }
        }
    }
    return pop();
}

