#include <stdio.h>
#include <string.h>
#define TAMM 40

typedef struct sPassageiro{
    char nome[TAMM];
    int idade;
}PASSAGEIRO;

typedef struct sOnibus{
    PASSAGEIRO embarque[TAMM];
    int inicio, fim;
}ONIBUS;

void inicializar(ONIBUS * onibus)
{
    onibus->inicio = TAMM -1;
    onibus->fim = TAMM -1;
}

int cheio(ONIBUS onibus)
{
    if((onibus.fim + 1) % TAMM == onibus.inicio)
    {
        return 1;
    }
    return 0;
}

int vazio(ONIBUS onibus)
{
    if(onibus.inicio == onibus.fim)
    {
        return 1;
    }
    return 0;
}

PASSAGEIRO passageiro()
{
    PASSAGEIRO p;
    fflush(stdin);
    printf("Digite o nome:");
    fflush(stdin);
    scanf("%[^\n]",p.nome);
    printf("Digite a idade:");
    scanf("%d",&p.idade);
    return p;
}

void embarcar_inicio(ONIBUS * onibus, PASSAGEIRO p)
{
    if(cheio(*onibus))
    {
        printf("Onibus CHEIO\n");
    }else{
        //INSERE ANTES E DECREMENTA  DPS (...... -1 + TAMM) % TAMM
        strcpy(onibus->embarque[onibus->inicio].nome, p.nome);
        onibus->embarque[onibus->inicio].idade = p.idade;
        onibus->inicio = (onibus->inicio - 1 +TAMM) % TAMM;
    }
}

void embarcar_fim(ONIBUS * onibus, PASSAGEIRO p)
{

    if(cheio(*onibus))
    {
        printf("Onibus CHEIO\n");
    }else{
        onibus->fim = (onibus->fim + 1) % TAMM;
        strcpy(onibus->embarque[onibus->fim].nome, p.nome);
        onibus->embarque[onibus->fim].idade = p.idade;
    }
}

void mostrar_onibus(ONIBUS onibus)
{
    int i= (onibus.inicio + 1) % TAMM;
    if(vazio(onibus))
    {
        printf("ONIBUS VAZIO, daqui so sai a morte\n\n");
    }else{
        while(i != (onibus.fim + 1) % TAMM)
        {
            printf("-------------------\n");
            printf("PASSAGEIRO %d\n",i);
            printf("[%s]\n",onibus.embarque[i].nome);
            printf("[%d]\n",onibus.embarque[i].idade);
            i = (i + 1) % TAMM;
        }
    }
}

PASSAGEIRO desembarcar(ONIBUS * onibus)
{
    PASSAGEIRO p = {"",};
    if(vazio(*onibus))
    {
        printf("ONIBUS VAZIO, daqui so sai a morte\n");
    }else{
        onibus->inicio = (onibus->inicio + 1) % TAMM;
        p = onibus->embarque[onibus->inicio];
    }
    return p;
}

int menu()
{
    int op;
    printf("[01]Embarcar\n");
    printf("[02]Desembarcar\n");
    printf("[03]Mostrar onibus\n");
    printf("Digite uma opcao:");
    scanf("%d",&op);
    return op;
}

void main()
{
    ONIBUS onibus;
    inicializar(&onibus);
    PASSAGEIRO p;
    int op;

    do{
        op = menu();
        switch(op)
        {
        case 1:
            p = passageiro();
            if(p.idade >= 60)
            {
                embarcar_inicio(&onibus,p);
            }else{
                embarcar_fim(&onibus,p);
            }
            break;
        case 2:
            p = desembarcar(&onibus);
            printf("[%s]\n",p.nome);
            printf("[%d]\n",p.idade);
            break;
        case 3:
            mostrar_onibus(onibus);
            break;
        default:
            printf("Opcao invalida\n");
        }
    }while(op != 4);

}
