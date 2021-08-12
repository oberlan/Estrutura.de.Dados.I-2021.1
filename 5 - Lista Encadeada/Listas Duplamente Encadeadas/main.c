#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

int main() {
    Lista *lista = criaLista();
    insereFimLista(lista, 1);
    insereFimLista(lista, 2);
    insereFimLista(lista, 3);
    insereFimLista(lista, 4);
    insereFimLista(lista, 5);
    imprimeLista(lista);
    imprimeReversoLista(lista);
    removeLista(lista, 1);
    imprimeLista(lista);
    removeLista(lista, 5);
    imprimeLista(lista);
    removeLista(lista, 3);
    imprimeLista(lista);

    liberaLista(lista);

    return 0;
}