#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Projetil :public Entidade
{
protected:
	int dano;
	bool atingiu;

public:
	Projetil();
	~Projetil();

	void setDano(const int nr_dano);
	const int getDano() const;

	void setAtingiu(const bool atg);
	const bool getAtingiu() const;
};