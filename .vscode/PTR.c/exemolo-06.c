#include <stdio.h>
#include <stdlib.h>
soma(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}
int main(){
int num1, num2, resultado;
printf("Digite o primeiro numero: ");
scanf("%d", &num1);
printf("Digite o segundo numero: ");    
scanf("%d", &num2);
soma(&num1, &num2, &resultado); 
printf("A soma de %d + %d : %d\n", num1, num2, resultado);
return 0;
}