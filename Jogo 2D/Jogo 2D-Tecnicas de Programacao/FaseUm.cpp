#include "FaseUm.h"

FaseUm::FaseUm():
Fase(1)
{
	iniciaVariaveis();
	iniciaTexturas();
	iniciaFase();

	esqueleto = new Esqueleto();
	jogador = new Jogador();
}

FaseUm::~FaseUm()
{
}

void FaseUm::iniciaVariaveis()
{
	chao.resize(23);
}

void FaseUm::iniciaTexturas()
{
	texturaFundo.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, grafico->getVideo().width, grafico->getVideo().height));
	if (!texturaFundo.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, grafico->getVideo().width, grafico->getVideo().height)))
	{
		cout << "Erro na textura do fundo do mapa.\n";
	}
	texturaFundo.setSmooth(true);
	fundo.setTexture(texturaFundo);

	if (!this->tChao.loadFromFile("../../Texturas/Cenario/Texturas_mapa.png", IntRect(184, 18, 77, 77)))
	{
		cout << "Erro na textura do mapa.\n";
	}
	this->tChao.setSmooth(true);
}

void FaseUm::iniciaFase()
{
	for (int i = 0; i < 23; i++)
	{
		chao[i].setSize(Vector2f(85, 85));
		chao[i].setPosition(0 + (i * chao[0].getSize().x), grafico->getVideo().height - 85.f);
		chao[i].setTexture(&tChao);
	}
}

void FaseUm::atualiza()
{
	jogador->atualizarJogador();
	esqueleto->atualizaInimigo();
}

void FaseUm::desenha()
{
	grafico->limpar();
	grafico->desenharSprite(fundo);
	grafico->desenhar(jogador->getForma());
	grafico->desenhar(esqueleto->getForma());
	grafico->mostrar();
}
