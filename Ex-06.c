#include <stdio.h>
#include <stdlib.h>
float salario(float sala1, float sala2)
{
    if (sala1 > sala2)
    {
        return sala1;
    }
    else
    {
        return sala2;
    }
}
int main()
{
    float sala1, sala2, maior;
    printf("Digite o salario do funcionario 1\n: ");
    scanf("%f", &sala1);
    printf("Digite o salario do funcionario 2\n: ");
    scanf("%f", &sala2);
    maior = salario(sala1, sala2);
    printf("O maior salario e: %.2f\n", maior);
}