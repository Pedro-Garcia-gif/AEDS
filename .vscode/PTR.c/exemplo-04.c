#include <stdio.h>
#include <stdlib.h>
void troca(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int num1 = 5;
    int num2 = 10;

    printf("Antes da troca: num1 = %d, num2 = %d\n", num1, num2);
    troca(&num1, &num2);
    printf("Depois da troca: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}