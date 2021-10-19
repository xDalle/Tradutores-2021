#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/structures.h"

#define WHITE "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define PURPLE "\x1b[35m"
#define BLUE "\x1b[36m"

#define MAX_CHILDREN 4

Ast root;
AstList astList;
Table symbolTable;
Context contextList;
ParameterTypeList parameterTypeList;

/* Symbol Table */

int isOnTable(Table *t, char *name, int scope){
    Symbol *actual = t->first;
    while(actual != NULL){
        if(strcmp(actual->name, name) == 0 && actual->scope == scope){
            return 1;
        }
        actual = actual->prox;
    }
    return 0;
}

void insertSymbol(Table *t, char *name, char *type, int decl_type, int line, int column, int scope, int *error){
    int i;
    if(isOnTable(t, name, scope)){
        printf("%sLine:%d\tColumn:%d\tSemantic error! Redeclaration of %s%s%s in the same scope.%s\n", RED, line, column, PURPLE, name, RED, WHITE);
        *error+= 1;
        //return;   -> Comment to show the replicated variable in the symbol table.
    }

    Symbol *new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    new_symbol->param_qtd = 0;
    new_symbol->decl_type = decl_type;
    new_symbol->line = line;
    new_symbol->column = column;
    new_symbol->scope = scope;
    new_symbol->prox = NULL;
    if(t->first == NULL){
        t->first = new_symbol;
    }else{
        t->last->prox = new_symbol;
    }
    t->last = new_symbol;
}

void freeSymbols(Table *t){
    while(t->first != NULL){
        Symbol *removed = t->first;
        t->first = t->first->prox;
        free(removed->name);
        free(removed->type);
        free(removed);
    }
    t->last = NULL;
}

void printTable(Table *t){
    printf("\n\t\t\t\t\t\t\t\t\t%sSymbol Table%s\n", GREEN, WHITE);
    printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
    printf("| %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s |\n", RED ,"Name", WHITE, 
    RED, "Type", WHITE, RED, "Declaration Type", WHITE, RED, "Num. Parameters", WHITE, RED, "Line", WHITE, RED, "Column", WHITE, RED, "Scope", WHITE);
    printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
    Symbol *actual = t->first;
    while(actual != NULL){
        switch(actual->decl_type){
            case 0: // function
                printf("| %-20s | %-20s | %-20s | %-20d | %-20d | %-20d | %-20d |\n", actual->name, actual->type, "function", actual->param_qtd, actual->line, actual->column, actual->scope);
                break;
            case 1: // variable
                printf("| %-20s | %-20s | %-20s | %-20s | %-20d | %-20d | %-20d |\n", actual->name, actual->type, "variable", "-", actual->line, actual->column, actual->scope);
                break;
            case 2: // parameter
                printf("| %-20s | %-20s | %-20s | %-20s | %-20d | %-20d | %-20d |\n", actual->name, actual->type, "parameter", "-", actual->line, actual->column, actual->scope);
                break;
        }
        actual = actual->prox;
    }
    printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
}

void setupParameters(Table *t){
    Symbol *actual = t->first;
    Symbol *function;

    while(actual != NULL){
        if(actual->decl_type == 0){  // Function
            actual->param_qtd = 0;
            function = actual;
        }else if(actual->decl_type == 2){    // Parameter
            function->param_qtd+= 1;
        }
        actual = actual->prox;
    }
}

int hasMainFunction(Table *t){
    int has_main = 0;
    Symbol *actual = t->first;
    while(actual != NULL){
        if(actual->decl_type == 0 && strcmp(actual->name, "main") == 0){    // function called main
            has_main = 1;
            break;
        }
        actual = actual->prox;
    }
    return has_main;
}

int isFunction(Table *t, char *id){
    Symbol *actual = t->first;
    while(actual != NULL){
        if(actual->decl_type == 0 && strcmp(actual->name, id) == 0){    // function equals id name
            return actual->scope;
        }
        actual = actual->prox;
    }
    return -1;
}

/* Ast */

Ast *createAstNode(char *name, int printable){
    Ast *new_ast_node = (Ast*)malloc(sizeof(Ast));
    new_ast_node->node_name = strdup(name);
    new_ast_node->node_type = NULL;
    new_ast_node->node_cast = NULL;
    new_ast_node->token_name = NULL;
    new_ast_node->token_print = NULL;
    new_ast_node->printable = printable;
    new_ast_node->token_line = new_ast_node->token_column = -1;
    new_ast_node->children[0] = NULL;
    new_ast_node->children[1] = NULL;
    new_ast_node->children[2] = NULL;
    new_ast_node->children[3] = NULL;
    return new_ast_node;
}

void insertAstNode(AstList *t, Ast *n){
    n->prox = t->first;
    t->first = n;
    if(t->last == NULL){
        t->last = t->first;
    }
}

void freeNode(Ast *n){
    int i;
    if(n == NULL)
        return;

    for(i = 0; i < MAX_CHILDREN; i++)
        freeNode(n->children[i]);

    if(n->node_name != NULL)
        free(n->node_name);

    if(n->node_type != NULL)
        free(n->node_type);

    if(n->node_cast != NULL)
        free(n->node_cast);

    if(n->token_name != NULL)
        free(n->token_name);

    if(n->token_print != NULL)
        free(n->token_print);

    if(n->prox != NULL)
        free(n->prox);
}

void printAstList(AstList *t){
    Ast *actual = t->first;
    while(actual != NULL){
        printf("%s", actual->node_name);
        if(actual->token_name){
            printf(" -> %s", actual->token_name);
        }
        printf("\n");
        actual = actual->prox;
    }
}

void printAST(Ast *root){
    printf("\n%sAST Tree%s\n", GREEN, WHITE);
    printNode(root, 0);
}

void printNode(Ast *n, int index){
    int i, spaces = 0;

    if(n == NULL)
        return;

    if(n->printable){
        for(i = 0; i < index; i++){
            printf("   ");
            spaces+= 3;
        }
        printf(" %s├─%s %s", GREEN, WHITE, n->node_name);
        if(n->token_name && n->token_line == -1)
            printf(" [%s%s%s]", RED, n->token_name, WHITE);
        if(n->node_type && strcmp(n->node_type, "undefined") != 0)
            printf(" <%s%s%s>", YELLOW, n->node_type, WHITE);
        if(n->node_cast && strcmp(n->node_type, "undefined") != 0){
            if(strcmp(n->node_type, "int list") != 0 && strcmp(n->node_type, "float list") != 0)
                printf(" <%scast to %s%s>", GREEN, n->node_cast, WHITE);
            else
                printf(" <%scast elements to %s%s>", GREEN, n->node_cast, WHITE);
        }
        printf("\n");
        index+= 1;
    }

    for(i = 0; i < MAX_CHILDREN; i++){
        if(n->children[i] != NULL){
            printNode(n->children[i], index);
        }
    }

    if(n->token_print && n->token_line != -1){
        for(i = 0; i < spaces+3; i++){
            printf(" ");
        }
        printf(" %s├─%s %s %s[%d:%d] %s\n", RED, WHITE, n->token_name, PURPLE, n->token_line, n->token_column, WHITE);
    }
}

void updateSignal(Ast *n){
    int i;
    static int negative_qtd = 0;
    char update_negative[100];

    if(n == NULL)
        return;

    if(n->printable){
        if(strcmp(n->node_name, "signed unary exp") == 0){
            if(strcmp(n->token_name, "-") == 0)
                negative_qtd+= 1;
        }else if(strcmp(n->node_name, "int constant") == 0 || strcmp(n->node_name, "real constant") == 0){
            if(negative_qtd % 2 != 0){
                strcpy(update_negative, "-");
                strcat(update_negative, n->token_name);
                free(n->token_name);
                n->token_name = strdup(update_negative);
                negative_qtd = 0;
            }
        }
    }

    for(i = 0; i < MAX_CHILDREN; i++){
        if(n->children[i] != NULL)
            updateSignal(n->children[i]);
    }
}

/* Scope */

void insertScope(int value, Context *c){
    Scope *new_scope = (Scope *)malloc(sizeof(Scope));
    new_scope->value = value;
    new_scope->prox = c->first;
    c->first = new_scope;
    if(c->last == NULL){
        c->last = c->first;
    }
}

void removeScope(Context *c){
    if(c->first == NULL)
        return;
    Scope *removed = c->first;
    c->first = c->first->prox;
    free(removed);
    if(c->first == NULL)
        c->last = NULL;
}

void setupContext(Context *c){
    insertScope(0, c);
}

void freeContextList(Context *c){
    while(c->first != NULL){
        removeScope(c);
    }
}

/* Parameter */

void insertParameterType(char *parameter_type, ParameterTypeList *p){
    Parameter *new_parameter = (Parameter *)malloc(sizeof(Parameter));
    new_parameter->parameter_type = strdup(parameter_type);
    new_parameter->prox = NULL;
    if(p->first == NULL){
        p->first = new_parameter;
    }else{
        p->last->prox = new_parameter;
    }
    p->last = new_parameter;
}

void popParameterTypeList(ParameterTypeList *p){
    if(p->first == NULL)
        return;
    Parameter *removed = p->first;
    p->first = p->first->prox;
    free(removed->parameter_type);
    free(removed);
    if(p->first == NULL)
        p->last = NULL;
}

void freeParameterTypeList(ParameterTypeList *p){
    Parameter *actual;
    while(p->first != NULL){
        actual = p->first;
        p->first = p->first->prox;
        free(actual->parameter_type);
        free(actual);
    }
    p->last = NULL;
}

/* General */

char *getType(Table *t, Context *c, char *name, int scope){
    Symbol *actual = t->first;
    while(actual != NULL){
        if(strcmp(actual->name, name) == 0 && actual->scope == scope){
            return actual->type;
        }
        actual = actual->prox;
    }
    return "undefined";
}

char *getContext(Table *t, Context *c, char *name, int line, int column, int *error){
    Scope *actual = c->first;
    while(actual != NULL){
        if(isOnTable(t, name, actual->value)){
            return getType(t, c, name, actual->value);
        }
        actual = actual->prox;
    }

    printf("%sLine:%d\tColumn:%d\tSemantic error! %s%s%s was not declared in this scope.%s\n", 
	RED, line, column, PURPLE, name, RED, WHITE);
    *error+= 1;

    return "undefined";
}

int getFunctionParameters(Table *t, Context *c, char *name, int scope){
    Symbol *actual = t->first;
    while(actual != NULL){
        if(strcmp(actual->name, name) == 0 && actual->scope == scope){
            return actual->param_qtd;
        }
        actual = actual->prox;
    }
    return -1;
}

void printParamTypes(Table *t, char *name, int scope){
    int i, qtd;
    Symbol *actual = t->first;
    while(actual != NULL){
        if(strcmp(actual->name, name) == 0 && actual->scope == scope){
            qtd = actual->param_qtd;
            for(i = 0; i < qtd; i++){
                printf("%s%s %s%s", BLUE, actual->prox->type, PURPLE, actual->prox->name);
                if(i != qtd-1){
                    printf(", ");
                }
                actual = actual->prox;
            }
            break;
        }
        actual = actual->prox;
    }
}

void typeCheckFunctionCall(char *type, ParameterTypeList *p, char *name, int line, int column, int actual_param, int *error){
    char parameter[15];
    strcpy(parameter, p->first->parameter_type);

    if(strcmp(type, "int") == 0 || strcmp(type, "float") == 0){
        if(strcmp(parameter, "int") != 0 && strcmp(parameter, "float") != 0){
            printf("%sLine:%d\tColumn:%d\tSemantic error! Type error in function call %s%s%s.%s\n",
            RED, line, column, GREEN, name, RED, WHITE);
            printf("\t\t\t%s<Formal parameter %s%d%s has type %s%s%s and argument %s%d%s passed has type %s%s%s>%s\n", 
			RED, GREEN, actual_param, RED, BLUE, type, RED, GREEN, actual_param, RED, BLUE, parameter, RED, WHITE);
			*error+= 1;
        }
    }else if(strcmp(type, "int list") == 0){
        if(strcmp(parameter, "int list") != 0){
            printf("%sLine:%d\tColumn:%d\tSemantic error! Type error in function call %s%s%s.%s\n",
            RED, line, column, GREEN, name, RED, WHITE);
            printf("\t\t\t%s<Formal parameter %s%d%s has type %s%s%s and argument %s%d%s passed has type %s%s%s>%s\n", 
			RED, GREEN, actual_param, RED, BLUE, type, RED, GREEN, actual_param, RED, BLUE, parameter, RED, WHITE);
			*error+= 1;
        }
    }else if(strcmp(type, "float list") == 0){
        if(strcmp(parameter, "float list") != 0){
            printf("%sLine:%d\tColumn:%d\tSemantic error! Type error in function call %s%s%s.%s\n",
            RED, line, column, GREEN, name, RED, WHITE);
            printf("\t\t\t%s<Formal parameter %s%d%s has type %s%s%s and argument %s%d%s passed has type %s%s%s>%s\n", 
			RED, GREEN, actual_param, RED, BLUE, type, RED, GREEN, actual_param, RED, BLUE, parameter, RED, WHITE);
			*error+= 1;
        }
    }
}

void checkFunctionCall(Table *t, Context *c, ParameterTypeList *p, char *name, int line, int column, int params_counter, int *error){
    int function_parameters = -1;
    int function_scope;
    int actual_param = 1;
    int i;

    Scope *actual_scope = c->first;
    Symbol *actual = t->first;

    while(actual_scope != NULL){
        if(isOnTable(t, name, actual_scope->value)){
            function_parameters = getFunctionParameters(t, c, name, actual_scope->value);
            if(function_parameters != -1){
                function_scope = actual_scope->value;
                break;
            }
        }
        actual_scope = actual_scope->prox;
    }
    
    if(function_parameters != -1){
        if(function_parameters != params_counter){
            printf("%sLine:%d\tColumn:%d\tSemantic error! Function %s%s%s requires %d argument(s).%s\n", RED, line, column, PURPLE, name, RED, function_parameters, WHITE);
            printf("\t\t\t%s<Formal parameters(s): %s%s%s(", RED, PURPLE, name, RED);
            printParamTypes(t, name, function_scope);
            printf("%s)%s>%s\n", RED, RED, WHITE);
            printf("\t\t\t%s<Number of argument(s) inserted: %d>%s\n", RED, params_counter, WHITE);
            *error+= 1;
        }else{
            while(actual != NULL){
                if(strcmp(actual->name, name) == 0 && actual->scope == function_scope){
                    for(i = 0; i < function_parameters; i++){
                        typeCheckFunctionCall(actual->prox->type, p, name, line, column, actual_param, error);
                        popParameterTypeList(p);
                        actual_param+= 1;
                        actual = actual->prox;
                    }
                    break;
                }
                actual = actual->prox;
            }
        }
    }
    freeParameterTypeList(p);
}

int checklvalueAssignment(Table *t, Context *c, char *name, int line, int column, int *error){
    Scope *actual = c->first;
    Symbol *actual_symbol = t->first;
    int scope = -1;
    while(actual != NULL){
        if(isOnTable(t, name, actual->value)){
            scope = actual->value;
            break;
        }
        actual = actual->prox;
    }

    if(scope != -1){
        while(actual_symbol != NULL){
            if(strcmp(actual_symbol->name, name) == 0 && actual_symbol->scope == scope){
                if(actual_symbol->decl_type == 0){
                    printf("%sLine:%d\tColumn:%d\tSemantic error! Function %s%s%s identified as left operand of assignment.%s\n", 
					RED, line, column, BLUE, name, RED, WHITE);
                    *error+= 1;
                    return 0;
                }
            }
            actual_symbol = actual_symbol->prox;
        }
    }
    return 1;
}

/*
void tac(Ast *n){
    int i;
    if(n == NULL)
        return;

    for(i = 0; i < MAX_CHILDREN; i++){
        if(n->children[i] != NULL)
            tac(n->children[i]);
    }
}
*/