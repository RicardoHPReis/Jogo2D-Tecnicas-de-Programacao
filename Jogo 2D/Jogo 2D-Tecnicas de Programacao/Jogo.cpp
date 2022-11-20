#include "Jogo.h"

//Gerenciador_Eventos* Gerenciador_Eventos::instancia_eventos = NULL;

Jogo::Jogo()
{
	menu = new Menu(3);
	fase1 = new FaseUm(1);
	jogador = new Jogador(4, Vector2f(100.f, 100.f));

	menuAbre = true;
	faseAtual = 1;
	numFase = 0;
}

Jogo::~Jogo()
{
	delete menu;
	delete fase1;
	delete jogador;

	menuAbre = false;
	faseAtual = 0;
	numFase = 0;
}

const bool Jogo::rodando() const
{
	if (Gerenciador_Grafico::getInstancia_Grafico()->janelaEstaAberta())
		return true;
	else
		return false;
}

void Jogo::update()
{
	//Gerenciador_Eventos::getInstancia_Eventos()->executar();
	if (menuAbre == true)
	{
		menu->executar();
		menuAbre = false;
	}

	numFase = 1;
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		menuAbre = true;
	}
	jogador->executar();

	if (this->numFase == 1)
	{
		fase1->executar();
	}
	/*else if (this->numFase == 2)
	{
		fase2.executar();
	}*/
}

