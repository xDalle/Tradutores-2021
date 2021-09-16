%defines "lib/syntax.tab.h"
%define lr.type canonical-lr
%define parse.error verbose

%debug

%{
	#define RED "\x1b[31m"
	#define WHITE "\x1b[0m"
	#define GREEN "\x1b[32m"
	#define ERROR -1

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
	static int count_errors = 0;
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
%type <ast> params
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
		root = *createAstNode("initial", 0);	// non-printable
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
		$$ = createAstNode("declaration list", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

decl:
	var_declaration{
		$$ = createAstNode("decl", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| func_definition{
		$$ = createAstNode("decl", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| error {
		$$ = createAstNode("error", 0);
		insertAstNode(&astList, $$);
		printf("a\n");
	}
;

var_definition:
	SIMPLE_TYPE ID{
		char concat_type[200];
		int var_type = 1;
		insertSymbol(&symbolTable, $2.lexeme_string, $1.lexeme_string, var_type, $1.line, $1.column, $1.scope);
		$$ = createAstNode("var definition", 1);
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		$$->token_name = strdup(concat_type);
		insertAstNode(&astList, $$);
	}
	| SIMPLE_TYPE COMPOUND_TYPE ID{
		char concat_type[200];
		int var_type = 1;
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		insertSymbol(&symbolTable, $3.lexeme_string, concat_type, var_type, $1.line, $1.column, $1.scope);
		$$ = createAstNode("var definition", 1);
		strcat(concat_type, " ");
		strcat(concat_type, $3.lexeme_string);
		$$->token_name = strdup(concat_type);
		insertAstNode(&astList, $$);
	}
;

var_declaration:
	SIMPLE_TYPE ID ';'{
		char concat_type[200];
		int var_type = 1;
		insertSymbol(&symbolTable, $2.lexeme_string, $1.lexeme_string, var_type, $1.line, $1.column, $1.scope);
		$$ = createAstNode("var declaration", 1);
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		$$->token_name = strdup(concat_type);
		insertAstNode(&astList, $$);
	}
	| SIMPLE_TYPE COMPOUND_TYPE ID ';'{
		char concat_type[200];
		int var_type = 1;
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		insertSymbol(&symbolTable, $3.lexeme_string, concat_type, var_type, $1.line, $1.column, $1.scope);
		$$ = createAstNode("var declaration", 1);
		strcat(concat_type, " ");
		strcat(concat_type, $3.lexeme_string);
		$$->token_name = strdup(concat_type);
		insertAstNode(&astList, $$);
	}
;	

func_definition:
	func_declaration '(' params.opt ')' stmts {
		$$ = createAstNode("function definition", 0);
		$$->children[0] = $1;
		$$->children[1] = $3;
		$$->children[2] = $5;
		insertAstNode(&astList, $$);
	}
;

params.opt:
	params{
		$$ = createAstNode("params optional", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| %empty{
		$$ = createAstNode("params optional empty", 0); 
		insertAstNode(&astList, $$);
	}
;

func_declaration:
	SIMPLE_TYPE ID{
		char concat_type[200];
		int func_type = 0;
		insertSymbol(&symbolTable, $2.lexeme_string, $1.lexeme_string, func_type, $1.line, $1.column, $1.scope);
		$$ = createAstNode("function declaration", 1);
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		$$->token_name = strdup(concat_type);
		insertAstNode(&astList, $$);
	}
	| SIMPLE_TYPE COMPOUND_TYPE ID{
		char concat_type[200];
		int func_type = 0;
		strcpy(concat_type, $1.lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, $2.lexeme_string);
		insertSymbol(&symbolTable, $3.lexeme_string, concat_type, func_type, $1.line, $1.column, $1.scope);
		$$ = createAstNode("function declaration", 1);
		strcat(concat_type, " ");
		strcat(concat_type, $3.lexeme_string);
		$$->token_name = strdup(concat_type);
		insertAstNode(&astList, $$);
	}
;

params:
	param_list{
		$$ = createAstNode("params", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

param_list:
	param{
		$$ = createAstNode("param list", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| param_list ',' param{
		$$ = createAstNode("param list", 0);
		$$->children[0] = $1;
		$$->children[1] = $3;
		insertAstNode(&astList, $$);
	}
;

param:
	var_definition{
		$$ = createAstNode("param", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

stmts:
	'{' stmt_list.opt '}'{
		$$ = createAstNode("stmts", 1);
		$$->children[0] = $2;
		insertAstNode(&astList, $$);
	}
;

stmt_list.opt:
	stmt_list{
		$$ = createAstNode("stmt list optional", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| %empty {
		$$ = createAstNode("stmt list empty", 0); 
		insertAstNode(&astList, $$);
	}
;

stmt_list:
	stmt_list stmt.item{
		$$ = createAstNode("stmt list", 0);
		$$->children[0] = $1;
		$$->children[1] = $2;
		insertAstNode(&astList, $$);
	}
	| stmt.item{
		$$ = createAstNode("stmt list", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

stmt.item:
	stmt{
		$$ = createAstNode("stmt item", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| var_declaration{
		$$ = createAstNode("stmt item", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

stmt:
	return_stmt{
		$$ = createAstNode("stmt", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| select_stmt{
		$$ = createAstNode("stmt", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| iter_stmt{
		$$ = createAstNode("stmt", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| io_stmt{
		$$ = createAstNode("stmt", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| exp_stmt{
		$$ = createAstNode("stmt", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| stmts{
		$$ = createAstNode("stmt", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

select_stmt:
	IF '(' simple_exp ')' stmt %prec THEN{
		$$ = createAstNode("select stmt", 1);
		$$->children[0] = $3;
		$$->children[1] = $5;
		insertAstNode(&astList, $$);
	}
	| IF '(' simple_exp ')' stmt ELSE stmt{
		$$ = createAstNode("select stmt", 1);
		$$->children[0] = $3;
		$$->children[1] = $5;
		$$->children[2] = $7;
		insertAstNode(&astList, $$);
	}
;

iter_stmt:
	FOR '(' exp ';' simple_exp ';' exp ')' stmt{
		$$ = createAstNode("iter stmt", 1);
		$$->children[0] = $3;
		$$->children[1] = $5;
		$$->children[2] = $7;
		$$->children[3] = $9;
		insertAstNode(&astList, $$);
	}
;

exp_stmt:
	exp ';'{
		$$ = createAstNode("expression", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

exp:
	assign_exp{
		$$ = createAstNode("exp stmt", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| simple_exp{
		$$ = createAstNode("exp stmt", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

return_stmt:
	RETURN exp ';'{
		$$ = createAstNode("return stmt", 1);
		$$->children[0] = $2;
		insertAstNode(&astList, $$);
	}
;

io_stmt:
	in_stmt{
		$$ = createAstNode("in/out stmt", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| out_stmt{
		$$ = createAstNode("in/out stmt", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

in_stmt:
	INPUT '(' ID ')' ';'{
		char input_type[200];
		$$ = createAstNode("input stmt", 1);
		strcpy(input_type, $1.lexeme_string);
		strcat(input_type, " (");
		strcat(input_type, $3.lexeme_string);
		strcat(input_type, ")");
		$$->token_name = strdup(input_type);
		insertAstNode(&astList, $$);
	}
;

out_stmt:
	OUTPUT '(' STRING ')' ';'{
		char output_type[200];
		$$ = createAstNode("output stmt", 1);
		strcpy(output_type, $1.lexeme_string);
		strcat(output_type, " (");
		strcat(output_type, $3.lexeme_string);
		strcat(output_type, ")");
		$$->token_name = strdup(output_type);
		insertAstNode(&astList, $$);
	}
	| OUTPUT '(' exp ')' ';'{
		$$ = createAstNode("output stmt", 1);
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
;

assign_exp:
	ID '=' exp{
		$$ = createAstNode("assign exp", 1);
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
;

simple_exp:
	simple_exp LOGICAL_OR and_exp{
		char operation[200];
		$$ = createAstNode("simple exp", 1);
		strcpy(operation, $2.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $1;
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
	| and_exp{
		$$ = createAstNode("simple exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

and_exp:
	and_exp LOGICAL_AND rel_exp{
		char operation[200];
		$$ = createAstNode("and exp", 1);
		strcpy(operation, $2.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $1;
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
	| rel_exp{
		$$ = createAstNode("and exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

rel_exp:
	rel_exp RELATIONAL list_exp{
		char operation[200];
		$$ = createAstNode("rel exp", 1);
		strcpy(operation, $2.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $1;
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
	| list_exp{
		$$ = createAstNode("rel exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

list_exp:
	sum_exp LIST_CONSTR list_exp{
		char operation[200];
		$$ = createAstNode("list exp", 1);
		strcpy(operation, $2.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $1;
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
	| sum_exp LIST_FUNC list_exp{
		char operation[200];
		$$ = createAstNode("list exp", 1);
		strcpy(operation, $2.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $1;
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
	| sum_exp{
		$$ = createAstNode("list exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

sum_exp:
	sum_exp ADD mul_exp{
		char operation[200];
		$$ = createAstNode("sum exp", 1);
		strcpy(operation, $2.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $1;
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
	| mul_exp{
		$$ = createAstNode("sum exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

mul_exp:
	mul_exp MUL unary_exp{
		char operation[200];
		$$ = createAstNode("mul exp", 1);
		strcpy(operation, $2.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $1;
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
	| unary_exp{
		$$ = createAstNode("mul exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

unary_exp:
	factor{
		$$ = createAstNode("unary exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| LIST_OP unary_exp{
		char operation[200];
		$$ = createAstNode("unary exp", 1);
		strcpy(operation, $1.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $2;
		insertAstNode(&astList, $$);
	}
	| LIST_DESTR unary_exp{
		char operation[200];
		$$ = createAstNode("unary exp", 1);
		strcpy(operation, $1.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $2;
		insertAstNode(&astList, $$);
	}
	| OP_OVERLOAD unary_exp{
		char operation[200];
		$$ = createAstNode("unary exp", 1);
		strcpy(operation, $1.lexeme_string);
		$$->token_name = strdup(operation);
		$$->children[0] = $2;
		insertAstNode(&astList, $$);
	}
	| ADD unary_exp{
		char signal_type[200];
		strcpy(signal_type, "signed unary exp");
		strcat(signal_type, " (");
		strcat(signal_type, RED);
		strcat(signal_type, $1.lexeme_string);
		strcat(signal_type, WHITE);
		strcat(signal_type, ")");
		$$ = createAstNode(signal_type, 1);
		$$->children[0] = $2;
		insertAstNode(&astList, $$);
	}
;

factor:
	ID{
		char id_type[200];
		$$ = createAstNode("factor exp", 1);
		strcpy(id_type, $1.lexeme_string);
		$$->token_name = strdup(id_type);
		insertAstNode(&astList, $$);
	}
	| '(' simple_exp ')'{
		$$ = createAstNode("factor exp", 0);
		$$->children[0] = $2;
		insertAstNode(&astList, $$);
	}
	| func_call{
		$$ = createAstNode("factor exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| constant{
		$$ = createAstNode("factor exp", 0);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
;

func_call:
	ID '(' func_params ')'{
		$$ = createAstNode("func call", 1);
		$$->children[0] = $3;
		insertAstNode(&astList, $$);
	}
;

func_params:
	simple_exp{
		$$ = createAstNode("func params", 1);
		$$->children[0] = $1;
		insertAstNode(&astList, $$);
	}
	| func_params ',' simple_exp{
		$$ = createAstNode("func params", 1);
		$$->children[0] = $1;
		$$->children[1] = $3;
		insertAstNode(&astList, $$);
	}
	| %empty{
		$$ = createAstNode("func params empty", 0); 
		insertAstNode(&astList, $$);
	}
;

constant:
	INTEGER{
		char int_type[200];
		$$ = createAstNode("int constant", 1);
		strcpy(int_type, $1.lexeme_string);
		$$->token_name = strdup(int_type);
		insertAstNode(&astList, $$);
	}
	| REAL{
		char real_type[200];
		$$ = createAstNode("real constant", 1);
		strcpy(real_type, $1.lexeme_string);
		$$->token_name = strdup(real_type);
		insertAstNode(&astList, $$);
	}
	| NIL_CONSTANT{
		char nil_type[200];
		$$ = createAstNode("nil constant", 1);
		strcpy(nil_type, $1.lexeme_string);
		$$->token_name = strdup(nil_type);
		insertAstNode(&astList, $$);
	}
;

%%

void yyerror(const char *error_msg){
	int column = num_chars - yylval.lexeme.length;
	printf("%sLine:%d\tColumn:%d\t%s%s\n", RED, num_lines, column, error_msg, WHITE);
	count_errors+= 1;
}


int main(int argc, char *argv[]){
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
	fclose(yyin);

	if(count_errors == 0)
		printAST(&root);
	else
		printf("%s~ AST tree will not be printed, due to syntax error.%s\n", RED, WHITE);
	printTable(&symbolTable);

	freeNode(&root);
	freeSymbols(&symbolTable);
	yylex_destroy();
	if(count_errors == 0){
		printf("%sSyntax analysis finished without errors.%s\n", GREEN, WHITE);
	}else{
		printf("%sSyntax analysis finished with %d errors.%s\n", RED, count_errors, WHITE);
	}
	return 0;
}