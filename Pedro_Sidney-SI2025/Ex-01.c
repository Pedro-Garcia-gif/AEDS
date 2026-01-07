#include <stdio.h>

struct Moto {
    int modelo;
    float consumo;
};

int main() {
    struct Moto motos[3]; 
    int i;
    float maiorConsumo;

    // Leitura dos dados
    for (i = 0; i < 3; i++) {
        printf("Digite o modelo da moto %d: ", i + 1);
        scanf("%d", &motos[i].modelo);

        printf("Digite o consumo (km/l) da moto %d: ", i + 1);
        scanf("%f", &motos[i].consumo);
    }

    // Descobrir o maior consumo
    maiorConsumo = motos[0].consumo;
    for (i = 1; i < 3; i++) {
        if (motos[i].consumo > maiorConsumo) {
            maiorConsumo = motos[i].consumo;
        }
    }

    // Mostrar moto(s) mais economica(s)
    printf("\nMoto(s) mais economica(s):\n");
    for (i = 0; i < 3; i++) {
        if (motos[i].consumo == maiorConsumo) {
            printf("Modelo: %d (%.2f km/l)\n",
                   motos[i].modelo, motos[i].consumo);
        }
    }

    // Consumo para percorrer 100 km
    printf("\nConsumo para percorrer 100 km:\n");
    for (i = 0; i < 3; i++) {
        printf("Modelo %d: %.2f litros\n",
               motos[i].modelo, 100 / motos[i].consumo);
    }

    return 0;
}
