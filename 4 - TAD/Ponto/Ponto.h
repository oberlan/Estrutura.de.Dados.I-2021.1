typedef struct ponto Ponto;

Ponto *inicializa(double x, double y);

void libera(Ponto *p);

double getX(Ponto *p);

double getY(Ponto *p);

void setX(Ponto *p, double x);

void setY(Ponto *p, double y);

double distancia(Ponto *p1, Ponto *p2);

/*
 *
*/
void imprime(Ponto *p);