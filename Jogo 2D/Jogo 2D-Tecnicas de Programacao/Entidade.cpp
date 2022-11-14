#include "Entidade.h"

Entidade::Entidade() :
Ente()
{
	forma = new RectangleShape;
	velocidade = { 0,0 };
	tamanho = { 0,0 };
	posicao = { 0,0 };
	velocidade_max = 0;
	empuxo = 0;
	seMovimenta = false;
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
	delete forma;
	velocidade = { 0,0 };
	tamanho = { 0,0 };
	posicao = { 0,0 };
	velocidade_max = 0;
	empuxo = 0;
	seMovimenta = false;
	tiraVida = false;
}

const RectangleShape* Entidade::getForma() const
{
	return forma;
}

void Entidade::setPosicao(const Vector2f pos)
{
	posicao = pos;
}

const Vector2f Entidade::getPosicao() const
{
	return posicao;
}

void Entidade::setTamanho(const Vector2f tam)
{
	tamanho = tam;
}

const Vector2f Entidade::getTamanho() const
{
	return tamanho;
}

void Entidade::setSeMovimenta(const bool mov)
{
	seMovimenta = mov;
}

const bool Entidade::getSeMovimenta() const
{
	return seMovimenta;
}

void Entidade::setVelocidadeY(const float vel)
{
	velocidade.y = vel;
}

void Entidade::setVelocidadeX(const float vel)
{
	velocidade.x = vel;
}

const float Entidade::getVelocidadeY() const
{
	return velocidade.y;
}

const float Entidade::getVelocidadeX() const
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