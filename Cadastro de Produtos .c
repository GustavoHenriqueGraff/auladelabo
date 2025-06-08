#define MAX_PRODUTOS 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
    int estoque;
} Produto;

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
        printf("ID %d - %s - R$ %.2f - Estoque: %d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
    }
}

Produto* buscarProdutoPorId(int id) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (produtos[i].id == id) return &produtos[i];
    }
    return NULL;
}
