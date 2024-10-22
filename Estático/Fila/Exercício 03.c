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

void mostrar_fila(FILA *fila) {
    int i = (fila->inicio + 1) % TAMM;
    if (!vazio_fila(*fila)) {
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

// Função para contar o número de elementos em uma fila
int contar_elementos(FILA *fila) {
    int count = 0;
    int inicio = fila->inicio;

    while (1) {
        inicio = (inicio + 1) % TAMM;
        if (inicio == (fila->fim + 1) % TAMM) {
            break;
        }
        count++;
    }
    return count;
}

// Função para testar se F1 tem mais elementos que F2
int fila_maior(FILA *F1, FILA *F2) {
    int countF1 = contar_elementos(F1);
    int countF2 = contar_elementos(F2);
    return countF1 > countF2;
}

// Função de menu
int menu() {
    int op;
    printf("\nMenu:\n");
    printf("1. Enfileirar elemento na Fila 1\n");
    printf("2. Enfileirar elemento na Fila 2\n");
    printf("3. Mostrar Fila 1\n");
    printf("4. Mostrar Fila 2\n");
    printf("5. Testar se Fila 1 tem mais elementos que Fila 2\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    FILA F1, F2;
    inicializar_fila(&F1);
    inicializar_fila(&F2);
    int op, elemento;

    do {
        op = menu();
        switch (op) {
            case 1: // Enfileirar na Fila 1
                printf("Digite um elemento para enfileirar na Fila 1: ");
                scanf("%d", &elemento);
                enfileirar(&F1, elemento);
                break;

            case 2: // Enfileirar na Fila 2
                printf("Digite um elemento para enfileirar na Fila 2: ");
                scanf("%d", &elemento);
                enfileirar(&F2, elemento);
                break;

            case 3: // Mostrar Fila 1
                printf("Fila 1:\n");
                mostrar_fila(&F1);
                break;

            case 4: // Mostrar Fila 2
                printf("Fila 2:\n");
                mostrar_fila(&F2);
                break;

            case 5: // Testar se F1 tem mais elementos que F2
                if (fila_maior(&F1, &F2)) {
                    printf("Fila 1 tem mais elementos que Fila 2.\n");
                } else {
                    printf("Fila 1 não tem mais elementos que Fila 2.\n");
                }
                break;

            case 6: // Sair
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 6);

    return 0;
}
