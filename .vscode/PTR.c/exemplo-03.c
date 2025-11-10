#include <stdio.h>
#include <stdlib.h>
void dobrar(int *n) {
    *n = *n * 2;
}
int main() {
    int valor = 15;
    printf("Valor antes de dobrar: %d\n", valor);
    dobrar(&valor);
    printf("Valor depois de dobrar: %d\n", valor);
    return 0;
}