CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=TS

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o TS.o Aluno.o
	gcc main.o TS.o Aluno.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

TS.o: TS.c
	gcc $(CFLAGS) -c TS.c

Aluno.o: Aluno.c
	gcc $(CFLAGS) -c Aluno.c


clean: 
	rm -rf *.o $(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)