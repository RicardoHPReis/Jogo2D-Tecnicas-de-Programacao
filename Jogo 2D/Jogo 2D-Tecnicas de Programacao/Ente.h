#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

class Ente
{
protected:
	const int id;
	Gerenciador_Grafico* grafico;

public:
	Ente(int i=0);
	virtual ~Ente();

	const int getId() const;
};