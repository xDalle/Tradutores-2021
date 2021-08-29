#include <stdio.h>
#include <stdlib.h>
#include <symbol_table.h>

Table *createTable(){
    Table *t = (Table*)malloc(sizeof(Table));
    t->first = NULL;
    t->last = NULL;
    return t;
}