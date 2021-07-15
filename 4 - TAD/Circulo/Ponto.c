#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Ponto.h"

struct ponto {
    double x;
    double y;
};

Ponto *inicializaPonto(double x, double y) {
    Ponto *p = malloc(sizeof(Ponto));
    if (p == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    p->x = x; //(*p).x
    p->y = y;
    return p;
}

void liberaPonto(Ponto *p) {
    free(p);
}

double getXPonto(Ponto *p) {
    return p->x;    
}

double getYPonto(Ponto *p) {
    return p->y;
}

void setXPonto(Ponto *p, double x) {
    p->x = x;
}

void setYPonto(Ponto *p, double y) {
    p->y = y;
}

void imprimePonto(Ponto *p) {
    printf("(%lf, %lf)\n", p->x, p->y);
}

double distanciaPonto(Ponto *p1, Ponto *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    //imprime(p1);
    //imprime(p2);
    return sqrt(dx * dx + dy * dy);
}

