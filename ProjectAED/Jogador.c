#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "Jogador.h"

// esta função recebe um e grava-o na base de dados
void gravaTodosJogadores(Jogador* jogadores, int n)
{
	// variaveis
	FILE* ficheiro;
	int i;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO, "w+b");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!", FICHEIRO);
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

void mostraTodosJogadores(void)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;

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

	// inicio da listagem
	printf("\n\n=== Jogadores ======\n");
	printf("%s\t%s\n", "ID", "NOME");

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0 && jogador.idEquipa == 6)
		{
			printf("%06d\t%-20s\n", jogador.id, jogador.nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// fim da listagem
	printf("=== fim ======\n");
}