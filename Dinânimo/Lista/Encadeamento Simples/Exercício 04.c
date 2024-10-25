#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sLista
{
    int elemento;
    struct sLista * next;
} LISTA;

void inicializar(LISTA ** lista)
{
    (*lista) = NULL;
}

int vazio(LISTA * lista)
{
    if(lista == NULL)
    {
        return 1;
    }
    return 0;
}

LISTA* getnode()
{
    return (LISTA*)malloc(sizeof(LISTA));
}

void inserir_fim(LISTA ** lista, int elemento)
{
    LISTA * q;
    LISTA * aux;
    q = getnode();
    if(q != NULL)
    {
        q->elemento = elemento;
        q->next = NULL;
        if(vazio(*lista))
        {
            (*lista) = q;
        }
        else
        {
            aux = *lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
    }
    else
    {
        printf("O no nao pode ser alocado\n");
    }
}

void mostrar_lista(LISTA * lista)
{
    LISTA * aux;
    if(!vazio(lista))
    {
        aux = lista;
        while(aux != NULL)
        {
            printf("[%d]",aux->elemento);
            aux = aux->next;
        }
    }
    else
    {
        printf("Lista vazia\n");
    }
}

void concatenar_listas(LISTA **lista_um, LISTA **lista_dois) {
    LISTA *aux;
    if (vazio(*lista_um)) {
        *lista_um = *lista_dois;
    } else {
        aux = *lista_um;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = *lista_dois;
    }
}

int menu()
{
    int op;
    printf("\nMenu:");
    printf("\n[01] Adicionar na lista 1\n");
    printf("[02] Adicionar na Lista 2\n");
    printf("[03] Mostrar listas\n");
    printf("[04] Concatenar listas\n");
    printf("[05] Encerrar programa\n");
    printf("Digite uma opcao:");
    scanf("%d",&op);
    return op;
}



void main()
{
    LISTA * lista_um, *lista_dois;
    inicializar(&lista_um);
    inicializar(&lista_dois);
    int op, elemento;

    do
    {
        op = menu();
        switch(op)
        {
        case 1:
            printf("Digite um elemento:");
            scanf("%d",&elemento);
            inserir_fim(&lista_um,elemento);

            break;
        case 2:
            printf("Digite um elemento:");
            scanf("%d",&elemento);
            inserir_fim(&lista_dois,elemento);
            break;
        case 3:
            printf("\n\tLista um\n");
            mostrar_lista(lista_um);
            printf("\n\tLista dois\n");
            mostrar_lista(lista_dois);
            break;
        case 4:
            concatenar_listas(&lista_um,&lista_dois);
            break;
        case 5:
            printf("Saindo ...");
            break;
        default:
            printf("Opcao invalida");
        }

    }
    while(op != 5);

}
