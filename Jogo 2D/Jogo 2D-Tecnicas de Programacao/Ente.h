#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

class Ente
{
protected:
	Gerenciador_Grafico* grafico;
	const int id;

public:
	Ente();
	Ente(int i);
	virtual ~Ente();

	virtual void executar() = 0;
	virtual void imprimir() = 0;

	const int getId() const;
};