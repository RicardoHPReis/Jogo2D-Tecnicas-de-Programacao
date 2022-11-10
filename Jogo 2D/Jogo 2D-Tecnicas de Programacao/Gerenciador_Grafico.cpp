#include "Gerenciador_Grafico.h"


Gerenciador_Grafico::Gerenciador_Grafico()
{
	video.height = 1080;
	video.width = 1920;

	janela = new RenderWindow (video, "Jogo 2D", Style::Titlebar | Style::Close);
	if (!janela)
	{
		cout << "Erro na criação da janela!" << endl;
		exit(1);
	}
	janela->setFramerateLimit(60);
	executarJanela();

	instancia_grafico->getInstancia_Grafico();
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	video = { 0, 0 };
	if(janela)
		delete janela;
	if (instancia_grafico)
		delete instancia_grafico;
}

static Gerenciador_Grafico* Gerenciador_Grafico::getInstancia_Grafico()
{
	if (!instancia_grafico)
	{
		instancia_grafico = new Gerenciador_Grafico;
	}
	return instancia_grafico;
}

const RenderWindow* Gerenciador_Grafico::getJanela() const
{
	return janela;
}

void Gerenciador_Grafico::executarJanela()
{
	while (instancia_grafico->janelaEstaAberta())
	{
		Event evento;
		if (instancia_grafico->getJanela()->pollEvent(evento))
		{
			switch (evento.type)
			{
				case Event::Closed:
					this->janela->close();
					break;
				case Event::KeyPressed:
					if (evento.key.code == Keyboard::Escape)
					{
						this->janela->close();
						break;
					}
			}
		}
	}
}

const bool Gerenciador_Grafico::janelaEstaAberta()
{
	while (janela->isOpen())
		return true;
	return false;
}


void Gerenciador_Grafico::desenhar(RectangleShape* figura)
{
	this->janela->draw(*figura);
	this->janela->display();
}


void Gerenciador_Grafico::fechar()
{
	this->janela->clear();
}