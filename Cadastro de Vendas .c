#define MAX_VENDAS 100
#define MAX_ITENS_VENDA 20

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

Venda vendas[MAX_VENDAS];
int qtdVendas = 0;
int proxIdVenda = 1;

Cliente* buscarClientePorId(int id);  // Declarar para uso

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
        printf("Digite o ID do produto para adicionar na venda: ");
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
            printf("Limite maximo de itens atingido.\n");
            break;
        }

        printf("Deseja adicionar mais itens? (1-Sim / 0-Nao): ");
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
        printf("ID Venda: %d - Cliente: %s\n", v.id, c ? c->nome : "Cliente nao encontrado");
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
