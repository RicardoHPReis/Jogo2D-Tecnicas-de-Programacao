#include "Ente.h"

Ente::Ente():
grafico()
{
	id = 0;
	posicao = { 0,0 };
	coordenada = { 0,0 };
	tamanho = { 0,0 };
	estaImprimindo = false;
	grafico = new Gerenciador_Grafico;
}

/*Ente::Ente(int nr_id, Vector2f pos, Vector2f coord, Vector2f tam)
{
	id = nr_id;
	posicao = pos;
	coordenada = coord;
	tamanho = tam;
	estaImprimindo = false;
}*/

Ente::~Ente()
{
	id = 0;
	posicao = { 0,0 };
	coordenada = { 0,0 };
	tamanho = { 0,0 };
	estaImprimindo = false;
}


void Ente::setId(const int nr_id)
{
	this->id = nr_id;
}

const int Ente::getId() const
{
	return id;
}

void Ente::setPosicao(const Vector2f pos)
{
	this->posicao = pos;
}

const Vector2f Ente::getPosicao() const
{
	return posicao;
}

void Ente::setCoordenada(const Vector2f coord)
{
	this->coordenada = coord;
}

const Vector2f Ente::getCoordenada() const
{
	return coordenada;
}

void Ente::setTamanho(const Vector2f coord)
{
	this->coordenada = coord;
}

const Vector2f Ente::getTamanho() const
{
	return tamanho;
}

void Ente::setImprimindo(const bool imp)
{
	this->estaImprimindo = imp;
}

const bool Ente::getImprimindo() const
{
	return estaImprimindo;
}

void Ente::setTextura(Texture* tx)
{
	textura = tx;
}

const Texture* Ente::getTextura() const
{
	return textura;
}

void Ente::setSprite(Sprite* sp)
{
	sprite = sp;
}

const Sprite* Ente::getSprite() const
{
	return sprite;
}


void Ente::executar(RectangleShape* obj)
{
	this->grafico->fechar();
	this->grafico->desenhar(obj);
}

bool Ente::getAberta()
{
	if (this->grafico->aberta() == 1)
		return true;
	else
		return false;
}