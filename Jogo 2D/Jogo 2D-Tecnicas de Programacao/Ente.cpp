#include "Ente.h"


Ente::Ente(int i):
janela(janela->getInstancia_Grafico())
{
	id = i;
}

Ente::~Ente()
{
	id = 0;
}

void Ente::executar(RectangleShape obj)
{
	this->janela->desenhar(&obj);
}

void Ente::executarTex(Text obj)
{
	this->janela->desenharT(&obj);
}

void Ente::executarSprite(Sprite obj)
{
	this->janela->desenharS(&obj);
}

void Ente::clear()
{
	this->janela->limpar();
}

void Ente::display()
{
	this->janela->mostrar();
}

RenderWindow* Ente::getJanelaCoord(void)
{
	return janela->getJanela();
}

void Ente::setId(int i)
{
	id = i;
}

int Ente::getAberta(void)
{
	return (1);
}
