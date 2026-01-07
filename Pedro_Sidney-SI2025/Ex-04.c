#include <stdio.h>

int main() {
    float notas[100];
    int qtd = 0;
    int opcao;
    int i, pos;
    float soma, media, maior, menor, novaNota;

    do {
        printf("\nMENU\n");
        printf("1 - Inserir nota\n");
        printf("2 - Remover nota\n");
        printf("3 - Calcular media\n");
        printf("4 - Mostrar maior e menor nota\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: // Inserir
                printf("Digite a nota: ");
                scanf("%f", &novaNota);
                notas[qtd] = novaNota;
                qtd++;
                break;

            case 2: // Remover
                if (qtd == 0) {
                    printf("Nao ha notas para remover.\n");
                } else {
                    printf("Informe a posicao (1 a %d): ", qtd);
                    scanf("%d", &pos);
                    pos--; // Ajuste para índice do vetor

                    if (pos >= 0 && pos < qtd) {
                        for (i = pos; i < qtd - 1; i++) {
                            notas[i] = notas[i + 1];
                        }
                        qtd--;
                        printf("Nota removida com sucesso.\n");
                    } else {
                        printf("Posicao invalida.\n");
                    }
                }
                break;

            case 3: // Média
                if (qtd == 0) {
                    printf("Nao ha notas para calcular media.\n");
                } else {
                    soma = 0;
                    for (i = 0; i < qtd; i++) {
                        soma += notas[i];
                    }
                    media = soma / qtd;
                    printf("Media das notas: %.2f\n", media);
                }
                break;

            case 4: // Maior e menor
                if (qtd == 0) {
                    printf("Nao ha notas cadastradas.\n");
                } else {
                    maior = menor = notas[0];
                    for (i = 1; i < qtd; i++) {
                        if (notas[i] > maior)
                            maior = notas[i];
                        if (notas[i] < menor)
                            menor = notas[i];
                    }
                    printf("Maior nota: %.2f\n", maior);
                    printf("Menor nota: %.2f\n", menor);
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
 