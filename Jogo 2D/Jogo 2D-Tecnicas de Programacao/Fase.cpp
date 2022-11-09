#include "Fase.h"

Fase::Fase() :
colisao()
{
	gravidade = 0;
}

Fase::~Fase()
{
	gravidade = 0;
	delete colisao;
}

void Fase::setGravidade(const float grav)
{
	gravidade = grav;
}

const float Fase::getGravidade() const
{
	return gravidade;
}