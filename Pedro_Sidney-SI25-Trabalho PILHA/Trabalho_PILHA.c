#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MaxTam 12

typedef int Apontador;

typedef struct
{
    int cod;
    int idade;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Topo;
} TipoPilha;

TipoPilha Pilha;
TipoItem x;

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = 0;
}

int Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == 0);
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{
    if (Pilha->Topo == MaxTam)
        printf("\n ERRO: pilha esta cheia\n");
    else
    {
        Pilha->Topo = Pilha->Topo + 1;
        Pilha->Item[Pilha->Topo - 1] = x;
    }
}

void ImprimeTopoFundo(TipoPilha Pilha)
{
    int aux;
    if (Vazia(Pilha))
    {
        printf("Pilha esta Vazia\n");
    }
    else
    {
        for (aux = Pilha.Topo - 1; aux >= 0; aux = aux - 1)
        {
            printf("Cod: %d\n Idade: %d\n\n\n", Pilha.Item[aux].cod, Pilha.Item[aux].idade);
        }
    }
}

void ImprimeFundoTopo(TipoPilha Pilha)
{
    int aux;
    if (Vazia(Pilha))
    {
        printf("Pilha esta Vazia\n");
    }
    else
    {
        for (aux = 0; aux <= Pilha.Topo - 1; aux = aux + 1)
        {
            printf("Cod: %d\n Idade: %d\n\n\n", Pilha.Item[aux].cod, Pilha.Item[aux].idade);
        }
    }
}

void Desempilha(TipoPilha *Pilha, TipoItem *x)
{
    if (Vazia(*Pilha))
    {
        printf("ERRO: Pilha esta Vazia\n");
    }
    else
    {
        *x = Pilha->Item[Pilha->Topo - 1];
        printf("O elemento retirado foi o de codigo %d\n", x->cod);
        Pilha->Topo = Pilha->Topo - 1;
    }
}

int Tamanho(TipoPilha Pilha)
{
    return (Pilha.Topo);
}
void buscarPorCodigo(TipoPilha *p, int codigo)
{
    int i, achou = 0;

    for (i = p->Topo; i >= 0; i--)
    {
        if (p->Item[i].cod == codigo)
        {
            printf("Elemento encontrado na posição %d\n", i);
            achou = 1;
            break;
        }
    }

    if (!achou)
    {
        printf("Elemento não encontrado\n");
    }
}
void partirPilha(TipoPilha *origem, TipoPilha *p1, TipoPilha *p2)
{
    int i;
    int meio = origem->Topo / 2;

    FPVazia(p1);
    FPVazia(p2);

    for (i = 0; i < origem->Topo; i++)
    {
        if (i < meio)
        {
            p1->Item[p1->Topo] = origem->Item[i];
            p1->Topo++;
        }
        else
        {
            p2->Item[p2->Topo] = origem->Item[i];
            p2->Topo++;
        }
    }
}
void OrdenaPilhaPorCodigo(TipoPilha *Pilha)
{
    int i, j;
    TipoItem aux;

    if (Vazia(*Pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }

    for (i = 0; i < Pilha->Topo - 1; i++)
    {
        for (j = i + 1; j < Pilha->Topo; j++)
        {
            if (Pilha->Item[i].cod > Pilha->Item[j].cod)
            {
                aux = Pilha->Item[i];
                Pilha->Item[i] = Pilha->Item[j];
                Pilha->Item[j] = aux;
            }
        }
    }

    printf("Pilha ordenada por codigo (fundo -> topo)\n");
}
void MaiorMenorMediaIdade(TipoPilha Pilha)
{
    int i;
    int maior, menor;
    float media, soma = 0;

    if (Vazia(Pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }

    maior = Pilha.Item[0].idade;
    menor = Pilha.Item[0].idade;

    for (i = 0; i < Pilha.Topo; i++)
    {
        if (Pilha.Item[i].idade > maior)
            maior = Pilha.Item[i].idade;

        if (Pilha.Item[i].idade < menor)
            menor = Pilha.Item[i].idade;

        soma += Pilha.Item[i].idade;
    }

    media = soma / Pilha.Topo;

    printf("Maior idade: %d\n", maior);
    printf("Menor idade: %d\n", menor);
    printf("Media das idades: %.2f\n", media);
}
void DividePilhaParImpar(TipoPilha Original, TipoPilha *P1, TipoPilha *P2)
{
    int i;

    FPVazia(P1);
    FPVazia(P2);

    for (i = 0; i < Original.Topo; i++)
    {
        if (Original.Item[i].cod % 2 == 0)
            Empilha(Original.Item[i], P1);
        else
            Empilha(Original.Item[i], P2);
    }
}
int main()
{
    int opcao, resposta;
    setlocale(LC_ALL, ""); // aceitar acentos
    FPVazia(&Pilha);
    do
    {

        printf("\n\nMENU\n\n");
        printf("\nDigite a opc�o desejada:\n ");
        printf("0 - Sair\n");
        printf("1 - Esvaziar pilha\n");
        printf("2- Verificar se a pilha esta vazia\n");
        printf("3 - Inserir elemento na pilha\n");
        printf("4 - Imprimir os elementos da pilha no sentido topo fundo \n");
        printf("5 - Imprimir os elementos da pilha no sentido fundo topo \n");
        printf("6 - Desempilhar elemento da pilha\n");
        printf("7 - Tamanho da Pilha\n");
        printf("8 - Procure um elemento por codigo\n");
        printf("9 - Dividir pilha em duas\n");
        printf("10 - Ordenar pilha por codigo sentido fundo topo \n");
        printf("11 - Maior, menor e media das idades\n");
        printf("12 - Dividir pilha em par e impar\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
        {
            printf("PROGRAMA ENCERRADO!\n");
            break;
        }
        case 1:
        {
            FPVazia(&Pilha);
            printf("\nA PILHA VAZIA\n");
            break;
        }
        case 2:
        {
            resposta = Vazia(Pilha);
            if (resposta == 1)
                printf("\n PILHA ESTA VAZIA\n");
            else
                printf("\n PILHA N�O ESTA VAZIA\n");
            break;
        }
        case 3:
        {
            printf("Digite o codigo\n");
            scanf("%d", &x.cod);
            printf("Digite a idade\n");
            scanf("%d", &x.idade);
            Empilha(x, &Pilha);
            break;
        }
        case 4:
        {
            ImprimeTopoFundo(Pilha);
            break;
        }
        case 5:
        {
            ImprimeFundoTopo(Pilha);
            break;
        }

        case 6:
        {
            Desempilha(&Pilha, &x);
            break;
        }

        case 7:
        {
            printf("A pilha tem %d elementos\n", Tamanho(Pilha));
            break;
        }
        case 8:
        {
            int codigo;
            printf("Digite o codigo que deseja buscar: ");
            scanf("%d", &codigo);
            buscarPorCodigo(&Pilha, codigo);
            break;
        }
        case 9:
        {
            TipoPilha Pilha1, Pilha2;

            FPVazia(&Pilha1);
            FPVazia(&Pilha2);

            partirPilha(&Pilha, &Pilha1, &Pilha2);

            printf("Pilha 1:\n");
            ImprimeTopoFundo(Pilha1);

            printf("Pilha 2:\n");
            ImprimeTopoFundo(Pilha2);

            break;
        }
        case 10:
        {
            OrdenaPilhaPorCodigo(&Pilha);
            ImprimeFundoTopo(Pilha);
            break;
        }
        case 11:
        {
            MaiorMenorMediaIdade(Pilha);
            break;
        }
        case 12:
        {
            TipoPilha Pilha1, Pilha2;

            DividePilhaParImpar(Pilha, &Pilha1, &Pilha2);

            printf("\nPilha PAR:\n");
            ImprimeTopoFundo(Pilha1);

            printf("\nPilha IMPAR:\n");
            ImprimeTopoFundo(Pilha2);

            break;
        }

        default:
            printf("\n\nOpcao invalida\n\n");
        } // fim do case
        _getch();
        system("cls");
    } while (opcao != 0); // fim do while
    return (0);
}
