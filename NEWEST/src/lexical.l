%option noinput nounput noyywrap
%option outfile="src/lex.yy.c"

%{
    #include <stdio.h>
    #include <stdlib.h>
	#include <string.h>
	#include "../lib/syntax.tab.h"
	#include "../lib/structures.h"
	#define ERROR -1
	#define RED "\x1b[31m"
	#define WHITE "\x1b[0m"
	#define GREEN "\x1b[32m"
	
	int num_lines = 1;
	int num_chars = 1;
	int multiline_height = 0;
	int multiline_start;
	int last_scope = 0;
	int func_context = 0;
	extern Context contextList;

	void updateLine();
	void updateColumn(int token_length);
	void printLexeme(char *token_id, char *token_text);
	void setupLexeme(char *token_text);
	int printCharacterError(char *token_id, char *token_text);
	void printMultilineError(int multiline_line, int multiline_column);
%}

comment_line			"//".*
delim					[ \t\r]
ws						{delim}+
newline					[\n]
brace_opening			"{"
brace_closing			"}"
parenthese_opening		"("
parenthese_closing		")"
letter					[A-Za-z_]
digit					[0-9]
keywords				"if"|"else"|"for"|"return"
simple_data_type		"int"|"float"
compound_data_type		"list"
input_command			"read"
output_command			"write"|"writeln"
nil_constant			"NIL"
id						{letter}({letter}|{digit})*
integer_number			-?{digit}+
real_number				-?{integer_number}(\.{digit}+)(E[+-]?{digit}+)?
arithmetic_op_mul 		"*"|"/"
arithmetic_op_add		"+"|"-"
relational_op		    "<"|"<="|">"|">="|"=="|"!="
logical_op				"||"|"&&"
assignment				"="
separator				","
flow_control			";"
list_constructor		":"
list_operator			"?"
list_destructor			"%"
list_functions			">>"|"<<"
string_literal			\"([^"\\\n]|\\.)*\"
operator_overload		"!"

%x comment
%%

"/*"         		{BEGIN(comment); multiline_start = num_chars; num_chars+=yyleng;}

    <comment>[^*\n]*		{}					/* ignora qualquer coisa que não seja '*' */
    <comment>"*"+[^*/\n]*	{}					/* ignora '*' não seguido por '/' */
    <comment>[\n]           {updateLine(); multiline_height+= 1;}
    <comment>"*"+"/"        {BEGIN(INITIAL); multiline_height = 0;}
	<comment><<EOF>>		{printMultilineError(num_lines - multiline_height, multiline_start); return ERROR_COMM;}

{comment_line}			{
							updateColumn(yyleng);
						}

{ws}					{	
							updateColumn(yyleng);
						}

{newline}				{
							updateLine();
						}

{brace_opening}			{
							//printLexeme("Opening brace", yytext);
							setupLexeme(yytext);
							if(func_context)
								insertScope(last_scope, &contextList);
							else
								insertScope(++last_scope, &contextList);
							func_context = 0;
							updateColumn(yyleng);
							return '{';
						}
					
{brace_closing}			{
							//printLexeme("Closing brace", yytext);
							setupLexeme(yytext);
							removeScope(&contextList);
							updateColumn(yyleng);
							return '}';
						}
					
{parenthese_opening}	{
							//printLexeme("Opening parenthese", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return '(';
						}
					
{parenthese_closing}	{
							//printLexeme("Closing parenthese", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return ')';
						}

{keywords}				{
							//printLexeme("Reserved keyword", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);

							if(strcmp(yytext, "if") == 0)
								return IF;
							else if(strcmp(yytext, "else") == 0)
								return ELSE;
							else if(strcmp(yytext, "for") == 0)
								return FOR;
							else
								return RETURN;
						}

{simple_data_type} 		{
							//printLexeme("Data type", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return SIMPLE_TYPE;
						}

{compound_data_type}	{
							//printLexeme("Compound data type", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return COMPOUND_TYPE;
						}
						
{nil_constant} 			{
							//printLexeme("Nil constant", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return NIL_CONSTANT;
						}
						
{input_command}			{
							//printLexeme("Input command", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return INPUT;
						}

{output_command}		{
							//printLexeme("Output command", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return OUTPUT;
						}

{id} 					{
							//printLexeme("Identifier", yytext);
							setupLexeme(yytext);
							yylval.lexeme.scope = contextList.first->value;
							updateColumn(yyleng);
							return ID;
						}

{integer_number} 		{
							//printLexeme("Integer number", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return INTEGER;
						}

{real_number} 			{
							//printLexeme("Real number", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return REAL;
						}

{list_constructor} 		{
							//printLexeme("List constructor", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return LIST_CONSTR;
						}
						
{list_operator} 		{
							//printLexeme("List operator", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return LIST_OP;
						}
						
{list_destructor} 		{
							//printLexeme("List destructor", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return LIST_DESTR;
						}
						
{list_functions} 		{
							//printLexeme("List function", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return LIST_FUNC;
						}
						
{arithmetic_op_mul} 	{
							//printLexeme("Arithmetic operator (mul/div)", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return MUL;
						}

{arithmetic_op_add} 	{
							//printLexeme("Arithmetic operator (add/sub)", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return ADD;
						}

{relational_op} 		{
							//printLexeme("Relational operator", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return RELATIONAL;
						}
						
{logical_op} 			{
							//printLexeme("Logical operator", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							if(strcmp(yytext, "||") == 0)
								return LOGICAL_OR;
							else
								return LOGICAL_AND;
						}

{assignment} 			{
							//printLexeme("Assignment", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return '=';
						}

{separator} 			{
							//printLexeme("Comma", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return ',';
						}

{flow_control} 			{
							//printLexeme("Semicolon", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return ';';
						}	

{string_literal}		{
							//printLexeme("String literal", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return STRING;
						}

{operator_overload}	{
							//printLexeme("Logical or list related operator", yytext);
							setupLexeme(yytext);
							updateColumn(yyleng);
							return OP_OVERLOAD;
						}
						
.						{
							if(printCharacterError("Unrecognized character", yytext) == -1)	// Caso aspas dupla
								return ERROR_STR;
							updateColumn(yyleng);
							return ERROR_CHAR;
						}

%%

void updateLine(){
	num_lines+= 1;
	num_chars = 1;	// Reset column
}

void updateColumn(int token_length){
	num_chars+= token_length;
}

void printLexeme(char *token_id, char *token_text){
	printf("Line:%d\tColumn:%d\t%s found: %s%s%s\n", num_lines, num_chars, token_id, GREEN, token_text, WHITE);
}

int printCharacterError(char *token_id, char *token_text){
	/* Caso aspas dupla seja tratada por printCharacterError, significa que a string não finalizou na mesma linha, ou seja, erro léxico.	*/

	if('"' == *token_text){
		printf("%sLine:%d\tColumn:%d\tLexical error! String initialized, but not finished. Expected `\"` at end.%s\n", 
	RED, num_lines, num_chars, WHITE);
		return -1;
	}

	printf("%sLine:%d\tColumn:%d\tLexical error! %s: %s%s\n", RED, num_lines, num_chars, token_id, token_text, WHITE);
	return 0;
}

void printMultilineError(int multiline_line, int multiline_column){
	printf("%sLine:%d\tColumn:%d\tLexical error! Multiline comment initialized, but not finished. Expected `*/` at end.%s\n", 
	RED, multiline_line, multiline_column, WHITE);
}

void setupLexeme(char *token_text){
	strcpy(yylval.lexeme.lexeme_string, token_text);
	yylval.lexeme.line = num_lines;
	yylval.lexeme.column = num_chars;
	yylval.lexeme.length = yyleng;
}

/*
int main(int argc, char *argv[]){
	if(argc == 2){
		FILE *fp = fopen(argv[1], "r");
		if(fp){
			yyin = fp;
			yylex();
		}else{
			printf("%sError reading file location, please insert a valid path.%s\n", RED, WHITE);
			return ERROR;
		}
	}else{
		printf("%sError calling lexical analyzer. You must only insert the file and path names as arguments.%s\n", RED, WHITE);
		return ERROR;
	}
	fclose(yyin);
	yylex_destroy();
	return 0;
}
*/