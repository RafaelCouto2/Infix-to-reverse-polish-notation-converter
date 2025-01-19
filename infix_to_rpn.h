#pragma once

#include <string.h>
#include <ctype.h>
#include "pilha_encadeada.h"
#include "lista_encadeada.h"

struct priority {
    char opr[5];
    int pri[5];
};

int _priority(char _c);
int has_priority(char c, char _c);
int same_priority(char c, char _c);
int infix_to_rpn(_stack ** stck);