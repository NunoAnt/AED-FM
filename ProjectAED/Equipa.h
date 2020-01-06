#include <stdio.h>
#include <string.h>

#define FICHEIRO_EQUIPA "Equipas.dat"
#define TRUE 1
#define FALSE 0

// Estrutura da Equipa
typedef struct {
	int id;
	char nome[30];
	char nomeEstadio[40];
	int numeroLugaresEstadio;
	float fundosClube;
	float despesasMensais;
	int ativo;
} Equipa;


// mostra dados existentes neste momento no ficheiro
void mostraEquipasAtivas(void);

// gravar uma cole��o de equipas
void gravaTodasEquipas(Equipa* equipas, int n);

// obter uma equipa conforme o nome
Equipa obterEquipa(char* nome);

// obter uma equipa conforme o id
Equipa obterEquipaById(int id);

// mostra os dados atuais da equipa
void mostrarEquipa(int id);

// esta fun��o retorna o indice onde se encontra a equipa no ficheiro
int getIndiceEquipa(int id);

// esta fun��o altera os dados da equipa com o indice
void editarEquipa(int indice, Equipa equipaAlterada);