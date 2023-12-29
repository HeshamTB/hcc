

SRC=
all: scanner.c parser.c token.h
	gcc  -o hcc expr.c parser.c scanner.c main.c

scanner.c: flex

parser.c: bison

token.h: bison

bison:
	bison --debug --defines=token.h --output=parser.c parser.bison

flex: bison
	flex --debug -o scanner.c scanner.flex

clean:
	rm -vf parser.c scanner.c hcc token.h


