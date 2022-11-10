#include "Inimigo.h"

Inimigo::Inimigo()
{
	this->Tela = new Ente();
	this->iniciarTexturas();
	this->inicEnemies();
	this->nocivo = true;
}

Inimigo::~Inimigo()
{
	delete this->Tela;
	nocivo = false;
}

void Inimigo::inicEnemies()
{

	this->videoModeE.height = 1080; //RESOLU�OES
	this->videoModeE.width = 1920;


	this->inimigo.setPosition(10, 10);
	this->inimigo.setSize(Vector2f(150.f, 200.f));

	//chao

	this->chao.setPosition(0.f, this->videoModeE.height - 85.f);
	this->chao.setSize(Vector2f(this->videoModeE.width, 85));
}

void Inimigo::spawnInimigo()
{
	this->inimigo.setPosition(this->videoModeE.width - 200.f, this->chao.getPosition().y - this->inimigo.getSize().y);
}

void Inimigo::iniciarTexturas()
{
	if (!this->tEnemy[0].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20, 0, 270, 386))) {
		std::cout << "ERROR";
	}
	tEnemy[0].setSmooth(true);

	//texturas Player
	for (int i = 0; i < 10; i++) {

		//textura inimigo
		if (!this->tEnemy[i + 1].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20 + ((i + 1) * 290), 0, 270, 386))) {
			std::cout << "ERROR";
		}
		tEnemy[i + 1].setSmooth(true);
	}
}

void Inimigo::atualizaInimigo()
{
	/*
		@return void
		Update inimigo tempo de spawn e
		quando o total de inimigos � menor que o maximo
		-mover inimigos para baixo e cima
		-remover inimigos no limite da tela
	*/

	this->spawnInimigo();

	this->inimigo.setTexture(&tEnemy[velTex1]);

	//muda para a proxima textura a cada 7 frames
	if (this->velTex1 == 10)
		this->velTex1 = 0;
	if (this->frame1 % 7 == 0)
		this->velTex1++;
	this->frame1++;
}
