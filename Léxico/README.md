Autor: Lucas Dalle Rocha

Matrícula: 17/0016641

O programa pode ser compilado pela utilização do Makefile, 
com o seguinte comando em seu terminal: 
$ make
	
Caso seja de seu interesse compilá-lo manualmente, execute a instrução:
$ flex src/lexical.l && gcc-11 -o tradutor src/main.c

Por fim, para execução do analisador léxico nos arquivos teste:
$ ./tradutor tests/<file>.c

Requisitos:

* Kernel: 4.4.0-19041-Microsoft <WSL Terminal>
* Ubuntu 20.04.2 LTS
* GNU ld (GNU Binutils for Ubuntu) 2.34
* gcc-11 11.1.0
* GNU Make 4.2.1
* GNU automake 1.16.1
* flex 2.6.4
* bison (GNU Bison) 3.5.1	<not required, for now :)>
