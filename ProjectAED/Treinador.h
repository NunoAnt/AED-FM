#include <stdio.h>
#include <string.h>

#define FICHEIRO "Treinador.dat"
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