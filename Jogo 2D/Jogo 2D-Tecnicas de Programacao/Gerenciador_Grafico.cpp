#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico()
{
	this->inicJanela();
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	delete this->janelaP;
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

	//evento
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

void Gerenciador_Grafico::clear()
{
	this->janelaP->clear();

}

Gerenciador_Grafico& Gerenciador_Grafico::getInstancia()
{
	static Gerenciador_Grafico INSTANCE;
	return INSTANCE;
}
