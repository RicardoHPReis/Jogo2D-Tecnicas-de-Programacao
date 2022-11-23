#include "Jogo.h"

//Gerenciador_Eventos* Gerenciador_Eventos::instancia_eventos = NULL;

Jogo::Jogo() :
	menu(),
	jogador(),
	jogador2(),
	fase1(1, &jogador, &jogador2),
	//fase2(1, &jogador, &jogador2),
	pause()
{
	menuAbre = true;
	pausou = false;
}

Jogo::~Jogo()
{
	menuAbre = false;
	pausou = false;
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
	menu.executar();
	if (menu.getNumJogadores() == 2)
	{
		fase1.setDoisJogadores(true);
		//fase2.setDoisJogadores(true);
		//inicializar();
	}
		
	while (!menu.getRodandoMenu() )//&& (jogador.getVida() < 0  && jogador2.getVida() < 0 ))
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			cout << "pausou!" << endl;
			pause.executar();
			if (pause.getVoltarMenu())
			{
				cout << "voltou para o menu!" << endl;
				menu.setRodandoMenu(true);
				inicializar();
				break;
			}
		}

		cout << menu.getNumJogadores() << endl;
		cout << menu.getNumFase() << endl;

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

void Jogo::inicializar()
{
	jogador.iniciarVariaiveis();
	fase1.deletarEntidades();
	fase1.iniciaFase();
	//fase2.in;
}