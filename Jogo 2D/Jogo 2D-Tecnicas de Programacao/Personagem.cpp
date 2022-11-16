#include "Personagem.h"

Personagem::Personagem(int id, bool mov, Vector2f pos, Vector2f tam, int nr_vidas, int nr_dano, int ld, bool atacar, bool morreu, bool foiAtacado):
Entidade(id, mov, pos, tam)
{
	vidas = nr_vidas;
	dano = nr_dano;
	lado = ld;
	podeAtacar = atacar;
	estaMorto = morreu;
	atacou = foiAtacado;
}

Personagem::~Personagem()
{
	vidas = 0;
	dano = 0;
	lado = 0;
	podeAtacar = false;
	estaMorto = false;
	atacou = false;
}

void Personagem::setAtaque(bool foiAtacado)
{
	atacou = foiAtacado;
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