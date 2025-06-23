#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 10
#define MAX_PRODUTOS 50
#define MAX_VENDAS 100
#define MAX_ITENS_VENDA 20

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_TELEFONE 20

// --- Estruturas ---

typedef struct {
    int id;
    char nome[MAX_NOME];
    char cpf[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
} Cliente;

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
    int estoque;
} Produto;

typedef struct {
    int produtoId;
    int quantidade;
    float valorUnitario;
} ItemVenda;

typedef struct {
    int id;
    int clienteId;
    int numItens;
    ItemVenda itens[MAX_ITENS_VENDA];
    float total;
} Venda;

// --- Variáveis globais ---

Cliente clientes[MAX_CLIENTES];
int qtdClientes = 0;
int proxIdCliente = 1;

Produto produtos[MAX_PRODUTOS];
int qtdProdutos = 0;
int proxIdProduto = 1;

Venda vendas[MAX_VENDAS];
int qtdVendas = 0;
int proxIdVenda = 1;

// --- Funções Clientes ---

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

    printf("Email do cliente: ");
    scanf(" %[^\n]", c.email);

    printf("Telefone do cliente: ");
    scanf(" %[^\n]", c.telefone);

    if (strlen(c.telefone) == 0) {
        printf("Telefone invalido. Operacao cancelada.\n");
        return;
    }

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

    Cliente* c = buscarClientePorId(id);
    if (c == NULL) {
        printf("Cliente com ID %d nao encontrado.\n", id);
        return;
    }

    printf("Editando cliente ID %d:\n", c->id);
    printf("Nome atual (%s): ", c->nome);
    scanf(" %[^\n]", c->nome);

    printf("CPF atual (%s): ", c->cpf);
    scanf(" %[^\n]", c->cpf);

    printf("Email atual (%s): ", c->email);
    scanf(" %[^\n]", c->email);

    printf("Telefone atual (%s): ", c->telefone);
    scanf(" %[^\n]", c->telefone);

    printf("Cliente atualizado com sucesso.\n");
}

// --- Funções Produtos ---

void inserirProduto() {
    if (qtdProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;
    p.id = proxIdProduto++;

    printf("Nome do produto: ");
    scanf(" %[^\n]", p.nome);

    printf("Preco do produto: R$ ");
    scanf("%f", &p.preco);

    printf("Estoque disponivel: ");
    scanf("%d", &p.estoque);

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

// --- Funções Vendas ---

void registrarVenda() {
    if (qtdVendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    Venda v;
    v.id = proxIdVenda++;
    v.numItens = 0;
    v.total = 0;

    listarClientes();
    printf("Digite o ID do cliente comprador: ");
    scanf("%d", &v.clienteId);

    Cliente* c = buscarClientePorId(v.clienteId);
    if (c == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    int maisItens;
    do {
        listarProdutos();
        printf("Digite o ID do produto: ");
        int prodId;
        scanf("%d", &prodId);

        Produto* p = buscarProdutoPorId(prodId);
        if (p == NULL) {
            printf("Produto nao encontrado.\n");
            continue;
        }

        printf("Quantidade: ");
        int qtd;
        scanf("%d", &qtd);

        if (qtd > p->estoque) {
            printf("Estoque insuficiente! Estoque atual: %d\n", p->estoque);
            continue;
        }

        ItemVenda item;
        item.produtoId = prodId;
        item.quantidade = qtd;
        item.valorUnitario = p->preco;

        v.itens[v.numItens++] = item;
        p->estoque -= qtd;

        printf("Produto adicionado.\n");

        if (v.numItens >= MAX_ITENS_VENDA) {
            printf("Limite de itens atingido.\n");
            break;
        }

        printf("Adicionar mais itens? (1-Sim / 0-Nao): ");
        scanf("%d", &maisItens);
    } while (maisItens == 1);

    for (int i = 0; i < v.numItens; i++) {
        v.total += v.itens[i].quantidade * v.itens[i].valorUnitario;
    }

    vendas[qtdVendas++] = v;

    printf("\nVenda registrada com sucesso! ID: %d\n", v.id);
    printf("Cliente: %s\n", c->nome);
    printf("Itens:\n");
    for (int i = 0; i < v.numItens; i++) {
        Produto* p = buscarProdutoPorId(v.itens[i].produtoId);
        printf(" - %s (ID %d), Quantidade: %d, Valor unitario: R$ %.2f\n",
               p->nome, p->id, v.itens[i].quantidade, v.itens[i].valorUnitario);
    }
    printf("Total da venda: R$ %.2f\n", v.total);
}

void listarVendas() {
    if (qtdVendas == 0) {
        printf("Nenhuma venda registrada.\n");
        return;
    }

    printf("Vendas registradas:\n");
    for (int i = 0; i < qtdVendas; i++) {
        Venda v = vendas[i];
        Cliente* c = buscarClientePorId(v.clienteId);
        printf("ID Venda: %d - Cliente: %s\n", v.id, c ? c->nome : "Desconhecido");

        printf("Itens:\n");
        for (int j = 0; j < v.numItens; j++) {
            Produto* p = buscarProdutoPorId(v.itens[j].produtoId);
            printf("  * %s (ID %d), Quantidade: %d, Valor unitario: R$ %.2f\n",
                   p ? p->nome : "Produto nao encontrado",
                   v.itens[j].produtoId,
                   v.itens[j].quantidade,
                   v.itens[j].valorUnitario);
        }

        printf("Total: R$ %.2f\n\n", v.total);
    }
}

// --- Menu e main ---

void mostrarMenu() {
    printf("\nMENU\n");
    printf("0 - Sair\n");
    printf("1 - Inserir cliente\n");
    printf("2 - Inserir produto\n");
    printf("3 - Listar clientes\n");
    printf("4 - Excluir cliente\n");
    printf("5 - Listar produtos\n");
    printf("6 - Registrar venda\n");
    printf("7 - Listar vendas\n");
    printf("8 - Editar cliente\n");
    printf("9 - Excluir produto\n");
    printf("Selecione uma opcao: ");
}

int main() {
    int opcao;
    do {
        mostrarMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 0: printf("Saindo...\n"); break;
            case 1: inserirCliente(); break;
            case 2: inserirProduto(); break;
            case 3: listarClientes(); break;
            case 4: excluirCliente(); break;
            case 5: listarProdutos(); break;
            case 6: registrarVenda(); break;
            case 7: listarVendas(); break;
            case 8: editarCliente(); break;
            case 9: excluirProduto(); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
