#include "Inimigo.h"

Inimigo::Inimigo():
Personagem()
{
	nocivo = true;
}

Inimigo::~Inimigo()
{
	nocivo = false;
}