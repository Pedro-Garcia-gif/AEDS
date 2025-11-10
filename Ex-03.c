#include <stdio.h>
#include <math.h>

// Função para calcular y
int calculaY(int x) {
    int h, f, g, y;

    h = (x * x) - 16;

    // Definição de f(x)
    if (h >= 0) {
        f = h;
    } else {
        f = 1;
    }

    // Definição de g(x)
    if (f == 0) {
        g = (x * x) + 16;
    } else {
        g = 0;
    }

    // y = f(x) + g(x)
    y = f + g;

    return y;
}

int main() {
    int x;

    printf("Digite um valor para x: ");
    scanf("%d", &x);

    printf("y = %d\n", calculaY(x));

    return 0;
}
