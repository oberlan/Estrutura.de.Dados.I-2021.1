#include <stdio.h>
#include <stdlib.h>

int fatorial(int n); //Prototipo da função 'fatorial'
int soma(int n);
int contaDigitos(int n);
int somaDigitos(int n);
int procura(int valores[], int tamanho, int valorProcurado);

int main(){

    // int f = fatorial(3);
    // int f = fatorial(-1);
    // int f = fatorial(15);
    // int f = fatorial(20);
    // printf("%d\n", f);
    // int a = 123, b = 10;
    // double x = (double)a/b;
    // printf("%lf\n", x);
    // printf("somaDigitos(%d) = %d\n", 234, somaDigitos(234));
    // for(int i = 1; i <= 1001; i += 100)
    //     printf("contaDigitos(%d) = %d\n", i, contaDigitos(i));
    int v[] = {1, 5, -4, -18, -33, 118, 11};
    int pos = procura(v, 7, 113);
    if (pos != -1) {
        printf("Valor encontrado na posicao: %d\n", pos);
    }
    else {
        printf("Valor nao encontrado\n");
    }

    return 0;
}

//N! = N*(N - 1)!
//0! = 1 // Caso base
//1! = 1*0! = 1 
//2! = 2*1*0! = 2
//3! = 3*2*1*0! = 6
//4! = 24
int fatorial(int n) {
    //printf("%d\n", n);
    if (n < 0)
        return -1;
    // Caso base
    if(n == 0)
        return 1;
    // Passo recursivo
    else
        return n*fatorial(n - 1);
}

//soma(0) = 0 //Caso base
//soma(1) = 1 + soma(0) = 1+0 = 1
//soma(2) = 2 + soma(1) = 2 + 1 + soma(0) = 2 + 1 + 0 = 3
//soma(3) = 3 + soma(2) = 3 + 2 + soma(1) = 3 + 2 + 1 + soma(0) = 3 + 2 + 1 + 0
//soma(n) = n + soma(n-1)
int soma(int n) {
    if(n == 0) return 0;
    else return n + soma(n-1);
}

//contaDigitos("se 0 <= n <= 9" ) = 1 //Caso base
//contaDigitos(12) = 1 + contaDigitos(1) = 1 + 1 = 2
//contaDigitos(234) = 1 + contaDigitos(23)
                //  = 1 + 1 + contaDigitos(2) = 1 + 1 + 1 = 3
//contaDigitos(n) = 1 + contaDigitos(n/10)
// 123 -> 3
// 1234 -> 4
int contaDigitos(int n) {
    printf("%d ", n);
    if (n < 10)
        return 1;
    else 
        return 1 + contaDigitos(n/10);
}

//Caso base
//somaDigitos("se 0 <= n <= 9") = n
//somaDigitos(23) = 3 + somaDigitos(2) = 3 + 2 = 5
//somaDigitos(234) = 4 + somaDigitos(23)
//                 = 4 + 3 + somaDigitos(2)
//                 = 4 + 3 + 2 = 9
//somaDigitos(n) = n%10 + somaDigitos(n/10)

//somaDigitos(123) = 1 + 2 + 3 = 3 + 2 + 1 = 6
int somaDigitos(int n) {
    printf("%d ", n);
    if (n < 10)
        return n;
    else
        return n % 10 + somaDigitos(n / 10);
}

int procura(int valores[], int n, int valorProcurado) {
    // for(int i = n - 1; i >= 0; i--)    
    //     if(valores[i] == valorProcurado)
    //         return i;
    if(n == 0)
        return -1;
    else {
        if (valores[n - 1] ==  valorProcurado)
            return n - 1;
        else
            return procura(valores, n - 1, valorProcurado);
    }
    // if(tamanho == 1){
    //     if(valores[0] == valorProcurado)
    //         return 0;
    //     else
    //         return -1;
    // }
    
}