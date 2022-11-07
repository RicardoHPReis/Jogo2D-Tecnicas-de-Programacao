#include "Fase.h"

Fase::Fase() :
Ente()
{

}

Fase::~Fase()
{

}

void Fase::setGravidade(const float grav)
{
	gravidade = grav;
}

const float Fase::getGravidade() const
{
	return gravidade;
}