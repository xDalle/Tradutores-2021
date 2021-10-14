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
	bison -o src/syntax.tab.c -d src/syntax.y
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	@echo "Execute using: ./tradutor tests/<FILE>.c"

valgrind:
	bison -o src/syntax.tab.c -d src/syntax.y
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="correct1.out" ./tradutor tests/correct1.c
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="correct2.out" ./tradutor tests/correct2.c

correct1:
	bison -o src/syntax.tab.c -d src/syntax.y
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	./tradutor tests/correct1.c

correct2:
	bison -o src/syntax.tab.c -d src/syntax.y
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	./tradutor tests/correct2.c

incorrect1:
	bison -o src/syntax.tab.c -d src/syntax.y
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	./tradutor tests/incorrect1.c

incorrect2:
	bison -o src/syntax.tab.c -d src/syntax.y
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	./tradutor tests/incorrect2.c

debug:
	bison -o src/syntax.tab.c -d src/syntax.y
	flex -o src/lex.yy.c src/lexical.l
	gcc-11 -g -c src/structures.c -o obj/structures.o
	gcc-11 -g src/syntax.tab.c src/lex.yy.c obj/structures.o -I lib -o tradutor -Wall -Wpedantic -Wextra
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="debug.out" ./tradutor tests/nalon.c

clean: $(RM) $(tradutor)