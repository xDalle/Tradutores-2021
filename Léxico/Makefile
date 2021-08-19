############################# Makefile ##########################
CC = gcc-11
FLEX = flex
CFLAGS = -g -Wall
FLEXTARGET = src/lexical.l
CTARGET = src/main.c
EXECNAME = tradutor

all: $(FLEXTARGET)
	$(FLEX) $(FLEXTARGET)
	$(CC) $(CFLAGS) -o $(EXECNAME) $(CTARGET)
	@echo "Execute using: ./tradutor tests/<FILE>.c"
clean: $(RM) $(tradutor)