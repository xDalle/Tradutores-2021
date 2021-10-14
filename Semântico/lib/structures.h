#ifndef H_STRUCTURES
#define H_STRUCTURES
#define MAX_CHILDREN 4

/* Symbol Table */
typedef struct Symbol{
    char *name;         //strdup
    char *type;         //strdup
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
void setupParameters(Table *t);
int isOnTable(Table *t, char *name, int scope);
int hasMainFunction(Table *t);
int checkDuplicatedSymbol(Table *t, char *name, int scope);
int isFunction(Table *t, char *id);

/* AST tree */
typedef struct Ast{
    char *node_name;
    char *node_type;
    char *node_cast;
    char *token_name;
    char *token_print;
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

Ast *createAstNode(char *name, int printable);

void insertAstNode(AstList *t, Ast *n);
void freeNode(Ast *n);
void printAstList(AstList *t);
void printAST(Ast *root);
void printNode(Ast *n, int index);
void updateSignal(Ast *n);

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

/* Parameter Type List (Function Call) */
typedef struct Parameter{
    char *parameter_type;
    struct Parameter *prox;
}Parameter;

typedef struct ParameterTypeList{
    Parameter *first;
    Parameter *last;
}ParameterTypeList;

void insertParameterType(char *parameter_type, ParameterTypeList *p);
void popParameterTypeList(ParameterTypeList *p);
void freeParameterTypeList(ParameterTypeList *p);

/* General (basically type check and function call) */
char *getType(Table *t, Context *c, char *name, int scope);
char *getContext(Table *t, Context *c, char *name, int line, int column, int *error);
int getFunctionParameters(Table *t, Context *c, char *name, int scope);
void typeCheckFunctionCall(char *type, ParameterTypeList *p, char *name, int line, int column, int actual_param, int *error);
void checkFunctionCall(Table *t, Context *c, ParameterTypeList *p, char *name, int line, int column, int params_counter, int *error);

#endif