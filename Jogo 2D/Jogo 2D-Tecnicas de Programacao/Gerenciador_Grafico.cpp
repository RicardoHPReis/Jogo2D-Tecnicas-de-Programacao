#include "Gerenciador_Grafico.h"


Gerenciador_Grafico::Gerenciador_Grafico()
{
	video.height = 1080;
	video.width = 1920;

	janela = new RenderWindow(video, "Jogo 2D", Style::Titlebar | Style::Close);
	if (!janela)
	{
		cout << "Erro na criação da janela!" << endl;
		exit(1);
	}
	janela->setFramerateLimit(60);
	executarJanela();
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

const RenderWindow* Gerenciador_Grafico::getJanela() const
{
	return janela;
}

const bool Gerenciador_Grafico::janelaEstaAberta()
{
	return janela->isOpen();
}

void Gerenciador_Grafico::desenhar(Drawable* figura)
{
	janela->draw(*figura);
}

void Gerenciador_Grafico::mostrar()
{
	janela->display();
}

void Gerenciador_Grafico::limpar()
{
	janela->clear();
}

void Gerenciador_Grafico::fechar()
{
	janela->close();
}

Vector2u Gerenciador_Grafico::getTamanhoJanela()
{
	return janela->getSize();
}

void Gerenciador_Grafico::executarJanela()
{
	while (janelaEstaAberta())
	{
		Event evento;
		if (this->janela->pollEvent(evento))
		{
			switch (evento.type)
			{
			case Event::Closed:
				fechar();
				break;
			case Event::KeyPressed:
				if (evento.key.code == Keyboard::Escape)
				{
					fechar();
					break;
				}
			}
		}
	}
}