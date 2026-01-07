#include <stdio.h>

int main() {
    int lista[100];
    int qtd = 0;
    int valor, i, pos;

    printf("Digite valores (0 para parar):\n");

    do {
        scanf("%d", &valor);

        if (valor != 0) {

            // 1️⃣ Encontrar a posição correta
            pos = 0;
            while (pos < qtd && lista[pos] < valor) {
                pos++;
            }

            // 2️⃣ Deslocar elementos para a direita (do final)
            for (i = qtd; i > pos; i--) {
                lista[i] = lista[i - 1];
            }

            // 3️⃣ Inserir o valor
            lista[pos] = valor;
            qtd++;
        }

    } while (valor != 0);

    // Mostrar a lista ordenada
    printf("\nLista ordenada:\n");
    for (i = 0; i < qtd; i++) {
        printf("%d ", lista[i]);
    }

    return 0;
}
