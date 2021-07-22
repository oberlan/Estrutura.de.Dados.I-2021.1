CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=Vetor

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o 
	gcc main.o  $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

clean: 
	rm -rf *.o $(EXECUTAVEL)


run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)