#include <stdio.h>
#include <string.h>
#define TAMM 100

typedef struct Spilha {
    int vetor[TAMM];
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

void reorganizar_pilha(PILHA *original) {
    PILHA pilha_par, pilha_impar;
    inicializar_pilha(&pilha_par);
    inicializar_pilha(&pilha_impar);

    // Transferir elementos para as pilhas auxiliares
    while (!vazio_pilha(*original)) {
        int elemento = desempilhar(original);
        if (elemento % 2 == 0) {
            empilhar(&pilha_par, elemento); // Empilha números pares
        } else {
            empilhar(&pilha_impar, elemento); // Empilha números ímpares
        }
    }

    // Reinserir os pares na pilha original (na base)
    while (!vazio_pilha(pilha_par)) {
        empilhar(original, desempilhar(&pilha_par));
    }

    // Reinserir os ímpares na pilha original (no topo)
    while (!vazio_pilha(pilha_impar)) {
        empilhar(original, desempilhar(&pilha_impar));
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
    printf("2. Reorganizar pilha (pares na base, ímpares no topo)\n");
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

        case 2: // Reorganizar pilha
            reorganizar_pilha(&pilha);
            printf("Pilha reorganizada com sucesso.\n");
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
