#include "Fase.h"

//Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Fase::Fase()
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