#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    int elemento;
    struct sLista *next;
    struct sLista *back;
} LISTA;

void inicializar(LISTA **lista) {
    (*lista) = NULL;
}

int vazio(LISTA *lista) {
    return (lista == NULL);
}

LISTA* getnode() {
    return (LISTA*) malloc(sizeof(LISTA));
}

void freenode(LISTA *q) {
    free(q);
}

void inserir_inicio(LISTA **lista, int elemento) {
    LISTA *q = getnode();
    if (q != NULL) {
        q->elemento = elemento;
        q->next = NULL;
        q->back = NULL;
        if (vazio(*lista)) {
            (*lista) = q;
        } else {
            q->next = (*lista);
            (*lista)->back = q;
            (*lista) = q;
        }
    } else {
        printf("Nao foi possivel alocar o no\n");
    }
}

void inserir_fim(LISTA **lista, int elemento) {
    LISTA *q = getnode();
    if (q != NULL) {
        q->elemento = elemento;
        q->next = NULL;
        q->back = NULL;
        if (vazio(*lista)) {
            (*lista) = q;
        } else {
            LISTA *aux = (*lista);
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = q;
            q->back = aux;
        }
    } else {
        printf("Nao foi possivel alocar o no\n");
    }
}

void remover_fim(LISTA ** lista) {
    LISTA *aux;
    LISTA *q;
    if(!vazio(*lista)) {
        aux = (*lista);
        if(aux->next == NULL) {
            (*lista) = NULL;
        } else {
            while(aux->next->next != NULL) {
                aux = aux->next;
            }
            q = aux->next;
            aux->next = NULL;
            freenode(q);
        }
    } else {
        printf("Lista vazia\n");
    }
}

void mostrar_lista(LISTA *lista) {
    if (!vazio(lista)) {
        LISTA *aux = lista;
        while (aux != NULL) {
            printf("[%d] ", aux->elemento);
            aux = aux->next;
        }
        printf("\n");
    } else {
        printf("Lista vazia\n");
    }
}

void remover_inicio(LISTA ** lista) {
    LISTA *q;
    if(!vazio(*lista)) {
        q = (*lista);
        if(q->next == NULL) {
            (*lista) = NULL;
        } else {
            (*lista) = (*lista)->next;
            (*lista)->back = NULL;
        }
        freenode(q);
    } else {
        printf("Lista vazia\n");
    }
}

LISTA* pesquisar_elemento(LISTA *lista, int elemento) {
    LISTA *aux = NULL;
    if (!vazio(lista)) {
        aux = lista;
        while (aux != NULL) {
            if (elemento == aux->elemento) {
                return aux;
            }
            aux = aux->next;
        }
    } else {
        printf("Lista vazia\n");
    }
    return NULL;
}

void menu() {
    printf("Menu:\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no fim\n");
    printf("3. Mostrar lista\n");
    printf("4. Remover do inicio\n");
    printf("5. Remover do fim\n");
    printf("6. Pesquisar elemento\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
}

void main() {
    LISTA *lista;
    inicializar(&lista);
    int opcao, elemento;

    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido no inicio: ");
                scanf("%d", &elemento);
                inserir_inicio(&lista, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser inserido no fim: ");
                scanf("%d", &elemento);
                inserir_fim(&lista, elemento);
                break;
            case 3:
                mostrar_lista(lista);
                break;
            case 4:
                remover_inicio(&lista);
                break;
            case 5:
                remover_fim(&lista);
                break;
            case 6:
                printf("Digite o elemento a ser pesquisado: ");
                scanf("%d", &elemento);
                LISTA *encontrado = pesquisar_elemento(lista, elemento);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado.\n", encontrado->elemento);
                } else {
                    printf("Elemento %d nao encontrado.\n", elemento);
                }
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 7);
}
