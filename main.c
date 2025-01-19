#include "infix_to_rpn.h"

int main(int argc, char const *argv[])
{
    _stack * stack = NULL;
    infix_to_rpn(&stack);
    linked_list * rpn = NULL;
    
    while(stack)
    {
        push_back(&rpn, top(stack));
        pop(&stack);
    }

    while (rpn)
    {
        printf("%c", pop_back(&rpn));
    }

    printf("\n\n");

    return 0;
}