


#include "Inimigo.h"

Inimigo::Inimigo()
{
	this->Tela = new Ente();
	this->status = new Personagem();
	this->iniciarStatus();
	this->iniciarTexturas();
	this->inicEnemies();
	this->spawnInimigo();
	this->nocivo = true;
}

Inimigo::~Inimigo()
{
	delete this->Tela;
	delete this->status;
	nocivo = false;
}

void Inimigo::iniciarStatus()
{
	this->status->setVidas(15);
	this->status->setLado(2);
	this->status->setPodeAtacar(true);
	this->status->setEstaAndando(false);
	this->status->setEstaParado(false);
	this->status->setAtaque(false);
	this->status->setDano(1);
	this->status->setVelocidadeMaxima(6);

	this->status->setVelocidadeX(7.f);
	this->status->setVelocidadeY(0.f);
}

void Inimigo::inicEnemies()
{

	this->videoModeE.height = 1080; //RESOLU�OES
	this->videoModeE.width = 1920;


	xpos = 1700;
	ypos = 795;
	this->esqueleto.setSize(Vector2f(150.f, 200.f));

	//chao

	this->chao.setPosition(0.f, this->videoModeE.height - 85.f);
	this->chao.setSize(Vector2f(this->videoModeE.width, 85));
}

void Inimigo::spawnInimigo()
{
	this->esqueleto.setPosition(this->videoModeE.width - 200.f, this->chao.getPosition().y - this->esqueleto.getSize().y);
}

void Inimigo::iniciarTexturas()
{

	// Texturas inimigo Parado

	if (!this->tEnemy[0].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20, 0, 270, 386))) {
		std::cout << "ERROR";
	}
	tEnemy[0].setSmooth(true);

	for (int i = 0; i < 10; i++) {

		if (!this->tEnemy[i + 1].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20 + ((i + 1) * 290), 0, 270, 386))) {
			std::cout << "ERROR";
		}
		tEnemy[i + 1].setSmooth(true);
	}

	// Texturas inimigo Andando
	
	for (int i = 0; i < 13; i++) {

		if (!this->tEnemyAnda[i].loadFromFile("../../Texturas/Personagens/Esqueleto/Andar.png", IntRect((i * 256.69), 0, 256.69, 385))) {
			std::cout << "ERROR";
		}
		tEnemyAnda[i].setSmooth(true);
	}
}


void Inimigo::atualizaInimigo()
{
	this->esqueleto.setPosition(xpos, ypos);

	this->andar();

	this->atualizaTextura();
	this->esqueleto.setTexture(&tEnemyAnda[velTex1]);
}

void Inimigo::atualizaTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (this->velTex1 == 12)
		this->velTex1 = 0;
	if (this->frame1 % 7 == 0)
		this->velTex1++;
	this->frame1++;
}


void Inimigo::andar()
{
	if (this->status->getLado() == 2)
	{
		this->andarEsq();
		this->esqueleto.setScale(Vector2f(-1, 1));
	}

	else if(this->status->getLado() == 1)
	{

		this->esqueleto.setScale(Vector2f(1, 1));

		this->andarDir();
	}

}

void Inimigo::andarDir()
{
	if (this->xpos <= 1920.f - 250.f) { //Player nao passar dos limites da tela esquerda
		this->xpos = xpos + (this->status->getVelocidadeX());
	}
	else
	{
		this->status->setLado(2);
	}
}

void Inimigo::andarEsq()
{
	if (this->xpos >= 100.f ) { //Player nao passar dos limites da tela esquerda
		this->xpos = xpos - (this->status->getVelocidadeX());
	}
	else
	{
		this->status->setLado(1);
	}
}

