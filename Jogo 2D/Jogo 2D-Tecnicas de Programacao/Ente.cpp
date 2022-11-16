#include "Ente.h"


Ente::Ente(int i):
	grafico(grafico->getInstancia_Grafico()),
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
