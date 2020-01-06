#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FICHEIRO_JOGADOR "Jogadores.dat"
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

// esta fun��o retorna um jogador da equipa convocada pelo treinador
Jogador obterJogadorEquipa(int idEquipa, int numeroJogador);

// Esta fun��o simula um plantel de uma equipa
Jogador simularConvocadosAI(int idEquipa, Jogador* jogadoresConvocados);

// mostrar jogadores por Nome
void mostraJogadoresByName(char* nome);

// mostrar jogadores por equipa
void mostraJogadoresByEquipa(int idEquipa);

// esta fun��o retorna um jogador conforme o ID
Jogador obterJogadorByID(int idJogador);

// esta fun��o realiza a transferencias de jogadores
void realizarTransferencia(int idEquipaTreinador);

// esta fun��o, procura o registo do jogo com o id e devolve o indice onde se encontra (dentro do ficheiro);
int getIndiceJogador(int id);