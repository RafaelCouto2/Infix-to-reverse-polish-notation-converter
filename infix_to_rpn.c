#include "infix_to_rpn.h"

struct priority my_priority = {
    .opr = {'^', '*', '/', '+', '-'},
    .pri = {0, 1, 1, 2, 2}
};

int _priority(char _c)
{
    for (int i = 0; i < 5; i++)
    {
        if (_c == my_priority.opr[i])
        {
            return my_priority.pri[i];
        }
    }
}

int has_priority(char c, char _c)
{
    if(c == 0 || _c == 0) return -1;
    return (_priority(c) < _priority(_c));   
}

int same_priority(char c, char _c)
{ 
    if(c == 0 || _c == 0) return -1;
    return _priority(c) == _priority(_c);
}


int infix_to_rpn(_stack ** stck) 
{
    if(!(stck)) return -1;
    _stack * stack = NULL;
    _stack * stack_aux = NULL;
    char buffer[500];
    printf("Digite a expressão numérica. Ex.: ");
    fflush(stdin);
    gets_s(buffer, 500);
    int paren = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
    {   
        if(isdigit(buffer[i]))
        {
            push(&stack, buffer[i]);
            continue;
        }

        if(isdigit(buffer[i+1]) && (buffer[i] <= 45 && buffer[i] >= 43))
        {
            push(&stack, buffer[i]);
            continue;
        }

        if((buffer[i] == ' ' && top(stack) != ' '))
        {
            push(&stack, ' ');
            continue;
        }

        if(buffer[i] == ' ') continue;
        
        if(buffer[i] != '(' && buffer[i] != ')')
        {
            if(paren)
            {
                push(&stack_aux, buffer[i]);
                paren = 0;
                continue;
            }
            else
            {
            if(top(stack_aux))
            {
                if(top(stack_aux) != '(')
                {   
                    if(has_priority(top(stack_aux), buffer[i]))
                    {
                        push(&stack, top(stack_aux));
                        pop(&stack_aux);
                        push(&stack, ' ');
                    }
                    else if (same_priority(top(stack_aux), buffer[i]))
                    {
                        push(&stack, top(stack_aux));
                        pop(&stack_aux);
                        push(&stack, ' ');
                    }
                }
            }
            }
        }
        
        push(&stack_aux, buffer[i]);

        if(buffer[i] == ')')
        {
            push(&stack, ' ');
            while(pop(&stack_aux) != '(')
            {
                if(top(stack_aux) != '(')
                {
                    push(&stack, top(stack_aux));
                    push(&stack, ' ');
                }
            }
        }

        if(top(stack_aux) == '(') paren = 1;
    }

    while(top(stack_aux))
    {
        if(top(stack) != ' ') push(&stack, ' ');
        push(&stack, top(stack_aux));
        pop(&stack_aux);
    }

    (*stck) = stack;
    return 0;
}