#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

class Ente 
{
protected:
	const int id;

public:
	Ente(int i = 0);
	virtual ~Ente();

	virtual void executar() = 0;

	const int getId() const;
	//static void setGerenciador_Grafico(Gerenciador_Grafico* gg);
};