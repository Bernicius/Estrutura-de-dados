#include <stdio.h>
#include <string.h>
#define TAMM 100

typedef struct sMusica{
    char nome[50];
    char genero[50];
}MUSICA;

typedef struct sPasta{
    MUSICA vetor[TAMM];
    int inicio , fim;
}PASTA;

void inicializar(PASTA * pasta)
{
    pasta->inicio = TAMM -1;
    pasta->fim = TAMM -1;
}

int vazio(PASTA pasta)
{
    if(pasta.inicio == pasta.fim)
    {
        return 1;
    }
    return 0;
}

int cheio(PASTA pasta)
{
    if((pasta.fim + 1) % TAMM == pasta.inicio)
    {
        return 1;
    }
    return 0;
}

MUSICA gerar_musica()
{
    MUSICA m;
    fflush(stdin);
    printf("Digite o nome da musica:");
    scanf("%[^\n]",m.nome);
    fflush(stdin);
    printf("Digite o genero da musica:");
    scanf("%[^\n]",m.genero);
    return m;
}

void adicionar_pasta(PASTA * pasta, MUSICA m)
{
    MUSICA musica = m;
    if(cheio(*pasta))
    {
        printf("Pasta cheia, nao eh possivel adicinar musica\n");
    }else{
        pasta->fim = (pasta->fim + 1) % TAMM;
        strcpy(pasta->vetor[pasta->fim].nome, musica.nome);
        strcpy(pasta->vetor[pasta->fim].genero, musica.genero);
    }
}

MUSICA remover_musica(PASTA * pasta)
{
    MUSICA retorno = {" "," "};
    if(vazio(*pasta))
    {
        printf("Pasta vazia\n");
    }else{
        pasta->inicio = (pasta->inicio + 1) % TAMM;
        retorno = pasta->vetor[pasta->inicio];
    }
    return retorno;
}

void mostrar_pasta(PASTA pasta)
{
    int i;
    if(vazio(pasta))
    {
        printf("Pasta vazia\n");
    }else{
        i = (pasta.inicio + 1) % TAMM;
        printf("\tPasta de musica\n");
        while(i != (pasta.fim + 1) % TAMM)
        {
            printf("Nome:[%s] - Genero[%s]",pasta.vetor[i].nome,pasta.vetor[i].genero);
            i = (i + 1) % TAMM;
            printf("\n");
        }
    }
}

void passar_musica(PASTA * pasta)
{
    if(vazio(*pasta))
    {
        printf("Pasta vazia\n");
    }else{
        adicionar_pasta(pasta,remover_musica(pasta));
    }
}

int menu()
{
    int op;
    printf("\t\n[01] Adicionar musica\n");
    printf("\t\n[02] Mostrar Musicas\n");
    printf("\t\n[03] Passar musica\n");
    printf("\t\nDigite uma opcao:\n");
    scanf("%d",&op);
    return op;
}

void main()
{
    PASTA pasta;
    MUSICA musica;
    inicializar(&pasta);
    int op;

    do{
        op = menu();
        switch(op)
        {
        case 1:
            musica = gerar_musica();
            adicionar_pasta(&pasta, musica);
            break;
        case 2:
            mostrar_pasta(pasta);
            break;
        case 3:
            passar_musica(&pasta);
            break;
        case 4:
            printf("Programa encerrado\n");
            break;
        default:
            printf("Opcao invalida\n");
        }

    }while(op != 4);
}
