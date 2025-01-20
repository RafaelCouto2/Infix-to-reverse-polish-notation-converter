#include "infix_to_rpn.h"

int main(int argc, char const *argv[])
{
    _stack * stack = NULL;
    infix_to_rpn(&stack);
    _stack * rpn = NULL;
    
    while(stack)
    {
        push(&rpn, top(stack));
        pop(&stack);
    }

    while (rpn)
    {
        printf("%c", pop(&rpn));
    }

    printf("\n\n");

    return 0;
}