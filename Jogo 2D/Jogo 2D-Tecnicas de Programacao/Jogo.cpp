#include "Jogo.h"


Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;

Jogo::Jogo():
grafico(grafico->getInstancia_Grafico()),
menu(),
fase1()
{
	menuAbre = true;
	faseAtual = 1;
	numFase = 0;
}

Jogo::~Jogo()
{
	menuAbre = false;
	faseAtual = 0;
	numFase = 0;
}

const bool Jogo::rodando() const
{
	if (grafico->janelaEstaAberta())
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
	if (menuAbre == true)
	{
		menu.run_menu();
		menuAbre = false;
	}
	numFase = 1;
	atualizaMenu();

	if (numFase == 1)
	{
		fase1.atualiza();
		fase1.desenha();
		//jogador.atualiza();
		//jogador.desenha();
	}
	/*else if (this->numFase == 2)
	{
		fase2.atualiza();
		fase2.desenha();
	}*/
}

