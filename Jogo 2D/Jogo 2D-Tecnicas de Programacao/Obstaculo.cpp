#include "Obstaculo.h"


Obstaculo::Obstaculo(int i, Vector2f pos, Vector2f tam):
Entidade(i, pos, tam)
{
	danoso = false;
}

Obstaculo::~Obstaculo()
{
	danoso = false;
}