#include <stdio.h>
#include <stdlib.h>
int main() {
    int x;
    int *p;
    p = &x;
    printf("Digite um valor inteiro: ");
    scanf("%d", p);
    printf("Valor lido: %d\n", *p);
    printf("Endereco de x: %p\n",&x);

    return 0;
}