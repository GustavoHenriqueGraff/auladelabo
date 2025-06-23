#include <stdio.h>
#include "clientes.h"
#include "produtos.h"
#include "vendas.h"

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
        getchar(); // limpar \n do buffer
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
