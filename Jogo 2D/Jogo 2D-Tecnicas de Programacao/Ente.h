#pragma once
#include"stdafx.h"

/*

	classe abstrata ente, onde precisa incluir a classe do gerenciador grafico
	classe será chamada sempre que for preciso imprimir algo

*/


class Ente
{
private:



public:

	//construtores e destrutores

	Ente();
	~Ente();

	//void que será chamada

	virtual void executar() = 0;

	//estará dentro da executar e chamará o gerenciador grafico
	void imprimir_se();





};

#pragma once
