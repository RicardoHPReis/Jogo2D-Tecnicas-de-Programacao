#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Obstaculo :public Entidade
{
protected:
	int dano;
	bool podeDarDano;

public:
	Obstaculo();
	~Obstaculo();

	virtual void executar() = 0;
	virtual void imprimir() = 0;
	virtual void clear() = 0;

	void setDano(const int nr_dano);
	const int getDano() const;
	void setPodeDarDano(const bool dano);
	const bool getPodeDarDano() const;
};