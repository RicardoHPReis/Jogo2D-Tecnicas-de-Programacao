#include "Gerenciador_Grafico.h"


//Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;

Gerenciador_Grafico::Gerenciador_Grafico()
{
	this->video.height = 1080; //RESOLUÇOES
	this->video.width = 1920;
	this->janela = new RenderWindow(this->video,
		"Game 1", Style::Titlebar |
		Style::Close);

	this->janela->setFramerateLimit(60); //limite FPS
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	delete this->janela;
	//delete instancia_grafico;
}

/*static Gerenciador_Grafico* getInstancia_Grafico()
{
	if (!instancia_grafico)
	{
		instancia_grafico = new Gerenciador_Grafico;
	}
	return instancia_grafico;
}*/


void Gerenciador_Grafico::setJanela(RenderWindow* window)
{
	janela = window;
}

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

/*void Gerenciador_Grafico::setTextura(const Texture tx)
{
	textura = tx;
}

const Texture Gerenciador_Grafico::getTextura() const
{
	return textura;
}*/

/*void setSprite(const Sprite sp)
{
	sprite = sp;
}

const Sprite getSprite() const
{
	return sprite;
}*/

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