#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sAluno
{
    char prontuario[9];
    char nome[60];
    char curso[40];
    int ano_ingresso;
    int ano_formatura;
    char endereco[40];
    char telefone_um[12];
    char telefone_dois[12];
} ALUNO;

typedef struct sLista
{
    ALUNO aluno;
    struct sLista *next;
} LISTA;

void inicializar(LISTA **lista)
{
    *lista = NULL;
}

ALUNO criar_aluno()
{
    ALUNO a;
    printf("Digite o prontuario: ");
    fflush(stdin);
    scanf("%[^\n]", a.prontuario);
    printf("Digite o nome: ");
    fflush(stdin);
    scanf("%[^\n]", a.nome);
    printf("Digite o curso: ");
    fflush(stdin);
    scanf("%[^\n]", a.curso);
    printf("Digite o ano de ingresso: ");
    scanf("%d", &a.ano_ingresso);
    printf("Digite o ano de formatura: ");
    scanf("%d", &a.ano_formatura);
    printf("Digite o primeiro telefone: ");
    fflush(stdin);
    scanf("%[^\n]", a.telefone_um);
    printf("Digite o segundo telefone: ");
    fflush(stdin);
    scanf("%[^\n]", a.telefone_dois);
    return a;
}

LISTA* getnode()
{
    return (LISTA*)malloc(sizeof(LISTA));
}

int vazio(LISTA *lista)
{
    return lista == NULL;
}

void inserir_lista_fim(LISTA **lista, ALUNO a)
{
    LISTA *q = getnode();
    if (q != NULL)
    {
        q->aluno = a;
        q->next = NULL;

        if (vazio(*lista))
        {
            *lista = q;
        }
        else
        {
            LISTA *aux = *lista;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
    }
    else
    {
        printf("O nó não pode ser alocado\n");
    }
}

void relatorio_por_curso(LISTA **lista)
{
    // Verifica se o curso já foi exibido
    int encontrado = 0,i;
    char cursos[100][40]; // Array para armazenar cursos já exibidos
    int curso_contador = 0;
    if (!vazio(*lista))
    {
        LISTA *aux = *lista;


        while (aux != NULL)
        {

            for (i = 0; i < curso_contador; i++)
            {
                if (strcmp(cursos[i], aux->aluno.curso) == 0)
                {
                    encontrado = 1;
                }
            }
            if (!encontrado)
            {
                // Se não foi encontrado, adiciona o curso à lista
                strcpy(cursos[curso_contador], aux->aluno.curso);
                curso_contador++;

                // Exibe o título do curso
                printf("\nCurso: %s\n", aux->aluno.curso);
                printf("Alunos:\n");

                // Exibe os alunos desse curso
                LISTA *temp = *lista; // Acessa o primeiro nó da lista
                while (temp != NULL)
                {
                    if (strcmp(temp->aluno.curso, aux->aluno.curso) == 0)
                    {
                        printf("  - Prontuario: %s, Nome: %s, Ano de Formatura: %d\n",
                               temp->aluno.prontuario, temp->aluno.nome, temp->aluno.ano_formatura);
                    }
                    temp = temp->next;
                }
            }
            aux = aux->next;
        }
    }
    else
    {
        printf("Lista vazia de alunos\n");
    }
}

void relatorio_por_ano_formatura(LISTA **lista)
{
    //garda os anos encontrados
    int encontrado = 0,anos[100],ano_contador = 0,i;

    if (!vazio(*lista))
    {
        LISTA *aux = *lista;
        while (aux != NULL)
        {

            for (i = 0; i < ano_contador; i++)
            {
                if (anos[i] == aux->aluno.ano_formatura)
                {
                    encontrado = 1;
                }
            }
            if (!encontrado)
            {
                // Se não foi encontrado, adiciona o ano à lista
                anos[ano_contador] = aux->aluno.ano_formatura;
                ano_contador++;

                // Exibe o título do ano
                printf("\nAno de Formatura: %d\n", aux->aluno.ano_formatura);
                printf("Alunos:\n");

                // Exibe os alunos desse ano
                LISTA *temp = *lista;
                while (temp != NULL)
                {
                    if (temp->aluno.ano_formatura == aux->aluno.ano_formatura)
                    {
                        printf("  - Prontuario: %s, Nome: %s, Curso: %s\n",
                               temp->aluno.prontuario, temp->aluno.nome, temp->aluno.curso);
                    }
                    temp = temp->next;
                }
            }
            aux = aux->next;
        }
    }
    else
    {
        printf("Lista vazia de alunos\n");
    }
}


int menu()
{
    int op;
    printf("\n[01] Adicionar na lista de alunos\n");
    printf("[02] Relatório por curso\n");
    printf("[03] Relatório por ano de formatura\n");
    printf("[04] Sair\n");
    printf("Digite uma opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *lista;
    inicializar(&lista);
    ALUNO a;
    int op;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            a = criar_aluno();
            inserir_lista_fim(&lista, a);
            break;
        case 2:
            relatorio_por_curso(&lista);
            break;
        case 3:
            relatorio_por_ano_formatura(&lista);
            break;
        case 4:
            printf("Saindo ....\n");
        }
    }
    while (op != 4);

    return 0;
}
