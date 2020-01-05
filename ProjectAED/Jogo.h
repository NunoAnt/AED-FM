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

// esta função guardar uma coleção de jogos	
void gravaTodosJogos(Jogo* jogos, int n);

// esta função apresenta a proxima jornada
void mostrarJornada(int numeroJornada);

// esta função retorna um jogo
Jogo obterJogo(int idEquipa, int numeroJornada);

// esta função simula o jogo
void simularJogo(Jogo jogo, int idEquipa);

// esta função simula os jogos da equipas controladas pelo computador
void simularJogosAI(int idEquipaTreinador, int numeroJornada);