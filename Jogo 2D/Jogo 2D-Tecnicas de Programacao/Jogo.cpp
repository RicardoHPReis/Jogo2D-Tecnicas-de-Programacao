#include "Jogo.h"


Jogo::Jogo():
menu(),
fase1()
{
	menuAbre = true;
	faseAtual = 1;
	numFase = 0;
	Ente::setGerenciador_Grafico(Gerenciador_Grafico::getInstancia_Grafico());
}

Jogo::~Jogo()
{
	menuAbre = false;
	faseAtual = 0;
	numFase = 0;
}

const bool Jogo::rodando() const
{
	if (menu.janelaEstaAberta())
		return true;
	else
		return false;
}

void Jogo::atualizaMenu()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape)) 
	{
		menuAbre = true;
	}
}

void Jogo::update()
{
	if (this->menuAbre == true)
	{
		this->menu.run_menu();
		this->menuAbre = false;
	}

	this->numFase = 1;
	this->atualizaMenu();

	if (this->numFase == 1)
	{
		this->fase1.atualiza();
		this->fase1.desenha();
	}
	/*else if (this->numFase == 2)
	{
		fase2.atualiza();
		fase2.desenha();
	}*/
}

