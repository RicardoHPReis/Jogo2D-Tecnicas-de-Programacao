#include "Personagem.h"

Personagem::Personagem():
Entidade(true)
{
	vidas = 1;
	dano = 0;
	atacou = false;
}

Personagem::~Personagem()
{
	vidas = 0;
	dano = 0;
	atacou = false;
}

void Personagem::setVidas(const int nr_vd)
{
	vidas = nr_vd;
}

const int Personagem::getVidas() const
{
	return vidas;
}

void Personagem::setDano(const int nr_dano)
{
	dano = nr_dano;
}

const int Personagem::getDano() const
{
	return dano;
}

void Personagem::setLado(const int ld)
{
	lado = ld;
}

const int Personagem::getLado() const
{
	return lado;
}

void Personagem::setAtacou(const bool atc)
{
	atacou = atc;
}

const bool Personagem::getAtacou() const
{
	return atacou;
}


