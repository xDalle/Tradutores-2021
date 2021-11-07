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
ParameterList parameterList;

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
    new_ast_node->func_name = NULL;
    new_ast_node->tac_table_item = NULL;
    new_ast_node->tac_code_item = NULL;
    new_ast_node->tac_code_item_if = NULL;
    new_ast_node->tac_code_item_then = NULL;
    new_ast_node->tac_code_item_for = NULL;
    new_ast_node->tac_value = NULL;
    new_ast_node->tac_symbol = -1;  // -1 -> nothing; 0 -> something, but not a symbol; 1 -> symbol
    new_ast_node->tac_register = -1;
    new_ast_node->is_function = 0;
    new_ast_node->function_args = 0;
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

    if(n->func_name != NULL)
        free(n->func_name);

    if(n->tac_table_item != NULL)
        free(n->tac_table_item);

    if(n->tac_code_item != NULL)
        free(n->tac_code_item);

    if(n->tac_code_item_if != NULL)
        free(n->tac_code_item_if);

    if(n->tac_code_item_then != NULL)
        free(n->tac_code_item_then);

    if(n->tac_code_item_for != NULL)
        free(n->tac_code_item_for);

    if(n->tac_value != NULL)
        free(n->tac_value);

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

void insertParameter(char *parameter_name, char *parameter_type, int literal, ParameterList *p){
    Parameter *new_parameter = (Parameter *)malloc(sizeof(Parameter));
    new_parameter->parameter_name = strdup(parameter_name);
    new_parameter->parameter_type = strdup(parameter_type);
    new_parameter->literal = literal;
    new_parameter->prox = NULL;
    if(p->first == NULL){
        p->first = new_parameter;
    }else{
        p->last->prox = new_parameter;
    }
    p->last = new_parameter;
}

void popParameterList(ParameterList *p){
    if(p->first == NULL)
        return;
    Parameter *removed = p->first;
    p->first = p->first->prox;
    free(removed->parameter_name);
    free(removed->parameter_type);
    free(removed);
    if(p->first == NULL)
        p->last = NULL;
}

void freeParameterList(ParameterList *p){
    Parameter *actual;
    while(p->first != NULL){
        actual = p->first;
        p->first = p->first->prox;
        free(actual->parameter_name);
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

int getScope(Table *t, Context *c, char *name){
    Scope *actual = c->first;
    while(actual != NULL){
        if(isOnTable(t, name, actual->value)){
            return actual->value;
        }
        actual = actual->prox;
    }
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

void typeCheckFunctionCall(char *type, ParameterList *p, char *name, int line, int column, int actual_param, int *error){
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

void checkFunctionCall(Ast *n, Table *t, Context *c, ParameterList *p, char *name, int line, int column, int params_counter, int *error){
    int function_parameters = -1;
    int function_scope;
    int actual_param = 1;
    int i;
    char scope_string[5];
    char tac_mov[1000] = "";
    char tac_instruction[2000];

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
                        if(strcmp(actual->prox->type, p->first->parameter_type) != 0){
                            if(strcmp(p->first->parameter_type, "int") == 0){
                                strcat(tac_mov, "inttofl $1019, ");
                                strcat(tac_mov, p->first->parameter_name);
                                if(p->first->literal == 0){
                                    strcat(tac_mov, "_");
                                    sprintf(scope_string, "%d", c->first->value);
                                    strcat(tac_mov, scope_string);
                                }
                                strcat(tac_mov, "\n");
                            }else if(strcmp(p->first->parameter_type, "float") == 0){
                                strcat(tac_mov, "fltoint $1019, ");
                                strcat(tac_mov, p->first->parameter_name);
                                if(p->first->literal == 0){
                                    strcat(tac_mov, "_");
                                    sprintf(scope_string, "%d", c->first->value);
                                    strcat(tac_mov, scope_string);
                                }
                                strcat(tac_mov, "\n");
                            }
                        }else{
                            strcat(tac_mov, "mov $1019, ");
                            strcat(tac_mov, p->first->parameter_name);
                            if(p->first->literal == 0){
                                strcat(tac_mov, "_");
                                sprintf(scope_string, "%d", c->first->value);
                                strcat(tac_mov, scope_string);
                            }
                            strcat(tac_mov, "\n");
                        }
                        strcat(tac_mov, "mov ");
                        strcat(tac_mov, actual->prox->name);
                        strcat(tac_mov, "_");
                        sprintf(scope_string, "%d", actual->prox->scope);
                        strcat(tac_mov, scope_string);
                        strcat(tac_mov, ", $1019\n");
                        popParameterList(p);
                        actual_param+= 1;
                        actual = actual->prox;
                    }
                    break;
                }
                actual = actual->prox;
            }
        }
    }
    freeParameterList(p);
    sprintf(tac_instruction, "%s\ncall _%s_%d, 0\npop $%d", tac_mov, name, function_scope, n->tac_register);
	n->tac_code_item = strdup(tac_instruction);
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

int checkFunctionID(Table *t, char *name, int scope){
    Symbol *actual_symbol = t->first;
    while(actual_symbol != NULL){
        if(strcmp(actual_symbol->name, name) == 0 && actual_symbol->scope == scope){
            if(actual_symbol->decl_type == 0){
                return 1;
            }
        }
        actual_symbol = actual_symbol->prox;
    }
    return 0;
}

int getFunctionArgs(Table *t, char *name, int scope){
    Symbol *actual_symbol = t->first;
    while(actual_symbol != NULL){
        if(strcmp(actual_symbol->name, name) == 0 && actual_symbol->scope == scope){
            if(actual_symbol->decl_type == 0){
                return actual_symbol->param_qtd;
            }
        }
        actual_symbol = actual_symbol->prox;
    }
    return 0;
}

void checkConstructorList(Ast *n){
    int i;
    char id_type[15];
    Ast *constructor_node;

    if(n == NULL)
        return;

    if(strcmp(n->node_name, "assign exp") == 0 && strcmp(n->children[0]->token_name, ":") == 0 && strcmp(n->children[0]->node_type, "nil") == 0){
        if(strcmp(n->node_type, "int list") == 0){
            strcpy(id_type, "int");
        }else if(strcmp(n->node_type, "float list") == 0){
            strcpy(id_type, "float");
        }

        constructor_node = n->children[0];
        while(strcmp(constructor_node->children[1]->token_name, ":") == 0){
            if(strcmp(constructor_node->children[0]->node_type, id_type) != 0){
                constructor_node->children[0]->node_cast = strdup(id_type);
            }
            constructor_node = constructor_node->children[1];
        }

        if(strcmp(constructor_node->children[1]->node_name, "nil constant") == 0){
            if(strcmp(constructor_node->children[0]->node_type, id_type) != 0){
                constructor_node->children[0]->node_cast = strdup(id_type);
            }
        }
    }

    for(i = 0; i < MAX_CHILDREN; i++)
        checkConstructorList(n->children[i]);

}

void printTACerror(int lexical_errors, int syntax_errors, int semantic_errors){
    int has_lexical_error = 0;
    int has_syntax_error = 0;
    int has_semantic_error = 0;
    int total_type_errors = 0;

    if(lexical_errors > 0){
        has_lexical_error = 1;
        total_type_errors+= 1;
    }
    if(syntax_errors > 0){
        has_syntax_error = 1;
        total_type_errors+= 1;
    }
    if(semantic_errors > 0){
        has_semantic_error = 1;
        total_type_errors+= 1;
    }
    
    printf("\n%s~> TAC will not be generated, due to ", RED);

    switch (total_type_errors){
    case 1:
        if(has_lexical_error){
            printf("lexical");
            break;
        }
        if(has_syntax_error){
            printf("syntax");
            break;
        }
        if(has_semantic_error){
            printf("semantic");
            break;
        }
    case 2:
        if(has_lexical_error && has_syntax_error){
            printf("lexical and syntax");
            break;
        }
        if(has_lexical_error && has_semantic_error){
            printf("lexical and semantic");
            break;
        }
        if(has_syntax_error && has_semantic_error){
            printf("syntax and semantic");
            break;
        }
    case 3:
        printf("lexical, syntax and semantic");
        break;
    }

    printf(" error(s).%s\n", WHITE);
}

void generateTACtable(FILE *fp, Ast *n){
    int i;
    if(n == NULL)
        return;

    if(n->tac_table_item)
        fprintf(fp, "%s\n", n->tac_table_item);

    for(i = 0; i < MAX_CHILDREN; i++){
        generateTACtable(fp, n->children[i]);
    }
}

void generateTACstring(FILE *fp){
    fprintf(fp, "_writeString:\n");
    fprintf(fp, "mov $1023, 0\n");
    fprintf(fp, "\n_writeChar:\n");
    fprintf(fp, "mov $1022, #1\n");
    fprintf(fp, "mov $1022, $1022[$1023]\n");
    fprintf(fp, "print $1022\n");
    fprintf(fp, "sub $1022, $1023, #0\n");
    fprintf(fp, "add $1023, $1023, 1\n");
    fprintf(fp, "brnz _writeChar, $1022\n");
    fprintf(fp, "return\n\n");
    fprintf(fp, "_writeStringln:\n");
    fprintf(fp, "call _writeString, 2\n");
    fprintf(fp, "println\n");
    fprintf(fp, "return\n\n");
}

void generateTACcode(FILE *fp, Ast *n){
    int i;
    static char for_loops[4][4];
    static char if_loop[10];
    static char if_loops[10][4];
    static int it = 0;
    static int it_if = 0;
    char for_register[5];
    char if_register[5];

    if(n == NULL)
        return;

    if(n->func_name)
        fprintf(fp, "\n%s:\n", n->func_name);

    if(strcmp(n->node_name, "if stmt") == 0){
        sprintf(if_loop, "L%d", it++);
        it_if++;
        generateTACcode(fp, n->children[0]);
        fprintf(fp, "brz %s, ", if_loop);
        sprintf(if_register, "$%d", n->children[0]->tac_register);
        fprintf(fp, "%s\n", if_register);
        generateTACcode(fp, n->children[1]);
        fprintf(fp, "%s:\n", if_loop);
        it_if--;
    }else if(strcmp(n->node_name, "if-else stmt") == 0){
        sprintf(if_loop, "L%d", it++);
        it_if++;
        generateTACcode(fp, n->children[0]);
        fprintf(fp, "brz %s, ", if_loop);
        sprintf(if_register, "$%d", n->children[0]->tac_register);
        fprintf(fp, "%s\n", if_register);
        generateTACcode(fp, n->children[1]);
        sprintf(if_loops[it_if], "L%d", it);
        it++;
        fprintf(fp, "jump %s\n%s:\n", if_loops[it_if], if_loop);
        generateTACcode(fp, n->children[2]);
        fprintf(fp, "%s:\n", if_loops[it_if--]);
    }else if(strcmp(n->node_name, "for stmt") == 0){
        generateTACcode(fp, n->children[0]);
        sprintf(for_loops[0], "L%d", it++);
        sprintf(for_loops[1], "L%d", it++);
        sprintf(for_loops[2], "L%d", it++);
        sprintf(for_loops[3], "L%d", it++);
        fprintf(fp, "%s:\n", for_loops[0]);
        generateTACcode(fp, n->children[1]);
        fprintf(fp, "jump %s\n%s:\n", for_loops[1], for_loops[3]);
        generateTACcode(fp, n->children[2]);
        fprintf(fp, "jump %s\n%s:\n", for_loops[0], for_loops[2]);
        generateTACcode(fp, n->children[3]);
        fprintf(fp, "jump %s\n%s:\n", for_loops[3], for_loops[1]);
        fprintf(fp, "brnz %s, ", for_loops[2]);
        sprintf(for_register, "$%d", n->children[1]->tac_register);
        fprintf(fp, "%s\n", for_register);
    }else{
        for(i = 0; i < MAX_CHILDREN; i++)
            generateTACcode(fp, n->children[i]);

        if(n->tac_code_item)
            fprintf(fp, "%s\n", n->tac_code_item);
    }

    /*if(n->tac_code_item_if)
        fprintf(fp, "%s\n", n->tac_code_item_if);

    if(n->tac_code_item_then)
        fprintf(fp, "%s\n", n->tac_code_item_then);*/
}

void generateTAC(Ast *n, char *file_name, int has_string){
    int i;
    char tac_file_name[200];

    for(i = 0; i < strlen(file_name)-2; i++){ // file name without .c
        tac_file_name[i] = file_name[i];
        tac_file_name[i+1] = '\0';
    }
    
    strcat(tac_file_name, ".tac");  // add .tac

    printf("%sTAC will be generated in %s%s%s.%s\n", GREEN, BLUE, tac_file_name, GREEN, WHITE);
    FILE *fp = fopen(tac_file_name, "w");
    fprintf(fp, "// tac table of %s\n", file_name);
    fprintf(fp, "%s\n", ".table");
    generateTACtable(fp, n);
    fprintf(fp, "\n// tac code of %s\n", file_name);
    fprintf(fp, "%s\n", ".code");
    if(has_string)
        generateTACstring(fp);
    generateTACcode(fp, n);
    fprintf(fp, "\nmain:\ncall _main_0, 0\n");   // generate fake main
    fclose(fp);
}