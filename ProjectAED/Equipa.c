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
	ficheiro = fopen(FICHEIRO_EQUIPA, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_EQUIPA);
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
	ficheiro = fopen(FICHEIRO_EQUIPA, "w+b");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!", FICHEIRO_EQUIPA);
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
	ficheiro = fopen(FICHEIRO_EQUIPA, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_EQUIPA);
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

// esta função retorna uma equipa com o mesmo id
Equipa obterEquipaById(int id)
{
	// variaveis
	FILE* ficheiro;
	Equipa equipa;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_EQUIPA, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_EQUIPA);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter as equipas
	while (fread(&equipa, sizeof(Equipa), 1, ficheiro) == 1)
	{
		if (equipa.id == id && equipa.ativo != 0)
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

// mostra os dados atuais da equipa
void mostrarEquipa(int id)
{
	// variaveis
	FILE* ficheiro;
	Equipa equipa;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_EQUIPA, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_EQUIPA);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// inicio da listagem
	printf("\n\n=== DADOS DO CLUBE ======\n");

	// obter as equipas
	while (fread(&equipa, sizeof(Equipa), 1, ficheiro) == 1)
	{
		if (equipa.id == id && equipa.ativo != 0)
		{
			printf("Equipa: %-30s\nEstadio: %-40s\nNumero de Lugares: %d\nFundos do Clube: %.2f\nDespesas Mensais: %.2f\n\n\n", equipa.nome, equipa.nomeEstadio, equipa.numeroLugaresEstadio, equipa.fundosClube, equipa.despesasMensais);
			printf("VIVA AO %s\n", equipa.nome);

			// fechar o ficheiro
			fclose(ficheiro);

			return;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função retorna o indice onde se encontra a equipa no ficheiro
int getIndiceEquipa(int id)
{
	// variaveis
	FILE* ficheiro;
	Equipa equipa;
	int indice = -1, i = -1;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_EQUIPA, "rb");

	// se não foi possivel abrir o ficheiro (por exemplo: por não existir), mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_EQUIPA);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// procurar o registo da equipa, cujo equipa.id == id
	while (fread(&equipa, sizeof(Equipa), 1, ficheiro) == 1)
	{
		// incrementa o contador de registos
		i++;

		// encontrou a equipa pretendida e se esse registo estiver ativo - guardar o indice
		if (equipa.id == id && (equipa.ativo != 0))
		{
			indice = i;
			return;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// devolver indice
	return indice;
}

// esta função altera os dados da equipa com o indice
void editarEquipa(int indice, Equipa equipaAlterada)
{
	// variaveis
	FILE* ficheiro;
	int posicaoFicheiro;

	// tentar abrir ficheiro (r = leitura (+) = permiteLeituraEscrita b = binario)
	ficheiro = fopen(FICHEIRO_EQUIPA, "r+b");

	// se não foi possivel abrir o ficheiro, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_EQUIPA);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// a posicao no ficheiro onde guardar a alteração calcula-se com a formula seguinte
	posicaoFicheiro = sizeof(Equipa) * indice;

	// colocar o apontador a apontar para o primeiro Byte respeitante do ficheiro
	// onde está gravado o registo com o indice
	fseek(ficheiro, posicaoFicheiro, SEEK_SET);

	// escreve sobre o novo jogador sobre o antigo
	fwrite(&equipaAlterada, sizeof(Equipa), 1, ficheiro);

	// fechar o ficheiro
	fclose(ficheiro);
}