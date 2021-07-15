#ifndef CIRCULO_H
#define CIRUCLO_H

#include "Ponto.h"

typedef struct circulo Circulo;

Circulo *inicializaCirculo(double x, double y, double r);

void liberaCirculo(Circulo *c);

double areaCirculo(Circulo *c);

int interiorCirculo(Circulo *c, Ponto *p);

#endif
