#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sCelular
{
    char numero_um[12];
    char numero_dois[12];
    char toque[30];
    char nome[50];
} CELULAR;

typedef struct sLista
{
    CELULAR celular;
    struct sLista *next;
} LISTA;

void inicializar(LISTA **lista)
{
    (*lista) = NULL;
}

int vazio(LISTA *lista)
{
    return lista == NULL;
}

void freenode(LISTA *q)
{
    free(q);
}

LISTA* getnode()
{
    return (LISTA*)malloc(sizeof(LISTA));
}

CELULAR criar_celular()
{
    CELULAR a;
    printf("Digite o nome do contato: ");
    fflush(stdin);
    scanf(" %[^\n]", a.nome);
    printf("Digite o primeiro numero de celular: ");
    fflush(stdin);
    scanf(" %[^\n]", a.numero_um);
    printf("Digite o segundo numero de celular: ");
    fflush(stdin);
    scanf(" %[^\n]", a.numero_dois);
    printf("Digite o toque de celular: ");
    fflush(stdin);
    scanf(" %[^\n]", a.toque);

    return a;
}

void inserir_lista_de_contatos(LISTA **lista, CELULAR c)
{
    LISTA *q = getnode();
    LISTA *aux, *aux2;

    if (q != NULL)
    {
        strcpy(q->celular.numero_um, c.numero_um);
        strcpy(q->celular.numero_dois, c.numero_dois);
        strcpy(q->celular.toque, c.toque);
        strcpy(q->celular.nome, c.nome);
        q->next = NULL;
        if (vazio(*lista))
        {
            (*lista) = q;
        }
        else if (strcmp(c.nome, (*lista)->celular.nome) < 0)
        {
            q->next = (*lista);
            (*lista) = q;
        }
        else
        {
            aux = (*lista);
            while (aux->next != NULL && strcmp(c.nome, aux->next->celular.nome) > 0)
            {
                aux = aux->next;
            }
            q->next = aux->next;
            aux->next = q;
        }
    }
    else
    {
        printf("No nao pode ser alocado\n");
    }
}

void listar_lista_de_contatos(LISTA *lista)
{
    LISTA *aux;
    if (!vazio(lista))
    {
        aux = lista;
        while (aux != NULL)
        {
            printf("Nome: %s\nNumero um: %s\nNumero dois: %s\nToque: %s\n\n",
                   aux->celular.nome, aux->celular.numero_um, aux->celular.numero_dois, aux->celular.toque);
            aux = aux->next;
        }
    }
    else
    {
        printf("Lista de contatos vazia\n");
    }
}

void remover_contato(LISTA **lista, char nome[])
{
    LISTA *aux = *lista;
    LISTA *aux2 = NULL;
    LISTA *q;

    if (!vazio(*lista))
    {
        while (aux != NULL)
        {
            if (strcmp(aux->celular.nome, nome) == 0 || strcmp(aux->celular.nome, nome) == 0)
            {
                q = aux;
                if (aux2 == NULL)
                {
                    *lista = aux->next;
                }
                else
                {
                    aux2->next = aux->next;
                }
                freenode(q);
                printf("Contato removido com sucesso!\n");
                return;
            }
            aux2 = aux;
            aux = aux->next;
        }
        printf("Contato nao encontrado!\n");
    }
    else
    {
        printf("Lista vazia, nao se pode excluir nenhum contato\n");
    }
}

void pesquisar_contato(LISTA *lista, char letra) {
    LISTA *aux;
    if (!vazio(lista)) {
        aux = lista;
        printf("\tLista de contato\n");
        while (aux != NULL) {
            if (aux->celular.nome[0] == letra) {
                printf("Nome: [%s] - Contato um: [%s] - Contato dois: [%s]\n",
                       aux->celular.nome, aux->celular.numero_um, aux->celular.numero_dois);
            }
            aux = aux->next;
        }
    }
}


void menu()
{
    LISTA *lista;
    inicializar(&lista);
    int opcao;
    char contato[12];
    char letra;
    CELULAR c;

    do
    {
        printf("Menu:\n");
        printf("1. Inserir contato\n");
        printf("2. Listar contatos\n");
        printf("3. Remover contato\n");
        printf("4. Pesquisar contato\n");
        printf("5. Encerra programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            c = criar_celular();
            inserir_lista_de_contatos(&lista, c);
            break;
        case 2:
            listar_lista_de_contatos(lista);
            break;
        case 3:
            printf("Digite o numero do contato a ser removido: ");
            fflush(stdin);
            scanf(" %[^\n]", contato);
            remover_contato(&lista, contato);
            break;
        case 4:
            if(!vazio(lista))
            {
                printf("Digite uma letra:");
                fflush(stdin);
                scanf("%c",&letra);
                pesquisar_contato(lista,letra);
            }
            else
            {
                printf("Lista vazia\n");
            }
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }
    while (opcao != 5);
}

int main()
{
    menu();
    return 0;
}
