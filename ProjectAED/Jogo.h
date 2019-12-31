#include <stdio.h>
#include <string.h>

#define FICHEIRO_JOGO "Jogos.dat"
#define TRUE 1
#define FALSE 0

// Estrutura do Treinador
typedef struct {
	int id;
	int idEquipa1;
	int idEquipa2;
	int golosEquipa1;
	int golosEquipa2;
	int jornada;
} Jogo;

// esta função guardar uma coleção de jogos	
void gravaTodosJogos(Jogo* jogos, int n);