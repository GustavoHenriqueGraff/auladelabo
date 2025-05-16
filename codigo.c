#include <stdio.h>
#include <string.h>

#define client_max    10
#define produto_mac   50
#define max_tam       50

typedef struct {
    char nome[max_tam];
    char email[max_tam];
} Cliente;

typedef struct {
    char nome[max_tam];
    float preco;
    float quantidade;
} Produto;

Cliente estrutura_clientes_[client_max];
Produto Estrutura_produto[produto_mac];
int qtdClientesCadastrados = 0;
int qtdProdutosCadastrados = 0;

// Menu de opções
void mostraOpcoes() {
    printf("MENU\n");
    printf("0 - Sair\n");
    printf("1 - Inserir cliente\n");
    printf("2 - Inserir produto\n");
    printf("3 - Listar clientes\n");
    printf("4 - Excluir cliente\n");
    printf("5 - Listar produtos\n");
    printf("\n");
}

void insereCliente() {
    if (qtdClientesCadastrados >= client_max) {
        printf("Limite de clientes atingido!\n");
        return;
    }
    printf("Nome do cliente: ");
    scanf("%s", estrutura_clientes_[qtdClientesCadastrados].nome);
    printf("Email do cliente: ");
    scanf("%s", estrutura_clientes_[qtdClientesCadastrados].email);
    qtdClientesCadastrados++;
    printf("Cliente inserido com sucesso!\n");
}

void listarClientes() {
    if (qtdClientesCadastrados == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("Clientes Cadastrados:\n");
    for (int i = 0; i < qtdClientesCadastrados; i++) {
        printf("%d) %s — %s\n",
               i + 1,
               estrutura_clientes_[i].nome,
               estrutura_clientes_[i].email);
    }
}

void excluirClientes() {
    if (qtdClientesCadastrados == 0) {
        printf("Não há clientes para excluir.\n");
        return;
    }
    listarClientes();
    int idx;
    printf("Número do cliente a excluir: ");
    scanf("%d", &idx);
    if (idx < 1 || idx > qtdClientesCadastrados) {
        printf("Índice inválido.\n");
        return;
    }
    for (int i = idx - 1; i < qtdClientesCadastrados - 1; i++) {
        estrutura_clientes_[i] = estrutura_clientes_[i + 1];
    }
    qtdClientesCadastrados--;
    printf("Cliente excluído com sucesso!\n");
}

void insereProduto() {
    if (qtdProdutosCadastrados >= produto_mac) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Nome do produto: ");
    scanf("%s", Estrutura_produto[qtdProdutosCadastrados].nome);

    printf("Preço do produto: R$ ");
    scanf("%f", &Estrutura_produto[qtdProdutosCadastrados].preco);

    printf("Quantidade do produto: ");
    scanf("%f", &Estrutura_produto[qtdProdutosCadastrados].quantidade);

    qtdProdutosCadastrados++;
    printf("Produto inserido com sucesso!\n");
}

void listarProdutos() {
    if (qtdProdutosCadastrados == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("\n--- Produtos Cadastrados ---\n");
    for (int i = 0; i < qtdProdutosCadastrados; i++) {
        printf("%d) %s — R$ %.2f (%.2f un.)\n",
               i + 1,
               Estrutura_produto[i].nome,
               Estrutura_produto[i].preco,
               Estrutura_produto[i].quantidade);
    }
}

int main(void) {
    int opcao;
    do {
        mostraOpcoes();
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: printf("Saindo...\n"); break;
            case 1: insereCliente();       break;
            case 2: insereProduto();       break;
            case 3: listarClientes();      break;
            case 4: excluirClientes();     break;
            case 5: listarProdutos();      break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
