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
    char *func_name;
    char *tac_table_item;
    char *tac_code_item;
    char *tac_code_item_if;
    char *tac_code_item_then;
    char *tac_code_item_for;
    char *tac_value;
    int tac_symbol;
    int tac_register;
    int printable;
    int token_line;
    int token_column;
    int is_function;
    int function_args;
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
    char *parameter_name;
    char *parameter_type;
    int literal;
    struct Parameter *prox;
}Parameter;

typedef struct ParameterList{
    Parameter *first;
    Parameter *last;
}ParameterList;

void insertParameter(char *parameter_name, char *parameter_type, int literal, ParameterList *p);
void popParameterList(ParameterList *p);
void freeParameterList(ParameterList *p);

/* General (basically type check and function call) */
char *getType(Table *t, Context *c, char *name, int scope);
char *getContext(Table *t, Context *c, char *name, int line, int column, int *error);
int getScope(Table *t, Context *c, char *name);
int getFunctionParameters(Table *t, Context *c, char *name, int scope);
void typeCheckFunctionCall(char *type, ParameterList *p, char *name, int line, int column, int actual_param, int *error);
void checkFunctionCall(Ast *n, Table *t, Context *c, ParameterList *p, char *name, int line, int column, int params_counter, int *error);
int checklvalueAssignment(Table *t, Context *c, char *name, int line, int column, int *error);
int checkFunctionID(Table *t, char *name, int scope);
int getFunctionArgs(Table *t, char *name, int scope);
void checkConstructorList(Ast *n);

/* TAC */
void printTACerror(int lexical_errors, int syntax_errors, int semantic_errors); // won't generate TAC if errors in analysis
void generateTAC(Ast *n, char *file_name, int has_string);
void generateTACtable(FILE *fp, Ast *n);
void generateTACstring(FILE *fp);
void generateTACcode(FILE *fp, Ast *n);

#endif