CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=Pilha

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Pilha.o
	gcc main.o Pilha.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Pilha.o: Pilha.c
	gcc $(CFLAGS) -c Pilha.c


clean: 
	rm -rf *.o $(EXECUTAVEL)


run: $(EXECUTAVEL)
	./$(EXECUTAVEL)