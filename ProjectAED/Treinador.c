#define _CRT_SECURE_NO_WARNINGS
#include "Treinador.h"

// esta função regista o treinador
void registarTreinador(Treinador treinador)
{
	// variaveis
	FILE* ficheiro;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO, "w+b");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!", FICHEIRO);
		return;
	}

	// Colocar o apontador no fim do ficheiro
	fseek(ficheiro, 0, SEEK_END);

	// gravar a equipa
	fwrite(&treinador, sizeof(Treinador), 1, ficheiro);

	// fechar o ficheiro
	fclose(ficheiro);
}