#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct linked_list {
    
    int global_size;
    int index;
    char obj;
    struct linked_list * next_node;
    struct linked_list * back_node;
    struct linked_list * last_node;

} linked_list;

int push_back(linked_list ** head, char value);
char pop_back(linked_list ** head);
void remove_at(linked_list ** head, int indx);
char _at(linked_list ** head, int indx);
int linked_list_size(linked_list ** head);
int simple_search(linked_list ** head, int value);
int binary_search(linked_list ** head, int value, int _start, int _end);
int __sort(linked_list ** head);
int __lsize(linked_list ** head);
char topl(linked_list ** head);