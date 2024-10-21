#include <stdio.h>
#define TAM 10

typedef struct {
    int vetor[TAM];
    int n;
} LISTA;

// Inicializa a lista
void inicializar(LISTA *lista) {
    lista->n = -1; // Indica que a lista está vazia
}

// Verifica se a lista está vazia
int lista_vazia(LISTA lista) {
    return (lista.n == -1);
}

// Verifica se a lista está cheia
int lista_cheia(LISTA lista) {
    return (lista.n == TAM - 1);
}

// Insere um elemento no início da lista
int inserir_inicio(LISTA *lista, int elemento) {
    if (lista_cheia(*lista)) {
        printf("Lista cheia, não é possível inserir no início.\n");
        return -1; // Erro
    }
    
    for (int i = lista->n; i >= 0; i--) {
        lista->vetor[i + 1] = lista->vetor[i]; // Move elementos para a direita
    }
    lista->vetor[0] = elemento; // Insere o elemento no início
    lista->n++; // Incrementa o tamanho da lista
    return 0; // Sucesso
}

// Insere um elemento no fim da lista
int inserir_fim(LISTA *lista, int elemento) {
    if (lista_cheia(*lista)) {
        printf("Lista cheia, não é possível inserir no fim.\n");
        return -1; // Erro
    }

    lista->vetor[++lista->n] = elemento; // Insere o elemento no fim
    return 0; // Sucesso
}

// Remove o último elemento da lista
int remover_fim(LISTA *lista) {
    if (lista_vazia(*lista)) {
        printf("Lista vazia, não é possível remover o fim.\n");
        return -1; // Erro
    }

    lista->n--; // Decrementa o tamanho da lista
    return 0; // Sucesso
}

// Remove o primeiro elemento da lista
int remover_inicio(LISTA *lista) {
    if (lista_vazia(*lista)) {
        printf("Lista vazia, não é possível remover o início.\n");
        return -1; // Erro
    }

    for (int i = 0; i < lista->n; i++) {
        lista->vetor[i] = lista->vetor[i + 1]; // Move elementos para a esquerda
    }
    lista->n--; // Decrementa o tamanho da lista
    return 0; // Sucesso
}

// Mostra os elementos da lista
void mostrar_lista(LISTA lista) {
    if (lista_vazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    for (int i = 0; i <= lista.n; i++) {
        printf("[%d] ", lista.vetor[i]);
    }
    printf("\n");
}

// Exibe o menu e retorna a opção escolhida
int menu() {
    int op;
    printf("\n[01] Inserir no início\n");
    printf("[02] Inserir no fim\n");
    printf("[03] Remover do início\n");
    printf("[04] Remover do fim\n");
    printf("[05] Mostrar lista\n");
    printf("[06] Sair\n");
    printf("Digite uma opcao: ");
    scanf("%d", &op);
    return op;
}

// Função principal
int main() {
    int op, elemento;
    LISTA lista;
    inicializar(&lista); // Inicializa a lista

    do {
        op = menu();
        switch (op) {
            case 1:
                printf("Digite um elemento: ");
                scanf("%d", &elemento);
                inserir_inicio(&lista, elemento);
                break;
            case 2:
                printf("Digite um elemento: ");
                scanf("%d", &elemento);
                inserir_fim(&lista, elemento);
                break;
            case 3:
                remover_inicio(&lista);
                break;
            case 4:
                remover_fim(&lista);
                break;
            case 5:
                mostrar_lista(lista);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (op != 6);

    return 0;
}
