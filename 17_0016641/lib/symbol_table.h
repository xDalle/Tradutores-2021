#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

typedef struct Symbol{
    char *name;
    char *type;
    int line;
    int column;
    int scope;
    struct Symbol *prox;
}Symbol;

typedef struct Table{
    Symbol *first;
    Symbol *last;
}Table;

Table *createTable();
void insertSymbol();
void freeSymbol();

#endif