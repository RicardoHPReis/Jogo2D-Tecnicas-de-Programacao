#include "Entidade.h"
//using namespace Entidades;

Entidade::Entidade(int i, Vector2f pos, Vector2f tam) :
	Ente(i)
{
	forma.setSize(tam);
	forma.setPosition(pos);
	tamanho = tam,
	posicao = pos,
	velocidade = { 0,0 };
	velocidade_max = 0.f;
	gravidade = 1.f;
	dano = 0;
	lado = Lado::neutro;
	vida = 1;
}

Entidade::~Entidade()
{
	forma;
	tamanho = { 0,0 };
	posicao = { 0,0 };
	velocidade = { 0,0 };
	velocidade_max = 0.f;
	gravidade = 0.f;
	dano = 0;
	lado = Lado::neutro;
	vida = 0;
}

RectangleShape Entidade::getForma()
{
	return forma;
}

void Entidade::setPosicao(const Vector2f pos)
{
	forma.setPosition(pos);
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

void Entidade::setDano(const int nr_dano)
{
	dano = nr_dano;
}

const int Entidade::getDano() const
{
	return dano;
}

void Entidade::setLado(const Lado ld)
{
	lado = ld;
}

const Lado Entidade::getLado() const
{
	return lado;
}

void Entidade::setVida(const int nr_vd)
{
	vida = nr_vd;
}

const int Entidade::getVida() const
{
	return vida;
}

void Entidade::calculaQueda()
{
	velocidade = { velocidade.x, velocidade.y + gravidade };
}