#include <stdio.h>
#include <stdlib.h>

typedef struct sDeque {
    int elemento;
    struct sDeque *next;
    struct sDeque *back;
} DEQUE;

void inicializar(DEQUE **inicio, DEQUE **fim) {
    *inicio = NULL;
    *fim = NULL;
}

int vazio(DEQUE *inicio) {
    return (inicio == NULL);
}

DEQUE* getnode() {
    return (DEQUE*)malloc(sizeof(DEQUE));
}

void freenode(DEQUE *d) {
    free(d);
}

void enfileirar_inicio(DEQUE **inicio, DEQUE **fim, int elemento) {
    DEQUE *q = getnode();
    if (q != NULL) {
        q->elemento = elemento;
        q->next = *inicio;
        q->back = NULL;
        if (vazio(*inicio)) {
            *fim = q;
        } else {
            (*inicio)->back = q;
        }
        *inicio = q;
    } else {
        printf("No nao pode ser alocado\n");
    }
}

void enfileirar_fim(DEQUE **inicio, DEQUE **fim, int elemento) {
    DEQUE *q = getnode();
    if (q != NULL) {
        q->elemento = elemento;
        q->next = NULL;
        q->back = *fim;
        if (vazio(*inicio)) {
            *inicio = q;
        } else {
            (*fim)->next = q;
        }
        *fim = q;
    } else {
        printf("No nao pode ser alocado\n");
    }
}

void remover_inicio(DEQUE **inicio, DEQUE **fim) {
    if (!vazio(*inicio)) {
        DEQUE *temp = *inicio;
        *inicio = (*inicio)->next;
        if (*inicio != NULL) {
            (*inicio)->back = NULL;
        } else {
            *fim = NULL;
        }
        freenode(temp);
    } else {
        printf("Deque vazio\n");
    }
}

void remover_fim(DEQUE **inicio, DEQUE **fim) {
    if (!vazio(*fim)) {
        DEQUE *temp = *fim;
        *fim = (*fim)->back;
        if (*fim != NULL) {
            (*fim)->next = NULL;
        } else {
            *inicio = NULL;
        }
        freenode(temp);
    } else {
        printf("Deque vazio\n");
    }
}

void imprimir_e_remover(DEQUE **inicio, DEQUE **fim) {
    while (!vazio(*inicio)) {
        printf("Elemento: %d\n", (*inicio)->elemento);
        remover_inicio(inicio, fim);
    }
}

int menu() {
    int op;
    printf("\nMenu de Opcoes:\n");
    printf("1. Enfileirar no inicio\n");
    printf("2. Enfileirar no fim\n");
    printf("3. Remover do inicio\n");
    printf("4. Remover do fim\n");
    printf("5. Imprimir e remover todos os elementos\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    return op;
}

int main() {
    DEQUE *inicio, *fim;
    inicializar(&inicio, &fim);
    int opcao, elemento;

    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser enfileirado no inicio: ");
                scanf("%d", &elemento);
                enfileirar_inicio(&inicio, &fim, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser enfileirado no fim: ");
                scanf("%d", &elemento);
                enfileirar_fim(&inicio, &fim, elemento);
                break;
            case 3:
                remover_inicio(&inicio, &fim);
                break;
            case 4:
                remover_fim(&inicio, &fim);
                break;
            case 5:
                imprimir_e_remover(&inicio, &fim);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

