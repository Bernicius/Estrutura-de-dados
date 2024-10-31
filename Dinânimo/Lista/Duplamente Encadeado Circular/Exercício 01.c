
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMM 40

typedef struct sCanal {
    char nome[TAMM];
    int numero;
    char HD;
} CANAL;

typedef struct sLista {
    CANAL a;
    struct sLista *next;
    struct sLista *back;
} LISTA;

void inicializar(LISTA **lista) {
    *lista = NULL;
}

int vazio(LISTA *lista) {
    return lista == NULL;
}

LISTA* getnode() {
    return (LISTA*)malloc(sizeof(LISTA));
}

void freenode(LISTA *q) {
    free(q);
}

CANAL criar_canal() {
    CANAL a;
    printf("Digite o nome do canal: ");
    fflush(stdin);
    scanf("%[^\n]", a.nome);
    printf("Digite o numero do canal: ");
    scanf("%d", &a.numero);
    printf("Canal eh em HD [s]Sim [n]Nao: ");
    fflush(stdin);
    scanf(" %c", &a.HD);
    return a;
}

void adicionar_no_inicio(LISTA **lista, CANAL a) {
    LISTA *q = getnode();
    if (q != NULL) {
        strcpy(q->a.nome, a.nome);
        q->a.numero = a.numero;
        q->a.HD = a.HD;

        if (vazio(*lista)) {
            q->next = q;
            q->back = q;
            *lista = q;
        } else {
            LISTA *aux = *lista;
            q->next = aux;
            q->back = aux->back;
            aux->back->next = q;
            aux->back = q;
            *lista = q;
        }
    } else {
        printf("Nao pode ser alocado o no\n");
    }
}

void inserir_no_fim(LISTA **lista, CANAL a) {
    LISTA *q = getnode();
    if (q != NULL) {
        strcpy(q->a.nome, a.nome);
        q->a.numero = a.numero;
        q->a.HD = a.HD;

        if (vazio(*lista)) {
            q->next = q;
            q->back = q;
            *lista = q;
        } else {
            LISTA *aux = *lista;
            q->next = aux;
            q->back = aux->back;
            aux->back->next = q;
            aux->back = q;
        }
    } else {
        printf("No nao pode ser alocado\n");
    }
}

void mostrar_canal_atual(LISTA *lista) {
    if (!vazio(lista)) {
        printf("Nome: [%s] Numero: [%d] HD: [%c]\n", lista->a.nome, lista->a.numero, lista->a.HD);
    } else {
        printf("Lista de canais vazia\n");
    }
}

void proximo(LISTA **lista) {
    if (!vazio(*lista)) {
        *lista = (*lista)->next;
    } else {
        printf("Lista de canais vazia\n");
    }
}

void anterior(LISTA **lista) {
    if (!vazio(*lista)) {
        *lista = (*lista)->back;
    } else {
        printf("Lista de canais vazia\n");
    }
}

void mostrar_todos_os_canais(LISTA *lista) {
    if (!vazio(lista)) {
        LISTA *aux = lista;
        do {
            printf("Nome: [%s] Numero: [%d] HD: [%c]\n", aux->a.nome, aux->a.numero, aux->a.HD);
            aux = aux->next;
        } while (aux != lista);
    } else {
        printf("Lista de canais vazia\n");
    }
}

int main() {
    LISTA *lista;
    inicializar(&lista);
    CANAL canal;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar canal no inicio\n");
        printf("2. Adicionar canal no fim\n");
        printf("3. Mostrar canal atual\n");
        printf("4. Ir para o proximo canal\n");
        printf("5. Ir para o canal anterior\n");
        printf("6. Mostrar todos os canais\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                canal = criar_canal();
                adicionar_no_inicio(&lista, canal);
                break;
            case 2:
                canal = criar_canal();
                inserir_no_fim(&lista, canal);
                break;
            case 3:
                mostrar_canal_atual(lista);
                break;
            case 4:
                proximo(&lista);
                break;
            case 5:
                anterior(&lista);
                break;
            case 6:
                mostrar_todos_os_canais(lista);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);
}

