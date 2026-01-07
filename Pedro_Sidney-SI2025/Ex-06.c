
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int vazia(Fila *f) {
    return f->frente == f->tras;
}

int cheia(Fila *f) {
    return f->tras == MAX;
}

void enfileirar(Fila *f, int valor) {
    if (!cheia(f)) {
        f->itens[f->tras++] = valor;
    } else {
        printf("Fila cheia!\n");
    }
}

int desenfileirar(Fila *f) {
    if (!vazia(f)) {
        return f->itens[f->frente++];
    } else {
        printf("Fila vazia!\n");
        return -1;
    }
}

void intercalarFilas(Fila *f1, Fila *f2, Fila *resultado) {
    while (!vazia(f1) || !vazia(f2)) {
        if (!vazia(f1)) {
            enfileirar(resultado, desenfileirar(f1));
        }
        if (!vazia(f2)) {
            enfileirar(resultado, desenfileirar(f2));
        }
    }
}

void mostrarFila(Fila *f) {
    for (int i = f->frente; i < f->tras; i++) {
        printf("%d ", f->itens[i]);
    }
    printf("\n");
}

int main() {
    Fila f1, f2, resultado;
    inicializar(&f1);
    inicializar(&f2);
    inicializar(&resultado);

    // Exemplo de dados
    enfileirar(&f1, 1);
    enfileirar(&f1, 3);
    enfileirar(&f1, 5);

    enfileirar(&f2, 2);
    enfileirar(&f2, 4);
    enfileirar(&f2, 6);
    enfileirar(&f2, 8);

    intercalarFilas(&f1, &f2, &resultado);

    printf("Fila intercalada: ");
    mostrarFila(&resultado);

    return 0;
}
