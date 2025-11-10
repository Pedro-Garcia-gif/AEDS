#include <stdio.h>
#include <stdlib.h>
float aumento(float X, float Y)
{
    return (X + (X * Y / 100));
}
int main()
{
    float X,Y,res;
    printf("Digite o valor de X\n: ");
    scanf("%f", &X);
    printf("Digite o valor de Y\n: ");
    scanf("%f", &Y);
    res = aumento(X,Y);
    printf("O valor com aumento e: %.2f\n", res);
}