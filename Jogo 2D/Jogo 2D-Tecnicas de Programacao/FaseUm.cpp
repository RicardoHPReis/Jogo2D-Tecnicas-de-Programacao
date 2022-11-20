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
	vidasSp.resize(5);
}

void FaseUm::iniciaTexturas()
{
	texturaFundo.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, Gerenciador_Grafico::getInstancia_Grafico()->getVideo().width, Gerenciador_Grafico::getInstancia_Grafico()->getVideo().height));
	if (!texturaFundo.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, Gerenciador_Grafico::getInstancia_Grafico()->getVideo().width, Gerenciador_Grafico::getInstancia_Grafico()->getVideo().height)))
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
	//criarPlataformas(Vector2f(0.f, 995.f), Vector2f(85, 85));
	criarJogador(Vector2f(), jogador);
	for (int i = 0; i < 3; i++)
	{
		criarPlataformas(Vector2f{ (i * 85.f), Gerenciador_Grafico::getInstancia_Grafico()->getVideo().height - 85.f }, Vector2f(85.f, 1920.f));
	}
	for (int i = 0; i < 2; i++)
	{
		//criarEsqueletos(Vector2f(900 * (i+1), 795));
		//criarMorcego(Vector2f(365 * (i + 1), 400));
	}
}

void FaseUm::executar()
{
	listaEntidades.atualizarEntidade();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador->getForma());
	listaEntidades.desenharEntidades();

	atualizaVidas();
}

void FaseUm::atualizaVidas()
{
	for (int i = 0; i < 5; i++)
	{
		Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(vidasSp[i]);
	}

	//se sofrer dano
	//this->jogador->status.setVidas(this->jogador->status.getVidas()--);

	//se ganhar uma vida
	//this->jogador->status.setVidas(this->jogador->status.getVidas()++);
}
