#include "Jogo.h"

//Gerenciador_Eventos* Gerenciador_Eventos::instancia_eventos = NULL;

Jogo::Jogo() :
	menu(),
	fase1(),
	jogador(4, Vector2f(100.f, 100.f)),
	pause()
{
	menuAbre = true;
	pausou = false;
	faseAtual = 1;
	numFase = 0;
}

Jogo::~Jogo()
{
	menuAbre = false;
	pausou = false;
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

void Jogo::rodando_menu()
{
	menu.executar();
	menuAbre = false;

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		menuAbre = true;
	}
	jogador.executar();

	if (this->numFase == 1)
	{
		fase1.executar();
	}
	/*else if (this->numFase == 2)
	{
		fase2.executar();
	}*/
}

void Jogo::update()
{
	//Gerenciador_Eventos::getInstancia_Eventos()->executar();
	menu.executar();
	while (!menu.getRodandoMenu())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			cout << "pausou!" << endl;
			pause.executar();
			if (pause.getVoltarMenu())
			{
				cout << "voltou para o menu!" << endl;
				menu.setRodandoMenu(true);
				break;
			}
		}
		jogador.executar();
		if (menu.getNumJogadores() == 2)
		{
			//jogador2.executar();
		}

		if (menu.getEscolha() == 1 || menu.getNumFase() == 1)
		{
			fase1.executar();
		}
		else if (menu.getNumFase() == 2)
		{
			//fase2.executar();
		}
	}
}

