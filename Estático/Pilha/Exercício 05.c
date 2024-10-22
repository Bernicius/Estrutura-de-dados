#include <stdio.h>
#include <string.h>
#define TAMM 100

typedef struct Spilha {
    char vetor[TAMM];
    int n;
} PILHA;

void inicializar_pilha(PILHA *pilha) {
    pilha->n = -1;
}

int vazio_pilha(PILHA pilha) {
    return pilha.n == -1;
}

int cheio_pilha(PILHA pilha) {
    return pilha.n >= TAMM - 1;
}

void empilhar(PILHA *pilha, char elemento) {
    if (!cheio_pilha(*pilha)) {
        pilha->vetor[++pilha->n] = elemento;
    } else {
        printf("Pilha cheia, não é possível empilhar %c\n", elemento);
    }
}

char desempilhar(PILHA *pilha) {
    if (!vazio_pilha(*pilha)) {
        return pilha->vetor[pilha->n--];
    }
    return '\0'; // Retorno de erro se a pilha estiver vazia
}

void trocar_topo_base(PILHA *pilha) {
    if (vazio_pilha(*pilha)) {
        printf("A pilha está vazia, não é possível trocar elementos.\n");
        return;
    }

    char topo = desempilhar(pilha); // Remove o elemento do topo
    char base = pilha->vetor[0];     // Acesso direto ao elemento da base

    // Empilha novamente o elemento do topo no lugar da base
    empilhar(pilha, base);
    
    // Empilha o antigo topo na base
    pilha->vetor[0] = topo; 
}

void mostrar_pilha(PILHA *pilha) {
    if (vazio_pilha(*pilha)) {
        printf("Pilha vazia.\n");
    } else {
        printf("Elementos da pilha:\n");
        for (int i = 0; i <= pilha->n; i++) {
            printf("[%c] ", pilha->vetor[i]);
        }
        printf("\n");
    }
}

int menu() {
    int op;
    printf("\nMenu:\n");
    printf("1. Empilhar elemento\n");
    printf("2. Trocar topo com base\n");
    printf("3. Mostrar pilha\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    
    scanf("%d", &op); // Leitura direta sem validação
    return op;
}

int main() {
    PILHA pilha;
    inicializar_pilha(&pilha);
    int op;
    char elemento;

    do {
        op = menu();
        switch (op) {
        case 1: // Empilhar
            printf("Digite um elemento: ");
            scanf(" %c", &elemento); // O espaço antes de %c ignora qualquer espaço em branco
            empilhar(&pilha, elemento);
            break;

        case 2: // Trocar topo com base
            trocar_topo_base(&pilha);
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
