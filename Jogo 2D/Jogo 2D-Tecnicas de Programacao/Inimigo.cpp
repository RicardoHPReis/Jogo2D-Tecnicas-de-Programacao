#include "Inimigo.h"

Inimigo::Inimigo(int i, Vector2f pos, Vector2f tam) :
	Personagem(i, pos, tam)
{
	danoso = true;
}

Inimigo::~Inimigo()
{
	danoso = false;
}

void Inimigo::setDanoso(const bool mal)
{
	danoso = mal;
}

const bool Inimigo::getDanoso() const
{
	return danoso;
}
