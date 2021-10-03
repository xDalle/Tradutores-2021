#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/structures.h"

#define RED "\x1b[31m"
#define WHITE "\x1b[0m"
#define GREEN "\x1b[32m"
#define PURPLE "\x1b[35m"

#define MAX_CHILDREN 4

Ast root;
AstList astList;
Table symbolTable;
Context contextList;
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

void insertSymbol(Table *t, char *name, char *type, int decl_type, int line, int column, int scope, int *errors){
    if(isOnTable(t, name, scope)){
        printf("%sLine:%d\tColumn:%d\tSemantic error! Redeclaration of variable %s%s%s in the same scope.%s\n", RED, line, column, PURPLE, name, RED, WHITE);
        *errors+= 1;
        //return;
    }

    Symbol *new_symbol = (Symbol*)malloc(sizeof(Symbol));
    //new_symbol->name = strdup(name);
    strcpy(new_symbol->name, name);
    //new_symbol->type = strdup(type);
    strcpy(new_symbol->type, type);
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
        //if(removed->name != NULL)
        //    free(removed->name);
        //else if(removed->type != NULL)
        //    free(removed->type);
        free(removed);
    }
    t->last = NULL;
}

void printTable(Table *t){
    printf("\n\t\t\t\t\t\t%sSymbol Table%s\n", GREEN, WHITE);
    printf(" ----------------------------------------------------------------------------------------------------------------------------------------- \n");
    printf("| %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s |\n", RED ,"Name", WHITE, 
    RED, "Type", WHITE, RED, "Declaration Type", WHITE, RED, "Line", WHITE, RED, "Column", WHITE, RED, "Scope", WHITE);
    printf(" ----------------------------------------------------------------------------------------------------------------------------------------- \n");
    Symbol *actual = t->first;
    while(actual != NULL){
        if(actual->decl_type)
            printf("| %-20s | %-20s | %-20s | %-20d | %-20d | %-20d |\n", actual->name, actual->type, "variable", actual->line, actual->column, actual->scope);
        else
            printf("| %-20s | %-20s | %-20s | %-20d | %-20d | %-20d |\n", actual->name, actual->type, "function", actual->line, actual->column, actual->scope);
        actual = actual->prox;
    }
    printf(" ----------------------------------------------------------------------------------------------------------------------------------------- \n");
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
    //strcpy(new_ast_node->node_name, name);
    new_ast_node->token_name = NULL;
    new_ast_node->token_type = NULL;
    new_ast_node->printable = printable;
    new_ast_node->token_line = new_ast_node->token_column = -1;
    //new_ast_node->has_token = 0;
    //strcpy(ast->node_name, name);
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
    if(n == NULL){
        return;
    }

    for(i = 0; i < MAX_CHILDREN; i++){
        freeNode(n->children[i]);
    }

    if(n->node_name != NULL){
        free(n->node_name);
    }

    if(n->token_name != NULL){
        free(n->token_name);
    }

    if(n->token_type != NULL){
        free(n->token_type);
    }
    
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
    free(actual);
}

void printAST(Ast *root){
    printf("\n%sAST Tree%s\n", GREEN, WHITE);
    printNode(root, 0);
}

void printNode(Ast *n, int index){
    int i, spaces = 0;

    if(n == NULL){
        return;
    }

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

    if(n->token_name && n->token_line != -1){
        for(i = 0; i < spaces+3; i++){
            printf(" ");
        }
        printf(" %s├─%s %s %s[%d:%d] %s\n", RED, WHITE, n->token_name, PURPLE, n->token_line, n->token_column, WHITE);
    }
}
/*
void checkType(Ast *n, int *error){
    if(strcmp(n->token_name, "return stmt") == 0){
        strcpy(n->token_type,);
    }else if(strcmp(n->token_name, "assign exp") == 0){

    }
        
}*/

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

int removeScope(Context *c){
    if(c->first == NULL){
        return -1;
    }
    int tmp = c->first->value;
    Scope *removed = c->first;
    c->first = c->first->prox;
    free(removed);
    if(c->first == NULL){
        c->last = NULL;
    }     
    return tmp;
}

void setupContext(Context *c){
    insertScope(0, c);
}

void freeContextList(Context *c){
    while(c->first != NULL){
        removeScope(c);
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

    printf("%sLine:%d\tColumn:%d\tSemantic error! Variable %s%s%s was not declared in this scope.%s\n", 
	RED, line, column, PURPLE, name, RED, WHITE);
    *error+= 1;

    return "error";
}