#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include <string.h>
#include "Equipa.h"
#include "Jogador.h"

void adicionarJogadores();

int main(void)
{
	mostraEquipasAtivas();	

	adicionarJogadores();

	mostraTodosJogadores();

	return 0;
}

void adicionarEquipas()
{
	Equipa equipas[18];

	equipas[0].id = 1;
	strcpy(equipas[0].nome, "Sport Lisboa e Benfica");
	strcpy(equipas[0].nomeEstadio, "Estadio da Luz");
	equipas[0].numeroLugaresEstadio = 60000;
	equipas[0].fundosClube = 178000.00f;
	equipas[0].despesasMensais = 1000.00f;
	equipas[0].ativo = 1;

	equipas[1].id = 2;
	strcpy(equipas[1].nome, "Futebol Clube do Porto");
	strcpy(equipas[1].nomeEstadio, "Estadio do Dragao");
	equipas[1].numeroLugaresEstadio = 50033;
	equipas[1].fundosClube = 178000.00f;
	equipas[1].despesasMensais = 1000.00f;
	equipas[1].ativo = 1;

	equipas[2].id = 3;
	strcpy(equipas[2].nome, "Sporting Clube de Portugal");
	strcpy(equipas[2].nomeEstadio, "Estadio José Alvalade");
	equipas[2].numeroLugaresEstadio = 50095;
	equipas[2].fundosClube = 178000.00f;
	equipas[2].despesasMensais = 1000.00f;
	equipas[2].ativo = 1;

	equipas[3].id = 4;
	strcpy(equipas[3].nome, "Futebol Clube de Famalicao");
	strcpy(equipas[3].nomeEstadio, "Estadio Municipal 22 de Junho");
	equipas[3].numeroLugaresEstadio = 5307;
	equipas[3].fundosClube = 178000.00f;
	equipas[3].despesasMensais = 1000.00f;
	equipas[3].ativo = 1;

	equipas[4].id = 5;
	strcpy(equipas[4].nome, "Vitoria Sport Clube");
	strcpy(equipas[4].nomeEstadio, "Estadio D. Afonso Henriques");
	equipas[4].numeroLugaresEstadio = 30146;
	equipas[4].fundosClube = 178000.00f;
	equipas[4].despesasMensais = 1000.00f;
	equipas[4].ativo = 1;

	equipas[5].id = 6;
	strcpy(equipas[5].nome, "Rio Ave");
	strcpy(equipas[5].nomeEstadio, "Estadio dos Arcos");
	equipas[5].numeroLugaresEstadio = 12815;
	equipas[5].fundosClube = 178000.00f;
	equipas[5].despesasMensais = 1000.00f;
	equipas[5].ativo = 1;

	equipas[6].id = 7;
	strcpy(equipas[6].nome, "Vitoria Futebol Clube");
	strcpy(equipas[6].nomeEstadio, "Estadio do Bonfim");
	equipas[6].numeroLugaresEstadio = 15497;
	equipas[6].fundosClube = 178000.00f;
	equipas[6].despesasMensais = 1000.00f;
	equipas[6].ativo = 1;

	equipas[7].id = 8;
	strcpy(equipas[7].nome, "Sporting Clube de Braga");
	strcpy(equipas[7].nomeEstadio, "Estadio Municipal de Braga");
	equipas[7].numeroLugaresEstadio = 30000;
	equipas[7].fundosClube = 178000.00f;
	equipas[7].despesasMensais = 1000.00f;
	equipas[7].ativo = 1;

	equipas[8].id = 9;
	strcpy(equipas[8].nome, "Boavista Futebol Clube");
	strcpy(equipas[8].nomeEstadio, "Estadio do Bessa Sec XXI");
	equipas[8].numeroLugaresEstadio = 28263;
	equipas[8].fundosClube = 178000.00f;
	equipas[8].despesasMensais = 1000.00f;
	equipas[8].ativo = 1;

	equipas[9].id = 10;
	strcpy(equipas[9].nome, "Clube Desportivo de Tondela");
	strcpy(equipas[9].nomeEstadio, "Estadio João Cardoso");
	equipas[9].numeroLugaresEstadio = 5000;
	equipas[9].fundosClube = 178000.00f;
	equipas[9].despesasMensais = 1000.00f;
	equipas[9].ativo = 1;

	equipas[10].id = 11;
	strcpy(equipas[10].nome, "Moreirense Futebol Clube");
	strcpy(equipas[10].nomeEstadio, "Estadio Comendador Joaquim de Almeida");
	equipas[10].numeroLugaresEstadio = 6100;
	equipas[10].fundosClube = 178000.00f;
	equipas[10].despesasMensais = 1000.00f;
	equipas[10].ativo = 1;

	equipas[11].id = 12;
	strcpy(equipas[11].nome, "Gil Vicente Futebol Clube");
	strcpy(equipas[11].nomeEstadio, "Estadio Cidade de Barcelos");
	equipas[11].numeroLugaresEstadio = 12504;
	equipas[11].fundosClube = 178000.00f;
	equipas[11].despesasMensais = 1000.00f;
	equipas[11].ativo = 1;

	equipas[12].id = 13;
	strcpy(equipas[12].nome, "Club Sport Maritimo");
	strcpy(equipas[12].nomeEstadio, "Estadio do Maritimo");
	equipas[12].numeroLugaresEstadio = 10932;
	equipas[12].fundosClube = 178000.00f;
	equipas[12].despesasMensais = 1000.00f;
	equipas[12].ativo = 1;

	equipas[13].id = 14;
	strcpy(equipas[13].nome, "Belenenses SAD");
	strcpy(equipas[13].nomeEstadio, "Estadio Nacional do Jamor");
	equipas[13].numeroLugaresEstadio = 37593;
	equipas[13].fundosClube = 178000.00f;
	equipas[13].despesasMensais = 1000.00f;
	equipas[13].ativo = 1;

	equipas[14].id = 15;
	strcpy(equipas[14].nome, "Clube Desportivo Santa Clara");
	strcpy(equipas[14].nomeEstadio, "Estadio de Sao Miguel");
	equipas[14].numeroLugaresEstadio = 13277;
	equipas[14].fundosClube = 178000.00f;
	equipas[14].despesasMensais = 1000.00f;
	equipas[14].ativo = 1;

	equipas[15].id = 16;
	strcpy(equipas[15].nome, "Portimonense Sporting Clube");
	strcpy(equipas[15].nomeEstadio, "Estadio Municipal de Portimao");
	equipas[15].numeroLugaresEstadio = 9544;
	equipas[15].fundosClube = 178000.00f;
	equipas[15].despesasMensais = 1000.00f;
	equipas[15].ativo = 1;

	equipas[16].id = 17;
	strcpy(equipas[16].nome, "Clube Desportivo das Aves");
	strcpy(equipas[16].nomeEstadio, "Estadio do Clube Desportivo das Aves");
	equipas[16].numeroLugaresEstadio = 8560;
	equipas[16].fundosClube = 178000.00f;
	equipas[16].despesasMensais = 1000.00f;
	equipas[16].ativo = 1;

	equipas[17].id = 18;
	strcpy(equipas[17].nome, "Pacos de Ferreira");
	strcpy(equipas[17].nomeEstadio, "Estadio da Capital do Movel");
	equipas[17].numeroLugaresEstadio = 9077;
	equipas[17].fundosClube = 178000.00f;
	equipas[17].despesasMensais = 1000.00f;
	equipas[17].ativo = 1;

	gravaTodasEquipas(equipas, 18);

}

void adicionarJogadores()
{
	Jogador jogadores[42];

	jogadores[0].id = 1;
	jogadores[0].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[0].nome, "Odisseas Vlachodimos");
	jogadores[0].numero = 99;
	jogadores[0].vencimentoMensal = 800.55f;
	jogadores[0].dia = 30;
	jogadores[0].mes = 06;
	jogadores[0].anoContrato = 2024;
	strcpy(jogadores[0].posicao, "GR");
	jogadores[0].statGr = 80;
	jogadores[0].statD = 10;
	jogadores[0].statM = 10;
	jogadores[0].statA = 5;
	jogadores[0].preco = 10000000.00f;
	jogadores[0].ativo = 1;

	jogadores[1].id = 2;
	jogadores[1].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[1].nome, "Ivan Zlobin");
	jogadores[1].numero = 72;
	jogadores[1].vencimentoMensal = 250.55f;
	jogadores[1].dia = 30;
	jogadores[1].mes = 06;
	jogadores[1].anoContrato = 2024;
	strcpy(jogadores[1].posicao, "GR");
	jogadores[1].statGr = 70;
	jogadores[1].statD = 10;
	jogadores[1].statM = 10;
	jogadores[1].statA = 10;
	jogadores[1].preco = 1500.00f;
	jogadores[1].ativo = 1;

	jogadores[2].id = 3;
	jogadores[2].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[2].nome, "German Conti");
	jogadores[2].numero = 2;
	jogadores[2].vencimentoMensal = 600.00f;
	jogadores[2].dia = 30;
	jogadores[2].mes = 06;
	jogadores[2].anoContrato = 2023;
	strcpy(jogadores[2].posicao, "Defesa");
	jogadores[2].statGr = 10;
	jogadores[2].statD = 74;
	jogadores[2].statM = 52;
	jogadores[2].statA = 49;
	jogadores[2].preco = 2500000.00f;
	jogadores[2].ativo = 1;

	jogadores[3].id = 4;
	jogadores[3].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[3].nome, "Alejandro Grimaldo");
	jogadores[3].numero = 3;
	jogadores[3].vencimentoMensal = 83000.55f;
	jogadores[3].dia = 30;
	jogadores[3].mes = 06;
	jogadores[3].anoContrato = 2023;
	strcpy(jogadores[3].posicao, "Defesa");
	jogadores[3].statGr = 10;
	jogadores[3].statD = 81;
	jogadores[3].statM = 78;
	jogadores[3].statA = 72;
	jogadores[3].preco = 32000000.00f;
	jogadores[3].ativo = 1;

	jogadores[4].id = 5;
	jogadores[4].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[4].nome, "Ruben Dias");
	jogadores[4].numero = 6;
	jogadores[4].vencimentoMensal = 900.55f;
	jogadores[4].dia = 30;
	jogadores[4].mes = 06;
	jogadores[4].anoContrato = 2024;
	strcpy(jogadores[4].posicao, "Defesa");
	jogadores[4].statGr = 10;
	jogadores[4].statD = 80;
	jogadores[4].statM = 53;
	jogadores[4].statA = 42;
	jogadores[4].preco = 32000000.00f;
	jogadores[4].ativo = 1;

	jogadores[5].id = 6;
	jogadores[5].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[5].nome, "Jardel");
	jogadores[5].numero = 33;
	jogadores[5].vencimentoMensal = 850.55f;
	jogadores[5].dia = 30;
	jogadores[5].mes = 06;
	jogadores[5].anoContrato = 2020;
	strcpy(jogadores[5].posicao, "Defesa");
	jogadores[5].statGr = 10;
	jogadores[5].statD = 80;
	jogadores[5].statM = 58;
	jogadores[5].statA = 22;
	jogadores[5].preco = 200000.00f;
	jogadores[5].ativo = 1;

	jogadores[6].id = 7;
	jogadores[6].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[6].nome, "Ferro");
	jogadores[6].numero = 97;
	jogadores[6].vencimentoMensal = 850.55f;
	jogadores[6].dia = 30;
	jogadores[6].mes = 06;
	jogadores[6].anoContrato = 2023;
	strcpy(jogadores[6].posicao, "Defesa");
	jogadores[6].statGr = 10;
	jogadores[6].statD = 77;
	jogadores[6].statM = 59;
	jogadores[6].statA = 49;
	jogadores[6].preco = 1500000.00f;
	jogadores[6].ativo = 1;

	jogadores[7].id = 8;
	jogadores[7].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[7].nome, "Florentino");
	jogadores[7].numero = 61;
	jogadores[7].vencimentoMensal = 450.55f;
	jogadores[7].dia = 30;
	jogadores[7].mes = 06;
	jogadores[7].anoContrato = 2024;
	strcpy(jogadores[7].posicao, "Medio");
	jogadores[7].statGr = 10;
	jogadores[7].statD = 45;
	jogadores[7].statM = 77;
	jogadores[7].statA = 63;
	jogadores[7].preco = 15000000.00f;
	jogadores[7].ativo = 1;

	jogadores[8].id = 9;
	jogadores[8].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[8].nome, "Andreas Samaris");
	jogadores[8].numero = 22;
	jogadores[8].vencimentoMensal = 750.55f;
	jogadores[8].dia = 30;
	jogadores[8].mes = 06;
	jogadores[8].anoContrato = 2023;
	strcpy(jogadores[8].posicao, "Medio");
	jogadores[8].statGr = 10;
	jogadores[8].statD = 60;
	jogadores[8].statM = 79;
	jogadores[8].statA = 67;
	jogadores[8].preco = 9000000.00f;
	jogadores[8].ativo = 1;

	jogadores[9].id = 10;
	jogadores[9].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[9].nome, "Gabriel");
	jogadores[9].numero = 8;
	jogadores[9].vencimentoMensal = 1100.55f;
	jogadores[9].dia = 30;
	jogadores[9].mes = 06;
	jogadores[9].anoContrato = 2024;
	strcpy(jogadores[9].posicao, "Medio");
	jogadores[9].statGr = 5;
	jogadores[9].statD = 77;
	jogadores[9].statM = 80;
	jogadores[9].statA = 75;
	jogadores[9].preco = 13000000.00f;
	jogadores[9].ativo = 1;

	jogadores[10].id = 11;
	jogadores[10].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[10].nome, "Adel Taarabt");
	jogadores[10].numero = 49;
	jogadores[10].vencimentoMensal = 500.55f;
	jogadores[10].dia = 30;
	jogadores[10].mes = 06;
	jogadores[10].anoContrato = 2022;
	strcpy(jogadores[10].posicao, "Medio");
	jogadores[10].statGr = 5;
	jogadores[10].statD = 48;
	jogadores[10].statM = 74;
	jogadores[10].statA = 69;
	jogadores[10].preco = 3000000.00f;
	jogadores[10].ativo = 1;

	jogadores[11].id = 12;
	jogadores[11].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[11].nome, "Pizzi");
	jogadores[11].numero = 21;
	jogadores[11].vencimentoMensal = 10000.55f;
	jogadores[11].dia = 30;
	jogadores[11].mes = 06;
	jogadores[11].anoContrato = 2023;
	strcpy(jogadores[11].posicao, "Medio");
	jogadores[11].statGr = 5;
	jogadores[11].statD = 65;
	jogadores[11].statM = 83;
	jogadores[11].statA = 83;
	jogadores[11].preco = 25000000.00f;
	jogadores[11].ativo = 1;

	jogadores[12].id = 13;
	jogadores[12].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[12].nome, "Franco Cervi");
	jogadores[12].numero = 11;
	jogadores[12].vencimentoMensal = 800.55f;
	jogadores[12].dia = 30;
	jogadores[12].mes = 06;
	jogadores[12].anoContrato = 2023;
	strcpy(jogadores[12].posicao, "Medio");
	jogadores[12].statGr = 5;
	jogadores[12].statD = 55;
	jogadores[12].statM = 74;
	jogadores[12].statA = 77;
	jogadores[12].preco = 10000000.00f;
	jogadores[12].ativo = 1;

	jogadores[13].id = 14;
	jogadores[13].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[13].nome, "Chiquinho");
	jogadores[13].numero = 19;
	jogadores[13].vencimentoMensal = 600.00f;
	jogadores[13].dia = 30;
	jogadores[13].mes = 06;
	jogadores[13].anoContrato = 2024;
	strcpy(jogadores[13].posicao, "Avancado");
	jogadores[13].statGr = 5;
	jogadores[13].statD = 56;
	jogadores[13].statM = 75;
	jogadores[13].statA = 77;
	jogadores[13].preco = 6000000.00f;
	jogadores[13].ativo = 1;

	jogadores[14].id = 15;
	jogadores[14].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[14].nome, "Raul de Tomas");
	jogadores[14].numero = 9;
	jogadores[14].vencimentoMensal = 700.00f;
	jogadores[14].dia = 30;
	jogadores[14].mes = 06;
	jogadores[14].anoContrato = 2024;
	strcpy(jogadores[14].posicao, "Avancado");
	jogadores[14].statGr = 10;
	jogadores[14].statD = 49;
	jogadores[14].statM = 71;
	jogadores[14].statA = 79;
	jogadores[14].preco = 18000000.00f;
	jogadores[14].ativo = 1;

	jogadores[15].id = 16;
	jogadores[15].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[15].nome, "Carlos Vinicius");
	jogadores[15].numero = 95;
	jogadores[15].vencimentoMensal = 1500.00f;
	jogadores[15].dia = 30;
	jogadores[15].mes = 06;
	jogadores[15].anoContrato = 2024;
	strcpy(jogadores[15].posicao, "Avancado");
	jogadores[15].statGr = 10;
	jogadores[15].statD = 42;
	jogadores[15].statM = 56;
	jogadores[15].statA = 71;
	jogadores[15].preco = 15000000.00f;
	jogadores[15].ativo = 1;

	jogadores[16].id = 17;
	jogadores[16].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[16].nome, "Haris Seferovic");
	jogadores[16].numero = 14;
	jogadores[16].vencimentoMensal =700.00f;
	jogadores[16].dia = 30;
	jogadores[16].mes = 06;
	jogadores[16].anoContrato = 2024;
	strcpy(jogadores[16].posicao, "Avancado");
	jogadores[16].statGr = 10;
	jogadores[16].statD = 60;
	jogadores[16].statM = 69;
	jogadores[16].statA = 78;
	jogadores[16].preco = 18000000.00f;
	jogadores[16].ativo = 1;

	jogadores[17].id = 18;
	jogadores[17].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[17].nome, "Rafa Silva");
	jogadores[17].numero = 27;
	jogadores[17].vencimentoMensal = 2000.00f;
	jogadores[17].dia = 30;
	jogadores[17].mes = 06;
	jogadores[17].anoContrato = 2024;
	strcpy(jogadores[17].posicao, "Avancado");
	jogadores[17].statGr = 10;
	jogadores[17].statD = 54;
	jogadores[17].statM = 75;
	jogadores[17].statA = 82;
	jogadores[17].preco = 2800000.00f;
	jogadores[17].ativo = 1;

	jogadores[18].id = 19;
	jogadores[18].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[18].nome, "Caio");
	jogadores[18].numero = 7;
	jogadores[18].vencimentoMensal = 600.00f;
	jogadores[18].dia = 30;
	jogadores[18].mes = 06;
	jogadores[18].anoContrato = 2023;
	strcpy(jogadores[18].posicao, "Avancado");
	jogadores[18].statGr = 10;
	jogadores[18].statD = 43;
	jogadores[18].statM = 67;
	jogadores[18].statA = 76;
	jogadores[18].preco = 300000.00f;
	jogadores[18].ativo = 1;

	jogadores[19].id = 20;
	jogadores[19].idEquipa = obterEquipa("Benfica").id;
	strcpy(jogadores[19].nome, "Ljubomir Fejsa");
	jogadores[19].numero = 5;
	jogadores[19].vencimentoMensal = 750.00f;
	jogadores[19].dia = 30;
	jogadores[19].mes = 06;
	jogadores[19].anoContrato = 2021;
	strcpy(jogadores[19].posicao, "Medio");
	jogadores[19].statGr = 10;
	jogadores[19].statD = 79;
	jogadores[19].statM = 77;
	jogadores[19].statA = 63;
	jogadores[19].preco = 800000.00f;
	jogadores[19].ativo = 1;

	jogadores[20].id = 21;
	jogadores[20].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[20].nome, "Agustin Marchesin");
	jogadores[20].numero = 32;
	jogadores[20].vencimentoMensal = 750.00f;
	jogadores[20].dia = 30;
	jogadores[20].mes = 06;
	jogadores[20].anoContrato = 2023;
	strcpy(jogadores[20].posicao, "GR");
	jogadores[20].statGr = 78;
	jogadores[20].statD = 15;
	jogadores[20].statM = 10;
	jogadores[20].statA = 9;
	jogadores[20].preco = 7200000.00f;
	jogadores[20].ativo = 1;

	jogadores[21].id = 22;
	jogadores[21].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[21].nome, "Diogo Costa");
	jogadores[21].numero = 31;
	jogadores[21].vencimentoMensal = 750.00f;
	jogadores[21].dia = 30;
	jogadores[21].mes = 06;
	jogadores[21].anoContrato = 2022;
	strcpy(jogadores[21].posicao, "GR");
	jogadores[21].statGr = 70;
	jogadores[21].statD = 15;
	jogadores[21].statM = 10;
	jogadores[21].statA = 9;
	jogadores[21].preco = 4000000.00f;
	jogadores[21].ativo = 1;

	jogadores[22].id = 23;
	jogadores[22].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[22].nome, "Alex Telles");
	jogadores[22].numero = 13;
	jogadores[22].vencimentoMensal = 8900.00f;
	jogadores[22].dia = 30;
	jogadores[22].mes = 06;
	jogadores[22].anoContrato = 2021;
	strcpy(jogadores[22].posicao, "Defesa");
	jogadores[22].statGr = 10;
	jogadores[22].statD = 83;
	jogadores[22].statM = 79;
	jogadores[22].statA = 76;
	jogadores[22].preco = 35000000.00f;
	jogadores[22].ativo = 1;

	jogadores[23].id = 24;
	jogadores[23].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[23].nome, "Pepe");
	jogadores[23].numero = 3;
	jogadores[23].vencimentoMensal = 8400.00f;
	jogadores[23].dia = 30;
	jogadores[23].mes = 06;
	jogadores[23].anoContrato = 2021;
	strcpy(jogadores[23].posicao, "Defesa");
	jogadores[23].statGr = 10;
	jogadores[23].statD = 83;
	jogadores[23].statM = 64;
	jogadores[23].statA = 59;
	jogadores[23].preco = 1000000.00f;
	jogadores[23].ativo = 1;

	jogadores[24].id = 25;
	jogadores[24].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[24].nome, "Ivan Marcano");
	jogadores[24].numero = 5;
	jogadores[24].vencimentoMensal = 1800.00f;
	jogadores[24].dia = 30;
	jogadores[24].mes = 06;
	jogadores[24].anoContrato = 2023;
	strcpy(jogadores[24].posicao, "Defesa");
	jogadores[24].statGr = 10;
	jogadores[24].statD = 78;
	jogadores[24].statM = 63;
	jogadores[24].statA = 57;
	jogadores[24].preco = 3000000.00f;
	jogadores[24].ativo = 1;

	jogadores[25].id = 26;
	jogadores[25].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[25].nome, "Chancel Mbemba");
	jogadores[25].numero = 19;
	jogadores[25].vencimentoMensal = 500.00f;
	jogadores[25].dia = 30;
	jogadores[25].mes = 06;
	jogadores[25].anoContrato = 2020;
	strcpy(jogadores[25].posicao, "Defesa");
	jogadores[25].statGr = 10;
	jogadores[25].statD = 72;
	jogadores[25].statM = 58;
	jogadores[25].statA = 45;
	jogadores[25].preco = 3500000.00f;
	jogadores[25].ativo = 1;

	jogadores[26].id = 27;
	jogadores[26].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[26].nome, "Renzo Saravia");
	jogadores[26].numero = 24;
	jogadores[26].vencimentoMensal = 2500.00f;
	jogadores[26].dia = 30;
	jogadores[26].mes = 06;
	jogadores[26].anoContrato = 2023;
	strcpy(jogadores[26].posicao, "Defesa");
	jogadores[26].statGr = 10;
	jogadores[26].statD = 73;
	jogadores[26].statM = 69;
	jogadores[26].statA = 52;
	jogadores[26].preco = 5000000.00f;
	jogadores[26].ativo = 1;

	jogadores[27].id = 28;
	jogadores[27].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[27].nome, "Danilo Pereira");
	jogadores[27].numero = 22;
	jogadores[27].vencimentoMensal = 8000.00f;
	jogadores[27].dia = 30;
	jogadores[27].mes = 06;
	jogadores[27].anoContrato = 2022;
	strcpy(jogadores[27].posicao, "Medio");
	jogadores[27].statGr = 10;
	jogadores[27].statD = 76;
	jogadores[27].statM = 81;
	jogadores[27].statA = 70;
	jogadores[27].preco = 30000000.00f;
	jogadores[27].ativo = 1;

	jogadores[28].id = 29;
	jogadores[28].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[28].nome, "Mateus Uribe");
	jogadores[28].numero = 16;
	jogadores[28].vencimentoMensal = 1300.00f;
	jogadores[28].dia = 30;
	jogadores[28].mes = 06;
	jogadores[28].anoContrato = 2023;
	strcpy(jogadores[28].posicao, "Medio");
	jogadores[28].statGr = 10;
	jogadores[28].statD = 70;
	jogadores[28].statM = 76;
	jogadores[28].statA = 72;
	jogadores[28].preco = 10000000.00f;
	jogadores[28].ativo = 1;

	jogadores[29].id = 30;
	jogadores[29].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[29].nome, "Otavio");
	jogadores[29].numero = 25;
	jogadores[29].vencimentoMensal = 900.00f;
	jogadores[29].dia = 30;
	jogadores[29].mes = 06;
	jogadores[29].anoContrato = 2021;
	strcpy(jogadores[29].posicao, "Medio");
	jogadores[29].statGr = 10;
	jogadores[29].statD = 53;
	jogadores[29].statM = 78;
	jogadores[29].statA = 72;
	jogadores[29].preco = 17000000.00f;
	jogadores[29].ativo = 1;

	jogadores[30].id = 31;
	jogadores[30].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[30].nome, "Mamadou Loum");
	jogadores[30].numero = 15;
	jogadores[30].vencimentoMensal = 2400.00f;
	jogadores[30].dia = 30;
	jogadores[30].mes = 06;
	jogadores[30].anoContrato = 2022;
	strcpy(jogadores[30].posicao, "Medio");
	jogadores[30].statGr = 10;
	jogadores[30].statD = 67;
	jogadores[30].statM = 74;
	jogadores[30].statA = 56;
	jogadores[30].preco = 5000000.00f;
	jogadores[30].ativo = 1;

	jogadores[31].id = 32;
	jogadores[31].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[31].nome, "Shoya Nakajima");
	jogadores[31].numero = 10;
	jogadores[31].vencimentoMensal = 750.00f;
	jogadores[31].dia = 30;
	jogadores[31].mes = 06;
	jogadores[31].anoContrato = 2024;
	strcpy(jogadores[31].posicao, "Avancado");
	jogadores[31].statGr = 10;
	jogadores[31].statD = 46;
	jogadores[31].statM = 72;
	jogadores[31].statA = 79;
	jogadores[31].preco = 25000000.00f;
	jogadores[31].ativo = 1;

	jogadores[32].id = 33;
	jogadores[32].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[32].nome, "Luis Diaz");
	jogadores[32].numero = 7;
	jogadores[32].vencimentoMensal = 900.00f;
	jogadores[32].dia = 30;
	jogadores[32].mes = 06;
	jogadores[32].anoContrato = 2024;
	strcpy(jogadores[32].posicao, "Avancado");
	jogadores[32].statGr = 10;
	jogadores[32].statD = 48;
	jogadores[32].statM = 73;
	jogadores[32].statA = 75;
	jogadores[32].preco = 7000000.00f;
	jogadores[32].ativo = 1;

	jogadores[33].id = 34;
	jogadores[33].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[33].nome, "Jesus Corona");
	jogadores[33].numero = 17;
	jogadores[33].vencimentoMensal = 800.00f;
	jogadores[33].dia = 30;
	jogadores[33].mes = 06;
	jogadores[33].anoContrato = 2022;
	strcpy(jogadores[33].posicao, "Avancado");
	jogadores[33].statGr = 10;
	jogadores[33].statD = 63;
	jogadores[33].statM = 76;
	jogadores[33].statA = 81;
	jogadores[33].preco = 22000000.00f;
	jogadores[33].ativo = 1;

	jogadores[34].id = 35;
	jogadores[34].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[34].nome, "Moussa Marega");
	jogadores[34].numero = 11;
	jogadores[34].vencimentoMensal = 900.00f;
	jogadores[34].dia = 30;
	jogadores[34].mes = 06;
	jogadores[34].anoContrato = 2021;
	strcpy(jogadores[34].posicao, "Avancado");
	jogadores[34].statGr = 10;
	jogadores[34].statD = 56;
	jogadores[34].statM = 65;
	jogadores[34].statA = 78;
	jogadores[34].preco = 30000000.00f;
	jogadores[34].ativo = 1;

	jogadores[35].id = 36;
	jogadores[35].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[35].nome, "Tiquinho Soares");
	jogadores[35].numero = 29;
	jogadores[35].vencimentoMensal = 700.00f;
	jogadores[35].dia = 30;
	jogadores[35].mes = 06;
	jogadores[35].anoContrato = 2021;
	strcpy(jogadores[35].posicao, "Avancado");
	jogadores[35].statGr = 10;
	jogadores[35].statD = 60;
	jogadores[35].statM = 67;
	jogadores[35].statA = 78;
	jogadores[35].preco = 12000000.00f;
	jogadores[35].ativo = 1;

	jogadores[36].id = 37;
	jogadores[36].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[36].nome, "Vincent Aboubakar");
	jogadores[36].numero = 9;
	jogadores[36].vencimentoMensal = 550.00f;
	jogadores[36].dia = 30;
	jogadores[36].mes = 06;
	jogadores[36].anoContrato = 2021;
	strcpy(jogadores[36].posicao, "Avancado");
	jogadores[36].statGr = 10;
	jogadores[36].statD = 52;
	jogadores[36].statM = 70;
	jogadores[36].statA = 77;
	jogadores[36].preco = 10000000.00f;
	jogadores[36].ativo = 1;

	jogadores[37].id = 38;
	jogadores[37].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[37].nome, "Ze Luis");
	jogadores[37].numero = 20;
	jogadores[37].vencimentoMensal = 700.00f;
	jogadores[37].dia = 30;
	jogadores[37].mes = 06;
	jogadores[37].anoContrato = 2023;
	strcpy(jogadores[37].posicao, "Avancado");
	jogadores[37].statGr = 10;
	jogadores[37].statD = 51;
	jogadores[37].statM = 65;
	jogadores[37].statA = 78;
	jogadores[37].preco = 9000000.00f;
	jogadores[37].ativo = 1;

	jogadores[38].id = 39;
	jogadores[38].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[38].nome, "Fabio Silva");
	jogadores[38].numero = 49;
	jogadores[38].vencimentoMensal = 900.00f;
	jogadores[38].dia = 30;
	jogadores[38].mes = 06;
	jogadores[38].anoContrato = 2022;
	strcpy(jogadores[38].posicao, "Avancado");
	jogadores[38].statGr = 10;
	jogadores[38].statD = 39;
	jogadores[38].statM = 54;
	jogadores[38].statA = 67;
	jogadores[38].preco = 3000000.00f;
	jogadores[38].ativo = 1;

	jogadores[39].id = 40;
	jogadores[39].idEquipa = obterEquipa("Porto").id;
	strcpy(jogadores[39].nome, "Bruno Costa");
	jogadores[39].numero = 6;
	jogadores[39].vencimentoMensal = 450.00f;
	jogadores[39].dia = 30;
	jogadores[39].mes = 06;
	jogadores[39].anoContrato = 2022;
	strcpy(jogadores[39].posicao, "Medio");
	jogadores[39].statGr = 10;
	jogadores[39].statD = 53;
	jogadores[39].statM = 66;
	jogadores[39].statA = 43;
	jogadores[39].preco = 1000000.00f;
	jogadores[39].ativo = 1;

	jogadores[40].id = 41;
	jogadores[40].idEquipa = obterEquipa("Sporting").id;
	strcpy(jogadores[40].nome, "Renan Ribeiro");
	jogadores[40].numero = 1;
	jogadores[40].vencimentoMensal = 650.00f;
	jogadores[40].dia = 30;
	jogadores[40].mes = 06;
	jogadores[40].anoContrato = 2023;
	strcpy(jogadores[40].posicao, "GR");
	jogadores[40].statGr = 77;
	jogadores[40].statD = 11;
	jogadores[40].statM = 10;
	jogadores[40].statA = 8;
	jogadores[40].preco =  3500000.00f;
	jogadores[40].ativo = 1;

	jogadores[41].id = 42;
	jogadores[41].idEquipa = obterEquipa("Sporting").id;
	strcpy(jogadores[41].nome, "Luis Maximiano");
	jogadores[41].numero = 81;
	jogadores[41].vencimentoMensal = 300.00f;
	jogadores[41].dia = 30;
	jogadores[41].mes = 06;
	jogadores[41].anoContrato = 2023;
	strcpy(jogadores[41].posicao, "GR");
	jogadores[41].statGr = 70;
	jogadores[41].statD = 11;
	jogadores[41].statM = 10;
	jogadores[41].statA = 8;
	jogadores[41].preco = 200000.00f;
	jogadores[41].ativo = 1;


	gravaTodosJogadores(jogadores, 42);
}