#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "EstatisticaEquipa.h"
#include "Equipa.h"

// esta fun��o recebe um conjuntos de estatisticas e grava-os na base de dados
void gravaStatEquipasTodas(EstatisticaEquipa* estatisticasEquipas, int n)
{
	// variaveis
	FILE* ficheiro;
	int i;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO_ESTATISTICA_EQUIPA, "w+b");

	// se n�o for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!n�o foi possivel abrir o ficheiro %s!!!", FICHEIRO_ESTATISTICA_EQUIPA);
		return;
	}

	// gravar cada uma das equipas no final do ficheiro
	for (i = 0; i < n; i++)
	{
		// Colocar o apontador no fim do ficheiro
		fseek(ficheiro, 0, SEEK_END);

		// gravar a equipa
		fwrite(&estatisticasEquipas[i], sizeof(EstatisticaEquipa), 1, ficheiro);
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta fun��o mostra a classifica��o dasEquipas
void mostrarClassificacao(void)
{
	// variaveis
	FILE* ficheiro;
	EstatisticaEquipa auxiliar, estatisticasEquipas[10], estatisticaEquipa;
	int i, j, numeroElementos = 10;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_ESTATISTICA_EQUIPA, "rb");

	// se n�o for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!n�o foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_ESTATISTICA_EQUIPA);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// inicializar a variavel i
	i = 0;

	// obter os dados dos ficheiros
	while (fread(&estatisticaEquipa, sizeof(EstatisticaEquipa), 1, ficheiro) == 1)
	{
		if (estatisticaEquipa.ativo != 0)
		{
			estatisticasEquipas[i] = estatisticaEquipa;
			i++;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// precorrer o array desde a primeira posi��o at� � penultima
	for (i = 0; i < (numeroElementos - 1); i++)
	{
		// para cada elemento do iterador principal,
		// percorrer o array desde a posi��o seguinte at� ao fim do array
		for (j = i + 1; j < numeroElementos; j++)
		{
			// verificar se a posi��o no iterador principal � maior que a do seguinte iterador
			if (estatisticasEquipas[i].numeroPontos < estatisticasEquipas[j].numeroPontos)
			{
				// se o valor do iterador principal for maior, troca os respetivos
				auxiliar = estatisticasEquipas[j];
				estatisticasEquipas[j] = estatisticasEquipas[i];
				estatisticasEquipas[i] = auxiliar;
			}
		}
	}

	// inicio da listagem
	printf("\n\n=== Classificacao ======\n");
	printf("Posicao\tEquipa\t\t\t\tGM GS DF  V  E  D Pontos\n");

	// apresentar a classifica��o
	for (i = 0; i < numeroElementos; i++)
	{
		printf("%2d - \t%-30s\t%2d %2d %2d %2d %2d %2d    %2d\n", i + 1, obterEquipaById(estatisticasEquipas[i].idEquipa).nome, estatisticasEquipas[i].golosMarcados, estatisticasEquipas[i].golosSofridos, estatisticasEquipas[i].golosMarcados - estatisticasEquipas[i].golosSofridos, estatisticasEquipas[i].numeroVitorias, estatisticasEquipas[i].numeroEmpates, estatisticasEquipas[i].numeroDerrotas, estatisticasEquipas[i].numeroPontos);
	}
}