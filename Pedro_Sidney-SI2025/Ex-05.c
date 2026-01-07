#include <stdio.h>

int main() {

    int n, i;
    int vetor[100];
    int maior, menor;
    float soma = 0, media;

    printf("Informe quantos numeros tem na lista: ");
    scanf("%d", &n);

    printf("Digite os %d valores:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Inicializa maior e menor com o primeiro elemento
    maior = menor = vetor[0];

    // Percorre o vetor
    for(i = 0; i < n; i++) {

        // soma para calcular média
        soma += vetor[i];

        // testa maior
        if(vetor[i] > maior) {
            maior = vetor[i];
        }

        // testa menor
        if(vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    media = soma / n;

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Media: %.2f\n", media);

    return 0;
}
