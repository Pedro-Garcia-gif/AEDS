#include <stdio.h>
#include <stdlib.h>

float soma(float num1, float num2)
{
    float So;
    So = num1 + num2;
    printf("Resultado: %.2f", So);
    return (So);
}
float subtracao(float num1, float num2)
{
    float S;
    S = num1 - num2;
    printf("Resultado: %.2f", S);
    return (S);
}
float multiplicacao(float num1, float num2)
{
    float M;
    M = num1 * num2;
    printf("Resultado: %.2f", M);
    return (M);
}
float verificacao(float num2)
{
    if (num2 == 0)
    {
        printf("DIVISAO COM DENOMINAR 0 INVALIDA\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
float divisao(float num1, float num2)
{
    float D;
    float Z = verificacao(num2);
    D = num1 / num2;
    if (Z == 1)
    {
        return 0;
    }
    else
    {
        printf("Resultado: %.2f", D);
    }
    return 0;
}
int main()
{
    float num1, num2;
    int opcao, opcao2;
    int y = 1;

    do
    {
        printf("\n");
        printf("\n-------CALCULADORA-------\n");
        printf("\n");
        printf("(1)para Informar os numeros\n");
        printf("(5)para sair\n");
        scanf("%d", &opcao);
        system("cls");
        switch (opcao)
        {
        case 1:
            printf("Informe os numeros:\n");
            scanf("%f%f", &num1, &num2);
            y = 0;
            printf("Escolha a operacao:\n");
            printf("(1)para somar\n");
            printf("(2)para subtrair\n");
            printf("(3)para multiplicar\n");
            printf("(4)para dividir\n");
            scanf("%d", &opcao2);
            system("cls");
            switch (opcao2)
            {

            case 1:
                if (y != 0)
                {
                    printf("Voce nao informou os valores\n");
                }
                else
                {
                    soma(num1, num2);
                }
                break;
            case 2:
                if (y != 0)
                {
                    printf("Voce nao informou os valores\n");
                }
                else
                {
                    subtracao(num1, num2);
                }
                break;
            case 3:
                if (y != 0)
                {
                    printf("Voce nao informou os valores\n");
                }
                else
                {
                    multiplicacao(num1, num2);
                }
                break;
            case 4:
                if (y != 0)
                {
                    printf("Voce nao informou os valores\n");
                }
                else
                {
                    divisao(num1, num2);
                }
                break;

            default:
                printf("Operacao invalida\n");
                break;
            }
            break;

        case 5:
            printf("\nSAINDO!!!\n");
            break;

        default:
            printf("Operacao invalida\n");
            break;
        }
    } while (opcao != 5);
    system("pause");
    system("cls");
}
