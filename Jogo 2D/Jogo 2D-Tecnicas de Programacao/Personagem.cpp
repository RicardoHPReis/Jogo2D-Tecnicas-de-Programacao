#include "Personagem.h"
//using namespace Entidades;
//using namespace Personagens;

Personagem::Personagem(int i, Vector2f pos, Vector2f tam):
Entidade(i, pos, tam)
{
	vida = 0;
	estaMorto = false;
	atacou = false;
}

Personagem::~Personagem()
{
	vida = 0;
	estaMorto = true;
	atacou = false;
}

void Personagem::setAtacou(bool foiAtacado)
{
	atacou = foiAtacado;
}

const bool Personagem::getAtacou() const
{
	return atacou;
}

void Personagem::setEstaMorto(const bool mrt)
{
	estaMorto = mrt;
}

const bool Personagem::getEstaMorto() const
{
	return estaMorto;
}