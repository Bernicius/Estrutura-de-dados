
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 50

typedef struct {
    char nome[40];
    char responsavel[40];
    char cpf[12];
    char situacao; // 's' para pago, 'n' para não pago
    int produto;   // 1: bebida, 2: lanches, 3: artigos em geral
} BARRACA;

typedef struct {
    BARRACA vetor[TAM];
    int n; // Contador de barracas alugadas
} LISTA;

void inicializar(LISTA *lista) {
    lista->n = -1; // Inicia a lista vazia
}

int verificar_vazio(LISTA *lista) {
    return (lista->n == -1);
}

int verificar_cheio(LISTA *lista) {
    return (lista->n == TAM - 1);
}

BARRACA adicionar_barraca() {
    BARRACA b;

    printf("Digite o nome do dono da barraca: ");
    scanf(" %[^\n]", b.nome);
    
    printf("Digite o nome do responsavel: ");
    scanf(" %[^\n]", b.responsavel);
    
    printf("Digite o CPF: ");
    scanf(" %[^\n]", b.cpf);
    
    printf("Digite a situacao da barraca (s para pago, n para não pago): ");
    scanf(" %c", &b.situacao);
    b.situacao = tolower(b.situacao); // Converte para minúsculo
    
    while (b.situacao != 's' && b.situacao != 'n') {
        printf("Situacao invalida! Digite novamente (s/n): ");
        scanf(" %c", &b.situacao);
        b.situacao = tolower(b.situacao);
    }
    
    printf("Digite o identificador de produto (1: bebida, 2: lanches, 3: artigos em geral): ");
    scanf("%d", &b.produto);

    while (b.produto < 1 || b.produto > 3) {
        printf("Produto invalido! Digite novamente (1-3): ");
        scanf("%d", &b.produto);
    }

    return b;
}

void alugar_barraca(LISTA *lista) {
    if (!verificar_cheio(lista)) {
        BARRACA barraca = adicionar_barraca();
        lista->n++;
        lista->vetor[lista->n] = barraca; // Adiciona a barraca
    } else {
        printf("Quantidade de barracas cheia.\n");
    }
}

void relatorio_inadimplentes(LISTA *lista) {
    if (verificar_vazio(lista)) {
        printf("Nenhuma barraca cadastrada.\n");
        return;
    }

    printf("Relatório de locatários inadimplentes:\n");
    for (int i = 0; i <= lista->n; i++) {
        if (lista->vetor[i].situacao == 'n') {
            printf("Nome: %s\n", lista->vetor[i].nome);
            printf("CPF: %s\n", lista->vetor[i].cpf);
            printf("Responsavel: %s\n", lista->vetor[i].responsavel);
            printf("Situacao: %c\n", lista->vetor[i].situacao);
            printf("Produto: %d\n", lista->vetor[i].produto);
            printf("-------------------------\n");
        }
    }
}

void relatorio_barracas(LISTA *lista) {
    if (verificar_vazio(lista)) {
        printf("Nenhuma barraca cadastrada.\n");
        return;
    }

    int ocupadas = 0;
    printf("Barracas ocupadas:\n");
    for (int i = 0; i <= lista->n; i++) {
        printf("Nome: %s\n", lista->vetor[i].nome);
        printf("CPF: %s\n", lista->vetor[i].cpf);
        printf("Responsavel: %s\n", lista->vetor[i].responsavel);
        printf("Situacao: %c\n", lista->vetor[i].situacao);
        printf("Produto: %d\n", lista->vetor[i].produto);
        printf("-------------------------\n");
        ocupadas++;
    }

    printf("Quantidade de barracas ocupadas: %d\n", ocupadas);
    printf("Quantidade de barracas vagas: %d\n", TAM - ocupadas);
}

int menu() {
    int op;
    printf("\n[01] Cadastrar uma barraca\n");
    printf("[02] Relatório de barracas inadimplentes\n");
    printf("[03] Relatório de barracas ocupadas e vagas\n");
    printf("[04] Sair\n");
    printf("Digite uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    LISTA lista;
    inicializar(&lista);
    int op;

    do {
        op = menu();
        switch (op) {
            case 1:
                alugar_barraca(&lista);
                break;
            case 2:
                relatorio_inadimplentes(&lista);
                break;
            case 3:
                relatorio_barracas(&lista);
                break;
            case 4:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 4);

    return 0;
}
