#include "Obstaculo.h"
//using namespace Entidades;
//using namespace Obstaculos;

Obstaculo::Obstaculo(int i, Vector2f pos, Vector2f tam):
Entidade(i, pos, tam)
{
	danoso = false;
}

Obstaculo::~Obstaculo()
{
	danoso = false;
}

void Obstaculo::setDanoso(const bool mal)
{
	danoso = mal;
}

const bool Obstaculo::getDanoso() const
{
	return danoso;
}
