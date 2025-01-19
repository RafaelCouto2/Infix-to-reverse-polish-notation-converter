#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct _stack
{
    char obj;
    int size;
    struct _stack * next_node;   
    struct _stack * prev_node; 

} _stack;

int is_empty(_stack * stack);
int push(_stack ** stack, char val);
char pop(_stack ** stack);
char top(_stack * stack);
int __size(_stack * stack);