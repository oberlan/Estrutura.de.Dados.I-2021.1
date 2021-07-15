#include <stdio.h>
#include <stdlib.h>

#define TAM 15

struct ponto{
    double x, y;
};

typedef struct ponto Ponto;
typedef long long ll;

typedef struct pontoint {
    int x, y;
}PontoInt;

int main(int argc, char *argv[]) {
    // printf("%d\n", argc);
    // for(int i = 0; i < argc; i++)
    //     printf("%s\n", argv[i]);
    Ponto p1;
    Ponto p2;
    ll x;

    struct pontoint pi1;
    PontoInt pi2;

    // scanf("%lf %lf", &p1.x, &p1.y);
    // printf("%.2lf %.2lf\n", p1.x, p1.y);
    // ll y = 12345678901234567890123456789;
    //scanf("%d", &y);
    // printf("%lld\n", y);
    // int y = 10;
    // int *p = &y;
    // printf("&y = %p\n", &y);
    // printf("&p = %p\n", &p);
    // printf("p = %p\n", p);
    // printf("y = %d\n", y);
    // printf("*p = %d\n", *p);

    // *p = 15;
    // printf("-----------------\n");
    // printf("&y = %p\n", &y);
    // printf("&p = %p\n", &p);
    // printf("p = %p\n", p);
    // printf("y = %d\n", y);
    // printf("*p = %d\n", *p);
    int y = 10; 
    scanf("%d", &y);
    int a[y];
    for(int i = 0; i < y; i++)
        a[i] = 1;

    y = 20;
    
    for (int i = 0; i < y; i++){
        printf("%p %p %p ", &y, &i, &a[i]);
        a[i] = 1;
        printf("%d %d %d\n", y, i, a[i]);
    }

    return 0;
}