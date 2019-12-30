#include <stdio.h>
#include <string.h>

#define FICHEIRO "Equipas.dat"
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

// gravar uma coleção de equipas
void gravaTodasEquipas(Equipa* equipas, int n);

// obter uma equipa conforme o nome
Equipa obterEquipa(char* nome);

// obter uma equipa conforme o id
Equipa obterEquipaById(int id);