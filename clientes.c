#include <stdio.h>
#include <string.h>
#include "clientes.h"

// Função para ler strings com segurança
void lerString(const char* mensagem, char* destino, int tamanho) {
    if (mensagem && mensagem[0] != '\0') {
        printf("%s", mensagem);
    }
    if (fgets(destino, tamanho, stdin)) {
        size_t len = strlen(destino);
        if (len > 0 && destino[len - 1] == '\n') {
            destino[len - 1] = '\0';
        }
    }
}

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

    lerString("Nome do cliente: ", c.nome, MAX_NOME);
    lerString("CPF do cliente: ", c.cpf, MAX_NOME);
    lerString("Email do cliente: ", c.email, MAX_EMAIL);
    lerString("Telefone do cliente: ", c.telefone, MAX_TELEFONE);

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
        printf("ID %d - %s - CPF: %s\n   Email: %s\n   Telefone: %s\n",
            clientes[i].id,
            clientes[i].nome,
            clientes[i].cpf,
            clientes[i].email,
            clientes[i].telefone);
    }
}

Cliente* buscarClientePorId(int id) {
    for (int i = 0; i < qtdClientes; i++) {
        if (clientes[i].id == id) return &clientes[i];
    }
    return NULL;
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
    getchar();

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

void editarCliente() {
    if (qtdClientes == 0) {
        printf("Nenhum cliente cadastrado para editar.\n");
        return;
    }

    listarClientes();
    printf("Digite o ID do cliente para editar: ");
    int id;
    scanf("%d", &id);
    getchar();

    Cliente* c = buscarClientePorId(id);
    if (c == NULL) {
        printf("Cliente com ID %d nao encontrado.\n", id);
        return;
    }

    printf("Editando cliente ID %d:\n", c->id);

    printf("Nome atual (%s): ", c->nome);
    lerString("", c->nome, MAX_NOME);

    printf("CPF atual (%s): ", c->cpf);
    lerString("", c->cpf, MAX_NOME);

    printf("Email atual (%s): ", c->email);
    lerString("", c->email, MAX_EMAIL);

    printf("Telefone atual (%s): ", c->telefone);
    lerString("", c->telefone, MAX_TELEFONE);

    printf("Cliente atualizado com sucesso.\n");
}
