#include <stdio.h>
#include <stdlib.h>
float quadrado(float num)
{
    return (num * num);
}
float circulo(float num)
{
    return (3.14 * num * num);
}
int main()
{
    float num, res, res2;
    printf("Digite o valor do lado do quadrado\n: ");
    scanf("%f", &num);
    printf("Digite o valor do raio do circulo\n: ");
    scanf("%f", &num);
    res2 = circulo(num);
    printf("A area do circulo e: %.2f\n", res2);
    res = quadrado(num);
    printf("A area do quadrado e: %.2f\n", res);
}