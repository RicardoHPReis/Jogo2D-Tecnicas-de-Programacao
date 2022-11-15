#include "Gerenciador_Grafico.h"


Gerenciador_Grafico::Gerenciador_Grafico()
{
	inicJanela();
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	videoMode = { 0, 0 };
	if (janelaP)
		delete janelaP;
	if (instancia_grafico)
		delete instancia_grafico;
}

void Gerenciador_Grafico::inicJanela()
{
	this->janelaP = nullptr;

	this->videoMode.height = 1080; //RESOLU�OES
	this->videoMode.width = 1920;
	this->janelaP = new RenderWindow(this->videoMode,
		"Game 1", Style::Titlebar |
		Style::Fullscreen);
	this->janelaP->setMouseCursorVisible(false);
	this->janelaP->setFramerateLimit(60); //limite FPS
}

void Gerenciador_Grafico::pollEvents()
{
	while (this->janelaP->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
			case Event::Closed:
				this->janelaP->close();
				break;
			case Event::KeyPressed:
				if (this->ev.key.code == Keyboard::Escape)
					this->janelaP->close();
				break;
		}
	}
}

void Gerenciador_Grafico::desenhar(RectangleShape* tela)
{
	this->janelaP->draw(*tela);
}

void Gerenciador_Grafico::desenharT(Text* tela)
{
	this->janelaP->draw(*tela);
}

void Gerenciador_Grafico::desenharS(Sprite* tela)
{
	this->janelaP->draw(*tela);
}

void Gerenciador_Grafico::limpar()
{
	this->janelaP->clear();
}

void Gerenciador_Grafico::mostrar()
{
	this->janelaP->display();
}

void Gerenciador_Grafico::fechar()
{
	this->janelaP->close();
}

RenderWindow* Gerenciador_Grafico::getJanela()
{
	return janelaP;
}

Gerenciador_Grafico* Gerenciador_Grafico::getInstancia_Grafico()
{
	if (!instancia_grafico)
	{
		instancia_grafico = new Gerenciador_Grafico;
	}
	return instancia_grafico;
}

bool Gerenciador_Grafico::janelaEstaAberta()
{
	if (janelaP)
		return true;
	else
		return false;
}