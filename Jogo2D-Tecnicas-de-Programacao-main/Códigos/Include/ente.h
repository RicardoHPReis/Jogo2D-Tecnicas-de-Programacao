#pragma once
#include"stdafx.h"

/*

	classe abstrata ente, onde precisa incluir a classe do gerenciador grafico
	classe ser� chamada sempre que for preciso imprimir algo
 
*/


class ente
{
private:



public:

	//construtores e destrutores

	ente();
	~ente();

	//void que ser� chamada

	virtual void executar() = 0;

	//estar� dentro da executar e chamar� o gerenciador grafico
	void imprimir_se();





};

