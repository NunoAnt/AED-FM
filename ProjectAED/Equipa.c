#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "Equipa.h"

// Esta função apresenta todas as equipas ativas
void mostraEquipasAtivas(void)
{
	// variaveis
	FILE* ficheiro;
	Equipa equipa;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter os dados dos ficheiros
	while (fread(&equipa, sizeof(Equipa), 1, ficheiro) == 1) 
	{
		if (equipa.ativo != 0)
		{
			printf("%02d\t%-20s\n", equipa.id, equipa.nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);
}


// esta função recebe um conjuntos de equipas e grava-o na base de dados
void gravaTodasEquipas(Equipa* equipas, int n)
{
	// variaveis
	FILE* ficheiro;
	int i;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO, "w+b");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!");
		return;
	}

	// gravar cada uma das equipas no final do ficheiro
	for (i = 0; i < n; i++)
	{
		// Colocar o apontador no fim do ficheiro
		fseek(ficheiro, 0, SEEK_END);

		// gravar a equipa
		fwrite(&equipas[i], sizeof(Equipa), 1, ficheiro);
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função retorna uma equipa com o mesmo nome
Equipa obterEquipa(char* nome)
{
	// variaveis
	FILE* ficheiro;
	Equipa equipa;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter as equipas
	while (fread(&equipa, sizeof(Equipa), 1, ficheiro) == 1)
	{
		if (strstr(equipa.nome, nome) != NULL && equipa.ativo != 0)
		{
			fclose(ficheiro);
			return equipa;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar a equipa
	return equipa;
}