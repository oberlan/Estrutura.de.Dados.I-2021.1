CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=Fila

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Fila.o
	gcc main.o Fila.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Fila.o: Fila.c
	gcc $(CFLAGS) -c Fila.c

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)


clean: 
	rm -rf *.o $(EXECUTAVEL)


run: $(EXECUTAVEL)
	./$(EXECUTAVEL)