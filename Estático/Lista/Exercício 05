#include <stdio.h>
#define TAM 20 // Tamanho máximo das listas

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

// Intercala duas listas e armazena o resultado em L3
int intercalar_listas(LISTA L1, LISTA L2, LISTA *L3) {
    inicializar(L3); // Inicializa a lista L3

    int i;
    int max_tam = (L1.n > L2.n) ? L1.n : L2.n; // Tamanho máximo para iteração

    for (i = 0; i < max_tam; i++) {
        if (i < L1.n) {
            inserir_fim(L3, L1.vetor[i]); // Adiciona elemento de L1
        }
        if (i < L2.n) {
            inserir_fim(L3, L2.vetor[i]); // Adiciona elemento de L2
        }
    }
    return 0; // Sucesso
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
    printf("[2] Inserir elemento na lista L2\n");
    printf("[3] Intercalar L1 e L2 em L3\n");
    printf("[4] Mostrar lista L1\n");
    printf("[5] Mostrar lista L2\n");
    printf("[6] Mostrar lista L3\n");
    printf("[7] Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

// Função principal
int main() {
    LISTA L1, L2, L3;
    inicializar(&L1); // Inicializa L1
    inicializar(&L2); // Inicializa L2
    inicializar(&L3); // Inicializa L3

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
                printf("Digite um elemento para L2: ");
                scanf("%d", &elemento);
                inserir_fim(&L2, elemento);
                break;
            case 3:
                intercalar_listas(L1, L2, &L3);
                printf("Listas intercaladas com sucesso.\n");
                break;
            case 4:
                printf("Lista L1: ");
                mostrar_lista(L1);
                break;
            case 5:
                printf("Lista L2: ");
                mostrar_lista(L2);
                break;
            case 6:
                printf("Lista L3: ");
                mostrar_lista(L3);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(op != 7);

    return 0;
}
