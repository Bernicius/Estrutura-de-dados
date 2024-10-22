#include <stdio.h>
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

LISTA * getnode()
{
    return (LISTA*)malloc(sizeof(LISTA));
}

void freenode(LISTA * q)
{
    free(q);
}

void adicionar_no_inicio(LISTA ** lista, int elemento)
{
    LISTA * q;
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
            q->next = (*lista);
            (*lista) = q;
        }
    }
    else
    {
        printf("Nao foi possivel alocar no");
    }
}

void adicionar_no_fim(LISTA ** lista, int elemento)
{
    LISTA * q;
    q = getnode();
    LISTA * aux;

    if(q != NULL)
    {
        q->elemento = elemento;
        q->next = NULL;

        if(vazio(*lista))
        {
            *lista = q;

        }
        else
        {
            aux = (*lista);
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
    }
    else
    {
        printf("Nao foi possivel alocar no\n");
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
        printf("Lista vazia \n");
    }
}

void remover_inicio(LISTA ** lista)
{
    LISTA * q;
    if(!vazio(*lista))
    {
        q = (*lista);
        (*lista) = (*lista)->next;
        freenode(q);
    }
    else
    {
        printf("Lista vazia\n");
    }
}

void remover_fim(LISTA ** lista)
{
    LISTA * aux;
    LISTA * q;

    if(!vazio(*lista))
    {
        aux = (*lista);
        if(aux->next == NULL)
        {
            remover_inicio(lista);
        }
        else
        {
            while(aux->next->next != NULL)
            {
                aux = aux->next;
            }
            q = aux->next;
            freenode(q);
            aux->next = NULL;
        }
    }
    else
    {
        printf("Lista vazia\n");
    }
}

int pesquisar_elemento(LISTA * lista,int elemento)
{
    int retorno = 0;
    LISTA * aux;
    if(!vazio(lista))
    {
        aux = lista;
        while(aux!= NULL)
        {
            if(aux->elemento == elemento)
            {
                retorno = 1;
            }
            aux = aux->next;
        }
    }else{
        printf("Lista vazia\n");
    }
    return retorno;
}
int verificar_posicao(LISTA * lista, int pos)
{
    int i=0,retorno=0;
    LISTA * aux;
    aux = lista;
    while(aux != NULL)
    {
        aux = aux->next;
        i++;
    }
    if(pos <= i)
    {
        retorno = 1;
    }
    return retorno;
}

void inserir_ordenado(LISTA ** lista, int elemento)
{
    LISTA * q = getnode();
    LISTA * aux, *aux2;
    if(q != NULL)
    {
        q->elemento = elemento;
        q->next = NULL;
        if(vazio(*lista))
        {
            *lista = q;
        }
        else if(q->elemento <= (*lista)->elemento)
        {
            q->next = *lista;
            *lista = q;
        }
        else
        {
            aux = *lista;
            aux2 = NULL;
            //andar com aux
            while(aux != NULL && q->elemento > aux->elemento)
            {
                aux2 = aux;
                aux = aux->next;
            }
            q->next = aux;
            if(aux2 != NULL)
            {
                aux2->next = q;
            }
        }
    }
}


void inserir_na_posicao(LISTA ** lista, int pos, int elemento)
{
    int i = 1;
    LISTA * aux = *lista;
    LISTA * novo_no = getnode();

    if (novo_no != NULL)
    {
        novo_no->elemento = elemento;
        novo_no->next = NULL;

        if (pos == 1)
        {
            adicionar_no_inicio(lista, elemento);
        }
        else
        {
            while (aux != NULL && i < pos - 1)
            {
                aux = aux->next;
                i++;
            }

            if (aux != NULL)
            {
                novo_no->next = aux->next;
                aux->next = novo_no;
            }
            else
            {
                printf("Posição inválida\n");
                freenode(novo_no);
            }
        }
    }
    else
    {
        printf("Não foi possível alocar nó\n");
    }
}


int menu()
{
    int op;
    printf("\n[01]Adicionar inicio\n");
    printf("[02]Adicionar no fim\n");
    printf("[03]Mostrar lista\n");
    printf("[04]Remover inicio\n");
    printf("[05]Remover fim\n");
    printf("[06]Pesquisar elemento\n");
    printf("[07]Inserir na posicao\n");
    printf("[08]Inserir Ordenado\n");
    printf("Digite uma opcao:");
    scanf("%d",&op);
    return op;
}

void main()
{
    LISTA * lista;
    inicializar(&lista);
    int op,elemento;
    int encontrado,pos;

    do
    {
        op = menu();
        switch(op)
        {
        case 1:
            printf("Digite um elemento:");
            scanf("%d",&elemento);
            adicionar_no_inicio(&lista,elemento);
            break;
        case 2:
            printf("Digite um elemento:");
            scanf("%d",&elemento);
            adicionar_no_fim(&lista,elemento);
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
            printf("Digite um elemento:");
            scanf("%d",&elemento);
            encontrado = pesquisar_elemento(lista,elemento);
            if(encontrado)
            {
                printf("Elemento pertence a lista\n");
            }else{
                printf("Elemento nao pertence a lista\n");
            }
            break;
        case 7:
            printf("Digite a posicao:");
            scanf("%d",&pos);
            if(verificar_posicao(lista,pos))
            {
                printf("Digite o elemento:");
                scanf("%d",&elemento);
                inserir_na_posicao(&lista,pos,elemento);
            }else{
                printf("Posicao invalida\n");
            }
            break;
        case 8:
            printf("Digite o elemento:");
            scanf("%d",&elemento);
            inserir_ordenado(&lista,elemento);
            break;
        }
    }
    while(op != 9);
}
