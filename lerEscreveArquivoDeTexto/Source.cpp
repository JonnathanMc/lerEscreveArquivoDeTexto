// text_read.cpp
// compile with: /clr

#using<system.dll>
#include "ConsoleHelper.h"
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "Player.h"
#include "LeituraInstrucoes.h"

using namespace System;
using namespace System::IO;
using namespace std;

//opcao listaopt[4];
extern opcao listaopcoes[4];


int main()
{
	setlocale(LC_ALL, "Portuguese");

	int paragrafo;

	Console::SetWindowSize(100, 30);
	Console::SetBufferSize(300, 300);

	Console::WriteLine("Digite o paragrafo escolhido: ");
	scanf_s("%d", &paragrafo);

	imprimirInstrucao(paragrafo);
	//InicializaPlayer(listaopt);
	for (;;)
	{ 
		Console::WriteLine("Escolha: ");
		scanf_s("%d", &paragrafo);

		imprimirInstrucao(paragrafo);
	}

	system("pause");
	return 0;
}

