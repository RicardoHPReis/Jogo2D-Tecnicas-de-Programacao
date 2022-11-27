#include "Jogo.h"

//Gerenciador_Eventos* Gerenciador_Eventos::instancia_eventos = NULL;

Jogo::Jogo()
{
	menuInicial = new Menu_Inicial(),
	jogador1 = new JogadorUm();
	jogador2 = new JogadorDois();
	fase1 = new FaseUm(1, jogador1, jogador2),
	fase2 = new FaseDois(2, jogador1, jogador2),
	menuPause = new Menu_Pause();
	
	menuAbre = true;
	pausou = false;
}

Jogo::~Jogo()
{
	delete menuInicial;
	delete jogador1;
	delete jogador2;
	delete fase1;
	delete fase2;
	delete menuPause;

	menuAbre = false;
	pausou = false;

	Gerenciador_Grafico::getInstancia_Grafico()->deletarInstancia_Grafico();
	Gerenciador_Colisoes::getInstancia_Colisoes()->deletarInstancia_Colisoes();
	//Gerenciador_Eventos::getInstancia_Eventos()->deletarInstancia_Eventos();
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
	menuInicial->executar();
	if (menuInicial->getNumJogadores() == 2)
	{
		fase1->setDoisJogadores(true);
		fase2->setDoisJogadores(true);
		jogador2->setEstaMorto(false);
		inicializar();
	}
	if (menuInicial->getNumFase() == 1 && fase1->getInicializada() == false)
	{
		fase1->iniciaFase();
		fase1->setInicializada(true);
	}
	if (menuInicial->getNumFase() == 2 && fase2->getInicializada() == false)
	{
		fase2->iniciaFase();
		fase2->setInicializada(true);
	}

	while (!menuInicial->getRodandoMenu())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			cout << "pausou!" << endl;
			menuPause->executar();
			if (menuPause->getVoltarMenu())
			{
				cout << "voltou para o menu!" << endl;
				menuInicial->setRodandoMenu(true);
				//inicializar();
				//break;
			}
		}

		if (menuInicial->getNumFase() == 1)
		{
			cout << "Entrou Fase 1" << endl;
			fase1->executar();
			if (fase1->getConcluido())
			{
				cout << "Concluiu" << endl;
				menuInicial->setNumFase(2);
			}
		}
		if (menuInicial->getNumFase() == 2)
		{
			cout << "Entrou Fase 2" << endl;
			fase2->executar();
		}
		cout << "Passou" << endl;
		if (jogador1->getEstaMorto() && jogador2->getEstaMorto())
		{
			cout << "morreu, então volta para o menu!" << endl;
			menuInicial->setRodandoMenu(true);
			jogador1->setEstaMorto(false);				//////////
			jogador1->setVida(500);						//////////
		}
	}
}

void Jogo::inicializar()
{
	jogador1->iniciarVariaveis();
	jogador2->iniciarVariaveis();
}