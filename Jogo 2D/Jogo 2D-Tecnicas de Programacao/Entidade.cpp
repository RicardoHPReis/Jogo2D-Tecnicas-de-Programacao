#include "Entidade.h"


Entidade::Entidade(int i, Vector2f pos, Vector2f tam) :
	Ente(i),
	tamanho(tam),
	posicao(pos),
	forma()
{
	seMovimenta = false;
	velocidade = { 0,0 };
	velocidade_max = 0.f;
	dano = 0;
	lado = 0;
	gravidade = 1;
}

Entidade::~Entidade()
{
	forma;
	velocidade = { 0,0 };
	tamanho = { 0,0 };
	posicao = { 0,0 };
	velocidade_max = 0;
	seMovimenta = false;
	gravidade = 0;
}

RectangleShape Entidade::getForma()
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

void Entidade::setDano(const int nr_dano)
{
	dano = nr_dano;
}

const int Entidade::getDano() const
{
	return dano;
}

void Entidade::setLado(const int ld)
{
	lado = ld;
}

const int Entidade::getLado() const
{
	return lado;
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

void Entidade::setGravidade(const float grav)
{
	gravidade = grav;
}

const float Entidade::getGravidade() const
{
	return gravidade;
}

void Entidade::calculaQueda()
{

}