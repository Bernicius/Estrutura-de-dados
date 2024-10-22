#include <stdio.h>
#define TAMM 10

typedef struct sFila {
    int vetor[TAMM];
    int inicio, fim;
} FILA;

void inicializar(FILA *fila) {
    fila->inicio = TAMM - 1;
    fila->fim = TAMM - 1;
}

int cheio(FILA fila) {
    return (fila.fim + 1) % TAMM == fila.inicio;
}

int vazio(FILA fila) {
    return fila.inicio == fila.fim;
}

void enfileirar(FILA *fila, int elemento) {
    if (cheio(*fila)) {
        printf("Fila cheia\n");
    } else {
        fila->fim = (fila->fim + 1) % TAMM;
        fila->vetor[fila->fim] = elemento;
        printf("Elemento %d enfileirado.\n", elemento);
    }
}

int desemfileirar(FILA *fila) {
    int retorno = -1;
    if (vazio(*fila)) {
        printf("Fila vazia\n");
    } else {
        fila->inicio = (fila->inicio + 1) % TAMM;
        retorno = fila->vetor[fila->inicio];
    }
    return retorno;
}

void mostrar_fila(FILA *fila) {
    int i = (fila->inicio + 1) % TAMM;
    if (!vazio(*fila)) {
        printf("FILA:");
        while (i != (fila->fim + 1) % TAMM) {
            printf("[%d]", fila->vetor[i]);
            i = (i + 1) % TAMM;
        }
        printf("\n");
    } else {
        printf("FILA VAZIA\n");
    }
}

int comprimento_fila(FILA fila) {
    return (fila.fim - fila.inicio + TAMM) % TAMM;
}

int menu() {
    int op;
    printf("\nMenu:\n");
    printf("1. Enfileirar elemento\n");
    printf("2. Desenfileirar elemento\n");
    printf("3. Mostrar fila\n");
    printf("4. Mostrar comprimento da fila\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    FILA fila;
    inicializar(&fila);
    int op, elemento;

    do {
        op = menu();
        switch (op) {
            case 1: // Enfileirar
                printf("Digite um elemento para enfileirar: ");
                scanf("%d", &elemento);
                enfileirar(&fila, elemento);
                break;

            case 2: // Desenfileirar
                elemento = desemfileirar(&fila);
                if (elemento != -1) {
                    printf("Elemento %d desenfileirado.\n", elemento);
                }
                break;

            case 3: // Mostrar fila
                mostrar_fila(&fila);
                break;

            case 4: // Mostrar comprimento da fila
                printf("Comprimento da fila: %d\n", comprimento_fila(fila));
                break;

            case 5: // Sair
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 5);

    return 0;
}

