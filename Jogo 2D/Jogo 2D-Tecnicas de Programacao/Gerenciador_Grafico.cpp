#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico()
{
	this->inicJanela();
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	delete this->janela;
}


void Gerenciador_Grafico::setTextura(const Texture tx)
{
	textura = tx;
}

const Texture Gerenciador_Grafico::getTextura() const
{
	return textura;
}

/*void Gerenciador_Grafico::setJanela(const RenderWindow* window)
{
	janela = window;
}*/

const RenderWindow* Gerenciador_Grafico::getJanela() const
{
	return janela;
}

void Gerenciador_Grafico::setVideo(const VideoMode vdm)
{
	video = vdm;
}
const VideoMode Gerenciador_Grafico::getVideo() const
{
	return video;
}

void Gerenciador_Grafico::setEvento(const Event ev)
{
	evento = ev;
}

const Event Gerenciador_Grafico::getEvento() const
{
	return evento;
}



void Gerenciador_Grafico::inicJanela()
{
	this->video.height = 1080; //RESOLUÇOES
	this->video.width = 1920;
	this->janela = new RenderWindow(this->video,
		"Game 1", Style::Titlebar |
		Style::Close);

	this->janela->setFramerateLimit(60); //limite FPS
}


void Gerenciador_Grafico::pollEvents()
{
	//evento
	while (this->janela->pollEvent(this->evento))
	{
		switch (this->evento.type)
		{
			case Event::Closed:
				this->janela->close();
				break;
			case Event::KeyPressed:
				if (this->evento.key.code == Keyboard::Escape)
				this->janela->close();
				break;
		}
	}
}


int Gerenciador_Grafico::aberta()
{
	while (janela->isOpen())
		return 1;
	return 0;
}


void Gerenciador_Grafico::desenhar(RectangleShape* tela)
{
	this->janela->draw(*tela);
	this->janela->display();
}


void Gerenciador_Grafico::fechar()
{
	this->janela->clear();
}