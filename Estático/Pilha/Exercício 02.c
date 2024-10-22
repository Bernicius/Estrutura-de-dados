#include <stdio.h>
#define TAMM 15

typedef struct Spilha
{
    int vetor[TAMM];
    int n;
} PILHA;

void inicializar(PILHA *pilha)
{
    pilha->n = -1;
}

int vazio(PILHA pilha)
{
    return pilha.n == -1;
}

int cheio(PILHA pilha)
{
    return pilha.n >= TAMM - 1;
}

void empilhar(PILHA *pilha, int elemento)
{
    if (!cheio(*pilha))
    {
        pilha->vetor[++pilha->n] = elemento;
    }
    else
    {
        printf("Pilha cheia, não é possível empilhar %d\n", elemento);
    }
}

int desempilhar(PILHA *pilha)
{
    if (!vazio(*pilha))
    {
        return pilha->vetor[pilha->n--];
    }
    else
    {
        printf("Pilha vazia, não é possível desempilhar\n");
        return -1; // Retorno de erro
    }
}

void mostrar_pilha(PILHA *pilha, const char *nome)
{
    if (vazio(*pilha))
    {
        printf("Pilha %s vazia.\n", nome);
    }
    else
    {
        printf("Elementos da pilha %s:\n", nome);
        for (int i = 0; i <= pilha->n; i++)
        {
            printf("[%d] ", pilha->vetor[i]);
        }
        printf("\n");
    }
}

int menu()
{
    int op;
    printf("\nMenu:\n");
    printf("1. Inserir número\n");
    printf("2. Desempilhar (para zero)\n");
    printf("3. Mostrar pilhas\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    
    while (scanf("%d", &op) != 1)
    {
        while (getchar() != '\n'); // Limpar o buffer
        printf("Entrada inválida! Escolha uma opção: ");
    }

    return op;
}

int main()
{
    PILHA pilha_P, pilha_N;
    inicializar(&pilha_P);
    inicializar(&pilha_N);

    int elemento;
    int op;

    do
    {
        op = menu();
        switch (op)
        {
        case 1: // Inserir número
            printf("Digite um número (digite 0 para sair do menu): ");
            scanf("%d", &elemento);
            if (elemento > 0)
            {
                empilhar(&pilha_P, elemento);
            }
            else if (elemento < 0)
            {
                empilhar(&pilha_N, elemento);
            }
            else
            {
                printf("Zero lido. Você pode escolher desempilhar agora.\n");
            }
            break;

        case 2: // Desempilhar
            printf("Zero lido. Desempilhando de ambas as pilhas...\n");
            desempilhar(&pilha_P);
            desempilhar(&pilha_N);
            break;

        case 3: // Mostrar pilhas
            mostrar_pilha(&pilha_P, "P");
            mostrar_pilha(&pilha_N, "N");
            break;

        case 4: // Sair
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 4);

    return 0;
}
