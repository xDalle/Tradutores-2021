%option noinput nounput noyywrap
%option outfile="src/lex.yy.c"

%{
    #include<stdio.h>
    #include<stdlib.h>
	
	#define ERROR -1
	#define RED "\x1b[31m"
	#define WHITE "\x1b[0m"
	#define GREEN "\x1b[32m"
	
	static int num_lines = 1;
	static int num_chars = 1;
	int multiline_height = 0;
	int multiline_start;

	void updateLine();
	void updateColumn(int token_length);
	void printLexeme(char *token_id, char *token_text);
	int printCharacterError(char *token_id, char *token_text);
	void printMultilineError(int multiline_line, int multiline_column);
%}

comment_line			"//".*
delim					[ \t\r]
ws						{delim}+
newline					[\n]
brace_opening			"{"
brace_closing			"}"
bracket_opening			"["
bracket_closing			"]"
parenthese_opening		"("
parenthese_closing		")"
letter					[A-Za-z_]
digit					[0-9]
keywords				"if"|"else"|"for"|"return"
data_type				"int list"|"int"|"float list"|"float"
input_command			"read"
output_command			"write"|"writeln"
nil_constant			"NIL"
id						{letter}({letter}|{digit})*
integer_number			-?{digit}+
real_number				-?{integer_number}(\.{digit}+)(E[+-]?{digit}+)?
arithmetic_operators	"+"|"-"|"*"|"/"
relational_operators	"<"|"<="|">"|">="|"=="|"!="
logical_operators		"||"|"&&"
assignment				"="
separator				","
flow_control			";"
list_constructor		":"
list_operator			"?"
list_destructor			"%"
list_functions			">>"|"<<"
string_literal			\"([^"\\\n]|\\.)*\"
ambiguous_operator		"!"

%x comment
%%

"/*"         		{BEGIN(comment); multiline_start = num_chars; num_chars+=yyleng;}

    <comment>[^*\n]*		{}					/* ignora qualquer coisa que não seja '*' */
    <comment>"*"+[^*/\n]*	{}					/* ignora '*' não seguido por '/' */
    <comment>[\n]           {updateLine(); multiline_height+= 1;}
    <comment>"*"+"/"        {BEGIN(INITIAL); multiline_height = 0;}
	<comment><<EOF>>		{printMultilineError(num_lines - multiline_height, multiline_start); return ERROR;}

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
							printLexeme("Opening brace", yytext);
							updateColumn(yyleng);
						}
					
{brace_closing}			{
							printLexeme("Closing brace", yytext);
							updateColumn(yyleng);
						}

{bracket_opening}		{
							printLexeme("Opening bracket", yytext);
							updateColumn(yyleng);
						}
					
{bracket_closing}		{
							printLexeme("Closing bracket", yytext);
							updateColumn(yyleng);
						}
					
{parenthese_opening}	{
							printLexeme("Opening parenthese", yytext);
							updateColumn(yyleng);
						}
					
{parenthese_closing}	{
							printLexeme("Closing parenthese", yytext);
							updateColumn(yyleng);
						}

{keywords}				{
							printLexeme("Reserved keyword", yytext);
							updateColumn(yyleng);
						}

{data_type} 			{
							printLexeme("Data type", yytext);
							updateColumn(yyleng);
						}

{nil_constant} 			{
							printLexeme("Nil constant", yytext);
							updateColumn(yyleng);
						}
						
{input_command}			{
							printLexeme("Input command", yytext);
							updateColumn(yyleng);
						}

{output_command}		{
							printLexeme("Output command", yytext);
							updateColumn(yyleng);
						}

{id} 					{
							printLexeme("Identifier", yytext);
							updateColumn(yyleng);
						}

{integer_number} 		{
							printLexeme("Integer number", yytext);
							updateColumn(yyleng);
						}

{real_number} 			{
							printLexeme("Real number", yytext);
							updateColumn(yyleng);
						}

{list_constructor} 		{
							printLexeme("List constructor", yytext);
							updateColumn(yyleng);
						}
						
{list_operator} 		{
							printLexeme("List operator", yytext);
							updateColumn(yyleng);
						}
						
{list_destructor} 		{
							printLexeme("List destructor", yytext);
							updateColumn(yyleng);
						}
						
{list_functions} 		{
							printLexeme("List function", yytext);
							updateColumn(yyleng);
						}
						
{arithmetic_operators} 	{
							printLexeme("Arithmetic operator", yytext);
							updateColumn(yyleng);
						}

{relational_operators} 	{
							printLexeme("Relational operator", yytext);
							updateColumn(yyleng);
						}
						
{logical_operators} 	{
							printLexeme("Logical operator", yytext);
							updateColumn(yyleng);
						}

{assignment} 			{
							printLexeme("Assignment", yytext);
							updateColumn(yyleng);
						}

{separator} 			{
							printLexeme("Comma", yytext);
							updateColumn(yyleng);
						}

{flow_control} 			{
							printLexeme("Semicolon", yytext);
							updateColumn(yyleng);
						}	

{string_literal}		{
							printLexeme("String literal", yytext);
							updateColumn(yyleng);
						}

{ambiguous_operator}	{
							printLexeme("Logical or list related operator", yytext);
							updateColumn(yyleng);
						}
						
.						{
							if(printCharacterError("Unrecognized character", yytext))	// Caso aspas dupla
								return ERROR;
							updateColumn(yyleng);
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
		return ERROR;
	}

	printf("%sLine:%d\tColumn:%d\tLexical error! %s: %s%s\n", RED, num_lines, num_chars, token_id, token_text, WHITE);
	return 0;
}

void printMultilineError(int multiline_line, int multiline_column){
	printf("%sLine:%d\tColumn:%d\tLexical error! Multiline comment initialized, but not finished. Expected `*/` at end.%s\n", 
	RED, multiline_line, multiline_column, WHITE);
}

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