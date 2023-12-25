
all: flex bison
	gcc expr.c parser.c scanner.c main.c

bison:
	bison --defines=token.h --output=parser.c parser.bison

flex: bison
	flex -o scanner.c scanner.flex
