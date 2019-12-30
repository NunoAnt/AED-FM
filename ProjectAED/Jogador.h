#include <stdio.h>
#include <string.h>

#define FICHEIRO "Jogadores.dat"
#define TRUE 1
#define FALSE 0

// Estrutura do Jogador
typedef struct {
	int id;
	int idEquipa;
	char nome[40];
	int numero;
	float vencimentoMensal;
	int dia, mes, anoContrato;
	char posicao[20];
	int statGr;
	int statD;
	int statM;
	int statA;
	float preco;
	int ativo;
} Jogador;


// Esta funcao guarda uma cole��o de jogadores
void gravaTodosJogadores(Jogador* jogadores, int n);

// Esta fun��o lista os jogadores
void mostraTodosJogadores(void);

// Esta fun��o lista os jogadores por id da Equipa
void mostrarJogadorEquipa(int idEquipa);
