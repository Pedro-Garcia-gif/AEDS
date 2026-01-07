
#include <stdio.h>

#define CAPACIDADE 20

typedef struct {
    int dados[CAPACIDADE];
    int frente;   // índice do primeiro elemento
    int tras;     // posição de inserção do próximo elemento
    int tamanho;  // quantidade de elementos na fila
} Fila;

// Inicializa a fila
void fila_init(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == CAPACIDADE;
}

// Enfileira (adiciona cliente com número)
int enfileirar(Fila *f, int numero) {
    if (fila_cheia(f)) {
        printf("Fila cheia! Capacidade maxima de %d pessoas.\n", CAPACIDADE);
        return 0;
    }
    f->dados[f->tras] = numero;
    f->tras = (f->tras + 1) % CAPACIDADE;
    f->tamanho++;
    return 1;
}

// Desenfileira (atende cliente)
int desenfileirar(Fila *f, int *atendido) {
    if (fila_vazia(f)) {
        printf("Fila vazia! Ninguem para atender.\n");
        return 0;
    }
    *atendido = f->dados[f->frente];
    f->frente = (f->frente + 1) % CAPACIDADE;
    f->tamanho--;
    return 1;
}

// Espia o primeiro (proximo a ser atendido)
int fila_frente(Fila *f, int *proximo) {
    if (fila_vazia(f)) return 0;
    *proximo = f->dados[f->frente];
    return 1;
}

// Mostra toda a fila (opcional, útil para depurar)
void fila_mostrar(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila (tam=%d/%d): ", f->tamanho, CAPACIDADE);
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->frente + i) % CAPACIDADE;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

int main(void) {
    Fila fila;
    fila_init(&fila);

    int opcao;
    do {
        printf("\n=== FILA DE ATENDIMENTO ===\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Atender cliente\n");
        printf("3 - Mostrar proximo\n");
        printf("4 - Mostrar toda a fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) {
            // Limpa entrada inválida
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrada invalida.\n");
            continue;
        }

        if (opcao == 1) {
            int numero;
            printf("Digite o numero do cliente: ");
            if (scanf("%d", &numero) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Entrada invalida.\n");
                continue;
            }
            enfileirar(&fila, numero);
        } else if (opcao == 2) {
            int atendido;
            if (desenfileirar(&fila, &atendido)) {
                printf("Atendido cliente numero: %d\n", atendido);
            }
        } else if (opcao == 3) {
            int proximo;
            if (fila_frente(&fila, &proximo)) {
                printf("Proximo a ser atendido: %d\n", proximo);
            } else {
                printf("Fila vazia.\n");
            }
        } else if (opcao == 4) {
            fila_mostrar(&fila);
        } else if (opcao == 0) {
            printf("Encerrando...\n");
        } else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
