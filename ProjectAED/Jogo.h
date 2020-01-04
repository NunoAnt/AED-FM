#include <stdio.h>
#include <string.h>
#include <time.h>


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
	int ativo;
} Jogo;

// esta fun��o guardar uma cole��o de jogos	
void gravaTodosJogos(Jogo* jogos, int n);

// esta fun��o apresenta a proxima jornada
void mostrarProximaJornada(int numeroJornada);

// esta fun��o retorna um jogo
Jogo obterJogo(int idEquipa, int numeroJornada);

// esta fun��o simula o jogo
void simularJogo(Jogo jogo, int idEquipa);