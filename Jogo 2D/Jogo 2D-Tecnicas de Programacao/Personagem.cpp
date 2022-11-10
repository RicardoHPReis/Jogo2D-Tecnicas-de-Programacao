#include "Personagem.h"

Personagem::Personagem():
Entidade()
{
	vidas = 1;
	dano = 0;
	lado = 0;
	podeAtacar = false;
	estaMorto = false;
}

Personagem::~Personagem()
{
	vidas = 0;
	dano = 0;
	lado = 0;
	podeAtacar = false;
	estaMorto = false;
}

void Personagem::setAtaque(bool nr_vd)
{
	this->atacou = nr_vd;
}

bool Personagem::getAtaque()
{
	return atacou;
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

void Personagem::setPodeAtacar(const bool atc)
{
	podeAtacar = atc;
}

const bool Personagem::getPodeAtacar() const
{
	return podeAtacar;
}

void Personagem::setEstaMorto(const bool mrt)
{
	estaMorto = mrt;
}

const bool Personagem::getEstaMorto() const
{
	return estaMorto;
}