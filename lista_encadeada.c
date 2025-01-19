#include "lista_encadeada.h"

int push_back(linked_list ** head, char value)
{ 
    if(head == NULL) return -1;
    if(value == 0) return -1;
    linked_list ** list_head = head;
    linked_list * new_node = (linked_list*) calloc(1, sizeof(linked_list));
    if ((new_node == NULL)) exit(1);
    new_node->obj = value;
    if (*list_head == NULL)
    {
        *list_head = new_node;
        (*list_head)->index = 0;
        (*list_head)->global_size = 1;
        (*list_head)->last_node = (*list_head);
        return 0;
    } 
    else
    {
        linked_list * temp = (*head);
        while (temp->next_node != NULL) temp = temp->next_node;
        temp->next_node = new_node;
        temp->next_node->back_node = temp;
        temp->next_node->index = temp->next_node->back_node->index + 1;
        (*head)->last_node = temp->next_node;
        (*head)->global_size++;
        return 0;
    }
}

char pop_back(linked_list ** head)
{
    if (head == NULL || (*head) == NULL) return 0;
    char ret = 0;
    linked_list * node = (*head);
    if((*head)->global_size <= 1) {
        ret = (*head)->obj;
        free(node); 
        (*head) = NULL; 
        return ret;
        }
    while (node->next_node != NULL) node = node->next_node;
    (*head)->global_size--;
    ret = node->obj;
    node->back_node->next_node = NULL;
    free(node);
    return ret;
}

void remove_at(linked_list ** head, int indx)
{
    if(indx < 0) return;
    if ((*head)->global_size - 1 < indx)
    {
        perror("LIST SIZE < INDEX");
        return;  
    } 
    linked_list * node = (*head);
    for (int i = 0; i < indx; i++)
    {
        node = node->next_node;
    }
    while (node->next_node != NULL) 
    {
        node->obj = node->next_node->obj;
        node = node->next_node;
    }
    (*head)->global_size--;
    node->back_node->next_node = NULL;
    free(node);
}

char _at(linked_list ** head, int indx)
{
    if (head == NULL || (*head) == NULL) return 0;
    if ((*head)->global_size - 1 < indx)
    {
        perror("LIST SIZE < INDEX");
        return 0;  
    }
    linked_list * node = (*head);
    for (int i = 0; i < indx; i++)
    {
        node = node->next_node;
    }
    return node->obj;
}

int linked_list_size(linked_list ** head)
{
    linked_list * node = (*head);
    int count = 0;
    while (node = node->next_node) count++;
    return count + 1;
}

int __lsize(linked_list ** head)
{
    if((*head) == NULL) return -1;
    if (head != NULL && (*head) != NULL) return (*head)->global_size;
    else return -1;
}

char topl(linked_list ** head)
{
    if(head == NULL || (*head) == NULL) return 0;
    return _at(head, __lsize(head) - 1);
}

int simple_search(linked_list ** head, int value)
{
    if (head == NULL || (*head) == NULL) return -1;
    linked_list * temp = (*head);
    while (temp != NULL)
    {
        if (temp->obj < value) temp = temp->next_node;
        else if (temp->obj == value) return temp->index;
        else return -1;
    }
}

int binary_search(linked_list ** head, int value, int _start, int _end)
{
    if (head == NULL || (*head) == NULL) return -1;
    linked_list * temp = (*head);
    int meio = floor((_start + _end) / 2);
    if (_start == _end && value != temp->obj) return -1;
    if (value <= _at(&temp, meio))
    {
        while (temp->obj < value) 
        {
            temp = temp->next_node;
        }
        if(temp->obj == value) return temp->index;
        else return -1;
    }
    else if (value > _at(&temp, meio)) return binary_search(&temp, value, meio + 1, _end);
    else return -1;
}