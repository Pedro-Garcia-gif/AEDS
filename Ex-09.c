#include <stdio.h>
#include <stdlib.h>
float metade(float num)
{
    return (num / 2);
}
int main()
{
    float num, res, A[4];
    for (int i = 0; i < 4; i++)
    {
        printf("Digite o valor %d\n: ", i + 1);
        scanf("%f", &num);
        A[i] = metade(num);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("A metade do valor %d e: %.2f\n", i + 1, A[i]);
    }
}
