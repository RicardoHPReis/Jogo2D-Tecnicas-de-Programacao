#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Obstaculo :public Entidade
{
protected:
	int dano;
	bool atacou;

public:
	Obstaculo();
	~Obstaculo();

	void setDano(const int nr_dano);
	const int getDano() const;
	void setAtacou(const bool atc);
	const bool getAtacou() const;
};