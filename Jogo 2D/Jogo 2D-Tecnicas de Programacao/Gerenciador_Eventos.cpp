#include "Gerenciador_Eventos.h"

/*
Gerenciador_Eventos::Gerenciador_Eventos()
{
	menuInicial = NULL;
	//menuMorte = NULL;
	menuPause = NULL;
	//menuVencedor = NULL;
	jogador = NULL;
	jogador2 = NULL;
}

Gerenciador_Eventos::~Gerenciador_Eventos()
{
}

Gerenciador_Eventos* Gerenciador_Eventos::getInstancia_Eventos()
{
	if (!instancia_eventos)
	{
		instancia_eventos = new Gerenciador_Eventos;
	}
	return instancia_eventos;
}

void deletarInstancia_Eventos()
{
	//if (instancia_eventos)
		//delete instancia_eventos;
}

void Gerenciador_Eventos::setJogador(Jogador* player)
{
	jogador = player;
}


void Gerenciador_Eventos::verificaTeclaPressionada(Keyboard::Key tecla)
{
	if (menuInicial->getRodandoMenu())
	{

	}
	else if (menuMorte->getRodandoMenu())
	{
		
	}
	else if (menuPause->getRodandoMenu())
	{

	}
	else if (menuVencedor->getRodandoMenu())
	{

	}
	else
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			jogador->direcionalEsquerdo();
		}

		else if (Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			jogador->direcionalDireito();
		}

		//pulo 
		if (Keyboard::isKeyPressed(Keyboard::W) && jogador->getPulou() == false)
		{
			limitadorTex_pulando = 0;
			jogador->setVelocidade({ jogador->getVelocidade().x,velocidade.y - forcaPulo});
			jogador_pulou = true;
		}

		//cair
		if (jogador_pulou == true)
		{
			jogador->pulo();
		}

		//atacar
		if ((Keyboard::isKeyPressed(Keyboard::Space) || Mouse::isButtonPressed(Mouse::Left)) && jogador->getAtaque() == false)
		{
			jogador->setAtaque(true);
			limitadorTex_ataque = 0;
		}
		if (jogador->getAtaque())
		{
			jogador->ataque();
		}

		if (menuInicial->getNumJogadores() == 2)
		{

		}
	}
}

void Gerenciador_Eventos::verificaTeclaSolta(Keyboard::Key tecla)
{
	jogador->parar();
}

void Gerenciador_Eventos::executar()
{
	Event evento;
	while (Gerenciador_Grafico::getInstancia_Grafico()->janelaEstaAberta())
	{
		if (evento.type == Event::KeyPressed)
		{
			verificaTeclaPressionada(evento.key.code);
		}
		else if (evento.type == Event::KeyReleased)
		{
			verificaTeclaSolta(evento.key.code);
		}
		else if (evento.type == Event::Closed)
		{
			Gerenciador_Grafico::getInstancia_Grafico()->fechar();
		}
	}
}

void teclasJogadorUm(Keyboard::Key tecla)
{

}
void teclasJogadorDois(Keyboard::Key tecla)
{

}

void teclasMenuInicial(Keyboard::Key tecla)
{

}

/*void teclasMenuMorte(Keyboard::Key tecla);
{

}

void teclasMenuVencedor(Keyboard::Key tecla)
{

}

void teclasMenuPause(Keyboard::Key tecla)
{

}*/