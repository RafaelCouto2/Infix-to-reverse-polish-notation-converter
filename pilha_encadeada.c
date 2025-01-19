#include "pilha_encadeada.h"

int is_empty(_stack * stack)
{
    return stack == NULL;
}

int push(_stack ** stack, char val)
{
    //if((*stack) == NULL) return -1;
    if(val == 0) return -1;
    _stack * new_node = NULL;
    if(!(new_node = (_stack*) calloc(1, sizeof(_stack)))) return -1;
    if(is_empty((*stack)))
    {
        (*stack) = new_node;
        (*stack)->obj = val;
        (*stack)->size = 1;
        return 0;
    }
    else
    {
        (*stack)->next_node = new_node;
        (*stack)->next_node->prev_node = (*stack);
        (*stack)->next_node->obj = val;
        (*stack) = (*stack)->next_node;
        (*stack)->size = (*stack)->prev_node->size + 1;
        return 0;
    }
}

char pop(_stack ** stack)
{
    
    if(is_empty((*stack))) return 0;
    char ret = 0;
    if(!(*stack)->prev_node) {
        ret = (*stack)->obj;
        free((*stack));
        (*stack) = NULL;
        return ret;
    }
    (*stack) = (*stack)->prev_node;
    ret = (*stack)->next_node->obj;
    free((*stack)->next_node);
    (*stack)->next_node = NULL;
    return ret;
}

char top(_stack * stack)
{
    return (!stack)? 0 : stack->obj;
}

int __size(_stack * stack)
{
    return (!stack)? -1 : stack->size;
}