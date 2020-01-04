#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "Jogador.h"
#include "Equipa.h"

// esta função gera um numero aliatorio entre o seguinte espaço
int rand_in_range(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

// esta função recebe um e grava-o na base de dados
void gravaTodosJogadores(Jogador* jogadores, int n)
{
	// variaveis
	FILE* ficheiro;
	int i;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "w+b");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!", FICHEIRO_JOGADOR);
		return;
	}

	// gravar cada uma das equipas no final do ficheiro
	for (i = 0; i < n; i++)
	{
		// Colocar o apontador no fim do ficheiro
		fseek(ficheiro, 0, SEEK_END);

		// gravar a equipa
		fwrite(&jogadores[i], sizeof(Jogador), 1, ficheiro);
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// mostrar todos os jogadores
void mostraTodosJogadores(void)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// inicio da listagem
	printf("\n\n=== Jogadores ======\n");
	printf("%s\t%s\n", "ID", "NOME");

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0)
		{
			printf("%06d\t%-20s\n", jogador.id, jogador.nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// fim da listagem
	printf("=== fim ======\n");
}

// Esta função lista os jogadores por id da Equipa
void mostrarJogadorEquipa(int idEquipa)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// inicio da listagem
	printf("\n\n=== Plantel %s ======\n", obterEquipaById(idEquipa).nome);

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0 && jogador.idEquipa == idEquipa)
		{
			printf("Nome: %-20s\tNumero: %2d\tPosicao: %10s\tStat Gr: %3d\tStat Defesa: %3d\tStat Medio: %3d\tStat Avancado: %3d\tContrato: %02d/%02d/%4d\n", jogador.nome, jogador.numero, jogador.posicao, jogador.statGr, jogador.statD, jogador.statM, jogador.statA, jogador.dia, jogador.mes, jogador.anoContrato);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função retorna um jogador da equipa convocada pelo treinador
Jogador obterJogadorEquipa(int idEquipa, int numeroJogador)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;
	int i = 0, j;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0 && jogador.idEquipa == idEquipa && jogador.numero == numeroJogador)
		{
			fclose(ficheiro);
			return jogador;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	return jogador;
}

// Esta função simula um plantel de uma equipa
Jogador* simularPlantelAI(int idEquipa)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;
	static Jogador jogadoresConvocados[11];
	Jogador plantelEquipa[20];
	int i = 0, j;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0 && jogador.idEquipa == idEquipa)
		{
			plantelEquipa[i] = jogador;
			i++;
		}
	}

	// igual o i a 0 para percorer o array todo
	i = 0;

	// simular convocados
	while (i != 11)
	{
		// obter um jogador do plantel de forma aletoria
		jogador = plantelEquipa[i + rand_in_range(0, 5)];

		// verificar se o jogador já está convocado
		if (jogadorConvocadoExits(jogadoresConvocados, jogador) == FALSE)
		{
			jogadoresConvocados[i] = jogador;
			i++;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar plantel
	return jogadoresConvocados;
}

// verificar se o jogador já está convocado
int jogadorConvocadoExits(Jogador* jogadores, Jogador jogador)
{
	// declarar variaveis
	int i, existe = FALSE;

	// verificar se já existe
	for (i = 0; i < 11 && existe == FALSE; i++)
	{
		if (jogador.id == jogadores[i].id)
		{
			existe = TRUE;
		}
	}

	return existe;
}