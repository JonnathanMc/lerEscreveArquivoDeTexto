#include "LeituraInstrucoes.h"
#include<stdlib.h>
#using<system.dll>
#include<stdio.h>


using namespace System;
using namespace System::IO;
using namespace std;

void imprimirInstrucao(int paragrafo){
	int contador = 0, count = 0, countOpcoes = 0;
	array<String^>^ managedArray = gcnew array<String^>(400);  //Array de Strings com 100 linhas, cada linha da String armazena uma linha do arquivo de texto
	array<String^>^ opcoes = gcnew array<String^>(100);
	array<String^>^ opcoesNumeros = gcnew array<String^>(100);
	
	String^ fileName;

	int a, assist = 0, finalInstrucao = 0;
	if (paragrafo <= 36)
		fileName = "instrucoes.txt"; // nome do arquivo txt, deve ter o mesmo nome do .txt localizado na pasta do projeto
	if (paragrafo > 36)
		fileName = "instrucoes2.txt"; // nome do arquivo txt, deve ter o mesmo nome do .txt localizado na pasta do projeto
	try
	{

		StreamReader^ din = File::OpenText(fileName);

		String^ str;
		String^ pars;

		Console::WriteLine("{0}", managedArray[0]);

		pars = "#" + paragrafo + "#";  // uma string (pars) que recebe o numero do paragrafo e concatena com "#" para corresponder à tag do arquivo de texto 

		while ((str = din->ReadLine()) != pars)  // str = din->ReadLine() || faz a string receber a linha do arquivo de texto e percorre o arquivo ate encontrar o padrado "#paragrafo#" ex: #12#
		{
			count++;
		}

		while ((str = din->ReadLine()) != "!!!"){
			if (str == "@")
				finalInstrucao = 1;

			if (assist == 2) //  se assist for igual a 1(encontrar '@') ele vai pegar a proxima linha depois do '@'
			{
				opcoesNumeros[countOpcoes] = str;
				assist = 0;
			}
			if (assist == 1) //  se assist for igual a 1(encontrar '@') ele vai pegar a proxima linha depois do '@'
			{
				opcoes[countOpcoes] = str;
				countOpcoes++;
				assist = 2;
			}

			if (str == "@"){
				assist = 1;
			}

			if (finalInstrucao != 1){
				managedArray[contador] = str; // array de string recebe a string que recebeu a linha do arquivo txt
				contador++;
			}

			Console::SetCursorPosition(3, count);
			count++;

		}

		//Console::WriteLine("{1}", count-1, din->ReadLine());	
	}
	catch (Exception^ e)
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("file '{0}' not found", fileName);
		else
			Console::WriteLine("problem reading file '{0}'", fileName);
	}
	Console::Clear();
	// Imprime todas as linhas da instrução atual
	Console::SetCursorPosition(0, (Console::WindowWidth * 0.5f));
	Console::Write("- " + paragrafo + " -");

	for (a = 0; a < contador; a++){
		Console::SetCursorPosition(3, a + 1);
		Console::WriteLine("{0}", managedArray[a]);

		//ConsoleHelper::ImprimirASCIIExtended(managedArray[a]);
	}
	Console::SetCursorPosition(0, a + 2);

	Console::WriteLine("Opcoes");
	// Imprime as opcoes que vem depois do '@'
	for (int x = 0; x < countOpcoes; x++){
		Console::WriteLine("{0}", opcoes[x]);
	}

	Console::Write("Opcoes Numeros: ");

	for (int x = 0; x < countOpcoes; x++){
		Console::WriteLine("{0}", opcoesNumeros[x]);
	}
}
