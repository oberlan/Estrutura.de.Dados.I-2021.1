#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto *inicializaPonto(double x, double y);

void liberaPonto(Ponto *p);

double getXPonto(Ponto *p);

double getYPonto(Ponto *p);

void setXPonto(Ponto *p, double x);

void setYPonto(Ponto *p, double y);

double distanciaPonto(Ponto *p1, Ponto *p2);

/*
 *
*/
void imprimePonto(Ponto *p);

#endif