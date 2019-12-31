#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "Jogo.h"


// esta fun��o recebe um conjuntos de jogos e grava-os na base de dados
void gravaTodosJogos(Jogo* jogos, int n)
{
	// variaveis
	FILE* ficheiro;
	int i;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO_JOGO, "w+b");

	// se n�o for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!n�o foi possivel abrir o ficheiro %s!!!", FICHEIRO_JOGO);
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
