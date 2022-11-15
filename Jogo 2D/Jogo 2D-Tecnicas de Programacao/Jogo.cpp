#include "Jogo.h"


Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;

Jogo::Jogo():
grafico(grafico->getInstancia_Grafico())
{
	this->inicVariaveis();
}

Jogo::~Jogo()
{
	delete this->menuP;
	delete this->fase1;
}

void Jogo::inicVariaveis()
{
	this->fase1 = new FaseUm();
	this->menuP = new Menu();
	//logica jogo
	this->menuAbre = true;
	
	this->faseAtual = 1;
}

//accesos

const bool Jogo::rodando() const
{
	if (grafico->janelaEstaAberta())
		return true;
	else
		return false;
}

void Jogo::atualizaMenu()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
	{
		this->menuAbre = true;
	}
}

void Jogo::update()
{
	if (menuAbre == true) {
		this->menuP->run_menu();
		menuAbre = false;
	}
	numFase = 1;
	this->atualizaMenu();

	if (this->numFase == 1)
	{
		this->fase1->atualiza();
		this->fase1->desenha();
	}
	/*
	else if (this->numFase == 2)
	{
		this->fase2->atualiza();

		this->fase2->desenha();
	}
	*/
}

