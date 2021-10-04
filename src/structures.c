#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/structures.h"

#define RED "\x1b[31m"
#define WHITE "\x1b[0m"
#define GREEN "\x1b[32m"
#define PURPLE "\x1b[35m"
#define BLUE "\x1b[36m"

#define MAX_CHILDREN 4

Ast root;
AstList astList;
Table symbolTable;
Context contextList;
//ParameterList parameterList;
extern int check_func_type;

/* SYMBOL TABLE */

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
    new_symbol->param_list = NULL;
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
        if(removed->param_list != NULL){
            freeParamList(removed->param_list);
        }
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
/* AST */

AstList *createAstList(){
    AstList *ast_list = (AstList*)malloc(sizeof(AstList));
    ast_list->first = NULL;
    ast_list->last = NULL;
    return ast_list;
}

Ast *createAstNode(char *name, int printable){
    Ast *new_ast_node = (Ast*)malloc(sizeof(Ast));
    new_ast_node->node_name = strdup(name);
    new_ast_node->node_type = NULL;
    new_ast_node->node_transform = NULL;
    new_ast_node->token_name = NULL;
    new_ast_node->token_type = NULL;
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

    if(n->node_transform != NULL)
        free(n->node_transform);

    if(n->token_name != NULL)
        free(n->token_name);

    if(n->token_type != NULL)
        free(n->token_type);
    
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
        printf("\n");
        index+= 1;
    }

    for(i = 0; i < MAX_CHILDREN; i++){
        if(n->children[i] != NULL){
            printNode(n->children[i], index);
        }
    }

    if(n->token_type && strcmp(n->token_name, "var definition") != 0){
        for(i = 0; i < spaces+3; i++){
            printf(" ");
        }
        printf(" %s├─%s %s %s[%d:%d] %s\n", RED, WHITE, n->token_name, PURPLE, n->token_line, n->token_column, WHITE);
    }
}

/* SCOPE */

void insertScope(int value, Context *c){
    Scope *new_scope = (Scope *)malloc(sizeof(Scope));
    new_scope->value = value;
    new_scope->prox = c->first;
    c->first = new_scope;
    if(c->last == NULL){ //l->inicio->proximo == NULL ou novoprimeiro->proximo == NULL
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

/* Parameter list */

ParameterList *createParameterList(){
    ParameterList *parameter_list = (ParameterList*)malloc(sizeof(ParameterList));
    parameter_list->first = NULL;
    parameter_list->last = NULL;
    return parameter_list;
}

void insertParam(char *param_type, ParameterList *p){
   Parameter * new_parameter = (Parameter *)malloc(sizeof(Parameter));
   //new_parameter->param_type = strdup(param_type);
   strcpy(new_parameter->param_type, param_type);
   new_parameter->prox = NULL;
   if(p->first == NULL){
      p->first = new_parameter;
   }else{
      p->last->prox = new_parameter;
   }
   p->last = new_parameter;
}

void freeParamList(ParameterList *p){
    Parameter *actual;
    while(p->first != NULL){
        actual = p->first;
        p->first = p->first->prox;
        free(actual);
    }
    p->last = NULL;
}

void setupParameters(Table *t){
    Symbol *actual = t->first;
    Symbol *function;
    ParameterList *param_start;

    while(actual != NULL){
        if(actual->decl_type == 0){  // Function
            actual->param_qtd = 0;
            actual->param_list = createParameterList();
            function = actual;
            param_start = actual->param_list;
        }else if(actual->decl_type == 2){    // Parameter
            function->param_qtd+= 1;
            insertParam(actual->type, param_start);
        }
        actual = actual->prox;
    }
}

void printParamList(ParameterList *p){
    Parameter *actual = p->first;
    while(actual != NULL){
        printf("%s, ", actual->param_type);
        actual = actual->prox;
    }
    printf("\n");
}

void printParams(Table *t){
    Symbol *actual = t->first;
    while(actual != NULL){
        if(actual->param_list){
            printf("%s -> ", actual->name);
            printParamList(actual->param_list);
        }
        actual = actual->prox;
    }
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
    return "error";
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

    return "error";
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
    Symbol *actual = t->first;
    Parameter *actual_parameter;
    while(actual != NULL){
        if(strcmp(actual->name, name) == 0 && actual->scope == scope){
            actual_parameter = actual->param_list->first;
            while(actual_parameter != NULL){
                printf("%s%s", BLUE, actual_parameter->param_type);
                if(actual_parameter->prox != NULL)
                    printf(", ");
                actual_parameter = actual_parameter->prox;
            }
            break;
        }
        actual = actual->prox;
    }
}

void checkFunctionCall(Table *t, Context *c, char *name, int line, int column, int params_counter, int *error){
    int function_parameters = -1;
    int function_scope;
    Scope *actual = c->first;
    while(actual != NULL){
        if(isOnTable(t, name, actual->value)){
            function_parameters = getFunctionParameters(t, c, name, actual->value);
            if(function_parameters != -1){
                function_scope = actual->value;
                break;
            }
        }
        actual = actual->prox;
    }

    if(function_parameters != -1 && function_parameters != params_counter){
        printf("%sLine:%d\tColumn:%d\tSemantic error! Function %s%s%s requires %d argument(s).%s\n", RED, line, column, PURPLE, name, RED, function_parameters, WHITE);
        printf("\t\t\t%s`%s%s(", RED, PURPLE, name);
        printParamTypes(t, name, function_scope);
        printf("%s)%s`%s\n", PURPLE, RED, WHITE);
        printf("\t\t\t%s<Number of argument(s) inserted: %d>%s\n", RED, params_counter, WHITE);
        *error+= 1;
    }
}

/*
void checkType(Ast *n, int line, int column, int *error){
    int alt = 0;    // 1 = return, 2 = assignment
    char func_type[15];
    if(strcmp(n->node_name, "return stmt") == 0){
        alt = 1;
    }else if(strcmp(n->node_name, "assign exp") == 0){
        alt = 2;
    }

    switch(check_func_type){
        case 1:
            strcpy(func_type, "int");
            break;
        case 2:
            strcpy(func_type, "float");
            break;
        case 3:
            strcpy(func_type, "int list");
            break;
        case 4:
            strcpy(func_type, "float list");
            break;
    }

    // check_func_type -> 1 = int, 2 = float, 3 = int list, 4 = float list
    switch(alt){
        case 1:
            n->node_type = strdup(func_type);
            printf("%s ", n->node_type);
            printf("%s ", n->node_name);
            //printf("%s ", n->children[0]->node_type);
                if (!((check_func_type > 2
                && (!strcmp(n->children[0]->node_type, "int") || !strcmp(n->children[0]->node_type, "float")))
                || ((!strcmp(func_type, "int") || !strcmp(func_type, "float"))
                    && check_func_type > 2))) {
                strcpy(n->children[0]->node_transform, n->node_type);
            }
            else {
                printf("%sLine:%d\tColumn:%d\tSemantic error! Type %s%s%s unexpected in return of function.%s\n", RED, line, column, PURPLE, "tipo", RED, WHITE);
                *error+= 1;
            }
            break;
        case 2:
            break;
    }
}


char *typeDiff(Ast *l, Ast *r){
    // 1 = int, 2 = float, 3 = int list, 4 = float list
    int l_type = 0;
    int r_type = 0;

    if(strcmp(l->node_type, "int") == 0){
        l_type = 1;
    }else if(strcmp(l->node_type, "float") == 0){
        l_type = 2;
    }else if(strcmp(l->node_type, "int list") == 0){
        l_type = 3;
    }else if(strcmp(l->node_type, "float list") == 0){
        l_type = 4;
    }
    
    if(strcmp(l->node_type, r->node_type) == 0)
        return l->node_type;
    else if(strcmp(l->node_type, r->node_type) == 0){

    }
}

void verifyExpressionType(Ast *n){
    if(n == NULL)
        return; //recursivity

    char *left_children;
    char *right_children;

    if(strcmp(n->node_name, "func params")){
        if(left_children == NULL && right_children == NULL){
            n->
        }
    }
}*/
