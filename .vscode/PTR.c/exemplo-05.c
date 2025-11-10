#include <stdio.h>
#include <stdlib.h>
void multiplica(int *a )
{
    *a = (*a) * 2;
    
}
int main()
{
   int v[5]; 
    for(int i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &v[i]);
        multiplica(&v[i]);

    }
    printf("Valores multiplicados por 2:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d\n", v[i]);
    }
}