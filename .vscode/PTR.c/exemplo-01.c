#include <stdio.h>
#include <stdlib.h>
int main(){
int x = 10;
int *p1;
int *p2;
p1 = &x;
*p1 = 20;
p2 = &x;
printf("Valor de x: %d\n", *p2);
return 0;
}












