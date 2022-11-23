#include "Personagem.h"

Personagem::Personagem(int i, Vector2f pos, Vector2f tam):
Entidade(i, pos, tam)
{
	vida = 0;
	podeAtacar = true;
	estaMorto = false;
	atacou = false;
}

Personagem::~Personagem()
{
	vida = 0;
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