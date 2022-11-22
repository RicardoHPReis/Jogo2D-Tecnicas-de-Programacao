#include "Pause.h"

Pause::Pause(int i) :
	Ente(i),
	fonte(),
	imagem(),
	fundo()
{
	inicVariaveis();
}

Pause::~Pause()
{
	apertou = false;
	selecao = false;
	delay = 0;
	tempoDelay = 0;
	escolha = 1;
	rodando_pause = true;
	voltar = true;

	if (!escrita.empty())
	{
		for (int i = 0; i < escrita.size(); i++)
		{
			delete& escrita[i];
		}
		escrita.clear();
	}
	if (!coordenadas.empty())
	{
		for (int i = 0; i < coordenadas.size(); i++)
		{
			delete &coordenadas[i];
		}
		coordenadas.clear();
	}
	if (!textos.empty())
	{
		for (int i = 0; i < textos.size(); i++)
		{
			delete& textos[i];
		}
		textos.clear();
	}
	if (!tamanhos.empty())
	{
		for (int i = 0; i < tamanhos.size(); i++)
		{
			delete& tamanhos[i];
		}
		tamanhos.clear();
	}
}

void Pause::inicVariaveis()
{
	apertou = false;
	selecao = false;
	rodando_pause = false;
	voltar = false;

	delay = 0;
	tempoDelay = 15;

	fonte.loadFromFile("../../Fontes/Font.otf");
	imagem.loadFromFile("../../Texturas/Cenario/Pause.jpg");
	fundo.setTexture(imagem);

	textos.resize(3);
	escrita = { "A Floresta","Continuar","Sair" };
	coordenadas = { { 610,200 }, { 610,650 }, { 610,750 } };
	tamanhos = { 100,50,50 };

	for (int i=0; i < textos.size(); i++) 
	{
		textos[i].setFont(fonte);
		textos[i].setString(escrita[i]);
		textos[i].setCharacterSize(tamanhos[i]);
		textos[i].setOutlineColor(Color::Black);
		textos[i].setPosition(coordenadas[i]);
	}

	textos[1].setOutlineThickness(4);
	escolha = 1;
}

void Pause::executar()
{
	bool clique = false;
	while (clique == false)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up) && delay == 0)
		{
			delay++;
			if (escolha != 1 && apertou == false)
			{
				cout << "contiuou!" << endl;
				escolha = 1;
				textos[escolha].setOutlineThickness(4);
				textos[escolha + 1].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && delay == 0)
		{
			delay++;
			if (escolha != 2 && apertou == false)
			{
				cout << "voltou!" << endl;
				escolha = 2;
				textos[escolha].setOutlineThickness(4);
				textos[escolha - 1].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && !selecao)
		{
			selecao = true;
			if (escolha == 1) //RODA JOGO
			{
				clique = true;
				rodando_pause = false;
			}
			else if (escolha == 2) //Volta para o menu
			{
				clique = true;
				rodando_pause = false;
				voltar = true;
			}
		}

		if (delay > 0)
		{
			delay += 1;
			if (delay >= tempoDelay)
				delay = 0;
		}
		imprimir();
	}
}

void Pause::imprimir()
{
	Gerenciador_Grafico::getInstancia_Grafico()->limpar();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[1]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[2]);
	Gerenciador_Grafico::getInstancia_Grafico()->mostrar();
}

const bool Pause::getRodandoPause() const
{
	return rodando_pause;
}

void Pause::setRodandoPause(const bool rodP)
{
	rodando_pause = rodP;
}

const bool Pause::getVoltarMenu() const
{
	return voltar;
}