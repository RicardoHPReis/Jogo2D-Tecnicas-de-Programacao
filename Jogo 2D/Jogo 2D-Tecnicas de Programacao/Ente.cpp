#include "Ente.h"

Ente::Ente(int i):
id(i),
grafico(grafico->getInstancia_Grafico())
{
}

Ente::Ente() :
grafico(grafico->getInstancia_Grafico()),
id()
{
}

Ente::~Ente()
{
	delete grafico;
}

const int Ente::getId() const
{
	return id;
}