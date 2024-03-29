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

	// orderar o array por pontos
	for (i = 0; i < (numeroElementos - 1); i++)
	{
		for (j = i + 1; j < numeroElementos; j++)
		{
			if (estatisticasEquipas[i].numeroPontos < estatisticasEquipas[j].numeroPontos)
			{
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

// esta fun��o, procura o registo da estatistica da equipa com o idEquipa e devolve o indice onde se encontra (dentro do ficheiro);
int getIndiceEstatisticaEquipa(int id)
{
	// variaveis
	FILE* ficheiro;
	EstatisticaEquipa estatisticaEquipa;
	int indice = -1, i = -1;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_ESTATISTICA_EQUIPA, "rb");

	// se n�o foi possivel abrir o ficheiro (por exemplo: por n�o existir), mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!n�o foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_ESTATISTICA_EQUIPA);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// procurar o registo da estatistica, cujo estatistica.idEquipa == id
	while (fread(&estatisticaEquipa, sizeof(EstatisticaEquipa), 1, ficheiro) == 1)
	{
		// incrementa o contador de registos
		i++;

		// encontrou o pretendido e se esse registo estiver ativo - guardar o indice
		if (estatisticaEquipa.idEquipa == id && (estatisticaEquipa.ativo != 0))
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

// esta fun��o, altera a estatistica com o indice <indice>
void editarEstatistica(int indice, EstatisticaEquipa estatisticaEquipaAlterada)
{
	// variaveis
	FILE* ficheiro;
	int posicaoFicheiro;

	// tentar abrir ficheiro (r = leitura (+) = permiteLeituraEscrita b = binario)
	ficheiro = fopen(FICHEIRO_ESTATISTICA_EQUIPA, "r+b");

	// se n�o foi possivel abrir o ficheiro, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!n�o foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_ESTATISTICA_EQUIPA);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// a posicao no ficheiro onde guardar a altera��o calcula-se com a formula seguinte
	posicaoFicheiro = sizeof(EstatisticaEquipa) * indice;

	// colocar o apontador a apontar para o primeiro Byte respeitante do ficheiro
	// onde est� gravado o registo com o indice <indice>
	fseek(ficheiro, posicaoFicheiro, SEEK_SET);

	// agora que o apontador est� a apontar para o primeiro Byte do registo, "descarregar"
	// ou "escrever" os Bytes que prefazem a nova versao deste jogo <jogoAlterado>
	fwrite(&estatisticaEquipaAlterada, sizeof(EstatisticaEquipa), 1, ficheiro);

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta fun��o retorna a estatistica da equipa
EstatisticaEquipa obterEstatisticaByEquipaId(int idEquipa) 
{
	// variaveis
	FILE* ficheiro;
	EstatisticaEquipa estatisticaEquipa;

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

	// obter as equipas
	while (fread(&estatisticaEquipa, sizeof(EstatisticaEquipa), 1, ficheiro) == 1)
	{
		if (estatisticaEquipa.idEquipa == idEquipa && estatisticaEquipa.ativo != 0)
		{
			fclose(ficheiro);
			return estatisticaEquipa;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar a equipa
	return estatisticaEquipa;
}