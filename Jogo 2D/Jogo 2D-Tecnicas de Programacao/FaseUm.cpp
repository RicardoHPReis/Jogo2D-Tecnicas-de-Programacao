#include "FaseUm.h"

FaseUm::FaseUm():
Fase()
{
	this->principal = new Fase;

	this->inicVariaveis();
	this->inicMapa();
}

FaseUm::~FaseUm()
{
	delete this->principal;
}


void FaseUm::inicVariaveis()
{
	
}

void FaseUm::inicMapa()
{
	
}
