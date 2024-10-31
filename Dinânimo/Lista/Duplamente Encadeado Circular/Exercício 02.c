#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPessoa
{
    char nome[40];
    char cpf[11];
    int idade;
} PESSOA;

typedef struct sLista
{
    PESSOA p;
    struct sLista *next;
    struct sLista *back;
} LISTA;

// Função para remover por cpf
void freenode(LISTA * q)
{
    free(q);
}

// Função para alocar um novo nó
LISTA* getnode()
{
    return (LISTA*)malloc(sizeof(LISTA));
}

// Verifica se a lista está vazia
int vazio(LISTA *lista)
{
    return lista == NULL;
}

// Insere uma nova pessoa em ordem alfabética em uma lista duplamente encadeada circular
void inserir_ordenado(LISTA **lista, PESSOA p)
{
    LISTA *q = getnode();
    if (q != NULL)
    {
        // Copia os dados da nova pessoa
        strcpy(q->p.nome, p.nome);
        strcpy(q->p.cpf, p.cpf);
        q->p.idade = p.idade;

        if (vazio(*lista))
        {
            // Lista vazia, inicializa a lista circular
            q->next = q;
            q->back = q;
            (*lista) = q;
        }
        else
        {
            LISTA *atual = *lista;
            LISTA *aux2 = atual->back;

            // Se o novo nó deve ser inserido antes do primeiro nó
            if (strcmp(q->p.nome, atual->p.nome) < 0)
            {
                q->next = atual;
                q->back = aux2;
                aux2->next = q;
                atual->back = q;
                (*lista) = q;
            }
            else
            {
                // Encontrar a posição correta para inserção
                while (atual->next != *lista && strcmp(q->p.nome, atual->next->p.nome) >= 0)
                {
                    atual = atual->next;
                }
                // Inserindo na posição encontrada
                q->next = atual->next;
                q->back = atual;
                atual->next = q;
                if (q->next != *lista)
                {
                    q->next->back = q;
                }
                else
                {
                    // Se estamos inserindo no final, atualizar o último elemento
                    (*lista)->back = q;
                }
            }
        }
    }
    else
    {
        printf("No nao pode ser alocado\n");
    }
}

// Função para exibir as pessoas da lista
void exibir_lista(LISTA *lista)
{
    if (vazio(lista))
    {
        printf("Lista vazia.\n");
        return;
    }

    LISTA *aux = lista;
    do
    {
        printf("Nome: %s, CPF: %s, Idade: %d\n", aux->p.nome, aux->p.cpf, aux->p.idade);
        aux = aux->next;
    }
    while (aux != lista);
}

// Função para criar uma nova pessoa a partir da entrada do usuário
PESSOA criar_pessoa()
{
    PESSOA p;
    printf("Digite o nome: ");
    fflush(stdin);
    scanf("%[^\n]", p.nome);
    printf("Digite o cpf: ");
    fflush(stdin);
    scanf("%[^\n]", p.cpf);
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    return p;
}

void remover_pelo_cpf(LISTA ** lista, char cpf[])
{
    LISTA * aux;
    LISTA * aux2 = NULL;
    LISTA * p;
    if(!vazio(*lista))
    {
        aux = (*lista);
        do
        {
            if(strcmp(aux->p.cpf, cpf) == 0)
            {
                p = aux; // o nó que deve ser removido
                if(aux2 != NULL) // se não for o primeiro nó a ser removido
                {
                    aux2->next = aux->next;
                }
                else
                {
                    (*lista) = aux->next; // se o nó a ser removido é o primeiro
                }
                freenode(p); // liberar nó
                printf("Pessoa removida com sucesso.\n");
                return; // Sai da função após remover
            }
            aux2 = aux;
            aux = aux->next;
        }
        while(aux != (*lista));
    }
    printf("CPF nao encontrado na lista.\n");
}

void mostrar_idade_maior(LISTA * lista)
{
    LISTA * aux;
    if(!vazio(lista))
    {
        aux = lista;
        do
        {
            if(aux->p.idade >= 25)
            {
                printf("[%s][%s][%d]\n",aux->p.nome,aux->p.cpf,aux->p.idade);
            }
            aux = aux->next;
        } while(aux != lista);
    }
    else
    {
        printf("Lista vazia\n");
    }
}

// Função principal
void main()
{
    LISTA *lista = NULL;
    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1. Inserir pessoa em ordem alfabetica\n");
        printf("2. Exibir lista de pessoas\n");
        printf("3. Remover pessoa pelo CPF\n");
        printf("4. Exibir pessoas com idade maior ou igual a 25\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            PESSOA p = criar_pessoa();
            inserir_ordenado(&lista, p);
            break;
        }
        case 2:
            exibir_lista(lista);
            break;
        case 3:
        {
            char cpf[11];
            printf("Digite o CPF da pessoa a ser removida: ");
            fflush(stdin);
            scanf("%[^\n]", cpf);
            remover_pelo_cpf(&lista, cpf);
            break;
        }
        case 4:
            mostrar_idade_maior(lista);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    while (opcao != 5);

}
