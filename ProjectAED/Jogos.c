#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "Jogo.h"
#include "Equipa.h"
#include "Jogador.h"
#include "EstatisticaEquipa.h"

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
		if (jogo.ativo != 0 && (jogo.idEquipa1 == idEquipa || jogo.idEquipa2 == idEquipa) && jogo.jornada == numeroJornada)
		{
			fclose(ficheiro);
			return jogo;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar os jogos
	return jogo;
}

// obter os jogos que tem de ser realizados pelo computador
Jogo* obterJogosAI(int idEquipa, int numeroJornada)
{
	// variaveis
	FILE* ficheiro;
	Jogo jogo;
	static Jogo jogos[4];
	int i;

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

	// inicializar a variavel i a 0 para percorrer o array todo
	i = 0;

	// obter as equipas
	while (fread(&jogo, sizeof(Jogo), 1, ficheiro) == 1)
	{
		if (jogo.ativo != 0 && (jogo.idEquipa1 != idEquipa && jogo.idEquipa2 != idEquipa) && jogo.jornada == numeroJornada)
		{
			jogos[i] = jogo;
			i++;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar os jogos
	return jogos;
}

// mostrar jogos da proxima jornada
void mostrarJornada(int numeroJornada)
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
			printf("%-30s %d vs %d %30s\n", obterEquipaById(jogo.idEquipa1).nome, jogo.golosEquipa1, jogo.golosEquipa2,obterEquipaById(jogo.idEquipa2).nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função mostra o calendario conforme o id da equipa
void mostraCalendarioByEquipa(int idEquipa)
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
	printf("\n\n=============== CALENDARIO ===============\n");

	// obter os dados dos ficheiros
	while (fread(&jogo, sizeof(Jogo), 1, ficheiro) == 1)
	{
		if (jogo.ativo != 0 && (jogo.idEquipa1 == idEquipa || jogo.idEquipa2 == idEquipa))
		{
			printf("%-30s %d vs %d %30s\n", obterEquipaById(jogo.idEquipa1).nome, jogo.golosEquipa1, jogo.golosEquipa2, obterEquipaById(jogo.idEquipa2).nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função, procura o registo do jogo com o id e devolve o indice onde se encontra (dentro do ficheiro);
int getIndiceJogo(int id)
{
	// variaveis
	FILE* ficheiro;
	Jogo jogo;
	int indice = -1, i = -1;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGO, "rb");

	// se não foi possivel abrir o ficheiro (por exemplo: por não existir), mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGO);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// procurar o registo dO jogo, cujo jogo.id == id
	while (fread(&jogo, sizeof(Jogo), 1, ficheiro) == 1)
	{
		// incrementa o contador de registos
		i++;

		// encontrou o nome pretendido e se esse registo estiver ativo - guardar o indice
		if (jogo.id == id && (jogo.ativo != 0))
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

// esta função, altera o numero e o nome do registo com o indice <indice>
void editarJogo(int indice, Jogo jogoAlterado)
{
	// variaveis
	FILE* ficheiro;
	int posicaoFicheiro;

	// tentar abrir ficheiro (r = leitura (+) = permiteLeituraEscrita b = binario)
	ficheiro = fopen(FICHEIRO_JOGO, "r+b");

	// se não foi possivel abrir o ficheiro, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGO);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// a posicao no ficheiro onde guardar a alteração calcula-se com a formula seguinte
	posicaoFicheiro = sizeof(Jogo) * indice;

	// colocar o apontador a apontar para o primeiro Byte respeitante do ficheiro
	// onde está gravado o registo com o indice <indice>
	fseek(ficheiro, posicaoFicheiro, SEEK_SET);

	// agora que o apontador está a apontar para o primeiro Byte do registo, "descarregar"
	// ou "escrever" os Bytes que prefazem a nova versao deste jogo <jogoAlterado>
	fwrite(&jogoAlterado, sizeof(Jogo), 1, ficheiro);

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função simula o resultado do jogo
void simularResultadoJogo(Jogo jogo, Jogador* equipa1, Jogador* equipa2)
{
	// declarar variaveis
	int forcaAtaqueEquipa1 = 0, forcaAtaqueEquipa2 = 0, forcaMediosEquipa1 = 0, forcaMediosEquipa2 = 0, forcaDefesasEquipa1 = 0, forcaDefesasEquipa2 = 0;
	int i, indiceGravar, golosEquipa1 = 0, golosEquipa2 = 0;
	EstatisticaEquipa estatisticaEquipa1, estatisticaEquipa2;

	// obter as estatisticas da equipa
	estatisticaEquipa1 = obterEstatisticaByEquipaId(jogo.idEquipa1);
	estatisticaEquipa2 = obterEstatisticaByEquipaId(jogo.idEquipa2);

	// somar força da equipa
	for (i = 0; i < 11; i++)
	{
		// força de ataque
		forcaAtaqueEquipa1 += equipa1[i].statA;
		forcaAtaqueEquipa2 += equipa2[i].statA;

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
		golosEquipa1 += randGolos(0, 3);
	}
	else if (forcaAtaqueEquipa2 > forcaDefesasEquipa1)
	{
		golosEquipa2 += randGolos(0, 3);
	}
	else
	{
		golosEquipa1 += randGolos(0, 2);
		golosEquipa2 += randGolos(0, 2);
	}

	// verificar quem tem um melhor meio campo
	if (forcaMediosEquipa1 > forcaMediosEquipa2)
	{
		golosEquipa1 += randGolos(0, 1);
	}
	else
	{
		golosEquipa2 += randGolos(0, 1);
	}

	// verificar quais os golos da equipa e as estatisticas
	if (jogo.idEquipa1 == equipa1[0].idEquipa)
	{
		jogo.golosEquipa1 = golosEquipa1;
		jogo.golosEquipa2 = golosEquipa2;
	} 
	else if (jogo.idEquipa1 == equipa2[0].idEquipa)
	{
		jogo.golosEquipa1 = golosEquipa2;
		jogo.golosEquipa2 = golosEquipa1;
	}

	// atuazalizar os golos nas estatisticas
	estatisticaEquipa1.golosMarcados += jogo.golosEquipa1;
	estatisticaEquipa1.golosSofridos += jogo.golosEquipa2;
	estatisticaEquipa2.golosMarcados += jogo.golosEquipa2;
	estatisticaEquipa2.golosSofridos += jogo.golosEquipa1;

	// atualizar os pontos e o numero vitorias derotas e empates
	if (jogo.golosEquipa1 > jogo.golosEquipa2)
	{
		estatisticaEquipa1.numeroVitorias += 1;
		estatisticaEquipa2.numeroDerrotas += 1;
		estatisticaEquipa1.numeroPontos += 3;
	}
	else if (jogo.golosEquipa1 < jogo.golosEquipa2)
	{
		estatisticaEquipa1.numeroDerrotas += 1;
		estatisticaEquipa2.numeroVitorias += 1;
		estatisticaEquipa2.numeroPontos += 3;
	}
	else
	{
		estatisticaEquipa1.numeroEmpates += 1;
		estatisticaEquipa2.numeroEmpates += 1;
		estatisticaEquipa1.numeroPontos += 1;
		estatisticaEquipa2.numeroPontos += 1;
	}

	// gravar no ficheiro as atualizações
	indiceGravar = getIndiceEstatisticaEquipa(estatisticaEquipa1.id);
	editarEstatistica(indiceGravar, estatisticaEquipa1);
	indiceGravar = getIndiceEstatisticaEquipa(estatisticaEquipa2.id);
	editarEstatistica(indiceGravar, estatisticaEquipa2);

	// apresentar o resultado do jogo
	printf("%-30s - %d vs %30s - %d\n", obterEquipaById(jogo.idEquipa1).nome, jogo.golosEquipa1, obterEquipaById(jogo.idEquipa2).nome, jogo.golosEquipa2);

	// atualizar os dados do jogo
	indiceGravar = getIndiceJogo(jogo.id);
	editarJogo(indiceGravar, jogo);
}

// esta funcao simula o jogo
void simularJogo(Jogo jogo, int idEquipa)
{
	// declarar variaveis
	int tatica, i, numeroJogador, idEquipaAdversaria;
	char taticas[4][6] = { "5-3-2", "4-5-1", "4-4-2", "4-3-3" };
	Jogador equipaConvocada1[11], equipaConvocada2[11];

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
	for (i = 0; i < 11; i++)
	{
		equipaConvocada2[i] = simularConvocadosAI(idEquipaAdversaria, equipaConvocada2);
	}

	// simular o resultado
	simularResultadoJogo(jogo, equipaConvocada1, equipaConvocada2);
}
 
// simular os jogos do Utilizador
void simularJogosAI(int idEquipaTreinador, int numeroJornada)
{
	// declarar variaveis
	Jogo* jogos;
	Jogador equipaConvocada1[11], equipaConvocada2[11];
	int i, j = 0;

	// obter os jogos todos menos os do treinador
	jogos = obterJogosAI(idEquipaTreinador, numeroJornada);

	// simular jogos
	for (i = 0; i < 4; i++)
	{
		// simular o plantel das equipas
		for (j = 0; j < 11; j++)
		{
			equipaConvocada1[j] = simularConvocadosAI(jogos[i].idEquipa1, equipaConvocada1);
			equipaConvocada2[j] = simularConvocadosAI(jogos[i].idEquipa2, equipaConvocada2);
		}

		// simular o jogo
		simularResultadoJogo(jogos[i], equipaConvocada1, equipaConvocada2);
	}
}