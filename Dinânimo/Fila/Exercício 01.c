#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPessoa
{
    char nome[50];
    char cpf[11];
    int idade;
    float peso;
} PESSOA;

typedef struct sFila{
    PESSOA pessoa;
    struct sFila * next;
} FILA;

void inicializar(FILA **inicio, FILA **fim)
{
    *inicio = NULL;
    *fim = NULL;
}

FILA* getnode()
{
    return (FILA*)malloc(sizeof(FILA));
}

void freenode(FILA *q)
{
    free(q);
}

int vazio(FILA * f)
{
    if(f == NULL)
        return 1;
    return 0;
}

PESSOA criar_pessoa()
{
    PESSOA p;
    printf("Digite o nome da pessoa: ");
    fflush(stdin);
    scanf("%[^\n]", p.nome);
    printf("Digite o cpf: ");
    fflush(stdin);
    scanf("%[^\n]", p.cpf);
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    printf("Digite o peso: ");
    scanf("%f", &p.peso);
    return p;
}

void enfileirar(FILA **inicio, FILA **fim, PESSOA p)
{
    FILA * q = getnode();
    if(q != NULL)
    {
        strcpy(q->pessoa.nome, p.nome);
        strcpy(q->pessoa.cpf, p.cpf);
        q->pessoa.idade = p.idade;
        q->pessoa.peso = p.peso;
        q->next = NULL;  // O próximo é NULL porque é o último da fila

        if(vazio(*inicio))
        {
            *inicio = q;  // A fila estava vazia, então o novo nó é o início e o fim
            *fim = q;
        }
        else
        {
            (*fim)->next = q;  // O último nó agora aponta para o novo nó
            *fim = q;  // Atualiza o ponteiro fim para o novo nó
        }
    }
    else
    {
        printf("Nao foi possivel alocar o no\n");
    }
}

PESSOA desenfileirar(FILA **inicio, FILA **fim)
{
    PESSOA p = {"","",0,0};
    FILA * q;
    if(!vazio(*inicio))
    {
        p = (*inicio)->pessoa;  // Pega os dados da pessoa do início da fila
        q = (*inicio);  // Guarda o ponteiro do nó que será removido

        if(*inicio == *fim)  // Se a fila tem apenas um elemento
        {
            inicializar(inicio,fim);  // Reseta a fila
        }
        else
        {
            *inicio = (*inicio)->next;  // Atualiza o ponteiro inicio
        }

        freenode(q);  // Libera o nó removido
    }
    else
    {
        printf("Fila vazia\n");
    }
    return p;
}

void mostrar_fila(FILA **inicio, FILA **fim)
{
    if(!vazio(*inicio))
    {
        while(*inicio != NULL)
        {
              printf("Nome: [%s] CPF: [%s] Idade: [%d] Peso: [%.2f]\n",
                   (*inicio)->pessoa.nome, (*inicio)->pessoa.cpf, (*inicio)->pessoa.idade, (*inicio)->pessoa.peso);
                   desenfileirar(inicio,fim);
        }

    }
    else
    {
        printf("Fila vazia\n");
    }
}

int menu()
{
    int op;
    printf("\nMenu de Opcoes:\n");
    printf("1. Enfileirar\n");
    printf("2. Desenfileirar\n");
    printf("3. Mostrar Fila\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    return op;
}

void main()
{
    FILA *inicio, *fim;
    inicializar(&inicio, &fim);

    PESSOA p;
    int opcao;

    do
    {
        opcao = menu();
        switch(opcao)
        {
            case 1:
                // Enfileirar uma nova pessoa
                p = criar_pessoa();
                enfileirar(&inicio, &fim, p);
                break;

            case 2:
                // Desenfileirar uma pessoa
                p = desenfileirar(&inicio, &fim);
                if (p.idade != 0)  // Verifica se não foi retornado um valor vazio
                {
                    printf("Pessoa removida: Nome: [%s] CPF: [%s] Idade: [%d] Peso: [%.2f]\n",
                            p.nome, p.cpf, p.idade, p.peso);
                }
                break;

            case 3:
                // Mostrar a fila
                mostrar_fila(&inicio, &fim);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while(opcao != 4);
}

