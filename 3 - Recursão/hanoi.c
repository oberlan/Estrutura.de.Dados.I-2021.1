#include <stdio.h>
#include <stdlib.h>

int i = 0;
void hanoi(int n, char origem, char auxiliar, char destino) {
    if (n > 0) {
        hanoi(n - 1, origem, destino, auxiliar);
        printf("Mova o disco %d de %c para %c.\n", n, origem, destino);
        hanoi(n - 1, auxiliar, origem, destino);
    }
}

int main() {
    hanoi(5, 'A', 'B', 'C');
    return 0;
}
