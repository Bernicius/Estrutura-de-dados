#include <stdio.h>
#include <stdlib.h>

typedef struct sPilha
{
    int elemento;
    struct sPilha * next;
} PILHA;

void inicializar(PILHA ** pilha)
{
    (*pilha) = NULL;
}

int vazio(PILHA * pilha)
{
    if(pilha == NULL)
    {
        return 1;
    }
    return 0;
}

PILHA* getnode()
{
    return(PILHA*)malloc(sizeof(PILHA));
}

void inserir_pilha(PILHA ** pilha, int elemento)
{
    PILHA * q = getnode();
    if(q != NULL)
    {
        q->elemento = elemento;
        q->next = (*pilha);
        (*pilha) = q;
    }
    else
    {
        printf("Nao foi possivel alocar o no\n");
    }
}

void mostrar_topo(PILHA * pilha)
{
    if(!vazio(pilha))
    {
        printf("Elemento do topo: %d\n", pilha->elemento);
    }
    else
    {
        printf("Pilha vazia\n");
    }
}

void freenode(PILHA * q)
{
    free(q);
}

void remover(PILHA ** pilha)
{
    PILHA * q;
    if(!vazio(*pilha))
    {
        q = (*pilha);
        (*pilha) = (*pilha)->next;
        freenode(q);
    }
    else
    {
        printf("Pilha vazia\n");
    }
}

void mostrar_pilha(PILHA * pilha)
{
    PILHA * aux = NULL;
    PILHA * temp;

    if(!vazio(pilha))
    {
        while(pilha != NULL)
        {
            temp = pilha;
            pilha = pilha->next;
            temp->next = aux;
            aux = temp;
            printf("%d\n", aux->elemento);
        }
        while(aux != NULL)
        {
            temp = aux;
            aux = aux->next;
            temp->next = pilha;
            pilha = temp;
        }
    }
    else
    {
        printf("Pilha vazia\n");
    }
}


int menu()
{
    int op;
    printf("\nMenu:");
    printf("\n[01] Inserir na pilha");
    printf("\n[02] Remover da pilha");
    printf("\n[03] Mostrar pilha");
    printf("\n[04] Mostrar topo da pilha");
    printf("\n[05] Encerrar");
    printf("\nDigite uma opcao: ");
    scanf("%d", &op);
    return op;
}

void main()
{
    PILHA * pilha;
    inicializar(&pilha);
    int op, elemento;

    do
    {
        op = menu();

        switch(op)
        {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                inserir_pilha(&pilha, elemento);
                break;

            case 2:
                remover(&pilha);
                break;

            case 3:
                mostrar_pilha(pilha);
                break;

            case 4:
                mostrar_topo(pilha);
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(op != 5);

}

