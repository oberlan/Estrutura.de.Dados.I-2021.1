#include <stdio.h>
#include <stdlib.h>


#include "Aluno.h"
#include "TS.h"


int main() {
    TS *ts = criaTS();
    imprimeTS(ts);
    put(ts, criaAluno(123, "Aluno1"));
    imprimeTS(ts);
    put(ts, criaAluno(456, "Aluno2"));
    imprimeTS(ts);
    put(ts, criaAluno(789, "Aluno3"));
    imprimeTS(ts);
    put(ts, criaAluno(123, "Aluno123"));
    imprimeTS(ts);

    Aluno *a = get(ts, 456);
    if (a) {
        printf("Aluno encontrado!\n");
    }
    else {
        printf("Aluno não encontrado!\n");
    }

    printf("\nRemovendo aluno com matricula 456\n");
    bool ok = erase(ts, 456);
    if(ok) {
        printf("Aluno removido!\n");
    }
    else {
        printf("Aluno não encontrado!\n");
    }
    imprimeTS(ts);

    printf("\nRemovendo aluno com matricula 456\n");
    ok = erase(ts, 456);
    if(ok) {
        printf("Aluno removido!\n");
    }
    else {
        printf("Aluno não encontrado!\n");
    }
    imprimeTS(ts);

    liberaTS(ts);

    return 0;
}

