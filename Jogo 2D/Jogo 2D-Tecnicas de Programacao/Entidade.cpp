#include "Entidade.h"

Entidade::Entidade() :
Ente()
{
	seMovimenta = false;
	velocidade = { 0,0 };
	velocidade_max = 0;
	empuxo = 0;
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
	empuxo = 0;
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

void Entidade::setVelocidade(const Vector2f vel)
{
	velocidade = vel;
}

const Vector2f Entidade::getVelocidade() const
{
	return velocidade;
}

void Entidade::setVelocidadeMaxima(const float vel_max)
{
	velocidade_max = vel_max;
}

const float Entidade::getVelocidadeMaxima() const
{
	return velocidade_max;
}

void Entidade::setEmpuxo(const float empx)
{
	empuxo = empx;
}

const float Entidade::getEmpuxo() const
{
	return empuxo;
}

void Entidade::setTiraVida(const bool danoso)
{
	tiraVida = danoso;
}

const bool Entidade::getTiraVida() const
{
	return tiraVida;
}