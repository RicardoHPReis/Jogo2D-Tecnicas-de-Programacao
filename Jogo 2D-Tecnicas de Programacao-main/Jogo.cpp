#include "Jogo.h"

//contrutores / destrutores
Jogo::Jogo()
{

	this->inicVariaiveis();
	this->inicMapa();
	this->inicTexturas();

	this->inimigo = new Inimigo();
	this->jogador = new Jogador();
	this->Tela = new Ente();
}

Jogo::~Jogo()
{
	delete this->inimigo;
	delete this->menuP;
	delete this->jogador;
	delete this->Tela;
}

void Jogo::inicVariaiveis()
{
	this->menuP = new Menu();
	//logica jogo
	this->menuAbre = true;

	this->points = 0;
	this->baixo = true;

}

void Jogo::inicTexturas()
{
	int i;

	//textura fundo
	this->tBg.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, this->videoMode.width, this->videoMode.height));
	this->tBg.setSmooth(true);
	this->fundo.setTexture(tBg);

}

void Jogo::inicMapa()
{
	//chao

	this->chao.setPosition(0, videoMode.height - 85.f);
	this->chao.setSize(Vector2f((videoMode.width), 85));
	chao.setFillColor(Color::White);

}

//accesos

const bool Jogo::rodando() const
{
	if ((Tela->getAberta()) == 1)
		return 1;
	else
		return 0;
}

//funcoes

void Jogo::atualizaMenu()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->menuAbre = true;
	}
}

void Jogo::update()
{
	if (menuAbre == true) {
		this->menuP->run_menu();
		menuAbre = false;
	}

	this->atualizaMenu();

	this->jogador->atualizarJogador();

	this->inimigo->atualizaInimigo();

	this->render();
}

void Jogo::render()
{
	this->Tela->clear();

	this->Tela->executarSprite(fundo);

	this->Tela->executar(this->jogador->obj);

	this->Tela->executar(this->inimigo->inimigo);

	this->Tela->display();
}
