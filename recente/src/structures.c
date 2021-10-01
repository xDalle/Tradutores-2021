#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/structures.h"

#define RED "\x1b[31m"
#define WHITE "\x1b[0m"
#define GREEN "\x1b[32m"
#define MAX_CHILDREN 4

/* SYMBOL TABLE */

void insertSymbol(Table *t, char *name, char *type, int decl_type, int line, int column, int scope){
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

int isOnTable(Table *t, char *name){
    Symbol *actual = t->first;
    while(actual != NULL){
        if(!strcmp(actual->name, name)){
            return actual->scope;
        }
        actual = actual->prox;
    }
    return -1;
}

void printTable(Table *t){
    printf("\n\t\t\t\t\t\t%sSymbol Table%s\n", GREEN, WHITE);
    printf(" ----------------------------------------------------------------------------------------------------------------------------------------- \n");
    printf("| %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s | %s%-20s%s |\n", RED ,"Name", WHITE, 
    RED, "Type", WHITE, RED, "Declaration Type", WHITE, RED, "Line", WHITE, RED, "Column", WHITE, RED, "Scope", WHITE);
    printf(" ----------------------------------------------------------------------------------------------------------------------------------------- \n");
    Symbol *actual = t->first;
    int getScope;
    int biggestScope = -1;
    while(actual != NULL){
        getScope = isOnTable(t, actual->name);
        if(biggestScope < getScope){
            biggestScope = getScope;
        }
        if(getScope == -1){  // mesmo símbolo no mesmo escopo...
            actual->scope = biggestScope;
        }
        actual = actual->prox;
    }
    actual = t->first;
    while(actual != NULL){
        if(actual->decl_type)
            printf("| %-20s | %-20s | %-20s | %-20d | %-20d | %-20d |\n", actual->name, actual->type, "variable", actual->line, actual->column, actual->scope);
        else
            printf("| %-20s | %-20s | %-20s | %-20d | %-20d | %-20d |\n", actual->name, actual->type, "function", actual->line, actual->column, actual->scope);
        actual = actual->prox;
    }
    printf(" ----------------------------------------------------------------------------------------------------------------------------------------- \n");
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
    new_ast_node->printable = printable;
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

    if(n->prox != NULL)
        free(n->prox);
}

void freeAst(AstList *t){
    Ast *actual = t->first;
    while(actual != NULL){
        if(actual->node_name != NULL)
            free(actual->node_name);
        else if(actual->token_name != NULL)
            free(actual->token_name);
        freeNode(actual);
        actual = actual->prox;
    }

    // int i;
    // Ast *actual = t->first;
    // while(actual != NULL){
    //     Ast *removed = t->first;
    //     // free(removed->symbol);
    //     for(i = 0; i < MAX_CHILDREN; i++){
    //         free(removed->children[i]);
    //     }
    //     t->first = t->first->prox;
    //     // free(removed->prox);
    //     free(removed);
    //     actual = actual->prox;
    // }
    // // free(actual);
    // // t->last = NULL;
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
        printf(" %s├─%s %s\n", GREEN, WHITE, n->node_name);
        index+= 1;
    }

    for(i = 0; i < MAX_CHILDREN; i++){
        if(n->children[i] != NULL){
            printNode(n->children[i], index);
        }
    }

    if(n->token_name){
        for(i = 0; i < spaces+3; i++){
            printf(" ");
        }
        printf(" %s├─%s %s\n", RED, WHITE, n->token_name);
    }
}