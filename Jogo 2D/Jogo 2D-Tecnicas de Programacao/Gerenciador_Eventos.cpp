#include "Gerenciador_Eventos.h"

/*Gerenciador_Eventos::Gerenciador_Eventos()
{

}

Gerenciador_Eventos::~Gerenciador_Eventos()
{
	if (instancia_eventos)
		delete instancia_eventos;
}

Gerenciador_Eventos* Gerenciador_Eventos::getInstancia_Eventos()
{
	if (!instancia_eventos)
	{
		instancia_eventos = new Gerenciador_Eventos;
	}
	return instancia_eventos;
}

void Gerenciador_Eventos::setJogador(Jogador* player)
{
	jogador = player;
}

void Gerenciador_Eventos::verificaTeclaPressionada(Keyboard::Key tecla)
{
	/*if (menu->getEstaAberto())
	{

	}
	else
	{
		if (tecla == Keyboard::A || tecla == Keyboard::Left)
			jogador->direcionalEsquerdo();
		else if (tecla == Keyboard::D || tecla == Keyboard::Right)
			jogador->direcionalDireito();
		else
			jogador->setVelocidade(Vector2f{ 0.f, getVelocidade().y });

		//pulo 
		if (tecla == Keyboard::W || tecla == Keyboard::Up)
		{
			jogador->
		}
		if (jogador_pulou == true)
		{
			pulo();
		}

		fdist = cPos.y - (posicao.y + tamanho.y);

		//atacar
		if ((Mouse::isButtonPressed(Mouse::Left) || tecla == Keyboard::Space) && atacou == false)
		{
			atacou = true;
			limitadorTex1 = 0;
		}
		if (atacou == true)
		{
			ataque();
		}
		if (atacou == true && jogador_pulou == true)
		{
			ataqueAereo();
		}
		atualizarTextura();
		if (tecla == Keyboard::Escape)
		{

		}
	}
	
}

void Gerenciador_Eventos::verificaTeclaSolta(Keyboard::Key tecla)
{
	//jogador->parar();
}

void Gerenciador_Eventos::executar()
{
	Event evento;
	while (Gerenciador_Grafico::getInstancia_Grafico()->janelaEstaAberta())
	{
		if (evento.type == Event::KeyPressed)
		{
			verificaTeclaPressionada();
		}
		else if (evento.type == Event::KeyReleased)
		{
			verificaTeclaSolta();
		}
		else if (evento.type == Event::Closed)
		{
			Gerenciador_Grafico::getInstancia_Grafico()->fechar();
		}
	}
}*/