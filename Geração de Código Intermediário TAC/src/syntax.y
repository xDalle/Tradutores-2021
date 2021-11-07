%defines "lib/syntax.tab.h"
%define lr.type canonical-lr
%define parse.error verbose

%{
	#define WHITE "\x1b[0m"
	#define RED "\x1b[31m"
	#define GREEN "\x1b[32m"
	#define YELLOW "\x1b[33m"
	#define PURPLE "\x1b[35m"
	#define BLUE "\x1b[36m"

	#define ERROR -1
	#define DEBUG_AST 0
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../lib/structures.h"

	extern int yylex();
	extern int yyparse();
	extern int yylex_destroy();
	extern FILE *yyin;
	extern void yyerror(const char *error_msg);
	extern int num_lines;
	extern int num_chars;
	extern int last_scope;
	extern int func_context;			// manipulate scope interaction between lexical and syntatic
	extern int lexical_errors;
	int error_comm = 0;

	static int syntax_errors = 0;	
	static int semantic_errors = 0;

	int func_params_counter = 0;		// incremented by the number of params in function call
	int has_return = 0;
	int return_line;
	int return_column;

	char return_type[15];
	char function_type[15];

	int has_string = 0;
	static int string_index = 0;
	static int register_index = 0;
	static int if_else_counter = 0;

	extern Ast root;
	extern AstList astList;
	extern Table symbolTable;
	extern Context contextList;
	extern ParameterList parameterList;
%}

%union {
	struct Ast *ast;
	struct Lexeme {
		char lexeme_string[200];
		int line;
		int column;
		int scope;
		int length;
	}lexeme;
}

%token <lexeme> ADD
%token <lexeme> MUL
%token <lexeme> INTEGER
%token <lexeme> REAL
%token <lexeme> LOGICAL_OR
%token <lexeme> LOGICAL_AND
%token <lexeme> IF
%token <lexeme> ELSE
%token <lexeme> FOR
%token <lexeme> RETURN
%token <lexeme> INPUT
%token <lexeme> OUTPUT
%token <lexeme> SIMPLE_TYPE
%token <lexeme> COMPOUND_TYPE
%token <lexeme> ID
%token <lexeme> NIL_CONSTANT
%token <lexeme> LIST_CONSTR
%token <lexeme> LIST_OP
%token <lexeme> LIST_DESTR
%token <lexeme> LIST_FUNC
%token <lexeme> RELATIONAL
%token <lexeme> STRING
%token <lexeme> OP_OVERLOAD
%token <lexeme> ERROR_STR
%token <lexeme> ERROR_CHAR
%token <lexeme> ERROR_COMM

%token <lexeme> '{'
%token <lexeme> '}'
%token <lexeme> '('
%token <lexeme> ')'
%token <lexeme> '='
%token <lexeme> ','
%token <lexeme> ';'

%nonassoc ELSE
%nonassoc THEN

%type <ast> initial
%type <ast> declaration_list
%type <ast> decl
%type <ast> var_definition
%type <ast> var_declaration
%type <ast> func_definition
%type <ast> func_declaration
%type <ast> param_list
%type <ast> param
%type <ast> stmts
%type <ast> stmt_list
%type <ast> stmt
%type <ast> exp_stmt
%type <ast> assign_exp
%type <ast> exp
%type <ast> simple_exp
%type <ast> select_stmt
%type <ast> iter_stmt
%type <ast> return_stmt
%type <ast> io_stmt
%type <ast> in_stmt
%type <ast> out_stmt
%type <ast> and_exp
%type <ast> rel_exp
%type <ast> sum_exp
%type <ast> mul_exp
%type <ast> factor
%type <ast> func_call
%type <ast> func_params
%type <ast> constant
%type <ast> stmt_list.opt
%type <ast> stmt.item
%type <ast> list_exp
%type <ast> unary_exp
%type <ast> params.opt

%start initial

%%

initial:
	declaration_list{
		//root = *createAstNode("initial", DEBUG_AST);	// non-printable
		root.node_name = strdup("initial");
		root.printable = DEBUG_AST;
		$$ = &root;
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

declaration_list:
	declaration_list decl{
		$$ = createAstNode("declaration list", 1);	// printable
		$$->children[0] = $1;
		$$->children[1] = $2;
		insertAstNode(&astList, $$);
	}
	| decl{
		$$ = $1;
	}
;

decl:
	var_declaration{
		$$ = $1;
	}
	| func_definition{
		$$ = $1;
	}
	| ';'{
		$$ = createAstNode("no operation", DEBUG_AST);
		$$->token_name = strdup(";");
		insertAstNode(&astList, $$);
	}
	| ERROR_COMM{
		error_comm = 1;
		fclose(yyin);
		yylex_destroy();
		return ERROR;
	}
	| error {
		$$ = createAstNode("error", DEBUG_AST);
		$$->node_type = strdup("invalid");
		insertAstNode(&astList, $$);
		yyerrok;
	}
;

var_definition:
	SIMPLE_TYPE ID{
		int var_type = 2;	// parameter
		char type_and_id[150];
		char tac_instruction[500];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, $1.lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " parameter definition");
		insertSymbol(&symbolTable, $2.lexeme_string, $1.lexeme_string, var_type, $2.line, $2.column, $2.scope, &semantic_errors);
		$$ = createAstNode(type_and_id, 1);
		$$->node_type = strdup($1.lexeme_string);
		$$->token_name = strdup($2.lexeme_string);
		$$->token_print = strdup($1.lexeme_string);
		$$->token_line = $2.line;
		$$->token_column = $2.column;
		sprintf(tac_instruction, "%s %s_%d", $1.lexeme_string, $2.lexeme_string, $2.scope);
		$$->tac_table_item = strdup(tac_instruction);
		insertAstNode(&astList, $$);
	}
	| SIMPLE_TYPE COMPOUND_TYPE ID{
		char concat_type[15];
		char type_and_id[150];
		int var_type = 2;	// parameter
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, concat_type);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " parameter definition");
		insertSymbol(&symbolTable, $3.lexeme_string, concat_type, var_type, $3.line, $3.column, $3.scope, &semantic_errors);
		$$ = createAstNode(type_and_id, 1);
		$$->node_type = strdup(concat_type);
		$$->token_name = strdup($3.lexeme_string);
		$$->token_print = strdup(concat_type);
		$$->token_line = $3.line;
		$$->token_column = $3.column;
		insertAstNode(&astList, $$);
	}
;

var_declaration:
	SIMPLE_TYPE ID ';'{
		int var_type = 1;
		char type_and_id[150];
		char tac_instruction[500];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, $1.lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " variable declaration");
		insertSymbol(&symbolTable, $2.lexeme_string, $1.lexeme_string, var_type, $2.line, $2.column, $2.scope, &semantic_errors);
		$$ = createAstNode(type_and_id, 1);
		$$->node_type = strdup($1.lexeme_string);
		$$->token_name = strdup($2.lexeme_string);
		$$->token_print = strdup($1.lexeme_string);
		$$->token_line = $2.line;
		$$->token_column = $2.column;
		sprintf(tac_instruction, "%s %s_%d", $1.lexeme_string, $2.lexeme_string, $2.scope);
		$$->tac_table_item = strdup(tac_instruction);
		insertAstNode(&astList, $$);
	}
	| SIMPLE_TYPE COMPOUND_TYPE ID ';'{
		char concat_type[15];
		char type_and_id[150];
		int var_type = 1;
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, concat_type);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " variable declaration");
		insertSymbol(&symbolTable, $3.lexeme_string, concat_type, var_type, $3.line, $3.column, $3.scope, &semantic_errors);
		$$ = createAstNode(type_and_id, 1);
		$$->node_type = strdup(concat_type);
		$$->token_name = strdup($3.lexeme_string);
		$$->token_print = strdup(concat_type);
		$$->token_line = $3.line;
		$$->token_column = $3.column;
		insertAstNode(&astList, $$);
	}
;	

func_definition:
	func_declaration '(' {
		func_context = 1;
		has_return = 0;
		insertScope(++last_scope, &contextList);
	} params.opt ')' stmts {
		char tac_instruction[500];
		$$ = createAstNode("function definition", DEBUG_AST);
		$$->children[0] = $1;
		$$->children[1] = $4;
		$$->children[2] = $6;

		char return_value[5];

		if(has_return){
			if(strcmp($$->children[0]->node_type, "int") == 0){
				if(strcmp(return_type, "int") == 0 || strcmp(return_type, "float") == 0){
					$$->node_type = strdup($$->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, $$->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, $$->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp($$->children[0]->node_type, "float") == 0){
				if(strcmp(return_type, "float") == 0 || strcmp(return_type, "int") == 0){
					$$->node_type = strdup($$->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, $$->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, $$->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp($$->children[0]->node_type, "int list") == 0){
				if(strcmp(return_type, "int list") == 0 || strcmp(return_type, "nil") == 0){
					$$->node_type = strdup($$->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, $$->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, $$->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp($$->children[0]->node_type, "float list") == 0){
				if(strcmp(return_type, "float list") == 0 || strcmp(return_type, "nil") == 0){
					$$->node_type = strdup($$->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, $$->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, $$->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}
		}else{
			$$->node_type = strdup($$->children[0]->node_type);
			if(strcmp($$->node_type, "int") == 0)
				strcpy(return_value, "0");
			else if(strcmp($$->node_type, "float") == 0)
				strcpy(return_value, "0.0");
			else
				strcpy(return_value, "NIL");
			printf("%sLine:%d\tColumn:%d\tSemantic warning! Function %s%s%s without a return. Default value of return is set to %s%s%s.%s\n", 
			YELLOW, $$->children[0]->token_line, $$->children[0]->token_column, GREEN, $$->children[0]->token_name, YELLOW, BLUE, return_value, YELLOW, WHITE);
			sprintf(tac_instruction, "return %s", return_value);
			$$->tac_code_item = strdup(tac_instruction);
		}
		insertAstNode(&astList, $$);
		removeScope(&contextList);
	}
;

params.opt:
	param_list{
		$$ = createAstNode("params optional", DEBUG_AST);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| %empty{
		$$ = createAstNode("params optional empty", DEBUG_AST); 
		insertAstNode(&astList, $$);
	}
;

func_declaration:
	SIMPLE_TYPE ID{
		int func_type = 0;
		char type_and_id[150];
		char tac_instruction[500];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, $1.lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " function declaration");
		insertSymbol(&symbolTable, $2.lexeme_string, $1.lexeme_string, func_type, $2.line, $2.column, $2.scope, &semantic_errors);
		$$ = createAstNode(type_and_id, 1);
		$$->node_type = strdup($1.lexeme_string);
		$$->token_name = strdup($2.lexeme_string);
		$$->token_print = strdup($1.lexeme_string);
		strcpy(function_type, $1.lexeme_string);
		$$->token_line = $2.line;
		$$->token_column = $2.column;
		sprintf(tac_instruction, "_%s_%d", $2.lexeme_string, $2.scope);
		$$->func_name = strdup(tac_instruction);
		insertAstNode(&astList, $$);
	}
	| SIMPLE_TYPE COMPOUND_TYPE ID{
		char concat_type[15];
		char type_and_id[150];
		int func_type = 0;
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, concat_type);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " function declaration");
		insertSymbol(&symbolTable, $3.lexeme_string, concat_type, func_type, $3.line, $3.column, $3.scope, &semantic_errors);
		$$ = createAstNode(type_and_id, 1);
		$$->node_type = strdup(concat_type);
		$$->token_name = strdup($3.lexeme_string);
		$$->token_print = strdup(concat_type);
		strcpy(function_type, concat_type);
		$$->token_line = $3.line;
		$$->token_column = $3.column;
		insertAstNode(&astList, $$);
	}
;

param_list:
	param{
		$$ = $1;
	}
	| param_list ',' param{
		$$ = createAstNode("param list", DEBUG_AST);
		$$->children[0] = $1;
		$$->children[1] = $3;
		insertAstNode(&astList, $$);
	}
	| error {
		$$ = createAstNode("error", DEBUG_AST);
		$$->node_type = strdup("invalid");
		insertAstNode(&astList, $$);
		yyerrok;
	}
;

param:
	var_definition{
		$$ = $1;
		setupParameters(&symbolTable);
	}
;

stmts:
	'{' stmt_list.opt '}'{
		$$ = $2;
	}
;

stmt_list.opt:
	stmt_list{
		$$ = createAstNode("stmt list optional", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| %empty {
		$$ = createAstNode("stmt list empty", 1);
		insertAstNode(&astList, $$);
	}
;

stmt_list:
	stmt_list stmt.item{
		$$ = createAstNode("stmt list", DEBUG_AST);
		$$->children[0] = $1;
		$$->children[1] = $2;
		insertAstNode(&astList, $$);
	}
	| stmt.item{
		$$ = $1;
	}
;

stmt.item:
	stmt{
		$$ = $1;
	}
	| var_declaration{
		$$ = $1;
	}
;

stmt:
	return_stmt{
		$$ = $1;
	}
	| select_stmt{
		if_else_counter++;
		$$ = $1;
	}
	| iter_stmt{
		$$ = $1;
	}
	| io_stmt{
		$$ = $1;
	}
	| exp_stmt{
		$$ = $1;
	}
	| ';'{
		$$ = createAstNode("no operation", DEBUG_AST);
		$$->token_name = strdup(";");
		insertAstNode(&astList, $$);
	}
	| ERROR_COMM{
		error_comm = 1;
		fclose(yyin);
		yylex_destroy();
		return ERROR;
	}
	| stmts{
		$$ = $1;
	}
;

select_stmt:
	IF '(' simple_exp ')' stmt %prec THEN{
		$$ = createAstNode("if stmt", 1);
		$$->children[0] = $3;
		$$->children[1] = $5;
		insertAstNode(&astList, $$);
	}
	| IF '(' simple_exp ')' stmt ELSE stmt{
		$$ = createAstNode("if-else stmt", 1);
		$$->children[0] = $3;
		$$->children[1] = $5;
		$$->children[2] = $7;
		insertAstNode(&astList, $$);
	}
;

iter_stmt:
	FOR '(' exp ';' simple_exp ';' exp ')' stmt{
		$$ = createAstNode("for stmt", 1);
		$$->children[0] = $3;
		$$->children[1] = $5;
		$$->children[2] = $7;
		$$->children[3] = $9;
		insertAstNode(&astList, $$);
	}
;

exp_stmt:
	exp ';'{
		$$ = $1;
	}
;

exp:
	assign_exp{
		$$ = $1;
	}
	| simple_exp{
		$$ = $1;
	}
;

return_stmt:
	RETURN exp ';'{
		char tac_instruction[500];
		$$ = createAstNode("return stmt", 1);
		$$->children[0] = $2;
		return_line = $1.line;
		return_column = $1.column;
		$$->node_type = strdup($$->children[0]->node_type);
		strcpy(return_type, $$->children[0]->node_type);
		if(strcmp(return_type, "int") == 0){
			if(strcmp(function_type, "float") == 0){
				$$->node_cast = strdup(function_type);
			}
		}else if(strcmp(return_type, "float") == 0){
			if(strcmp(function_type, "int") == 0){
				$$->node_cast = strdup(function_type);
			}
		}

		if(semantic_errors == 0){
			if($$->children[0]->tac_symbol == 0){
            	$$->tac_symbol = 0;
				sprintf(tac_instruction, "return $%d", $$->children[0]->tac_register);
				$$->tac_code_item = strdup(tac_instruction);
        	}else if($$->children[0]->tac_symbol == 1){
            	$$->tac_symbol = 0;
            	sprintf(tac_instruction, "return %s", $$->children[0]->tac_value);
				$$->tac_code_item = strdup(tac_instruction);
        	}
		}
		insertAstNode(&astList, $$);
		has_return = 1;
	}
;

io_stmt:
	in_stmt{
		$$ = $1;
	}
	| out_stmt{
		$$ = $1;
	}
;

in_stmt:
	INPUT '(' ID ')' ';'{
		char input_type[200];
		char id_type[15];
		char tac_instruction[500];
		strcpy(id_type, getContext(&symbolTable, &contextList, $3.lexeme_string, $3.line, $3.column, &semantic_errors));
		$$ = createAstNode("input stmt", 1);
		strcpy(input_type, $1.lexeme_string);
		strcat(input_type, "(");
		strcat(input_type, $3.lexeme_string);
		strcat(input_type, ")");
		$$->token_name = strdup(input_type);

		int id_scope = getScope(&symbolTable, &contextList, $3.lexeme_string);
		if(semantic_errors == 0){
			if(strcmp(id_type, "int") == 0){
				$$->tac_symbol = 1;
				sprintf(tac_instruction, "scani %s_%d", $3.lexeme_string, id_scope);
				$$->tac_code_item = strdup(tac_instruction);
			}else if(strcmp(id_type, "float") == 0){
				$$->tac_symbol = 1;
				sprintf(tac_instruction,"scanf %s_%d", $3.lexeme_string, id_scope);
				$$->tac_code_item = strdup(tac_instruction);
			}
		}
		insertAstNode(&astList, $$);
	}
;

out_stmt:
	OUTPUT '(' STRING ')' ';'{
		has_string = 1;
		char output_type[200];
		char tac_instruction[500];
		$$ = createAstNode("output stmt", 1);
		strcpy(output_type, $1.lexeme_string);
		strcat(output_type, "(");
		strcat(output_type, $3.lexeme_string);
		strcat(output_type, ")");
		$$->token_name = strdup(output_type);
		string_index+= 1;
		int string_size = strlen($3.lexeme_string)-2;	// remove quotation marks
		sprintf(tac_instruction, "char str_%d[] = %s\nint str_%d_size = %d", string_index, $3.lexeme_string, string_index, string_size);
		$$->tac_table_item = strdup(tac_instruction);

		if(strcmp($1.lexeme_string, "write") == 0){
            sprintf(tac_instruction, "param str_%d_size\nmov $1021, &str_%d\nparam $1021\ncall _writeString, 2", string_index, string_index);
			$$->tac_code_item = strdup(tac_instruction);
        }
        else if(!strcmp($1.lexeme_string, "writeln")){
            sprintf(tac_instruction, "param str_%d_size\nmov $1021, &str_%d\nparam $1021\ncall _writeStringln, 2", string_index, string_index);
			$$->tac_code_item = strdup(tac_instruction);
        }

		insertAstNode(&astList, $$);
	}
	| OUTPUT '(' exp ')' ';'{
		char output_type[200];
		char tac_instruction[500];
		$$ = createAstNode("output stmt", 1);
		strcpy(output_type, $1.lexeme_string);
		strcat(output_type, "()");
		$$->token_name = strdup(output_type);
		$$->children[0] = $3;

		if(semantic_errors == 0){
			if(strcmp($1.lexeme_string, "write") == 0){
				if($$->children[0]->tac_symbol == 0){
					sprintf(tac_instruction, "print $%d", $$->children[0]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[0]->tac_symbol == 1){
					sprintf(tac_instruction, "print %s", $$->children[0]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}else if(strcmp($1.lexeme_string, "writeln") == 0){
				if($$->children[0]->tac_symbol == 0){
					sprintf(tac_instruction, "println $%d", $$->children[0]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[0]->tac_symbol == 1){
					sprintf(tac_instruction, "println %s", $$->children[0]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}
		}
		insertAstNode(&astList, $$);
	}
;

assign_exp:
	ID '=' exp{
		char id_type[15];
		char tac_instruction[500];
		char tac_instruction_value[500];
		strcpy(id_type, getContext(&symbolTable, &contextList, $1.lexeme_string, $1.line, $1.column, &semantic_errors));
		$$ = createAstNode("assign exp", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->token_print = strdup(id_type);
		$$->token_line = $1.line;
		$$->token_column = $1.column;
		$$->children[0] = $3;
		if(checklvalueAssignment(&symbolTable, &contextList, $1.lexeme_string, $1.line, $1.column, &semantic_errors)){
			if(strcmp(id_type, "int") == 0){
				if(strcmp($$->children[0]->node_type, "int") == 0){
					$$->node_type = strdup(id_type);
				}else if(strcmp($$->children[0]->node_type, "float") == 0){
					$$->node_type = strdup(id_type);
					$$->children[0]->node_cast = strdup(id_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, id_type, RED, BLUE, $$->children[0]->node_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp(id_type, "float") == 0){
				if(strcmp($$->children[0]->node_type, "int") == 0){
					$$->node_type = strdup(id_type);
					$$->children[0]->node_cast = strdup(id_type);
				}else if(strcmp($$->children[0]->node_type, "float") == 0){
					$$->node_type = strdup(id_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, id_type, RED, BLUE, $$->children[0]->node_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp(id_type, "int list") == 0){
				if(strcmp($$->children[0]->node_type, "int list") == 0 || strcmp($$->children[0]->node_type, "nil") == 0){
					$$->node_type = strdup(id_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, id_type, RED, BLUE, $$->children[0]->node_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp(id_type, "float list") == 0){
				if(strcmp($$->children[0]->node_type, "float list") == 0 || strcmp($$->children[0]->node_type, "nil") == 0){
					$$->node_type = strdup(id_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, id_type, RED, BLUE, $$->children[0]->node_type, RED, WHITE);
					$$->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}
		}else{
			$$->node_type = strdup("invalid");
		}

		int id_scope = getScope(&symbolTable, &contextList, $1.lexeme_string);

		if(semantic_errors == 0){
            $$->tac_symbol = 1;
            sprintf(tac_instruction_value, "%s_%d", $1.lexeme_string, id_scope);
			$$->tac_value = strdup(tac_instruction_value);
            if($$->children[0]->tac_symbol == 0){
				if($$->children[0]->node_cast){
        			if(strcmp($$->children[0]->node_type, "int") == 0 && strcmp($$->children[0]->node_cast, "float") == 0){
						sprintf(tac_instruction, "inttofl $%d, $%d\nmov %s, $%d", $$->children[0]->tac_register, $$->children[0]->tac_register,
						$$->tac_value, $$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
        			}else if(strcmp($$->children[0]->node_type, "float") == 0 && strcmp($$->children[0]->node_cast, "int") == 0){
						sprintf(tac_instruction, "fltoint $%d, $%d\nmov %s, $%d", $$->children[0]->tac_register, $$->children[0]->tac_register,
						$$->tac_value, $$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
    			}else{
					sprintf(tac_instruction, "mov %s, $%d", $$->tac_value, $$->children[0]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}
            }else if($$->children[0]->tac_symbol == 1){
				if($$->children[0]->node_cast){
					if(strcmp($$->children[0]->node_type, "int") == 0 && strcmp($$->children[0]->node_cast, "float") == 0){
						sprintf(tac_instruction, "inttofl $1020, %s\nmov %s, $1020", $$->children[0]->tac_value, $$->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
        			}else if(strcmp($$->children[0]->node_type, "float") == 0 && strcmp($$->children[0]->node_cast, "int") == 0){
						sprintf(tac_instruction, "fltoint $1020, %s\nmov %s, $1020", $$->children[0]->tac_value, $$->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else{
					sprintf(tac_instruction, "mov %s, %s", $$->tac_value, $$->children[0]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}
            }
		}
		insertAstNode(&astList, $$);
	}
;

simple_exp:
	simple_exp LOGICAL_OR and_exp{
		char tac_instruction[500];
		$$ = createAstNode("simple exp", 1);
		$$->token_name = strdup($2.lexeme_string);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if(strcmp($$->children[0]->node_type, "int") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup("int");
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup("int");
				$$->children[0]->node_cast = strdup($$->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp($$->children[0]->node_type, "float") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup("int");
				$$->children[1]->node_cast = strdup($$->children[0]->node_type);
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup("int");
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
        }

		if(semantic_errors == 0){
			if($$->children[0]->tac_symbol == 0){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "or $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "or $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nor $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
					$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nor $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
					$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nor $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
					$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nor $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
					$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}else if($$->children[0]->tac_symbol == 1){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "or $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "or $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nor $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
					$$->children[1]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nor $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
					$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nor $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
					$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nor $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
					$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}
		}
		insertAstNode(&astList, $$);
	}
	| and_exp{
		$$ = $1;
	}
	| error {
		$$ = createAstNode("error", DEBUG_AST);
		$$->node_type = strdup("invalid");
		insertAstNode(&astList, $$);
		yyerrok;
	}
;

and_exp:
	and_exp LOGICAL_AND rel_exp{
		char tac_instruction[500];
		$$ = createAstNode("and exp", 1);
		$$->token_name = strdup($2.lexeme_string);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if(strcmp($$->children[0]->node_type, "int") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup("int");
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup("int");
				$$->children[0]->node_cast = strdup($$->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp($$->children[0]->node_type, "float") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup("int");
				$$->children[1]->node_cast = strdup($$->children[0]->node_type);
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup("int");
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
        }

		if(semantic_errors == 0){
			if($$->children[0]->tac_symbol == 0){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "and $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "and $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nand $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
					$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nand $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
					$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nand $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
					$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nand $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
					$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}else if($$->children[0]->tac_symbol == 1){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "and $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
					sprintf(tac_instruction, "and $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nor $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
					$$->children[1]->tac_register, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nor $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
					$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, $%d\nor $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
					$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
					sprintf(tac_instruction, "inttofl $1020, %s\nor $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
					$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}
		}
		insertAstNode(&astList, $$);
	}
	| rel_exp{
		$$ = $1;
	}
;

rel_exp:
	rel_exp RELATIONAL list_exp{
		char tac_instruction[500];
		$$ = createAstNode("rel exp", 1);
		$$->token_name = strdup($2.lexeme_string);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if(strcmp($$->children[0]->node_type, "int") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup("int");
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup("int");
				$$->children[0]->node_cast = strdup($$->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp($$->children[0]->node_type, "float") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup("int");
				$$->children[1]->node_cast = strdup($$->children[0]->node_type);
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup("int");
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp($$->children[0]->node_type, "int list") == 0){
			if(strcmp($$->children[1]->node_type, "nil") == 0){
				$$->node_type = strdup("int");
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else if(strcmp($$->children[0]->node_type, "float list") == 0){
			if(strcmp($$->children[1]->node_type, "nil") == 0){
				$$->node_type = strdup("int");
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else if(strcmp($$->children[0]->node_type, "nil") == 0){
			if(strcmp($$->children[1]->node_type, "int list") == 0 || strcmp($$->children[1]->node_type, "float list") == 0){
				$$->node_type = strdup("int");
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
        }

		if(semantic_errors == 0){
			if(strcmp($$->token_name, "<") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}else if(strcmp($$->token_name, "<=") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}else if(strcmp($$->token_name, ">") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, $%d, $%d\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, $%d, %s\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, $1020, $%d\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, $1020, %s\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, $%d, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, $%d, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, %s, $%d\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sleq $%d, %s, %s\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, $1020, $%d\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, $1020, %s\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsleq $%d, %s, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsleq $%d, %s, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}else if(strcmp($$->token_name, ">=") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, $%d, $%d\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, $%d, %s\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, $1020, $%d\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, $1020, %s\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, $%d, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, $%d, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, %s, $%d\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "slt $%d, %s, %s\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, $1020, $%d\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, $1020, %s\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nslt $%d, %s, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nslt $%d, %s, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}else if(strcmp($$->token_name, "==") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, $%d, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, $1020, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, $1020, %s\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, %s, $1020\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}else if(strcmp($$->token_name, "!=") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, $%d, $%d\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, $%d, %s\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, $1020, $%d\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, $1020, %s\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, $%d, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, $%d, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, %s, $%d\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "seq $%d, %s, %s\nnot $%d, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value,
						$$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, $1020, $%d\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, $1020, %s\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nseq $%d, %s, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nseq $%d, %s, $1020\nnot $%d, $%d\nfltoint $%d, $%d", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value, $$->tac_register, $$->tac_register, $$->tac_register, $$->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}
		}
		insertAstNode(&astList, $$);
	}
	| list_exp{
		$$ = $1;
	}
;

list_exp:
	sum_exp LIST_CONSTR list_exp{
		$$ = createAstNode("list exp", 1);
		$$->token_name = strdup($2.lexeme_string);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if(strcmp($$->children[0]->node_type, "int") == 0 || strcmp($$->children[0]->node_type, "float") == 0){
			if(strcmp($$->children[1]->node_type, "int list") == 0 || strcmp($$->children[1]->node_type, "float list") == 0 || strcmp($$->children[1]->node_type, "nil") == 0){
				$$->node_type = strdup($$->children[1]->node_type);
				if(strcmp($$->children[0]->node_type, "int") == 0 && strcmp($$->children[1]->node_type, "float list") == 0){
					$$->children[0]->node_cast = strdup("float");
				}else if(strcmp($$->children[0]->node_type, "float") == 0 && strcmp($$->children[1]->node_type, "int list") == 0){
					$$->children[0]->node_cast = strdup("int");
				}
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
		}
		insertAstNode(&astList, $$);
	}
	| sum_exp LIST_FUNC list_exp{
		char concat_type[15];
		$$ = createAstNode("list exp", 1);
		$$->token_name = strdup($2.lexeme_string);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if((strcmp($$->children[0]->node_type, "int") == 0 || strcmp($$->children[0]->node_type, "float") == 0) && $$->children[0]->is_function == 1 && $$->children[0]->function_args == 1){
			if((strcmp($$->children[1]->node_type, "int list") == 0 || strcmp($$->children[1]->node_type, "float list") == 0) && strcmp($2.lexeme_string, "<<") == 0){
				$$->node_type = strdup($$->children[1]->node_type);
			}else if((strcmp($$->children[1]->node_type, "int list") == 0 || strcmp($$->children[1]->node_type, "float list") == 0) && strcmp($2.lexeme_string, ">>") == 0){
				strcpy(concat_type, $$->children[0]->node_type);
				strcat(concat_type, " list");
				$$->node_type = strdup(concat_type);
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else{
			if($$->children[0]->is_function != 1){
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s. Left operand must be a function.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}else if($$->children[0]->function_args != 1){
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s. Left operand must have an unary parameter.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
			if(strcmp($$->children[0]->node_type, "int") != 0 && strcmp($$->children[0]->node_type, "float") != 0){
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}
		insertAstNode(&astList, $$);
	}
	| sum_exp{
		$$ = $1;
	}
;

sum_exp:
	sum_exp ADD mul_exp{
		char tac_instruction[500];
		$$ = createAstNode("sum exp", 1);
		$$->token_name = strdup($2.lexeme_string);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if(strcmp($$->children[0]->node_type, "int") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup($$->children[0]->node_type);
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup($$->children[1]->node_type);
				$$->children[0]->node_cast = strdup($$->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in additive operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp($$->children[0]->node_type, "float") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup($$->children[0]->node_type);
				$$->children[1]->node_cast = strdup($$->children[0]->node_type);
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup($$->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in additive operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in additive operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
        }

		if(semantic_errors == 0){
			if(strcmp($$->token_name, "+") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "add $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "add $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nadd $%d, $1020, $%d\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nadd $%d, $1020, %s\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nadd $%d, $%d, $1020\n", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nadd $%d, $%d, $1020\n", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "add $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "add $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nadd $%d, $1020, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nadd $%d, $1020, %s", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nadd $%d, %s, $1020", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nadd $%d, %s, $1020", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}else{
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sub $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sub $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsub $%d, $1020, $%d\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsub $%d, $1020, %s\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsub $%d, $%d, $1020\n", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsub $%d, $%d, $1020\n", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sub $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "sub $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsub $%d, $1020, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsub $%d, $1020, %s", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nsub $%d, %s, $1020", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nsub $%d, %s, $1020", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}
		}
		insertAstNode(&astList, $$);
	}
	| mul_exp{
		$$ = $1;
	}
;

mul_exp:
	mul_exp MUL unary_exp{
		char tac_instruction[500];
		$$ = createAstNode("mul exp", 1);
		$$->token_name = strdup($2.lexeme_string);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if(strcmp($$->children[0]->node_type, "int") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup($$->children[0]->node_type);
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup($$->children[1]->node_type);
				$$->children[0]->node_cast = strdup($$->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in multiplicative operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp($$->children[0]->node_type, "float") == 0){
            if(strcmp($$->children[1]->node_type, "int") == 0){
                $$->node_type = strdup($$->children[0]->node_type);
				$$->children[1]->node_cast = strdup($$->children[0]->node_type);
            }else if(strcmp($$->children[1]->node_type, "float") == 0){
                $$->node_type = strdup($$->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in multiplicative operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
				$$->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in multiplicative operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, $2.line, $2.column, YELLOW, $2.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, BLUE, $$->children[1]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
        }

		if(semantic_errors == 0){
			if(strcmp($$->token_name, "*") == 0){
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "mul $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "mul $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nmul $%d, $1020, $%d\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nmul $%d, $1020, %s\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nmul $%d, $%d, $1020\n", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nmul $%d, $%d, $1020\n", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "mul $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "mul $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nmul $%d, $1020, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nmul $%d, $1020, %s", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\nmul $%d, %s, $1020", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\nmul $%d, %s, $1020", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}else{
				if($$->children[0]->tac_symbol == 0){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "div $%d, $%d, $%d", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "div $%d, $%d, %s", $$->tac_register, $$->children[0]->tac_register, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\ndiv $%d, $1020, $%d\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\ndiv $%d, $1020, %s\n", $$->children[0]->tac_register, $$->tac_register, 
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\ndiv $%d, $%d, $1020\n", $$->children[1]->tac_register, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\ndiv $%d, $%d, $1020\n", $$->children[1]->tac_value, $$->tac_register, 
						$$->children[0]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}else if($$->children[0]->tac_symbol == 1){
					$$->tac_register = register_index++;
					$$->tac_symbol = 0;
					if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "div $%d, %s, $%d", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast == NULL && $$->children[1]->node_cast == NULL){
						sprintf(tac_instruction, "div $%d, %s, %s", $$->tac_register, $$->children[0]->tac_value, $$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\ndiv $%d, $1020, $%d", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_register);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[0]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\ndiv $%d, $1020, %s", $$->children[0]->tac_value, $$->tac_register,
						$$->children[1]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 0 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, $%d\ndiv $%d, %s, $1020", $$->children[1]->tac_register, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}else if($$->children[1]->tac_symbol == 1 && $$->children[1]->node_cast){
						sprintf(tac_instruction, "inttofl $1020, %s\ndiv $%d, %s, $1020", $$->children[1]->tac_value, $$->tac_register,
						$$->children[0]->tac_value);
						$$->tac_code_item = strdup(tac_instruction);
					}
				}
			}
		}
		insertAstNode(&astList, $$);
	}
	| unary_exp{
		$$ = $1;
	}
;

unary_exp:
	factor{
		$$ = $1;
	}
	| LIST_OP unary_exp{
		$$ = createAstNode("unary exp", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->children[0] = $2;
		if(strcmp($$->children[0]->node_type, "int list") == 0){
			$$->node_type = strdup("int");
		}else if(strcmp($$->children[0]->node_type, "float list") == 0){
			$$->node_type = strdup("float");
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Unary type error in operation %s%s%s to %s%s%s expression.%s\n", 
			RED, $1.line, $1.column, YELLOW, $1.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
		}
		insertAstNode(&astList, $$);
	}
	| LIST_DESTR unary_exp{
		$$ = createAstNode("unary exp", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->children[0] = $2;
		if(strcmp($$->children[0]->node_type, "int list") == 0 || strcmp($$->children[0]->node_type, "float list") == 0){
			$$->node_type = strdup($$->children[0]->node_type);
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Unary type error in operation %s%s%s to %s%s%s expression.%s\n", 
			RED, $1.line, $1.column, YELLOW, $1.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
		}
		insertAstNode(&astList, $$);
	}
	| OP_OVERLOAD unary_exp{
		char tac_instruction[500];
		$$ = createAstNode("unary exp", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->children[0] = $2;
		$$->node_type = strdup($$->children[0]->node_type);
		if((strcmp($$->node_type, "int") == 0 || strcmp($$->node_type, "float") == 0) && semantic_errors == 0){
			if($$->children[0]->tac_symbol == 0){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				sprintf(tac_instruction, "not $%d, $%d", $$->tac_register, $$->children[0]->tac_register);
				$$->tac_code_item = strdup(tac_instruction);
			}else if($$->children[0]->tac_symbol == 1){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				sprintf(tac_instruction, "not $%d, %s", $$->tac_register, $$->children[0]->tac_value);
				$$->tac_code_item = strdup(tac_instruction);
			}
		}
		insertAstNode(&astList, $$);
	}
	| ADD unary_exp{
		char tac_instruction[500];
		$$ = createAstNode("signed unary exp", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->children[0] = $2;
		if(strcmp($$->children[0]->node_type, "int") == 0 || strcmp($$->children[0]->node_type, "float") == 0){
			$$->node_type = strdup($$->children[0]->node_type);
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Unary type error in assigning %s%s%s to %s%s%s expression.%s\n", 
			RED, $1.line, $1.column, YELLOW, $1.lexeme_string, RED, BLUE, $$->children[0]->node_type, RED, WHITE);
			$$->node_type = strdup("undefined");
			semantic_errors+= 1;
		}

		if(semantic_errors == 0){
			if($$->children[0]->tac_symbol == 0){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				if(strcmp($1.lexeme_string, "+") == 0){
					sprintf(tac_instruction, "mov $%d, $%d", $$->tac_register, $$->children[0]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}else{
					sprintf(tac_instruction, "minus $%d, $%d", $$->tac_register, $$->children[0]->tac_register);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}else if($$->children[0]->tac_symbol == 1){
				$$->tac_register = register_index++;
				$$->tac_symbol = 0;
				if(strcmp($1.lexeme_string, "+") == 0){
					sprintf(tac_instruction, "mov $%d, %s", $$->tac_register, $$->children[0]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}else{
					sprintf(tac_instruction, "minus $%d, %s", $$->tac_register, $$->children[0]->tac_value);
					$$->tac_code_item = strdup(tac_instruction);
				}
			}
		}
		insertAstNode(&astList, $$);
	}
;

factor:
	ID{
		char id_type[15];
		char tac_instruction[500];
		strcpy(id_type, getContext(&symbolTable, &contextList, $1.lexeme_string, $1.line, $1.column, &semantic_errors));
		$$ = createAstNode("id", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->token_print = strdup(id_type);
		$$->node_type = strdup(id_type);
		$$->token_line = $1.line;
		$$->token_column = $1.column;
		$$->tac_symbol = 1;
		int id_scope = getScope(&symbolTable, &contextList, $1.lexeme_string);
		$$->is_function = checkFunctionID(&symbolTable, $1.lexeme_string, id_scope);
		if($$->is_function == 1)
			$$->function_args = getFunctionArgs(&symbolTable, $1.lexeme_string, id_scope);
		sprintf(tac_instruction, "%s_%d", $1.lexeme_string, id_scope);
		$$->tac_value = strdup(tac_instruction);
		insertAstNode(&astList, $$);
	}
	| '(' simple_exp ')'{
		$$ = $2;
	}
	| func_call{
		$$ = $1;
	}
	| constant{
		$$ = $1;
	}
;

func_call:
	ID '(' func_params ')'{
		char func_id[200];
		char func_type[15];
		strcpy(func_type, getContext(&symbolTable, &contextList, $1.lexeme_string, $1.line, $1.column, &semantic_errors));
		$$ = createAstNode("func call", 1);
		strcpy(func_id, $1.lexeme_string);
		strcat(func_id, "()");
		$$->token_name = strdup(func_id);
		$$->token_print = strdup(func_type);
		$$->node_type = strdup(func_type);
		$$->token_line = $1.line;
		$$->token_column = $1.column;
		$$->children[0] = $3;
		$$->tac_register = register_index++;
		$$->tac_symbol = 0;
		checkFunctionCall($$, &symbolTable, &contextList, &parameterList, $1.lexeme_string, $1.line, $1.column, func_params_counter, &semantic_errors);
		insertAstNode(&astList, $$);
		func_params_counter = 0;
	}
	| ID '(' ')'{
		char func_id[200];
		char func_type[15];
		char tac_instruction[500];
		strcpy(func_type, getContext(&symbolTable, &contextList, $1.lexeme_string, $1.line, $1.column, &semantic_errors));
		$$ = createAstNode("func call", 1);
		strcpy(func_id, $1.lexeme_string);
		strcat(func_id, "()");
		$$->token_name = strdup(func_id);
		$$->token_print = strdup(func_type);
		$$->node_type = strdup(func_type);
		$$->token_line = $1.line;
		$$->token_column = $1.column;
		$$->tac_register = register_index++;
		$$->tac_symbol = 0;
		int func_scope = getScope(&symbolTable, &contextList, $1.lexeme_string);
		sprintf(tac_instruction, "call _%s_%d, 0\npop $%d", $1.lexeme_string, func_scope, $$->tac_register);
		$$->tac_code_item = strdup(tac_instruction);
		insertAstNode(&astList, $$);
	}
;

func_params:
	simple_exp{
		int literal = 0;
		func_params_counter+= 1;
		$$ = createAstNode("func params", 1);
		$$->children[0] = $1;
		if(strcmp($$->children[0]->node_name, "int constant") == 0 || strcmp($$->children[0]->node_name, "real constant") == 0){
			literal = 1;
			insertParameter($$->children[0]->tac_value, $$->children[0]->node_type, literal, &parameterList);
		}else{
			insertParameter($$->children[0]->token_name, $$->children[0]->node_type, literal, &parameterList);
		}
		insertAstNode(&astList, $$);
	}
	| func_params ',' simple_exp{
		int literal = 0;
		func_params_counter+= 1;
		$$ = createAstNode("func params", 1);
		$$->children[0] = $1;
		$$->children[1] = $3;
		if(strcmp($$->children[1]->node_name, "int constant") == 0 || strcmp($$->children[1]->node_name, "real constant") == 0){
			literal = 1;
			insertParameter($$->children[1]->tac_value, $$->children[1]->node_type, literal, &parameterList);
		}else{
			insertParameter($$->children[1]->token_name, $$->children[1]->node_type, literal, &parameterList);
		}
		insertAstNode(&astList, $$);
	}
;

constant:
	INTEGER{
		$$ = createAstNode("int constant", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->token_print = strdup("int");
		$$->node_type = strdup("int");
		$$->token_line = $1.line;
		$$->token_column = $1.column;
		$$->tac_value = strdup($1.lexeme_string);
		$$->tac_symbol = 1;
		insertAstNode(&astList, $$);
	}
	| REAL{
		$$ = createAstNode("real constant", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->token_print = strdup("float");
		$$->node_type = strdup("float");
		$$->token_line = $1.line;
		$$->token_column = $1.column;
		$$->tac_value = strdup($1.lexeme_string);
		$$->tac_symbol = 1;
		insertAstNode(&astList, $$);
	}
	| NIL_CONSTANT{
		$$ = createAstNode("nil constant", 1);
		$$->token_name = strdup($1.lexeme_string);
		$$->token_print = strdup("nil");
		$$->node_type = strdup("nil");
		$$->token_line = $1.line;
		$$->token_column = $1.column;
		insertAstNode(&astList, $$);
	}
;

%%

void yyerror(const char *error_msg){
	int column = num_chars - yylval.lexeme.length;
	printf("%sLine:%d\tColumn:%d\t%s%s\n", RED, num_lines, column, error_msg, WHITE);
	syntax_errors+= 1;
}


int main(int argc, char *argv[]){
	setupContext(&contextList);
	
	if(argc == 2){
		FILE *fp = fopen(argv[1], "r");
		if(fp){
			yyin = fp;
			yyparse();
		}else{
			printf("%sError reading file location, please insert a valid path.%s\n", RED, WHITE);
			return ERROR;
		}
	}else{
		printf("%sError calling analyzer. You must only insert the file and path names as arguments.%s\n", RED, WHITE);
		return ERROR;
	}
	if(!error_comm)
		fclose(yyin);

	if(!hasMainFunction(&symbolTable)){
		printf("%sLine:?\tColumn:?\tSemantic error! Undefined reference to %s`main()`%s function.%s\n", RED, PURPLE, RED, WHITE);
		semantic_errors+= 1;
	}

	if(syntax_errors == 0){
		if(semantic_errors == 0)
			checkConstructorList(&root);
		printAST(&root);
	}else{
		printf("\n%s~> AST tree will not be printed, due to syntax error(s).%s\n", RED, WHITE);
	}

	printTable(&symbolTable);

	if(lexical_errors == 0)
		printf("\n%sLexical analysis finished without error(s).%s", GREEN, WHITE);
	else
		printf("\n%sLexical analysis finished with %d error(s).%s", RED, lexical_errors, WHITE);
		
	if(syntax_errors == 0)
		printf("\n%sSyntax analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("\n%sSyntax analysis finished with %d error(s).%s\n", RED, syntax_errors, WHITE);

	if(semantic_errors == 0)
		printf("%sSemantic analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("%sSemantic analysis finished with %d error(s).%s\n", RED, semantic_errors, WHITE);

	if(lexical_errors == 0 && syntax_errors == 0 && semantic_errors == 0){
		generateTAC(&root, argv[1], has_string);
	}else{
		printTACerror(lexical_errors, syntax_errors, semantic_errors);
	}

	freeNode(&root);
	freeSymbols(&symbolTable);
	freeContextList(&contextList);
	freeParameterList(&parameterList);	// avoid mem leak caused by func params semantic errors.

	if(!error_comm)
		yylex_destroy();
	
	return 0;
}