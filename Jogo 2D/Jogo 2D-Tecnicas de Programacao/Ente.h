#pragma once
#include"stdafx.h"

/*

	classe abstrata ente, onde precisa incluir a classe do gerenciador grafico
	classe ser� chamada sempre que for preciso imprimir algo

*/


class Ente
{
private:



public:

	//construtores e destrutores

	Ente();
	~Ente();

	//void que ser� chamada

	virtual void executar() = 0;

	//estar� dentro da executar e chamar� o gerenciador grafico
	void imprimir_se();





};

#pragma once
