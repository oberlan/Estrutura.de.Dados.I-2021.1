#include <stdio.h>
#include <stdlib.h>

typedef struct vetor Vetor;

struct vetor {
    int *dados;  //Vetor com os Elementos
    int tamanho; //Quantidade de elementos do vetor
    int capacidade; //Quantidade máxima de elementos que o vetor pode armazenar
};

Vetor *criaVetor(int capacidade){
    if(capacidade < 1) {
        printf("Capacidade deve ser >= 1\n");
        return NULL;
    }
    Vetor *v = malloc(sizeof(Vetor));
    if (v == NULL){
        printf("Sem memoria!\n");
        exit(0);
    }
    v->capacidade = capacidade;
    v->tamanho = 0;
    v->dados = malloc(capacidade*sizeof(int));
    if (v->dados == NULL) {
        printf("Sem memoria!\n");
        exit(0);
    }
    return v;
}

void liberaVetor(Vetor *v) {
    if(v == NULL)
        return;
    if (v->dados != NULL)
        free(v->dados);
    free(v);
    v = NULL;
}

void insereNoFimVetor(Vetor *v, int valor) {
    if(v == NULL){
        printf("Vetor não alocado!\n");
        return;
    }
    if(v->tamanho < v->capacidade) {
        v->dados[v->tamanho] = valor;
        v->tamanho++;
    }
    else{
        printf("Vetor sem espaço!\n");
    }
}

void imprimeVetor(Vetor *v) {
    if(v == NULL) {
        printf("Vetor não alocado!\n");
        return;
    }

    for (int i = 0; i < v->tamanho; i++)
        printf("%d ", v->dados[i]);
    printf("\n");
}

int tamanhoVetor(Vetor *v){
    if(v == NULL) {
        printf("Vetor não alocado!\n");
        return 0;
    }
    return v->tamanho;
}

int capacidadeVetor(Vetor *v){
    if(v == NULL) {
        printf("Vetor não alocado!\n");
        return 0;
    }
    return v->capacidade;
}

Vetor *copiaVetor(Vetor *v) {
    if (v == NULL) {
        return NULL;
    }
    Vetor *cpy = criaVetor(v->capacidade);
    cpy->capacidade = v->capacidade;
    cpy->tamanho = v->tamanho;
    //cpy->dados = v->dados;
    //cpy->dados = malloc(cpy->capacidade*sizeof(int));
    for(int i = 0; i < v->tamanho; i++)
        cpy->dados[i] = v->dados[i];
    return cpy;
}


int main() {
    int n = 10;
    //int *dados = malloc(n*sizeof(int));
    Vetor *v = criaVetor(n);
    printf("   Tamanho: %d\n", v->tamanho);
    printf("Capacidade: %d\n", v->capacidade);

    for (int i = 0; i < 5; i++) {
        insereNoFimVetor(v, i + 1);
    }
    imprimeVetor(v);
    printf("   Tamanho: %d\n", v->tamanho);
    printf("Capacidade: %d\n", v->capacidade);
    
    Vetor *tmp = v;
    v = copiaVetor(v);
    liberaVetor(tmp);
    
    // Vetor *v1 = copiaVetor(v);
    // imprimeVetor(v1);

    // insereNoFimVetor(v, 123);
    // printf(" v: ");
    // imprimeVetor(v);
    // insereNoFimVetor(v1, -1);
    // printf("v1: ");
    // imprimeVetor(v1);
    // printf(" v: ");
    // imprimeVetor(v);

    // printf("%p ", v->dados);
    // printf("%p ", v1->dados);

    liberaVetor(v);
    // liberaVetor(v1);
    return 0;   
}