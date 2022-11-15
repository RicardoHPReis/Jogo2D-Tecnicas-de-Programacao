#include "Gerenciador_Grafico.h"


Gerenciador_Grafico::Gerenciador_Grafico()
{
	janela = nullptr;
	video.height = 1080;
	video.width = 1920;
	janela = new RenderWindow(video, "Game 1", Style::Titlebar | Style::Fullscreen);
	janela->setMouseCursorVisible(false);
	janela->setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	video = { 0, 0 };
	if (janela)
		delete janela;
	if (instancia_grafico)
		delete instancia_grafico;
}

Gerenciador_Grafico* Gerenciador_Grafico::getInstancia_Grafico()
{
	if (!instancia_grafico)
	{
		instancia_grafico = new Gerenciador_Grafico;
	}
	return instancia_grafico;
}

void Gerenciador_Grafico::pollEvents()
{
	Event evento;
	while (janela->pollEvent(evento))
	{
		switch (evento.type)
		{
			case Event::Closed:
				janela->close();
				break;
			case Event::KeyPressed:
				if (evento.key.code == Keyboard::Escape)
					janela->close();
				break;
		}
	}
}

void Gerenciador_Grafico::desenhar(RectangleShape retangulo)
{
	janela->draw(retangulo);
}

void Gerenciador_Grafico::desenharTexto(Text texto)
{
	janela->draw(texto);
}

void Gerenciador_Grafico::desenharSprite(Sprite sprite)
{
	janela->draw(sprite);
}

void Gerenciador_Grafico::limpar()
{
	janela->clear();
}

void Gerenciador_Grafico::mostrar()
{
	janela->display();
}

void Gerenciador_Grafico::fechar()
{
	janela->close();
}

RenderWindow* Gerenciador_Grafico::getJanela()
{
	return janela;
}

bool Gerenciador_Grafico::janelaEstaAberta()
{
	if (janela)
		return true;
	else
		return false;
}

VideoMode Gerenciador_Grafico::getVideo()
{
	return video;
}