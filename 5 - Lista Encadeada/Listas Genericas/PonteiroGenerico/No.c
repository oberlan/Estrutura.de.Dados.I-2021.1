#include <stdio.h>
#include <stdlib.h>

#include "No.h"

No *criaRetangulo(double b, double h){
    Retangulo *r = malloc(sizeof(Retangulo));
    r->b = b;
    r->h = h;

    No *no = malloc(sizeof(No));
    no->tipo = RET;
    no->objeto = r;

    return no;
}

No *criaTriangulo(double b, double h) {
    Triangulo *t = malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;

    No *no = malloc(sizeof(No));
    no->tipo = TRI;
    no->objeto = t;

    return no;
}

No *criaCirculo(double r){
    Circulo *c = malloc(sizeof(Circulo));
    c->r = r;

    No *no = malloc(sizeof(No));
    no->tipo = CIRC;
    no->objeto = c;

    return no;
}

void liberaNo(No *no) {
    if(no) {
        if(no->objeto) free(no->objeto);
        free(no);
    }
}

void imprimeNo(No *no) {
     if (no->tipo == RET) {
        printf("** Retangulo **\n");
        Retangulo *r = (Retangulo *)no->objeto;
        printf("-   Base: %lf\n", r->b);
        printf("- Altura: %lf\n", r->h);
    }
    else if(no->tipo == TRI) {
        printf("** Triangulo **\n");
        Triangulo *t = (Triangulo *)no->objeto;
        printf("-   Base: %lf\n", t->b);
        printf("- Altura: %lf\n", t->h);
    }
    else if (no->tipo == CIRC) {
        printf("** Circulo **\n");
        Circulo *c = (Circulo *)no->objeto;
        printf("- Raio: %lf\n", c->r);
    }
    else {
        printf("Objeto não reconhecido\n");
    }
}