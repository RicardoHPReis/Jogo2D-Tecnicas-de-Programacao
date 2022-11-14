#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:
	int contador_movimento;

public:
	Inimigo();
	virtual ~Inimigo();

	virtual void executar() = 0;
	virtual void imprimir() = 0;
};