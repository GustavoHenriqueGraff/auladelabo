#include <stdio.h>
#include "produtos.h"

Produto produtos[MAX_PRODUTOS];
int qtdProdutos = 0;
int proxIdProduto = 1;

void inserirProduto() {
    if (qtdProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;
    p.id = proxIdProduto++;

    printf("Nome do produto: ");
    fgets(p.nome, MAX_NOME, stdin);
    size_t len = strlen(p.nome);
    if (len > 0 && p.nome[len - 1] == '\n') p.nome[len - 1] = '\0';

    printf("Preco do produto: R$ ");
    scanf("%f", &p.preco);
    getchar();

    printf("Estoque disponivel: ");
    scanf("%d", &p.estoque);
    getchar();

    produtos[qtdProdutos++] = p;
    printf("Produto inserido com sucesso! ID: %d\n", p.id);
}

void listarProdutos() {
    if (qtdProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Produtos cadastrados:\n");
    for (int i = 0; i < qtdProdutos; i++) {
        printf("ID %d - %s - R$ %.2f - Estoque: %d\n",
            produtos[i].id,
            produtos[i].nome,
            produtos[i].preco,
            produtos[i].estoque);
    }
}

Produto* buscarProdutoPorId(int id) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (produtos[i].id == id) return &produtos[i];
    }
    return NULL;
}

void excluirProduto() {
    if (qtdProdutos == 0) {
        printf("Nenhum produto cadastrado para excluir.\n");
        return;
    }

    listarProdutos();
    printf("Digite o ID do produto para excluir: ");
    int id;
    scanf("%d", &id);
    getchar();

    int idx = -1;
    for (int i = 0; i < qtdProdutos; i++) {
        if (produtos[i].id == id) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Produto com ID %d nao encontrado.\n", id);
        return;
    }

    for (int i = idx; i < qtdProdutos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    qtdProdutos--;

    printf("Produto com ID %d excluido com sucesso.\n", id);
}
