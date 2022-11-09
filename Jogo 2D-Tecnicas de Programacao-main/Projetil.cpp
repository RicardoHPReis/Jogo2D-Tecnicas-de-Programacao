#include "Projetil.h"

Projetil::Projetil():
Entidade()
{
	dano = 0;
	atingiu = false;
}

Projetil::~Projetil()
{
	dano = 0;
	atingiu = false;
}


void Projetil::setDano(const int nr_dano)
{
	dano = nr_dano;
}

const int Projetil::getDano() const
{
	return dano;
}

void Projetil::setAtingiu(const bool atg)
{
	atingiu = atg;
}

const bool Projetil::getAtingiu() const
{
	return atingiu;
}