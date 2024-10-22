#include <stdio.h>
#include <string.h>
#define TAMM 40

typedef struct sPassageiro {
    char nome[TAMM];
    int idade;
} PASSAGEIRO;

typedef struct sDeque {
    PASSAGEIRO passageiros[TAMM];
    int inicio, fim;
} DEQUE;

void inicializar(DEQUE *deque) {
    deque->inicio = TAMM - 1; // Início da deque
    deque->fim = TAMM - 1; // Fim da deque
}

int cheio(DEQUE deque) {
    return (deque.fim + 1) % TAMM == deque.inicio;
}

int vazio(DEQUE deque) {
    return deque.inicio == deque.fim;
}

PASSAGEIRO criar_passageiro() {
    PASSAGEIRO p;
    printf("Digite o nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    return p;
}

void embarcar_inicio(DEQUE *deque, PASSAGEIRO p) {
    if (cheio(*deque)) {
        printf("Onibus CHEIO\n");
    } else {
        deque->passageiros[deque->inicio] = p; // Adiciona o passageiro
        deque->inicio = (deque->inicio - 1 + TAMM) % TAMM; // Move o início
    }
}

void embarcar_fim(DEQUE *deque, PASSAGEIRO p) {
    if (cheio(*deque)) {
        printf("Onibus CHEIO\n");
    } else {
        deque->fim = (deque->fim + 1) % TAMM; // Move o fim
        deque->passageiros[deque->fim] = p; // Adiciona o passageiro
    }
}

PASSAGEIRO desembarcar(DEQUE *deque) {
    PASSAGEIRO p = {"", 0};
    if (vazio(*deque)) {
        printf("Onibus VAZIO\n");
    } else {
        deque->inicio = (deque->inicio + 1) % TAMM; // Move o início
        p = deque->passageiros[deque->inicio]; // Retorna o passageiro
    }
    return p;
}

void mostrar_onibus(DEQUE deque) {
    int i = (deque.inicio + 1) % TAMM;
    if (vazio(deque)) {
        printf("ONIBUS VAZIO\n");
    } else {
        while (i != (deque.fim + 1) % TAMM) {
            printf("PASSAGEIRO: %s, IDADE: %d\n", deque.passageiros[i].nome, deque.passageiros[i].idade);
            i = (i + 1) % TAMM;
        }
    }
}

int main() {
    DEQUE onibus;
    inicializar(&onibus);
    PASSAGEIRO p;
    int op;

    // Cenário de embarque
    char *passageiros_iniciais[][2] = {
        {"Bart", "20"},
        {"Lisa", "19"},
        {"Homer Simpson", "62"},
        {"Marge", "65"},
        {"Maggie", "15"}
    };

    for (int i = 0; i < 5; i++) {
        p = criar_passageiro();
        strcpy(p.nome, passageiros_iniciais[i][0]);
        p.idade = atoi(passageiros_iniciais[i][1]);
        if (p.idade >= 60) {
            embarcar_inicio(&onibus, p);
        } else {
            embarcar_fim(&onibus, p);
        }
    }

    // Mais passageiros
    char *passageiros_vice[][2] = {
        {"Papai Smurf", "70"},
        {"Smurfette", "18"},
        {"Desastrado", "25"},
        {"Preguiça", "30"},
        {"Vovô Smurf", "95"}
    };

    for (int i = 0; i < 5; i++) {
        p = criar_passageiro();
        strcpy(p.nome, passageiros_vice[i][0]);
        p.idade = atoi(passageiros_vice[i][1]);
        if (p.idade >= 60) {
            embarcar_inicio(&onibus, p);
        } else {
            embarcar_fim(&onibus, p);
        }
    }

    // Passageiros da última parada
    char *passageiros_fim[][2] = {
        {"Bob Esponja", "10"},
        {"Patrick", "12"},
        {"Seu Serigueijo", "62"}
    };

    for (int i = 0; i < 3; i++) {
        p = criar_passageiro();
        strcpy(p.nome, passageiros_fim[i][0]);
        p.idade = atoi(passageiros_fim[i][1]);
        if (p.idade >= 60) {
            embarcar_inicio(&onibus, p);
        } else {
            embarcar_fim(&onibus, p);
        }
    }

    // Desembarque de todos os passageiros
    printf("\nDesembarque de todos os passageiros:\n");
    while (!vazio(onibus)) {
        p = desembarcar(&onibus);
        if (p.idade > 0) { // Verifica se o passageiro é válido
            printf("Desembarcou: %s, IDADE: %d\n", p.nome, p.idade);
        }
    }

    return 0;
}

