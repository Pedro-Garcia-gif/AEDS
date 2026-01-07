
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;      // vetor de elementos
    int capacidade;  // tamanho atual do vetor
    int tamanho;     // quantidade de elementos na fila
    int frente;      // índice do primeiro elemento
    int tras;        // posição onde o próximo elemento será inserido
} Fila;

// Inicializa a fila com capacidade inicial
void fila_init(Fila *f, int capacidade_inicial) {
    if (capacidade_inicial <= 0) capacidade_inicial = 1;
    f->dados = (int *)malloc(capacidade_inicial * sizeof(int));
    if (f->dados == NULL) {
        fprintf(stderr, "Erro de memoria ao criar a fila.\n");
        exit(1);
    }
    f->capacidade = capacidade_inicial;
    f->tamanho = 0;
    f->frente = 0;
    f->tras = 0;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_tamanho(Fila *f) {
    return f->tamanho;
}

// Dobra a capacidade da fila quando estiver cheia
void fila_dobrar_capacidade(Fila *f) {
    int nova_cap = f->capacidade * 2;
    int *novo = (int *)malloc(nova_cap * sizeof(int));
    if (novo == NULL) {
        fprintf(stderr, "Erro de memoria ao redimensionar a fila.\n");
        exit(1);
    }

    // Copiar os elementos na ordem correta para o novo vetor,
    // começando da frente e seguindo o buffer circular.
    for (int i = 0; i < f->tamanho; i++) {
        novo[i] = f->dados[(f->frente + i) % f->capacidade];
    }

    free(f->dados);
    f->dados = novo;
    f->capacidade = nova_cap;
    f->frente = 0;
    f->tras = f->tamanho; // próxima inserção
}

// Enfileira (insere no fim). Redimensiona se estiver cheia.
void enfileirar(Fila *f, int valor) {
    if (f->tamanho == f->capacidade) {
        fila_dobrar_capacidade(f);
    }
    f->dados[f->tras] = valor;
    f->tras = (f->tras + 1) % f->capacidade;
    f->tamanho++;
}

// Desenfileira (remove da frente). Retorna -1 se vazia.
int desenfileirar(Fila *f) {
    if (fila_vazia(f)) {
        fprintf(stderr, "Fila vazia.\n");
        return -1;
    }
    int valor = f->dados[f->frente];
    f->frente = (f->frente + 1) % f->capacidade;
    f->tamanho--;
    return valor;
}

// Espia o primeiro sem remover
int fila_frente(Fila *f) {
    if (fila_vazia(f)) {
        fprintf(stderr, "Fila vazia.\n");
        return -1;
    }
    return f->dados[f->frente];
}

void fila_imprimir(Fila *f) {
    printf("Fila (cap=%d, tam=%d): ", f->capacidade, f->tamanho);
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->frente + i) % f->capacidade;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

void fila_free(Fila *f) {
    free(f->dados);
    f->dados = NULL;
    f->capacidade = 0;
    f->tamanho = 0;
    f->frente = 0;
    f->tras = 0;
}

// Demonstração
int main(void) {
    Fila f;
    fila_init(&f, 4); // capacidade inicial pequena para testar o redimensionamento

    // Enfileirar vários elementos (vai dobrar a capacidade algumas vezes)
    for (int i = 1; i <= 12; i++) {
        enfileirar(&f, i * 10);
        fila_imprimir(&f);
    }

    // Remover alguns elementos
    for (int i = 0; i < 5; i++) {
        int x = desenfileirar(&f);
        printf("Desenfileirado: %d\n", x);
        fila_imprimir(&f);
    }

    // Enfileirar mais (testar o comportamento circular)
    for (int i = 13; i <= 18; i++) {
        enfileirar(&f, i * 10);
        fila_imprimir(&f);
    }

    printf("Frente da fila: %d\n", fila_frente(&f));

    fila_free(&f);
    return 0;
}
