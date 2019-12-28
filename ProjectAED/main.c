#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include <string.h>
#include "Equipa.h"
#include "Jogador.h"
#include "Treinador.h"

void recolherDadosTreinador();

int main(void)
{
	// Mensagem inicial
	printf("==============================\n");
	printf("            AED FM              \n");
	printf("==============================\n\n");

	recolherDadosTreinador();

	return 0;
}

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