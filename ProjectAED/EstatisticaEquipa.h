#include <stdio.h>
#include <string.h>

#define FICHEIRO_ESTATISTICA_EQUIPA "StatEquipa.dat"
#define TRUE 1
#define FALSE 0

// Estrutura da estatistica da equipa
typedef struct {
	int id;
	int idEquipa;
	int golosMarcados;
	int golosSofridos;
	int numeroVitorias;
	int numeroEmpates;
	int numeroDerrotas;
	int numeroPontos;
	int ativo;
} EstatisticaEquipa;

// esta função recebe um conjuntos de estatisticas e grava-os na base de dados
void gravaStatEquipasTodas(EstatisticaEquipa* estatisticasEquipas, int n);

// esta função mostra a classificação dasEquipas
void mostrarClassificacao(void);

// esta função, procura o registo da estatistica da equipa com o idEquipa e devolve o indice onde se encontra (dentro do ficheiro);
int getIndiceEstatisticaEquipa(int id);

// esta função retorna a estatistica da equipa
EstatisticaEquipa obterEstatisticaByEquipaId(int idEquipa);

// esta função edita uma estatistica já no ficheiro
void editarEstatistica(int indice, EstatisticaEquipa estatisticaEquipaAlterada);