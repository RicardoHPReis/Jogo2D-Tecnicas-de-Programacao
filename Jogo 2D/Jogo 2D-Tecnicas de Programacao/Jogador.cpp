#include "Jogador.h"

void Jogador::iniciarVariaiveis()
{
	//VideoMode

	this->videoModeP.height = 1080.f; //RESOLUÇOES
	this->videoModeP.width = 1920.f;


	//chao

	this->chao.setPosition(0.f, this->videoModeP.height - 85.f);
	this->chao.setSize(Vector2f(this->videoModeP.width, 85.f));

	//logica player

	this->lado = 1;
	this->jogador_pulou = false;
	this->xpos = 50.f;
	this->ypos = 50.f;
	this->gravidade = 15.f;
	this->velMax = 13;
	this->xvel = 0.f;
	this->yvel = 0.f;
	this->aT = 0.f;
	this->pAltura = 150.f;
	this->cPos = chao.getPosition();
	this->pPos = jogador.getPosition();
	this->frame = 0;
	this->velTex = 0;

}

void Jogador::iniciarJogador()
{
	this->jogador.setSize(Vector2f(100.f, pAltura));
	this->jogador.setPosition(50.f, 600.f - jogador.getSize().y);

}

void Jogador::iniciarTexturas()
{
	int i;

	//texturas Player
	for (i = 0; i < 10; i++) {
		if (!this->txJogadorCorre[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Correr.png", IntRect(99.f + (i * 580.f), 30.f, 460.f, 660.f))) {
			std::cout << "ERROR";
		}
		this->txJogadorCorre[i].setSmooth(true);

		if (!this->txJogadorPula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Pular.png", IntRect(51.f + (i * 588.f), 30.f, 470.f, 626.f))) {
			std::cout << "ERROR";
		}
		this->txJogadorPula[i].setSmooth(true);

		if (!this->txJogadorParado[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Parado.png", IntRect(51.f + (i * 588.f), 30.f, 448.f, 626.f))) {
			std::cout << "ERROR";
		}
		this->txJogadorParado[i].setSmooth(true);
	}
}

Jogador::Jogador() {

	this->iniciarVariaiveis();
	this->iniciarJogador();
	this->iniciarTexturas();
}

Jogador::~Jogador() 
{

}

void Jogador::atualizarJogador()
{

	//textura no frame
	this->jogador.setTexture(&txJogadorParado[this->velTex]);

	//oega posicoes importantes
	this->cPos = this->chao.getPosition();
	this->jogador.setPosition(this->xpos, this->ypos);

	//define para qual lado o player esta virado
	if (this->lado == 0) {
		this->jogador.setScale(Vector2f(-1, 1));
		this->lado = 2;
	}
	else if (this->lado == 1) {
		this->jogador.setScale(Vector2f(1, 1));
		this->lado = 2;
	}

	//defina para nao passar a velocidade maxima
	if (this->xvel >= this->velMax)
		this->xvel = this->velMax;

	//andar para os 2 lados
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		direcionalEsquerdo();

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		direcionalDireito();

	//se nao andar a velocidade é 0 // fica parado
	else
		this->xvel = 0.f;

	//pulo
	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) {
		direcionalCima();
	}

	else {
		this->jogador_pulou = false;
	}

	this->fdist = this->cPos.y - (this->ypos + this->pAltura);

	cair();

	if (this->jogador_pulou == true)
		this->limitadorTex = 0;

	//limita os frames do pulo
	if (this->limitadorTex <= 9) {

		this->jogador.setTexture(&txJogadorPula[this->limitadorTex]);
		if (this->frame % 3 == 0)
			this->limitadorTex++;

	}

	atualizarTextura();

}

void Jogador::direcionalEsquerdo() {

	this->jogador.setTexture(&txJogadorCorre[this->velTex]);
	this->lado = 0;
	if (this->xpos > this->jogador.getSize().x) { //Player nao passar dos limites da tela esquerda
		this->xpos -= this->xvel;
		this->xvel += 1.f;
	}


}

void Jogador::direcionalDireito() {

	this->jogador.setTexture(&txJogadorCorre[this->velTex]);

	this->lado = 1.f;
	if (this->xpos < (this->videoModeP.width - this->jogador.getSize().x)) {  //Player nao passar dos limites da tela direita
		this->xpos += xvel;
		this->xvel += 1.f;
	}

}

void Jogador::direcionalCima() {

	if (this->aT <= 10) {
		this->yvel = this->gravidade;
		this->jogador_pulou = true;
		if (this->aT >= 10) {
			this->jogador_pulou = false;
		}
	}

}

void Jogador::cair() {

	//Atterrisar do pulo
	if (this->fdist <= 0.f && this->jogador_pulou == false) {
		this->yvel = 0.f;
		this->aT = 0.f;
		this->jogador_pulou = false;
		this->ypos = this->cPos.y - this->pAltura;
	}
	else {
		this->yvel += -1.f;
		this->ypos -= this->yvel;
		this->aT += 1.f;
	}

}

void Jogador::atualizarTextura() {

	//muda para a proxima textura a cada 7 frames
	if (this->velTex == 9)
		this->velTex = 0;
	if (this->frame % 7 == 0)
		this->velTex++;
	this->frame++;
}