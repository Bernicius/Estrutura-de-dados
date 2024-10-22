#include <stdio.h>
#define TAMM 10

// Estrutura da Fila
typedef struct sFila {
    int vetor[TAMM];
    int inicio, fim;
} FILA;

// Funções da Fila
void inicializar_fila(FILA *fila) {
    fila->inicio = TAMM - 1;
    fila->fim = TAMM - 1;
}

int cheio_fila(FILA fila) {
    return (fila.fim + 1) % TAMM == fila.inicio;
}

int vazio_fila(FILA fila) {
    return fila.inicio == fila.fim;
}

void enfileirar(FILA *fila, int elemento) {
    if (cheio_fila(*fila)) {
        printf("Fila cheia\n");
    } else {
        fila->fim = (fila->fim + 1) % TAMM;
        fila->vetor[fila->fim] = elemento;
    }
}

int desemfileirar(FILA *fila) {
    int retorno = -1;
    if (vazio_fila(*fila)) {
        printf("Fila vazia\n");
    } else {
        fila->inicio = (fila->inicio + 1) % TAMM;
        retorno = fila->vetor[fila->inicio];
    }
    return retorno;
}

// Função para encontrar o maior elemento
int encontrar_maior(FILA *fila) {
    if (vazio_fila(*fila)) {
        printf("Fila vazia. Não é possível calcular.\n");
        return -1; // Indica que a fila está vazia
    }

    int maior = fila->vetor[(fila->inicio + 1) % TAMM];
    int i = (fila->inicio + 1) % TAMM;

    while (i != (fila->fim + 1) % TAMM) {
        if (fila->vetor[i] > maior) {
            maior = fila->vetor[i];
        }
        i = (i + 1) % TAMM;
    }

    return maior;
}

// Função para encontrar o menor elemento
int encontrar_menor(FILA *fila) {
    if (vazio_fila(*fila)) {
        printf("Fila vazia. Não é possível calcular.\n");
        return -1; // Indica que a fila está vazia
    }

    int menor = fila->vetor[(fila->inicio + 1) % TAMM];
    int i = (fila->inicio + 1) % TAMM;

    while (i != (fila->fim + 1) % TAMM) {
        if (fila->vetor[i] < menor) {
            menor = fila->vetor[i];
        }
        i = (i + 1) % TAMM;
    }

    return menor;
}

// Função para calcular a média
float calcular_media(FILA *fila) {
    int soma =0;
    int count =0;
    if (vazio_fila(*fila)) {
        printf("Fila vazia. Não é possível calcular.\n");
        return soma; // Indica que a fila está vazia
    }
    int i = (fila->inicio + 1) % TAMM;

    while (i != (fila->fim + 1) % TAMM) {
        soma += fila->vetor[i];
        count++;
        i = (i + 1) % TAMM;
    }

    return (float)soma / count;
}

// Função de menu
int menu() {
    int op;
    printf("\nMenu:\n");
    printf("1. Enfileirar elemento\n");
    printf("2. Calcular maior, menor e média\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    FILA fila;
    inicializar_fila(&fila);
    int maior, menor;
    float media;
    int op;

    do {
        op = menu();
        switch (op) {
            case 1: { // Enfileirar
                int elemento; // Declaração da variável aqui
                printf("Digite um elemento para enfileirar: ");
                scanf("%d", &elemento);
                enfileirar(&fila, elemento);
                break;
            }

            case 2: { // Calcular maior, menor e média
                maior = encontrar_maior(&fila);
                menor = encontrar_menor(&fila);
                media = calcular_media(&fila);

                if (maior != -1 && menor != -1) {
                    printf("Maior: %d\n", maior);
                    printf("Menor: %d\n", menor);
                    printf("Média: %.2f\n", media);
                }
                break;
            }

            case 3: // Sair
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 3);

    return 0;
}
