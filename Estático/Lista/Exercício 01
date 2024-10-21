
#include <stdio.h>
#include <stdlib.h>

#define TAMM 10

typedef struct {
    int vetor[TAMM];
    int n;
} LISTA;

void inicializar(LISTA *lista) {
    lista->n = -1; // Inicializa a lista vazia
}

int verificar_vazio(LISTA lista) {
    return (lista.n == -1); // Retorna 1 se a lista estiver vazia
}

int verificar_cheio(LISTA lista) {
    return (lista.n >= TAMM - 1); // Retorna 1 se a lista estiver cheia
}

int verificar_posicao(LISTA lista, int pos) {
    return (pos >= 0 && pos <= lista.n); // Permite inserir na última posição
}

void mover_direita(LISTA *lista, int pos) {
    for (int i = lista->n; i >= pos; i--) {
        lista->vetor[i + 1] = lista->vetor[i]; // Move elementos para a direita
    }
}

void mover_esquerda(LISTA *lista, int pos) {
    for (int i = pos; i < lista->n; i++) {
        lista->vetor[i] = lista->vetor[i + 1]; // Move elementos para a esquerda
    }
}

void inserir_inicio(LISTA *lista, int elemento) {
    if (!verificar_cheio(*lista)) {
        mover_direita(lista, 0); // Move elementos para a direita
        lista->vetor[0] = elemento; // Insere o elemento no início
        lista->n++; // Incrementa o tamanho da lista
    }
}

void inserir_posicao(LISTA *lista, int pos, int elemento) {
    if (verificar_cheio(*lista)) {
        printf("Lista cheia\n");
        return;
    }

    if (!verificar_posicao(*lista, pos) && pos != lista->n + 1) {
        printf("Posicao invalida\n");
        return;
    }

    if (pos == 0) {
        inserir_inicio(lista, elemento);
    } else {
        mover_direita(lista, pos); // Move elementos para a direita
        lista->vetor[pos] = elemento; // Insere o elemento na posição desejada
        lista->n++; // Incrementa o tamanho da lista
    }
}

void remover_posicao(LISTA *lista, int pos) {
    if (verificar_vazio(*lista)) {
        printf("Lista vazia\n");
        return;
    }

    if (!verificar_posicao(*lista, pos)) {
        printf("Posicao invalida\n");
        return;
    }

    mover_esquerda(lista, pos); // Move elementos para a esquerda
    lista->n--; // Decrementa o tamanho da lista
}

int encontrar_elemento(LISTA lista, int pos) {
    if (!verificar_posicao(lista, pos)) {
        printf("Posicao invalida\n");
        return -1; // Indica erro
    }
    return lista.vetor[pos]; // Retorna o elemento na posição especificada
}

int procurar_elemento(LISTA lista, int elemento) {
    for (int i = 0; i <= lista.n; i++) {
        if (lista.vetor[i] == elemento) {
            return 1; // Elemento encontrado
        }
    }
    return -1; // Elemento não encontrado
}

void mostrar_lista(LISTA lista) {
    for (int i = 0; i <= lista.n; i++) {
        printf("[%d] ", lista.vetor[i]);
    }
    printf("\n");
}

int menu() {
    int op;
    printf("\n[01] Insira um elemento em uma posicao especifica\n");
    printf("[02] Remover um elemento de uma posicao especifica\n");
    printf("[03] Acessar um elemento de uma posicao especifica\n");
    printf("[04] Procurar um determinado elemento\n");
    printf("[05] Exibir os elementos da lista\n");
    printf("[06] Sair\n");
    printf("Digite uma opcao: ");
    scanf("%d", &op);
    return op;
}

int main() {
    int op, pos, elemento, retorno;
    LISTA lista;
    inicializar(&lista);

    do {
        op = menu();
        switch (op) {
            case 1:
                if (!verificar_cheio(lista)) {
                    printf("Digite a posicao: ");
                    scanf("%d", &pos);
                    if (verificar_posicao(lista, pos) || pos == lista.n + 1) {
                        printf("Digite o elemento: ");
                        scanf("%d", &elemento);
                        inserir_posicao(&lista, pos, elemento);
                    }
                } else {
                    printf("Lista cheia\n");
                }
                break;
            case 2:
                printf("Digite uma posicao: ");
                scanf("%d", &pos);
                remover_posicao(&lista, pos);
                break;
            case 3:
                printf("Digite uma posicao: ");
                scanf("%d", &pos);
                elemento = encontrar_elemento(lista, pos);
                if (elemento != -1) {
                    printf("Elemento da posicao %d = %d\n", pos, elemento);
                }
                break;
            case 4:
                printf("Digite um elemento: ");
                scanf("%d", &elemento);
                retorno = procurar_elemento(lista, elemento);
                if (retorno == 1) {
                    printf("Elemento encontrado\n");
                } else {
                    printf("Elemento nao encontrado\n");
                }
                break;
            case 5:
                mostrar_lista(lista);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (op != 6);

    return 0;
}
