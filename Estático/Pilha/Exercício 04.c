#include <stdio.h>
#include <string.h>
#define TAMM 100
#define TAM_LISTA 100

typedef struct Spilha {
    int vetor[TAMM];
    int n;
} PILHA;

typedef struct Lista {
    int vetor[TAM_LISTA];
    int n;
} LISTA;

void inicializar_pilha(PILHA *pilha) {
    pilha->n = -1;
}

int vazio_pilha(PILHA pilha) {
    return pilha.n == -1;
}

int cheio_pilha(PILHA pilha) {
    return pilha.n >= TAMM - 1;
}

void empilhar(PILHA *pilha, int elemento) {
    if (!cheio_pilha(*pilha)) {
        pilha->vetor[++pilha->n] = elemento;
    } else {
        printf("Pilha cheia, não é possível empilhar %d\n", elemento);
    }
}

int desempilhar(PILHA *pilha) {
    if (!vazio_pilha(*pilha)) {
        return pilha->vetor[pilha->n--];
    }
    return -1; // Retorno de erro se a pilha estiver vazia
}

void inicializar_lista(LISTA *lista) {
    lista->n = -1;
}

void adicionar_lista(LISTA *lista, int elemento) {
    if (lista->n < TAM_LISTA - 1) {
        lista->vetor[++lista->n] = elemento;
    } else {
        printf("Lista auxiliar cheia, não é possível adicionar %d\n", elemento);
    }
}

void inverter_pilha(PILHA *pilha) {
    LISTA lista_aux;
    inicializar_lista(&lista_aux);

    // Transferir elementos da pilha para a lista auxiliar
    while (!vazio_pilha(*pilha)) {
        adicionar_lista(&lista_aux, desempilhar(pilha));
    }

    // Transferir elementos da lista auxiliar de volta para a pilha
    for (int i = 0; i <= lista_aux.n; i++) {
        empilhar(pilha, lista_aux.vetor[i]);
    }
}

void mostrar_pilha(PILHA *pilha) {
    if (vazio_pilha(*pilha)) {
        printf("Pilha vazia.\n");
    } else {
        printf("Elementos da pilha:\n");
        for (int i = 0; i <= pilha->n; i++) {
            printf("[%d] ", pilha->vetor[i]);
        }
        printf("\n");
    }
}

int menu() {
    int op;
    printf("\nMenu:\n");
    printf("1. Empilhar elemento\n");
    printf("2. Inverter pilha\n");
    printf("3. Mostrar pilha\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    
    scanf("%d", &op); // Leitura direta sem validação
    return op;
}

int main() {
    PILHA pilha;
    inicializar_pilha(&pilha);
    int op, elemento;

    do {
        op = menu();
        switch (op) {
        case 1: // Empilhar
            printf("Digite um elemento: ");
            scanf("%d", &elemento);
            empilhar(&pilha, elemento);
            break;

        case 2: // Inverter pilha
            inverter_pilha(&pilha);
            printf("Pilha invertida com sucesso.\n");
            break;

        case 3: // Mostrar pilha
            mostrar_pilha(&pilha);
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
