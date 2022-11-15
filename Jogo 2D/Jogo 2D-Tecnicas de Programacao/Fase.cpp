#include "Fase.h"


Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Fase::Fase():
	colisao(colisao->getInstancia_Colisoes()),
	listaEntidades(),
	listaObstaculos(),
	listaPersonagens()
{
	this->inicVariaveis();
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
	this->chao.resize(23);
}

void Fase::inicTexturas()
{
	int i;
	TexturaFundo.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, this->videoMode.width, this->videoMode.height));
	if (!TexturaFundo.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, this->videoMode.width, this->videoMode.height)))
	{
		cout << "Erro na textura do fundo do mapa.\n";
	}
	TexturaFundo.setSmooth(true);
	fundo.setTexture(TexturaFundo);

	if (!this->tChao.loadFromFile("../../Texturas/Cenario/Texturas_mapa.png", IntRect(184, 18, 77, 77))) 
	{
		cout << "Erro na textura do mapa.\n";
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

void Fase::desenha()
{
	this->Tela->clear();

	this->Tela->executarSprite(fundo);

	this->Tela->executar(jogador->getForma());

	this->Tela->executar(this->inimigo->inimigo);

	this->Tela->display();
}

void calculaQueda()
{

}