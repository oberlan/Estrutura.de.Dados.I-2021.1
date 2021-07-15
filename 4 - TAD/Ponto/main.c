#include <stdio.h>

#include "Ponto.h"

int main() {  
    Ponto *p = inicializa(2.5, 3.8);
    imprime(p);
    setX(p, 5.5);
    imprime(p);
    libera(p);
    return 0;
}