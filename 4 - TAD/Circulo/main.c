#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Circulo.h"
#include "Ponto.h"


int main() {
    Circulo *c = inicializaCirculo(0, 0, 3.5);

    Ponto *p = inicializaPonto(1, 1);
    imprimePonto(p);
    if (interiorCirculo(c, p))
        printf("Está no interior\n");
    else
        printf("Não Está no interior\n");

    liberaCirculo(c);
    liberaPonto(p);

    return 0;
}