CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=FilaPrioridade

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o FilaPrioridade.o
	gcc main.o FilaPrioridade.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

FilaPrioridade.o: FilaPrioridade.c
	gcc $(CFLAGS) -c FilaPrioridade.c

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)


clean: 
	rm -rf *.o $(EXECUTAVEL)


run: $(EXECUTAVEL)
	./$(EXECUTAVEL)