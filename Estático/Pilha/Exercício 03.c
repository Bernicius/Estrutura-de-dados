#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAMM 100

typedef struct Spilha
{
    char vetor[TAMM];
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

void empilhar(PILHA *pilha, char elemento)
{
    if (!cheio(*pilha))
    {
        pilha->vetor[++pilha->n] = elemento;
    }
}

char desempilhar(PILHA *pilha)
{
    if (!vazio(*pilha))
    {
        return pilha->vetor[pilha->n--];
    }
    return '\0'; // Retorno de erro se a pilha estiver vazia
}

void converter_para_minusculas(char *palavra)
{
    for (int i = 0; palavra[i]; i++)
    {
        palavra[i] = tolower(palavra[i]);
    }
}

int verificar_palindromo(const char *palavra)
{
    PILHA pilha;
    inicializar(&pilha);
    
    for (int i = 0; i < strlen(palavra); i++)
    {
        empilhar(&pilha, palavra[i]);
    }

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] != desempilhar(&pilha))
        {
            return 0; // Não é um palíndromo
        }
    }

    return 1; // É um palíndromo
}

int menu()
{
    int op;
    printf("\nMenu:\n");
    printf("1. Verificar se a palavra é um palíndromo\n");
    printf("2. Sair\n");
    printf("Escolha uma opção: ");
    
    while (scanf("%d", &op) != 1)
    {
        while (getchar() != '\n'); // Limpar o buffer
        printf("Entrada inválida! Escolha uma opção: ");
    }

    return op;
}

void ler_palavra(char *palavra)
{
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
}

int main()
{
    char palavra[TAMM];
    int op;

    do
    {
        op = menu();
        switch (op)
        {
        case 1: // Verificar palíndromo
            ler_palavra(palavra);
            converter_para_minusculas(palavra);
            if (verificar_palindromo(palavra))
            {
                printf("A palavra '%s' é um palíndromo.\n", palavra);
            }
            else
            {
                printf("A palavra '%s' não é um palíndromo.\n", palavra);
            }
            break;

        case 2: // Sair
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 2);

    return 0;
}
