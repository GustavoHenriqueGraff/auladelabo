#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 10
#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    char cpf[MAX_NOME];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int qtdClientes = 0;
int proxIdCliente = 1;

void inserirCliente() {
    if (qtdClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }
    Cliente c;
    c.id = proxIdCliente++;

    printf("Nome do cliente: ");
    scanf(" %[^\n]", c.nome);
    printf("CPF do cliente: ");
    scanf(" %[^\n]", c.cpf);

    clientes[qtdClientes++] = c;
    printf("Cliente inserido com sucesso! ID: %d\n", c.id);
}

void listarClientes() {
    if (qtdClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("Clientes cadastrados:\n");
    for (int i = 0; i < qtdClientes; i++) {
        printf("ID %d - %s - CPF: %s\n", clientes[i].id, clientes[i].nome, clientes[i].cpf);
    }
}

void excluirCliente() {
    if (qtdClientes == 0) {
        printf("Nenhum cliente cadastrado para excluir.\n");
        return;
    }
    listarClientes();
    printf("Digite o ID do cliente para excluir: ");
    int id;
    scanf("%d", &id);

    int idx = -1;
    for (int i = 0; i < qtdClientes; i++) {
        if (clientes[i].id == id) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("Cliente com ID %d nao encontrado.\n", id);
        return;
    }

    for (int i = idx; i < qtdClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    qtdClientes--;
    printf("Cliente com ID %d excluido com sucesso.\n", id);
}
