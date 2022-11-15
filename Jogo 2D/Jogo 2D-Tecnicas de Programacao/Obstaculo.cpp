#include "Obstaculo.h"


Obstaculo::Obstaculo(int id, bool mov, Vector2f pos, Vector2f tam):
Entidade(id, mov, pos, tam)
{
	forma.setFillColor(Color::Red);
}

Obstaculo::~Obstaculo()
{

}