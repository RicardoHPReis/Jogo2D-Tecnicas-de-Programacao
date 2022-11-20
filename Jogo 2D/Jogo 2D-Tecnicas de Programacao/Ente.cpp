#include "Ente.h"

Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;

Ente::Ente(int i):
	id(i)
{
}

Ente::~Ente()
{
}

const int Ente::getId() const
{
	return id;
}