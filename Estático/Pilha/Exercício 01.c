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

void mostrar_pilha(PILHA *pilha)
{
    PILHA aux;
    inicializar(&aux);
    printf("Elementos da pilha:\n");
    while (!vazio(*pilha))
    {
        int topo = desempilhar(pilha);
        printf("[%d]\n", topo);
        empilhar(&aux, topo);
    }
    // Restaurar a pilha original
    while (!vazio(aux))
    {
        empilhar(pilha, desempilhar(&aux));
    }
}

int main()
{
    PILHA pilha;
    inicializar(&pilha);

    int elemento;
    for (int i = 0; i < TAMM; i++)
    {
        printf("Digite um número: ");
        scanf("%d", &elemento);

        if (elemento % 2 == 0)
        {
            empilhar(&pilha, elemento);
        }
        else
        {
            printf("Número ímpar lido. Desempilhando...\n");
            desempilhar(&pilha);
        }
    }

    // Mostrar e esvaziar a pilha
    mostrar_pilha(&pilha);

    return 0;
}
