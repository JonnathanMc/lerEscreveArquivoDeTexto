#ifndef PLAYER_H
#define PLAYER_H

struct opcao
{
	char* nome;
	int   idopt;
};

void ProcessaComandoPlayer(opcao optPlayer);//processa a opcao digitada pelo player
void InicializaPlayer(opcao listaopt[4]);

#endif