#ifndef PRODUTOS_H
#define PRODUTOS_H

#define MAX_PRODUTOS 50
#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
    int estoque;
} Produto;

extern Produto produtos[MAX_PRODUTOS];
extern int qtdProdutos;
extern int proxIdProduto;

void inserirProduto();
void listarProdutos();
Produto* buscarProdutoPorId(int id);
void excluirProduto();

#endif
