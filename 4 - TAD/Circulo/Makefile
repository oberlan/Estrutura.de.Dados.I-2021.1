# alvo: pre-requisitos
	# comando

CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
CLIBS=-lm
EXECUTAVEL=Circulo

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Ponto.o Circulo.o
	gcc main.o Ponto.o Circulo.o $(CLIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc -c $(CFLAGS)  main.c

Ponto.o: Ponto.c
	gcc -c $(CFLAGS)  Ponto.c

Circulo.o: Circulo.c
	gcc -c $(CFLAGS)  Circulo.c

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

clean: 
	rm -rf *.o $(EXECUTAVEL)