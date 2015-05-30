// text_read.cpp
// compile with: /clr
#using<system.dll>
#include "ConsoleHelper.h"
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

using namespace System;
using namespace System::IO;
using namespace std;

void imprimirInstrucao(int paragrafo);

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int paragrafo;

	Console::SetWindowSize(100, 30);
	Console::SetBufferSize(100, 300);

	Console::WriteLine("Digite o paragrafo escolhido: ");
	scanf_s("%d", &paragrafo);

	imprimirInstrucao(paragrafo);

	system("pause");
	return 0;
}

void imprimirInstrucao(int paragrafo){
	int contador = 0, count = 0, countOpcoes = 0;
	array<String^>^ managedArray = gcnew array<String^>(100);
	array<String^>^ opcoes = gcnew array<String^>(100);

	int a, assist = 0;

	//String^ fileName = "textfile.txt";
	//try
	//{
	//	//Console::WriteLine("trying to open file {0}...", fileName);
	//	StreamReader^ din = File::OpenText(fileName);

	//	String^ str;
	//	String^ pars;

	//	managedArray[0] = { "Teste" };
	//	Console::WriteLine("{0}", managedArray[0]);

	//	pars = "#" + paragrafo + "#";

	//	while ((str = din->ReadLine()) != pars)
	//	{
	//		count++;
	//	}

	//	while ((str = din->ReadLine()) != "!!!"){
	//		Console::SetCursorPosition(3, count);

	//		managedArray[contador] = str;

	//		//Console::WriteLine("{1}", count, str);
	//		count++;
	//		contador++;
	//	}

	//	//Console::WriteLine("{1}", count-1, din->ReadLine());	
	//}
	//catch (Exception^ e)
	//{
	//	if (dynamic_cast<FileNotFoundException^>(e))
	//		Console::WriteLine("file '{0}' not found", fileName);
	//	else
	//		Console::WriteLine("problem reading file '{0}'", fileName);
	//}
	//Console::Clear();
	//for (int a = 0; a < contador; a++){
	//	Console::WriteLine("{0}", managedArray[a]);
	//}

	String^ fileName = "textfile.txt";
	try
	{
		//Console::WriteLine("trying to open file {0}...", fileName);
		StreamReader^ din = File::OpenText(fileName);

		String^ str;
		String^ pars;

		Console::WriteLine("{0}", managedArray[0]);

		pars = "#" + paragrafo + "#";

		while ((str = din->ReadLine()) != pars)
		{
			count++;
		}


		while ((str = din->ReadLine()) != "!!!"){
			managedArray[contador] = str;
			contador++;

			if (assist == 1) //  se assist for igual a 1(encontrar '@') ele vai pegar a proxima linha depois do '@'
			{
				opcoes[countOpcoes] = str;
				countOpcoes++;
				assist = 0;
			}
			if (str == "@"){
				assist = 1;
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
	for (a = 0; a < contador; a++){
		Console::SetCursorPosition(3, a);
		Console::WriteLine("{0}", managedArray[a]);
		
		//ConsoleHelper::ImprimirASCIIExtended(managedArray[a]);
	}
	Console::SetCursorPosition(0, a + 2);
	
	// Imprime as opcoes que vem depois do '@'
	for (int x = 0; x < countOpcoes; x++){
		Console::WriteLine("{0}", opcoes[x]);
	}


}