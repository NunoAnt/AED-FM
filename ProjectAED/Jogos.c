#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "Jogo.h"
#include "Equipa.h"
#include "Jogador.h"

// esta função gera um numero aliatorio entre o seguinte espaço
int randGolos(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

// esta função recebe um conjuntos de jogos e grava-os na base de dados
void gravaTodosJogos(Jogo* jogos, int n)
{
	// variaveis
	FILE* ficheiro;
	int i;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO_JOGO, "w+b");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!", FICHEIRO_JOGO);
		return;
	}

	// gravar cada uma das equipas no final do ficheiro
	for (i = 0; i < n; i++)
	{
		// Colocar o apontador no fim do ficheiro
		fseek(ficheiro, 0, SEEK_END);

		// gravar a equipa
		fwrite(&jogos[i], sizeof(Jogo), 1, ficheiro);
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função retorna um jogo com o mesmo id e na mesma jornada
Jogo obterJogo(int idEquipa, int numeroJornada)
{
	// variaveis
	FILE* ficheiro;
	Jogo jogo;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGO, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGO);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter as equipas
	while (fread(&jogo, sizeof(Jogo), 1, ficheiro) == 1)
	{
		if (jogo.ativo != 0 && (jogo.idEquipa1 == idEquipa || jogo.golosEquipa2 == idEquipa) && jogo.jornada == numeroJornada)
		{
			fclose(ficheiro);
			return jogo;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar a equipa
	return jogo;
}

// mostrar jogos da proxima jornada
void mostrarProximaJornada(int numeroJornada)
{
	// variaveis
	FILE* ficheiro;
	Jogo jogo;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGO, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGO);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// inicio da listagem
	printf("\n\n=============== PROXIMA JORNADA ===============\n");

	// obter os dados dos ficheiros
	while (fread(&jogo, sizeof(Jogo), 1, ficheiro) == 1)
	{
		if (jogo.ativo != 0 && jogo.jornada == numeroJornada)
		{
			printf("%-30s vs %30s\n", obterEquipaById(jogo.idEquipa1).nome, obterEquipaById(jogo.idEquipa2).nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função simula o jogo
void simularResultadoJogo(Jogo jogo, Jogador* equipa1, Jogador* equipa2)
{
	// declarar variaveis
	int forcaAtaqueEquipa1 = 0, forcaAtaqueEquipa2 = 0, forcaMediosEquipa1 = 0, forcaMediosEquipa2 = 0, forcaDefesasEquipa1 = 0, forcaDefesasEquipa2 = 0;
	int i;

	// somar força da equipa
	for (i = 0; i < 11; i++)
	{
		// força de ataque
		forcaAtaqueEquipa1 += equipa1[i].statA;
		forcaAtaqueEquipa2 += forcaAtaqueEquipa2 + equipa2[i].statA;

		// força de meio campo
		forcaMediosEquipa1 += equipa1[i].statM;
		forcaMediosEquipa2 += equipa2[i].statM;

		// força de defesa
		forcaDefesasEquipa1 += equipa1[i].statD;
		forcaDefesasEquipa2 += equipa2[i].statD;
	}

	// definir quantos golos marca uma equipa com ataque vs defesa
	if (forcaAtaqueEquipa1 > forcaDefesasEquipa2)
	{
		jogo.golosEquipa1 += randGolos(0, 3);
	}
	else if (forcaAtaqueEquipa2 > forcaDefesasEquipa1)
	{
		jogo.golosEquipa2 += randGolos(0, 3);
	}
	else
	{
		jogo.golosEquipa1 += randGolos(0, 3);
		jogo.golosEquipa2 += randGolos(0, 3);
	}

	// verificar quem tem um melhor meio campo
	if (forcaMediosEquipa1 > forcaMediosEquipa2)
	{
		jogo.golosEquipa1 += randGolos(0, 2);
	}
	else
	{
		jogo.golosEquipa2 += randGolos(0, 2);
	}

	printf("Equipa1-%d vs Equipa2-%d", jogo.golosEquipa1, jogo.golosEquipa2);
}

// esta funcao simula o jogo
void simularJogo(Jogo jogo, int idEquipa)
{
	// declarar variaveis
	int tatica, i, numeroJogador, idEquipaAdversaria;
	char taticas[4][6] = { "5-3-2", "4-5-1", "4-4-2", "4-3-3" };
	Jogador equipaConvocada1[11], *equipaConvocada2;

	// limpar consola
	system("cls");

	// apresentar proximo jogo
	printf("============ JOGO ==============\n");
	printf("%s vs %s\n", obterEquipaById(jogo.idEquipa1).nome, obterEquipaById(jogo.idEquipa2).nome);

	// apresentar a taticas
	for (i = 0; i < 4; i++)
	{
		printf("%d- %s\n", i+1, taticas[i]);
	}

	// escolher a tatica
	printf("Indique qual a tatica que pretende escolher: ");
	scanf("%d", &tatica);
	while (getchar() != '\n');

	// apresentar o plantel da equipa
	mostrarJogadorEquipa(idEquipa);

	// recolher convocados
	for (i = 0; i < 11; i++)
	{
		printf("Indique o numero do Jogador para convocar: ");
		scanf("%d", &numeroJogador);
		while (getchar() != '\n');

		equipaConvocada1[i] = obterJogadorEquipa(idEquipa, numeroJogador);
	}

	// verificar qual a equipa para ser controlada pelo computador
	if (idEquipa == jogo.idEquipa1)
	{
		idEquipaAdversaria = jogo.idEquipa2;
	}
	else
	{
		idEquipaAdversaria = jogo.idEquipa1;
	}

	// simular o plantel da equipa adversaria
	equipaConvocada2 = simularPlantelAI(idEquipaAdversaria);

	// simular o resultado
	simularResultadoJogo(jogo, equipaConvocada1, equipaConvocada2);
}