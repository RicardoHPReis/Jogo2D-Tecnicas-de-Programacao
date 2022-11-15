#include "Jogo.h"

//contrutores / destrutores
Jogo::Jogo()
{

	this->inicVariaveis();
}

Jogo::~Jogo()
{
	delete this->menuP;
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
	if (fase1->principal->Tela->getAberta() == 1)
		return 1;
	else
		return 0;
}

//funcoes

void Jogo::atualizaMenu()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->menuAbre = true;
	}
}

void Jogo::update()
{
	if (menuAbre == true) {
		this->menuP->run_menu();
		menuAbre = false;
	}

	this->atualizaMenu();

	if (this->faseAtual == 1)
	{
		this->fase1->principal->atualiza();

		this->fase1->principal->desenha();
	}
	/*
	else if (this->numFase == 2)
	{
		this->fase2->principal->atualiza();

		this->fase2->principal->desenha();
	}
	*/
}

