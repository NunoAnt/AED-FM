#include <stdio.h>
#include <string.h>

#define FICHEIRO "Jogos.dat"
#define TRUE 1
#define FALSE 0

// Estrutura do Treinador
typedef struct {
	int id;
	int idEquipa1;
	int idEquipa2;
	int dia, mes, ano;
	int golosEquipa1;
	int golosEquipa2;
} Jogo;