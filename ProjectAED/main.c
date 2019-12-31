#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include <string.h>
#include "Equipa.h"
#include "Jogador.h"
#include "Treinador.h"
#include "Jogo.h"

// declarar sub-rotinas
void recolherDadosTreinador();
void realizarCalendario();
void mostrarPlantel(int idEquipa);
void mostrarDadosEquipa(int idEquipa);

int main(void)
{
	// declarar variaveis
	int opcao;

	// Mensagem inicial
	printf("==============================\n");
	printf("            AED FM              \n");
	printf("==============================\n\n");

	// este met�do guarda os dados do utilizador
	recolherDadosTreinador();

	// este met�do realiza o cal�ndario
	realizarCalendario();

	// Menu
	do 
	{
		// limpar a consola
		system("cls");
		
		// Apresenta��o do Ecra Principal
		printf("============ AED FM ===============\n\n");
		printf("Treinador: %s", obterTreinador(1).nome);
		printf("Clube Atual: %s \n\n", obterEquipaById(obterTreinador(1).idEquipa).nome);

		// Apresentacao Menu
		printf("1 - Plantel\n");
		printf("2 - Classificacao\n");
		printf("3 - Jogos\n");
		printf("4 - Transferencias\n");
		printf("6 - Clube\n");
		printf("7 - Treinador\n");
		printf("8 - Proximo Jogo\n");
		printf("0 - Sair\n\n");

		// recolher op��o e limpar o buffer
		printf("Insira a sua opcao: ");
		scanf("%d", &opcao);
		while (getchar() != '\n');

		// decidir a op��o
		switch (opcao)
		{
		case 1: 
			// apresentar o plantel da equipa
			mostrarPlantel(obterTreinador(1).idEquipa);
			break;
		case 6:
			// apresentar os dados da equipa
			mostrarDadosEquipa(obterTreinador(1).idEquipa);
			break;
		default:
			printf("Categoria nao prevista");
			break;
		}

	} while (opcao != 0);

	return 0;
}

// recolher os dados e guardar na base de dados
void recolherDadosTreinador() 
{
	// declarar vairaveis
	Treinador treinador;

	treinador.id = 1;
	treinador.ativo = TRUE;

	// recolher o nome do treiandor
	printf("Insira o seu nome: ");
	fgets(treinador.nome, 40, stdin);

	// recolher a idade
	printf("Insira a Data de Nascimento: Ex: (21/12/1998) ");
	scanf("%d/%d/%d", &treinador.dia, &treinador.mes, &treinador.ano);

	printf("\n");

	// apresentar as equipas
	mostraEquipasAtivas();

	// recolher a equipa escolhida
	printf("Escolha uma equipa (Nao incluir o 0): ");
	scanf("%d", &treinador.idEquipa);

	// guardar dados
	registarTreinador(treinador);
}

// sortear calend�rio e guardar na base de dados
void realizarCalendario()
{
	Jogo jogos[45];

	jogos[0].id = 1;
	jogos[0].idEquipa1 = 1;
	jogos[0].idEquipa2 = 8;
	jogos[0].jornada = 1;
	jogos[0].golosEquipa1 = 0;
	jogos[0].golosEquipa2 = 0;

	jogos[1].id = 2;
	jogos[1].idEquipa1 = 2;
	jogos[1].idEquipa2 = 3;
	jogos[1].jornada = 1;
	jogos[1].golosEquipa1 = 0;
	jogos[1].golosEquipa2 = 0;

	jogos[2].id = 3;
	jogos[2].idEquipa1 = 4;
	jogos[2].idEquipa2 = 7;
	jogos[2].jornada = 1;
	jogos[2].golosEquipa1 = 0;
	jogos[2].golosEquipa2 = 0;

	jogos[3].id = 4;
	jogos[3].idEquipa1 = 7;
	jogos[3].idEquipa2 = 6;
	jogos[3].jornada = 1;
	jogos[3].golosEquipa1 = 0;
	jogos[3].golosEquipa2 = 0;

	jogos[4].id = 5;
	jogos[4].idEquipa1 = 10;
	jogos[4].idEquipa2 = 9;
	jogos[4].jornada = 1;
	jogos[4].golosEquipa1 = 0;
	jogos[4].golosEquipa2 = 0;

	jogos[5].id = 6;
	jogos[5].idEquipa1 = 3;
	jogos[5].idEquipa2 = 1;
	jogos[5].jornada = 2;
	jogos[5].golosEquipa1 = 0;
	jogos[5].golosEquipa2 = 0;

	jogos[6].id = 7;
	jogos[6].idEquipa1 = 6;
	jogos[6].idEquipa2 = 10;
	jogos[6].jornada = 2;
	jogos[6].golosEquipa1 = 0;
	jogos[6].golosEquipa2 = 0;

	jogos[7].id = 8;
	jogos[7].idEquipa1 = 7;
	jogos[7].idEquipa2 = 5;
	jogos[7].jornada = 2;
	jogos[7].golosEquipa1 = 0;
	jogos[7].golosEquipa2 = 0;

	jogos[8].id = 9;
	jogos[8].idEquipa1 = 8;
	jogos[8].idEquipa2 = 4;
	jogos[8].jornada = 2;
	jogos[8].golosEquipa1 = 0;
	jogos[8].golosEquipa2 = 0;

	jogos[9].id = 10;
	jogos[9].idEquipa1 = 9;
	jogos[9].idEquipa2 = 2;
	jogos[9].jornada = 2;
	jogos[9].golosEquipa1 = 0;
	jogos[9].golosEquipa2 = 0;

	jogos[10].id = 11;
	jogos[10].idEquipa1 = 1;
	jogos[10].idEquipa2 = 9;
	jogos[10].jornada = 3;
	jogos[10].golosEquipa1 = 0;
	jogos[10].golosEquipa2 = 0;

	jogos[11].id = 12;
	jogos[11].idEquipa1 = 2;
	jogos[11].idEquipa2 = 6;
	jogos[11].jornada = 3;
	jogos[11].golosEquipa1 = 0;
	jogos[11].golosEquipa2 = 0;

	jogos[12].id = 13;
	jogos[12].idEquipa1 = 4;
	jogos[12].idEquipa2 = 3;
	jogos[12].jornada = 3;
	jogos[12].golosEquipa1 = 0;
	jogos[12].golosEquipa2 = 0;

	jogos[13].id = 14;
	jogos[13].idEquipa1 = 8;
	jogos[13].idEquipa2 = 7;
	jogos[13].jornada = 3;
	jogos[13].golosEquipa1 = 0;
	jogos[13].golosEquipa2 = 0;

	jogos[14].id = 15;
	jogos[14].idEquipa1 = 10;
	jogos[14].idEquipa2 = 5;
	jogos[14].jornada = 3;
	jogos[14].golosEquipa1 = 0;
	jogos[14].golosEquipa2 = 0;

	jogos[15].id = 16;
	jogos[15].idEquipa1 = 3;
	jogos[15].idEquipa2 = 8;
	jogos[15].jornada = 4;
	jogos[15].golosEquipa1 = 0;
	jogos[15].golosEquipa2 = 0;

	jogos[16].id = 17;
	jogos[16].idEquipa1 = 5;
	jogos[16].idEquipa2 = 2;
	jogos[16].jornada = 4;
	jogos[16].golosEquipa1 = 0;
	jogos[16].golosEquipa2 = 0;

	jogos[17].id = 18;
	jogos[17].idEquipa1 = 6;
	jogos[17].idEquipa2 = 1;
	jogos[17].jornada = 4;
	jogos[17].golosEquipa1 = 0;
	jogos[17].golosEquipa2 = 0;

	jogos[18].id = 19;
	jogos[18].idEquipa1 = 7;
	jogos[18].idEquipa2 = 10;
	jogos[18].jornada = 4;
	jogos[18].golosEquipa1 = 0;
	jogos[18].golosEquipa2 = 0;

	jogos[19].id = 20;
	jogos[19].idEquipa1 = 9;
	jogos[19].idEquipa2 = 4;
	jogos[19].jornada = 4;
	jogos[19].golosEquipa1 = 0;
	jogos[19].golosEquipa2 = 0;

	jogos[20].id = 21;
	jogos[20].idEquipa1 = 1;
	jogos[20].idEquipa2 = 5;
	jogos[20].jornada = 5;
	jogos[20].golosEquipa1 = 0;
	jogos[20].golosEquipa2 = 0;

	jogos[21].id = 22;
	jogos[21].idEquipa1 = 2;
	jogos[21].idEquipa2 = 10;
	jogos[21].jornada = 5;
	jogos[21].golosEquipa1 = 0;
	jogos[21].golosEquipa2 = 0;

	jogos[22].id = 23;
	jogos[22].idEquipa1 = 3;
	jogos[22].idEquipa2 = 7;
	jogos[22].jornada = 5;
	jogos[22].golosEquipa1 = 0;
	jogos[22].golosEquipa2 = 0;

	jogos[23].id = 24;
	jogos[23].idEquipa1 = 4;
	jogos[23].idEquipa2 = 6;
	jogos[23].jornada = 5;
	jogos[23].golosEquipa1 = 0;
	jogos[23].golosEquipa2 = 0;

	jogos[24].id = 25;
	jogos[24].idEquipa1 = 8;
	jogos[24].idEquipa2 = 9;
	jogos[24].jornada = 5;
	jogos[24].golosEquipa1 = 0;
	jogos[24].golosEquipa2 = 0;

	jogos[25].id = 26;
	jogos[25].idEquipa1 = 5;
	jogos[25].idEquipa2 = 4;
	jogos[25].jornada = 6;
	jogos[25].golosEquipa1 = 0;
	jogos[25].golosEquipa2 = 0;

	jogos[26].id = 27;
	jogos[26].idEquipa1 = 6;
	jogos[26].idEquipa2 = 8;
	jogos[26].jornada = 6;
	jogos[26].golosEquipa1 = 0;
	jogos[26].golosEquipa2 = 0;

	jogos[27].id = 28;
	jogos[27].idEquipa1 = 7;
	jogos[27].idEquipa2 = 2;
	jogos[27].jornada = 6;
	jogos[27].golosEquipa1 = 0;
	jogos[27].golosEquipa2 = 0;

	jogos[28].id = 29;
	jogos[28].idEquipa1 = 9;
	jogos[28].idEquipa2 = 3;
	jogos[28].jornada = 6;
	jogos[28].golosEquipa1 = 0;
	jogos[28].golosEquipa2 = 0;

	jogos[29].id = 30;
	jogos[29].idEquipa1 = 10;
	jogos[29].idEquipa2 = 1;
	jogos[29].jornada = 6;
	jogos[29].golosEquipa1 = 0;
	jogos[29].golosEquipa2 = 0;

	jogos[30].id = 31;
	jogos[30].idEquipa1 = 1;
	jogos[30].idEquipa2 = 2;
	jogos[30].jornada = 7;
	jogos[30].golosEquipa1 = 0;
	jogos[30].golosEquipa2 = 0;

	jogos[31].id = 32;
	jogos[31].idEquipa1 = 3;
	jogos[31].idEquipa2 = 6;
	jogos[31].jornada = 7;
	jogos[31].golosEquipa1 = 0;
	jogos[31].golosEquipa2 = 0;

	jogos[32].id = 33;
	jogos[32].idEquipa1 = 4;
	jogos[32].idEquipa2 = 10;
	jogos[32].jornada = 7;
	jogos[32].golosEquipa1 = 0;
	jogos[32].golosEquipa2 = 0;

	jogos[33].id = 34;
	jogos[33].idEquipa1 = 8;
	jogos[33].idEquipa2 = 5;
	jogos[33].jornada = 7;
	jogos[33].golosEquipa1 = 0;
	jogos[33].golosEquipa2 = 0;

	jogos[34].id = 35;
	jogos[34].idEquipa1 = 9;
	jogos[34].idEquipa2 = 7;
	jogos[34].jornada = 7;
	jogos[34].golosEquipa1 = 0;
	jogos[34].golosEquipa2 = 0;

	jogos[35].id = 36;
	jogos[35].idEquipa1 = 1;
	jogos[35].idEquipa2 = 7;
	jogos[35].jornada = 8;
	jogos[35].golosEquipa1 = 0;
	jogos[35].golosEquipa2 = 0;

	jogos[36].id = 37;
	jogos[36].idEquipa1 = 2;
	jogos[36].idEquipa2 = 4;
	jogos[36].jornada = 8;
	jogos[36].golosEquipa1 = 0;
	jogos[36].golosEquipa2 = 0;

	jogos[37].id = 38;
	jogos[37].idEquipa1 = 5;
	jogos[37].idEquipa2 = 3;
	jogos[37].jornada = 8;
	jogos[37].golosEquipa1 = 0;
	jogos[37].golosEquipa2 = 0;

	jogos[38].id = 39;
	jogos[38].idEquipa1 = 6;
	jogos[38].idEquipa2 = 9;
	jogos[38].jornada = 8;
	jogos[38].golosEquipa1 = 0;
	jogos[38].golosEquipa2 = 0;

	jogos[39].id = 40;
	jogos[39].idEquipa1 = 10;
	jogos[39].idEquipa2 = 8;
	jogos[39].jornada = 8;
	jogos[39].golosEquipa1 = 0;
	jogos[39].golosEquipa2 = 0;

	jogos[40].id = 41;
	jogos[40].idEquipa1 = 3;
	jogos[40].idEquipa2 = 10;
	jogos[40].jornada = 9;
	jogos[40].golosEquipa1 = 0;
	jogos[40].golosEquipa2 = 0;

	jogos[41].id = 42;
	jogos[41].idEquipa1 = 4;
	jogos[41].idEquipa2 = 1;
	jogos[41].jornada = 9;
	jogos[41].golosEquipa1 = 0;
	jogos[41].golosEquipa2 = 0;

	jogos[42].id = 43;
	jogos[42].idEquipa1 = 7;
	jogos[42].idEquipa2 = 6;
	jogos[42].jornada = 9;
	jogos[42].golosEquipa1 = 0;
	jogos[42].golosEquipa2 = 0;

	jogos[43].id = 44;
	jogos[43].idEquipa1 = 8;
	jogos[43].idEquipa2 = 2;
	jogos[43].jornada = 9;
	jogos[43].golosEquipa1 = 0;
	jogos[43].golosEquipa2 = 0;

	jogos[44].id = 45;
	jogos[44].idEquipa1 = 9;
	jogos[44].idEquipa2 = 5;
	jogos[44].jornada = 9;
	jogos[44].golosEquipa1 = 0;
	jogos[44].golosEquipa2 = 0;

	gravaTodosJogos(jogos, 45);
}	

// esta fun��o mostra o plantel da equipa pretendida
void mostrarPlantel(int idEquipa) 
{
	// esta fun��o obt�m o plantel da equipa e apresenta-o
	mostrarJogadorEquipa(idEquipa);

	// mensagem de como continuar o pograma
	printf("\nPara continuar pressione o ENTER");

	// Aguardar que o utilizador carrege no enter
	while (getchar() != '\n');
}

// esta fun��o apresenta os dados da equipa
void mostrarDadosEquipa(int idEquipa)
{
	// esta fun��o apresenta os dados da equipa
	mostrarEquipa(idEquipa);

	// mensagem de como continuar o pograma
	printf("\nPara continuar pressione o ENTER");

	// Aguardar que o utilizador carrege no enter
	while (getchar() != '\n');
}