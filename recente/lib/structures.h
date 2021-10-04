#ifndef H_STRUCTURES
#define H_STRUCTURES
#define MAX_CHILDREN 4

/* Symbol Table */
typedef struct Symbol{
    char *name;         //strdup
    char *type;         //strdup
    struct ParameterList *param_list;
    int param_qtd;
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

/* AST tree */
typedef struct Ast{
    char *node_name;
    char *node_type;
    char *node_transform;
    char *token_name;
    char *token_type;
    int printable;
    int token_line;
    int token_column;
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

/* Scope (context) list */
typedef struct Scope{
    int value;
    struct Scope *prox;
}Scope;

typedef struct Context{
    Scope *first;
    Scope *last;
}Context;

void insertScope(int value, Context *c);
void removeScope(Context *c);
void setupContext(Context *c);
void freeContextList(Context *c);

/* Parameter list */
typedef struct Parameter{
    char param_type[15];    //int, int list, float, float list
    struct Parameter *prox;
}Parameter;

typedef struct ParameterList{
    Parameter *first;
    Parameter *last;
}ParameterList;

ParameterList *createParameterList();
void insertParam(char *param_type, ParameterList *p);
void freeParamList(ParameterList *p);
void setupParameters(Table *t);
void printParamList(ParameterList *p);
void printParams(Table *t);

/* General */
char *getType(Table *t, Context *c, char *name, int scope);
char *getContext(Table *t, Context *c, char *name, int line, int column, int *error);
//void checkType(Ast *n, int line, int column, int *error);
//void verifyExpressionType(Ast *n);

#endif