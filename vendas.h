#ifndef VENDAS_H
#define VENDAS_H

#define MAX_ITENS_VENDA 20
#define MAX_VENDAS 100

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

extern Venda vendas[MAX_VENDAS];
extern int qtdVendas;
extern int proxIdVenda;

void registrarVenda();
void listarVendas();

#endif
