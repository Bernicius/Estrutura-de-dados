#include <stdio.h>
#define TAM 20 // Tamanho máximo da lista

typedef struct {
    int vetor[TAM]; // Array para armazenar os números inteiros
    int n; // Tamanho atual da lista
} LISTA;

// Inicializa a lista
void inicializar(LISTA *lista) {
    lista->n = 0; // Indica que a lista está vazia
}

// Verifica se a lista está cheia
int lista_cheia(LISTA lista) {
    return (lista.n == TAM);
}

// Insere um elemento no final da lista
int inserir_fim(LISTA *lista, int elemento) {
    if (lista_cheia(*lista)) {
        printf("Lista cheia, não é possível inserir o elemento.\n");
        return -1; // Erro
    }
    lista->vetor[lista->n] = elemento;
    lista->n++; // Incrementa o tamanho da lista
    return 0; // Sucesso
}

// Inverte a lista L1 e armazena em L2
void inverter_lista(LISTA L1, LISTA *L2) {
    inicializar(L2); // Inicializa a lista L2
    for (int i = L1.n - 1; i >= 0; i--) {
        inserir_fim(L2, L1.vetor[i]); // Adiciona os elementos de L1 em ordem inversa
    }
}

// Mostra os elementos da lista
void mostrar_lista(LISTA lista) {
    if (lista.n == 0) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < lista.n; i++) {
        printf("[%d] ", lista.vetor[i]);
    }
    printf("\n");
}

// Exibe o menu e retorna a opção escolhida
int menu() {
    int op;
    printf("\nMenu:\n");
    printf("[1] Inserir elemento na lista L1\n");
    printf("[2] Inverter lista L1 e armazenar em L2\n");
    printf("[3] Mostrar lista L1\n");
    printf("[4] Mostrar lista L2\n");
    printf("[5] Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

// Função principal
int main() {
    LISTA L1, L2;
    inicializar(&L1); // Inicializa L1
    inicializar(&L2); // Inicializa L2

    int op, elemento;

    do {
        op = menu();
        switch(op) {
            case 1:
                printf("Digite um elemento para L1: ");
                scanf("%d", &elemento);
                inserir_fim(&L1, elemento);
                break;
            case 2:
                inverter_lista(L1, &L2);
                printf("Lista L1 invertida e armazenada em L2.\n");
                break;
            case 3:
                printf("Lista L1: ");
                mostrar_lista(L1);
                break;
            case 4:
                printf("Lista L2: ");
                mostrar_lista(L2);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(op != 5);

    return 0;
}
