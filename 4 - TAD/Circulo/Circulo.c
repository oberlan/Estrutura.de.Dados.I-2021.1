#include <stdio.h>
#include <stdlib.h>

#include "Circulo.h"
#include "Ponto.h"

#define PI 3.1415

struct circulo {
    Ponto *centro;
    double r;
};


Circulo *inicializaCirculo(double x, double y, double r){
    Circulo *c = malloc(sizeof(Circulo));
    if (c == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    c->centro = inicializaPonto(x, y);
    c->r = r;
    return c;
}

void liberaCirculo(Circulo *c){
    liberaPonto(c->centro);
    free(c);
}

double areaCirculo(Circulo *c){
    return PI * c->r * c->r;
}

int interiorCirculo(Circulo *c, Ponto *p){
    double d = distanciaPonto(c->centro, p);
    return (d < c->r);
}
