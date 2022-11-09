#include "Ente.h"

Ente::Ente(int i) {
	this->id = i;
	this->janela = NULL;
}

Ente::Ente()
{
	id = 0;
	janela = NULL;
	this->inicEnte();
}

Ente::~Ente()
{
	id = 0;
}

void Ente::inicEnte()
{
	this->janela = nullptr;
	
	this->janela = &Gerenciador_Grafico::getInstancia();
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
	this->janela->clear();
}

void Ente::display()
{
	this->janela->janelaP->display();
}

RenderWindow* Ente::getJanelaCoord(void)
{
	return (janela->janelaP);
}

void Ente::setId(int i)
{
	id = i;
}

int Ente::getAberta(void)
{
	return (1);
}
