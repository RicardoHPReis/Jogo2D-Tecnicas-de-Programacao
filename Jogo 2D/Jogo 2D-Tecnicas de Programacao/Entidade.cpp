#include "Entidade.h"

Entidade::Entidade() :
Ente()
{
	seMovimenta = false;
	velocidade = { 0,0 };
	velocidade_max = 0;
	tiraVida = false;
}

/*Entidade::Entidade(bool mov, Vector2f vel, float vel_max, bool danoso, int nr_id, Vector2f pos, Vector2f coord, Vector2f tam) :
//Ente(nr_id, pos, coord, tam)
Ente()
{
	seMovimenta = mov;
	velocidade = vel;
	velocidade_max = vel_max;
	tiraVida = danoso;
}*/

Entidade::~Entidade()
{
	seMovimenta = false;
	velocidade = { 0,0 };
	velocidade_max = 0;
	tiraVida = false;
}

void Entidade::setSeMovimenta(const bool mov)
{
	seMovimenta = mov;
}

const bool Entidade::getSeMovimenta() const
{
	return seMovimenta;
}

void Entidade::setVelocidadeY( float vel)
{
	velocidade.y = vel;
}

void Entidade::setVelocidadeX( float vel)
{
	velocidade.x = vel;
}

 float Entidade::getVelocidadeY() 
{
	return velocidade.y;
}

 float Entidade::getVelocidadeX() 
{
	return velocidade.x;
}

void Entidade::setVelocidadeMaxima(const float vel_max)
{
	velocidade_max = vel_max;
}

const float Entidade::getVelocidadeMaxima() const
{
	return velocidade_max;
}

void Entidade::setTiraVida(const bool danoso)
{
	tiraVida = danoso;
}

const bool Entidade::getTiraVida() const
{
	return tiraVida;
}