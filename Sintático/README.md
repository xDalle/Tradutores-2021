Autor: Lucas Dalle Rocha
Matrícula: 17/0016641

O programa pode ser compilado pela utilização do Makefile, 
com o seguinte comando em seu terminal: 

	$ make

Ademais, pode-se compilar e executar o valgrind em algum dos arquivos de
teste:

correct1.c -> $ make valgrind1

correct2.c -> $ make valgrind2

incorrect1.c -> $ make valgrind3

incorrect2.c -> $ make valgrind4

Caso seja de seu interesse compilá-lo manualmente, execute a sequência de instruções:

	$ bison -o src/syntax.tab.c -d src/syntax.y -Wcounterexamples
	$ flex -o src/lex.yy.c src/lexical.l
	$ gcc-11 -g -c src/structures.c -o obj/structures.o
	$ gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic

Por fim, para execução do analisador sintático nos arquivos teste:

	$ ./tradutor tests/<file>.c

Definições:

* Kernel: 4.4.0-19041-Microsoft <WSL Terminal>
* Ubuntu 20.04.2 LTS
* GNU ld (GNU Binutils for Ubuntu) 2.34
* gcc-11 11.1.0
* GNU Make 4.2.1
* GNU automake 1.16.1
* flex 2.6.4
* bison (GNU Bison) 3.7.4
