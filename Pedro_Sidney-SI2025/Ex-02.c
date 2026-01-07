#include <stdio.h>

int main() {
    int notas[100];
    int qtd = 0;
    int soma = 0;
    int valor;

    float media;

    do {
        printf("Digite as notas para o processamento do dados: (Informe -1 para encerrar a coleta): ");
        scanf("%d", &valor);

        if (valor != -1) {
            notas[qtd] = valor;
            soma += valor;
            qtd++;
        }

    } while (valor != -1);

    // a) Quantidade de valores lidos
    printf("\nA)Quantidade de valores lidos: %d\n", qtd);

    // b) Valores na ordem informada
    printf("B)Valores na ordem informada:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", notas[i]);
    }

    // c) Valores na ordem inversa
    printf("\n\nC)Valores na ordem inversa:\n");
    for (int i = qtd - 1; i >= 0; i--) {
        printf("%d\n", notas[i]);
    }

    // d) Soma dos valores
    printf("\nD)Soma dos valores: %d\n", soma);

    // e) Média dos valores
    media = (float)soma / qtd;
    printf("E)Media dos valores: %.2f\n", media);

    // f) Valores acima da media
    int acimaMedia = 0;
    for (int i = 0; i < qtd; i++) {
        if (notas[i] > media) {
            acimaMedia++;
        }
    }
    printf("F)Quantidade de valores acima da media: %d\n", acimaMedia);

    // g) Valores abaixo de 7
    int abaixo7 = 0;
    for (int i = 0; i < qtd; i++) {
        if (notas[i] < 7) {
            abaixo7++;
        }
    }
    printf("G)Quantidade de valores abaixo de 7: %d\n", abaixo7);

    // h) Mensagem final
    printf("\nH)Programa encerrado.\n");

    return 0;
}
