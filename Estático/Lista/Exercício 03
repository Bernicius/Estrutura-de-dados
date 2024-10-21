#include <stdio.h>
#define TAM 10

typedef struct {
    float vetor[TAM]; // Array para armazenar números reais
    int n; // Tamanho atual da lista
} LISTA;

// Inicializa a lista
void inicializar(LISTA *lista) {
    lista->n = 0; // Indica que a lista está vazia
}

// Verifica se a lista está vazia
int lista_vazia(LISTA lista) {
    return (lista.n == 0);
}

// Verifica se a lista está cheia
int lista_cheia(LISTA lista) {
    return (lista.n == TAM);
}

// Insere um elemento na lista, mantendo a ordem crescente
int inserir_crescentemente(LISTA *lista, float elemento) {
    if (lista_cheia(*lista)) {
        printf("Lista cheia, não é possível inserir o elemento.\n");
        return -1; // Erro
    }

    int i = 0;
    // Encontra a posição correta para inserir o elemento
    while (i < lista->n && lista->vetor[i] < elemento) {
        i++;
    }

    // Move os elementos para a direita para abrir espaço
    for (int j = lista->n; j > i; j--) {
        lista->vetor[j] = lista->vetor[j - 1];
    }
    lista->vetor[i] = elemento; // Insere o elemento na posição correta
    lista->n++; // Incrementa o tamanho da lista
    return 0; // Sucesso
}

// Remove um elemento da lista
int remover_valor(LISTA *lista, float valor) {
    if (lista_vazia(*lista)) {
        printf("Lista vazia, não é possível remover o elemento.\n");
        return -1; // Erro
    }

    int i;
    // Busca o valor a ser removido
    for (i = 0; i < lista->n; i++) {
        if (lista->vetor[i] == valor) {
            break;
        }
    }

    if (i == lista->n) {
        printf("Valor não encontrado na lista.\n");
        return -1; // Erro: valor não encontrado
    }

    // Move os elementos para a esquerda para eliminar lacuna
    for (int j = i; j < lista->n - 1; j++) {
        lista->vetor[j] = lista->vetor[j + 1];
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

    for (int i = 0; i < lista.n; i++) {
        printf("[%.2f] ", lista.vetor[i]);
    }
    printf("\n");
}

// Exibe o menu e retorna a opção escolhida
int menu() {
    int op;
    printf("\n[01] Inserir elemento na lista\n");
    printf("[02] Remover um elemento da lista\n");
    printf("[03] Mostrar lista\n");
    printf("[04] Sair\n");
    printf("Digite uma opcao: ");
    scanf("%d", &op);
    return op;
}

// Função principal
int main() {
    int op;
    float elemento;
    LISTA lista;
    inicializar(&lista); // Inicializa a lista

    do {
        op = menu();
        switch (op) {
            case 1:
                printf("Digite um elemento: ");
                scanf("%f", &elemento);
                inserir_crescentemente(&lista, elemento);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%f", &elemento);
                remover_valor(&lista, elemento);
                break;
            case 3:
                mostrar_lista(lista);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (op != 4);

    return 0;
}

