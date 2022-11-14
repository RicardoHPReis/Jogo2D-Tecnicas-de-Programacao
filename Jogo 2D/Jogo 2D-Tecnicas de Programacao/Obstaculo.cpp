#include "Obstaculo.h"


Obstaculo::Obstaculo():
Entidade()
{
	dano = 0;
	podeDarDano = false;
}

Obstaculo::~Obstaculo()
{
	dano = 0;
	podeDarDano = false;
}

void Obstaculo::setDano(const int nr_dano)
{
	dano = nr_dano;
}

const int Obstaculo::getDano() const
{
	return dano;
}

void Obstaculo::setPodeDarDano(const bool dano)
{
	podeDarDano = dano;
}

const bool Obstaculo::getPodeDarDano() const
{
	return podeDarDano;
}