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

typedef struct sFila
{
    PESSOA pessoa;
    struct sFila *inicio;
    struct sFila *fim;
} FILA;

void inicializar(FILA **fila)
{
    *fila = NULL;
}

int vazio(FILA *fila)
{
    return (fila == NULL);
}

FILA* getnode()
{
    return (FILA*)malloc(sizeof(FILA));
}

void freenode(FILA *q)
{
    free(q);
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

void enfileirar(FILA **fila, PESSOA p)
{
    FILA *q = getnode();
    if (q != NULL)
    {
        strcpy(q->pessoa.nome, p.nome);
        strcpy(q->pessoa.cpf, p.cpf);
        q->pessoa.idade = p.idade;
        q->pessoa.peso = p.peso;
        q->inicio = NULL;
        q->fim = NULL;
        if (vazio(*fila))
        {
            *fila = q;
        }
        else
        {
            FILA *aux = *fila;
            while (aux->inicio != NULL)
            {
                aux = aux->inicio;
            }
            aux->inicio = q;
        }
    }
    else
    {
        printf("Nao foi possivel alocar o no\n");
    }
}

PESSOA desemfileirar(FILA **fila)
{
    PESSOA p = {" ", " ", 0, 0};
    if (!vazio(*fila))
    {
        FILA *q = *fila;
        p = q->pessoa;
        *fila = q->inicio;
        freenode(q);
    }
    else
    {
        printf("FILA VAZIA\n");
    }
    return p;
}

void mostrar_fila(FILA **fila)
{
    FILA * aux = NULL;
    if(!vazio(*fila))
    {
        while(!vazio(*fila))
        {
            printf("Nome: [%s] CPF: [%s] Idade: [%d] Peso: [%.2f]\n",
                   (*fila)->pessoa.nome, (*fila)->pessoa.cpf, (*fila)->pessoa.idade, (*fila)->pessoa.peso);
            enfileirar(&aux,desemfileirar(fila));
        }
        while(!vazio(aux))
        {

            enfileirar(fila,desemfileirar(&aux));
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

int main()
{
    FILA *fila;
    inicializar(&fila);
    PESSOA p;
    int opcao;

    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            p = criar_pessoa();
            enfileirar(&fila, p);
            break;
        case 2:
            p = desemfileirar(&fila);
            if (p.idade != 0)
            {
                printf("Pessoa removida: Nome: [%s] CPF: [%s] Idade: [%d] Peso: [%.2f]\n", p.nome, p.cpf, p.idade, p.peso);
            }
            break;
        case 3:
            mostrar_fila(&fila);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
    while (opcao != 4);

    return 0;
}

