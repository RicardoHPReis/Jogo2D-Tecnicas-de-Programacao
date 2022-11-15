#include "Entidade.h"


Entidade::Entidade(int id, bool mov, Vector2f pos, Vector2f tam) :
	Ente(id)
{
	forma;
	tamanho = tam;
	posicao = pos;
	seMovimenta = mov;
	velocidade = { 0,0 };
	velocidade_max = 0.f;
}

Entidade::~Entidade()
{
	forma;
	velocidade = { 0,0 };
	tamanho = { 0,0 };
	posicao = { 0,0 };
	velocidade_max = 0;
	seMovimenta = false;
}

const RectangleShape Entidade::getForma() const
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