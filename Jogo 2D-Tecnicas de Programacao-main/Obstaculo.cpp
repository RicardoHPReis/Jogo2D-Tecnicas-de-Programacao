#include "Obstaculo.h"


Obstaculo::Obstaculo():
Entidade()
{
	dano = 0;
	atacou = false;
}

Obstaculo::~Obstaculo()
{
	dano = 0;
	atacou = false;
}


void Obstaculo::setDano(const int nr_dano)
{
	dano = nr_dano;
}

const int Obstaculo::getDano() const
{
	return dano;
}

void Obstaculo::setAtacou(const bool atc)
{
	atacou = atc;
}

const bool Obstaculo::getAtacou() const
{
	return atacou;
}