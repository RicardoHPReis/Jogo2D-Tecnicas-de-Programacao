#include "Fase.h"

Fase::Fase() :
Ente()
{
	this->inicVariaveis();
	this->inicVidas();
	this->inicTexturas();
	this->iniciaFase();

	this->inimigo = new Inimigo();
	this->jogador = new Jogador();
	this->Tela = new Ente();
}

Fase::~Fase()
{
	delete this->inimigo;
	delete this->jogador;
	delete this->Tela;
}

void Fase::inicVariaveis()
{
	this->vidasN = 5;
	this->vidas.resize(this->vidasN);
	
	this->chao.resize(23);
}

void Fase::inicVidas()
{
	this->tVidas.loadFromFile("../../Texturas/Cenario/Vida.png");
	this->tVidas.setSmooth(true);

	//textura vidas

	for (size_t i{}; i < vidas.size(); ++i) {

		this->vidas[i].setTexture(tVidas);
		this->vidas[i].setPosition(Vector2f((30.f) + (50 * i), 10.f));

	}
}

void Fase::inicTexturas()
{
	int i;

	//textura fundo
	this->tBg.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, this->videoMode.width, this->videoMode.height));
	this->tBg.setSmooth(true);
	this->fundo.setTexture(tBg);

	//
	if (!this->tChao.loadFromFile("../../Texturas/Cenario/Texturas_mapa.png", IntRect(184, 18, 77, 77))) {
		cout << "ERROR";
	}
	this->tChao.setSmooth(true);
}

void Fase::iniciaFase()
{
	
	for (int i = 0; i < 23; i++)
	{
		this->chao[i].setSize(Vector2f(85, 85));
		this->chao[i].setPosition(0 + (i * chao[0].getSize().x), videoMode.height - 85.f);
		this->chao[i].setTexture(&tChao);
	}

}

void Fase::atualiza()
{
	this->jogador->atualizarJogador();

	this->inimigo->atualizaInimigo();
}

void Fase::imprimeVidas()
{
	for (int i = 0; i < this->jogador->getVidas(); i++)
	{
		this->Tela->executarSprite(this->vidas[i]);
	}
}

void Fase::desenha()
{
	this->Tela->clear();

	this->Tela->executarSprite(fundo);

	this->imprimeVidas();

	this->Tela->executar(this->jogador->player);

	this->Tela->executar(this->inimigo->esqueleto);

	this->Tela->display();
}
