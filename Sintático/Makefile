############################# Makefile ##########################
CC = gcc-11
FLEX = flex
BISON = bison
CFLAGS = -g -Wall
FLEXTARGET = src/lexical.l
CTARGET = src/lex.yy.c
BISONTARGET = src/syntax.y
BISONFLAGS = -Wcounterexamples
BISONSRC = src/syntax.tab.c
ALLSRC = src/*.c
EXECNAME = tradutor

all:
	bison -o src/syntax.tab.c -d src/syntax.y -Wcounterexamples
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	@echo "Execute using: ./tradutor tests/<FILE>.c"

valgrind1:
	bison -o src/syntax.tab.c -d src/syntax.y -Wcounterexamples
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="logfile1.out" ./tradutor tests/correct1.c

valgrind2:
	bison -o src/syntax.tab.c -d src/syntax.y -Wcounterexamples
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="logfile2.out" ./tradutor tests/correct2.c

valgrind3:
	bison -o src/syntax.tab.c -d src/syntax.y -Wcounterexamples
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="logfile3.out" ./tradutor tests/incorrect1.c

valgrind4:
	bison -o src/syntax.tab.c -d src/syntax.y -Wcounterexamples
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="logfile4.out" ./tradutor tests/incorrect2.c

clean: $(RM) $(tradutor)