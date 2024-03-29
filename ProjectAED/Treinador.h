#include <stdio.h>
#include <string.h>

#define FICHEIRO_TREINADOR "Treinador.dat"
#define TRUE 1
#define FALSE 0

// Estrutura do Treinador
typedef struct {
	int id;
	int idEquipa;
	char nome[40];
	int dia, mes, ano;
	int ativo;
} Treinador;


// Esta funcao guarda o treinador
void registarTreinador(Treinador treinador);

// esta fun��o retorna um treinador conforme o Id enviado
Treinador obterTreinador(int id);