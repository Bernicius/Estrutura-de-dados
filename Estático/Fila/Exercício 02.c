#include <stdio.h>
#define TAMM 10

// Estrutura da Pilha
typedef struct sPilha {
    int vetor[TAMM];
    int topo;
} PILHA;

// Estrutura da Fila
typedef struct sFila {
    int vetor[TAMM];
    int inicio, fim;
} FILA;

// Funções da Pilha
void inicializar_pilha(PILHA *pilha) {
    pilha->topo = -1;
}

int vazio_pilha(PILHA pilha) {
    return pilha.topo == -1;
}

int cheio_pilha(PILHA pilha) {
    return pilha.topo >= TAMM - 1;
}

void empilhar(PILHA *pilha, int elemento) {
    if (!cheio_pilha(*pilha)) {
        pilha->vetor[++pilha->topo] = elemento;
    } else {
        printf("Pilha cheia\n");
    }
}

int desempilhar(PILHA *pilha) {
    if (!vazio_pilha(*pilha)) {
        return pilha->vetor[pilha->topo--];
    }
    return -1; // Retorno de erro
}

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
        printf("Elemento %d enfileirado.\n", elemento);
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

// Função para inverter a fila usando uma pilha
void inverter_fila(FILA *fila) {
    PILHA pilha;
    inicializar_pilha(&pilha);

    // Transferir elementos da fila para a pilha
    while (!vazio_fila(*fila)) {
        empilhar(&pilha, desemfileirar(fila));
    }

    // Transferir elementos da pilha de volta para a fila
    while (!vazio_pilha(pilha)) {
        enfileirar(fila, desempilhar(&pilha));
    }
}

// Função de menu
int menu() {
    int op;
    printf("\nMenu:\n");
    printf("1. Enfileirar elemento\n");
    printf("2. Desenfileirar elemento\n");
    printf("3. Mostrar fila\n");
    printf("4. Inverter fila\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    FILA fila;
    inicializar_fila(&fila);
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

            case 4: // Inverter fila
                inverter_fila(&fila);
                printf("Fila invertida com sucesso!\n");
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
