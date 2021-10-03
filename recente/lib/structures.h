#ifndef H_STRUCTURES
#define H_STRUCTURES
#define MAX_CHILDREN 4

typedef struct Symbol{
    char name[100];   //strcpy
    char type[10];   //strcpy
    //char *name;         //strdup
    //char *type;         //strdup
    int decl_type;      // 0 = function, 1 = variable
    int line;
    int column;
    int scope;
    struct Symbol *prox;
}Symbol;

typedef struct Table{
    Symbol *first;
    Symbol *last;
}Table;

void insertSymbol(Table *t, char *name, char *type, int decl_type, int line, int column, int scope, int *errors);
void freeSymbols(Table *t);
void printTable(Table *t);
int isOnTable(Table *t, char *name, int scope);
int hasMainFunction(Table *t);
int checkDuplicatedSymbol(Table *t, char *name, int scope);

typedef struct Ast{
    char *node_name;
    char *token_name;
    char *token_type;
    int printable;
    int token_line;
    int token_column;
    //int has_token;
    struct Ast *children[MAX_CHILDREN];
    struct Ast *prox;
}Ast;

typedef struct AstList{
    Ast *first;
    Ast *last;
}AstList;

AstList *createAstList();
Ast *createAstNode(char *name, int printable);

void insertAstNode(AstList *t, Ast *n);
void freeNode(Ast *n);
void printAstList(AstList *t);
void printAST(Ast *root);
void printNode(Ast *n, int index);

typedef struct Scope{
    int value;
    struct Scope *prox;
}Scope;

typedef struct Context{
    Scope *first;
    Scope *last;
}Context;

void insertScope(int value, Context *c);
int removeScope(Context *c);
int isContextEmpty(Context *c);
void startContext(Context *c);
void freeContextList(Context *c);

char *getType(Table *t, Context *c, char *name, int scope);
char *getContext(Table *t, Context *c, char *name, int line, int column, int *error);

#endif