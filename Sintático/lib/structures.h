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

void insertSymbol(Table *t, char *name, char *type, int decl_type, int line, int column, int scope);
void freeSymbols(Table *t);
void printTable(Table *t);
int isOnTable(Table *t, char *name);
static Table symbolTable;

typedef struct Ast{
    char *node_name;
    char *token_name;
    int printable;
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
void freeAst(AstList *t);
void printAstList(AstList *t);
void printAST(Ast *root);
void printNode(Ast *n, int index);

static Ast root;
static AstList astList;

#endif