#include "Jogo.h"

Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;
Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Jogo::Jogo():
menu(),
jogador()
{
	iniciaMapa();

	grafico->getInstancia_Grafico();
	colisao->getInstancia_Colisoes();
	menuAbre = true;
	baixo = true;
}

Jogo::~Jogo()
{
	delete grafico;
	delete colisao;
}



void Jogo::iniciaMapa()
{
	chao.setPosition(0, 1080.f - 85.f);
	chao.setSize(Vector2f((1920.f), 85.f));
	chao.setFillColor(Color::Blue);
}

const bool Jogo::rodando() const
{
	if (grafico->janelaEstaAberta())
		return 1;
	else
		return 0;
}

void Jogo::atualizaMenu()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->menuAbre = true;
	}
}

void Jogo::atualizaJogo()
{
	if (menuAbre == true) 
	{
		menu.executar();
		menuAbre = false;
	}

	atualizaMenu();

	jogador.executar();
	renderizar();
}

void Jogo::renderizar()
{
	grafico->fechar();
	jogador.imprimir();
}
