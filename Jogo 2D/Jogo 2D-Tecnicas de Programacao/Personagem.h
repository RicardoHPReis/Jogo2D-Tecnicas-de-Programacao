#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Personagem :public Entidade
{
protected:
	int vidas;
	int dano;
	int lado;
	bool atacou;

public:
	Personagem();
	~Personagem();

	void setVidas(const int nr_vd);
	const int getVidas() const;
	void setDano(const int nr_dano);
	const int getDano() const;
	void setLado(const int ld);
	const int getLado() const;
	void setAtacou(const bool atc);
	const bool getAtacou() const;
};
