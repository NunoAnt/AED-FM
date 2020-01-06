#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define _CRT_SECURE_NO_WARNINGS
#include "Jogador.h"
#include "Equipa.h"

// esta função gera um numero aliatorio entre o seguinte espaço
int rand_in_range(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

// esta função recebe um e grava-o na base de dados
void gravaTodosJogadores(Jogador* jogadores, int n)
{
	// variaveis
	FILE* ficheiro;
	int i;

	// tentar abrir ficheiro (w = escrever b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "w+b");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!", FICHEIRO_JOGADOR);
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

// esta função, procura o registo do jogo com o id e devolve o indice onde se encontra (dentro do ficheiro);
int getIndiceJogador(int id)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;
	int indice = -1, i = -1;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não foi possivel abrir o ficheiro (por exemplo: por não existir), mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// procurar o registo do jogador, cujo jogador.id == id
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		// incrementa o contador de registos
		i++;

		// encontrou o jogador pretendido e se esse registo estiver ativo - guardar o indice
		if (jogador.id == id && (jogador.ativo != 0))
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

// esta função altera o jogador no ficheiro com o indice
void editarJogador(int indice, Jogador jogadorAlterado)
{
	// variaveis
	FILE* ficheiro;
	int posicaoFicheiro;

	// tentar abrir ficheiro (r = leitura (+) = permiteLeituraEscrita b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "r+b");

	// se não foi possivel abrir o ficheiro, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);

	// a posicao no ficheiro onde guardar a alteração calcula-se com a formula seguinte
	posicaoFicheiro = sizeof(Jogador) * indice;

	// colocar o apontador a apontar para o primeiro Byte respeitante do ficheiro
	// onde está gravado o registo com o indice
	fseek(ficheiro, posicaoFicheiro, SEEK_SET);

	// escreve sobre o novo jogador sobre o antigo
	fwrite(&jogadorAlterado, sizeof(Jogador), 1, ficheiro);

	// fechar o ficheiro
	fclose(ficheiro);
}

// mostrar todos os jogadores
void mostraTodosJogadores(void)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
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
		if (jogador.ativo != 0)
		{
			printf("%06d\t%-20s\n", jogador.id, jogador.nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// fim da listagem
	printf("=== fim ======\n");
}

// mostrar jogadores por Nome
void mostraJogadoresByName(char* nome)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
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
		if (jogador.ativo != 0 && strstr(jogador.nome, nome))
		{
			printf("%06d\t%-20s\n", jogador.id, jogador.nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// fim da listagem
	printf("=== fim ======\n");
}

// mostrar jogadores por equipa
void mostraJogadoresByEquipa(int idEquipa)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
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
		if (jogador.ativo != 0 && jogador.idEquipa == idEquipa)
		{
			printf("%06d\t%-20s\n", jogador.id, jogador.nome);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// fim da listagem
	printf("=== fim ======\n");
}

// Esta função lista os jogadores por id da Equipa
void mostrarJogadorEquipa(int idEquipa)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	
	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0 && jogador.idEquipa == idEquipa)
		{
			printf("Nome: %-20s\tNumero: %2d\tPosicao: %10s\tStat Gr: %3d\tStat Defesa: %3d\tStat Medio: %3d\tStat Avancado: %3d\tContrato: %02d/%02d/%4d\n", jogador.nome, jogador.numero, jogador.posicao, jogador.statGr, jogador.statD, jogador.statM, jogador.statA, jogador.dia, jogador.mes, jogador.anoContrato);
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função retorna um jogador da equipa convocada pelo treinador
Jogador obterJogadorEquipa(int idEquipa, int numeroJogador)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;
	int i = 0, j;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0 && jogador.idEquipa == idEquipa && jogador.numero == numeroJogador)
		{
			fclose(ficheiro);
			return jogador;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar jogador
	return jogador;
}

// esta função retorna um jogador conforme o ID
Jogador obterJogadorByID(int idJogador)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;
	int i = 0, j;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1)
	{
		if (jogador.ativo != 0 && jogador.id == idJogador)
		{
			fclose(ficheiro);
			return jogador;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar jogador
	return jogador;
}

// Esta função simula um plantel de uma equipa
Jogador simularConvocadosAI(int idEquipa, Jogador* jogadoresConvocados)
{
	// variaveis
	FILE* ficheiro;
	Jogador jogador;
	Jogador plantelEquipa[20];
	int i = 0, j, jogadorEncontrado;

	// tentar abrir ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO_JOGADOR, "rb");

	// se não for possivel abrir o ficherio, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO_JOGADOR);
		return;
	}

	// posicionar no inicio do ficheiro
	rewind(ficheiro);  //fseek(ficheiro, 0, SEEK_SET);

	// obter os dados dos ficheiros
	while (fread(&jogador, sizeof(Jogador), 1, ficheiro) == 1 && i != 11)
	{
		if (jogador.ativo != 0 && jogador.idEquipa == idEquipa)
		{
			plantelEquipa[i] = jogador;
			i++;
		}
	}

	// incializar variavel
	jogadorEncontrado = FALSE;

	// procurar equanto não encontrar um jogador
	while (jogadorEncontrado == FALSE)
	{
		// obter um jogador do plantel de forma aletoria
		jogador = plantelEquipa[rand_in_range(0, 19)];

		if (jogadorConvocadoExits(jogadoresConvocados, jogador) == FALSE)
		{
			jogadorEncontrado = TRUE;
		}
	}

	// fechar o ficheiro
	fclose(ficheiro);

	// retornar plantel
	return jogador;
}

// verificar se o jogador já está convocado
int jogadorConvocadoExits(Jogador* jogadores, Jogador jogador)
{
	// declarar variaveis
	int i, existe = FALSE;

	// verificar se já existe
	for (i = 0; i < 11 && existe == FALSE; i++)
	{
		if (jogador.id == jogadores[i].id)
		{
			existe = TRUE;
		}
	}

	return existe;
}

// esta função realiza a transferencias de jogadores
void realizarTransferencia(int idEquipaTreinador)
{
	// declarar variaveis
	int idJogadorPretendeTransferir, idJogadorOfercer, mesesFinalContrato, anoAtual, mesAtual, indiceGravar;
	char nome[30];
	Equipa equipaTreinador, equipaTransferencia;
	Jogador jogadorTransferir, jogadorOfercer;
	float valorJogador;

	// recolher nome
	printf("Insira o Nome do Jogador: ");
	gets(nome);

	// apresentar jogadores pelo nome pretendido
	mostraJogadoresByName(nome);

	// recolher o ID do jogador que pretende obter
	printf("Insira o ID do jogador que pretende obter (nao incluir os 0): ");
	scanf("%d", &idJogadorPretendeTransferir);
	while (getchar() != '\n');

	// apresentares os jogador da equipa
	mostraJogadoresByEquipa(idEquipaTreinador);

	// recolher o ID do jogador que pretende ofercer
	printf("Insira o ID do jogador que pretende ofercer (nao incluir os 0): ");
	scanf("%d", &idJogadorOfercer);
	while (getchar() != '\n');

	// obter os jogadores
	jogadorTransferir = obterJogadorByID(idJogadorPretendeTransferir);
	jogadorOfercer = obterJogadorByID(idJogadorOfercer);

	// obter as equipas
	equipaTreinador = obterEquipaById(idEquipaTreinador);
	equipaTransferencia = obterEquipaById(jogadorTransferir.idEquipa);

	// obter a data atual
	time_t s, val = 1;
	struct tm* current_time;
	s = time(NULL);
	current_time = localtime(&s);
	anoAtual = (current_time->tm_year + 1900);
	mesAtual = (current_time->tm_mon + 1);

	// calcular os meses ate ao final de contrato
	mesesFinalContrato = ((jogadorTransferir.anoContrato - anoAtual) * 12) + jogadorTransferir.mes - mesAtual;

	// calcular o valor do jogador
	valorJogador = jogadorTransferir.vencimentoMensal * 5 * mesesFinalContrato;

	// verificar se a equipa possui fundos para a transferencia, se não tiver sai
	if (equipaTreinador.fundosClube < valorJogador)
	{
		printf("A equipa nao possui fundos suficientes para a transferencia");
		return;
	} 
	else
	{
		// atualizar os valores ao jogador
		jogadorTransferir.anoContrato = anoAtual + 3;
		jogadorTransferir.idEquipa = equipaTreinador.id;
		jogadorTransferir.preco = valorJogador;

		// atualizar os valores ao jogador oferecido
		jogadorOfercer.anoContrato = anoAtual + 3;
		jogadorOfercer.idEquipa = equipaTransferencia.id;

		// atuailizar os fundos dos clubes
		equipaTreinador.fundosClube = equipaTreinador.fundosClube - valorJogador;
		equipaTransferencia.fundosClube = equipaTransferencia.fundosClube + valorJogador;

		// gravar as alterações do jogadores
		indiceGravar = getIndiceJogador(jogadorTransferir.id);
		editarJogador(indiceGravar, jogadorTransferir);
		indiceGravar = getIndiceJogador(jogadorOfercer.id);
		editarJogador(indiceGravar, jogadorOfercer);

		// gravar as alterações das equipas
		indiceGravar = getIndiceEquipa(equipaTransferencia.id);
		editarEquipa(indiceGravar, equipaTransferencia);
		indiceGravar = getIndiceEquipa(equipaTreinador.id);
		editarEquipa(indiceGravar, equipaTreinador);
	}
}