#include "Ente.h"


Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;

Ente::Ente(int i):
	id(i),
	grafico(grafico->getInstancia_Grafico())
{
	//setGerenciador_Grafico(Gerenciador_Grafico::getInstancia_Grafico());
}

Ente::~Ente()
{
}

const int Ente::getId() const
{
	return id;
}

/*void Ente::setGerenciador_Grafico(Gerenciador_Grafico* gg)
{
	grafico = gg;
}*/

void Ente::desenhar(RectangleShape retangulo)
{
	grafico->desenhar(retangulo);
}

void Ente::desenharTexto(Text texto)
{
	grafico->desenharTexto(texto);
}

void Ente::desenharSprite(Sprite sprite)
{
	grafico->desenharSprite(sprite);
}

void Ente::limpar()
{
	grafico->limpar();
}

void Ente::mostrar()
{
	grafico->mostrar();
}

bool Ente::janelaEstaAberta()
{
	if(grafico->getJanela())
		return true;
	return false;
}