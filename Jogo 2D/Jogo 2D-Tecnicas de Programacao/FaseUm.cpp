#include "FaseUm.h"

FaseUm::FaseUm(int i):
Fase(i)
{
	jogador = new Jogador();

	iniciaVariaveis();
	iniciaTexturas();
	iniciaFase();
}

FaseUm::~FaseUm()
{
	delete jogador;
}

void FaseUm::iniciaVariaveis()
{
	chao.resize(23);
	vidasSp.resize(5);
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

	tVidas.loadFromFile("../../Texturas/Cenario/Vida.png");
	if (!tVidas.loadFromFile("../../Texturas/Cenario/Vida.png"))
	{
		cout << "Erro na textura dos corações da vida.\n";
	}
	tVidas.setSmooth(true);
	for (size_t i{}; i < 5; ++i)
	{
		vidasSp[i].setTexture(tVidas);
		vidasSp[i].setPosition(Vector2f((30.f) + (50 * i), 10.f));
	}
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
	morcego->atualizaInimigo();
	esqueleto->atualizaInimigo();
	jogador->atualizaJogador();

}

void FaseUm::atualizaVidas()
{
	for (int i = 0; i < 5; i++)
	{
		grafico->desenharSprite(vidasSp[i]);
	}

	//se sofrer dano
	//this->jogador->status.setVidas(this->jogador->status.getVidas()--);

	//se ganhar uma vida
	//this->jogador->status.setVidas(this->jogador->status.getVidas()++);
}

void FaseUm::desenhar()
{
	grafico->limpar();

	grafico->desenharSprite(fundo);
	grafico->desenhar(esqueleto->getForma());
	grafico->desenhar(jogador->getForma());
	grafico->desenhar(morcego->getForma());

	atualizaVidas();
	grafico->mostrar();
}
