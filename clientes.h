#ifndef CLIENTES_H
#define CLIENTES_H

#define MAX_CLIENTES 10
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_TELEFONE 20

typedef struct {
    int id;
    char nome[MAX_NOME];
    char cpf[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
} Cliente;

extern Cliente clientes[MAX_CLIENTES];
extern int qtdClientes;
extern int proxIdCliente;

void inserirCliente();
void listarClientes();
Cliente* buscarClientePorId(int id);
void excluirCliente();
void editarCliente();

#endif
