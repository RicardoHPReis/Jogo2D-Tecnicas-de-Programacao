#include "jogador.h"

void Jogador::inicVariaiveisP()
{
	//VideoMode

	this->videoModeP.height = 1080.f; //RESOLUÇOES
	this->videoModeP.width = 1920.f;
	
	
	//chao

	this->chao.setPosition(0.f, this->videoModeP.height - 85.f);
	this->chao.setSize(Vector2f(this->videoModeP.width, 85.f));

	//logica player

	this->lado = 1;
	this->pulo = false;
	this->xpos = 50.f;
	this->ypos = 50.f;
	this->gravidade = 15.f;
	this->velMax = 13;
	this->xvel = 0.f;
	this->yvel = 0.f;
	this->aT = 0.f;
	this->pAltura = 150.f;
	this->cPos = chao.getPosition();
	this->pPos = player.getPosition();
	this->frame = 0;
	this->velTex = 0;

}

void Jogador::inicPlayerP()
{
	this->player.setSize(Vector2f(100.f, pAltura));
	this->player.setPosition(50.f, 600.f - player.getSize().y);

}

void Jogador::inicTexturasP()
{
	int i;
	
	//texturas Player
	for (i = 0; i < 10; i++) {
		if (!this->tPlayerCorre[i].loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/cavaleiro/Run.png", IntRect(99.f + (i * 580.f), 30.f, 460.f, 660.f))) {
			std::cout << "ERROR";
		}
		this->tPlayerCorre[i].setSmooth(true);

		if (!this->tPlayerPula[i].loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/cavaleiro/Jump.png", IntRect(51.f + (i * 588.f), 30.f, 470.f, 626.f))) {
			std::cout << "ERROR";
		}
		this->tPlayerPula[i].setSmooth(true);

		if (!this->tPlayerParado[i].loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/cavaleiro/Idle.png", IntRect(51.f + (i * 588.f), 30.f, 448.f, 626.f))) {
			std::cout << "ERROR";
		}
		this->tPlayerParado[i].setSmooth(true);

	}

}

Jogador::Jogador() {

	this->inicVariaiveisP();
	this->inicPlayerP();
	this->inicTexturasP();

}

Jogador::~Jogador() {

}

void Jogador::updatePlayer()
{

	//textura no frame
	this->player.setTexture(&tPlayerParado[this->velTex]);

	//oega posicoes importantes
	this->cPos = this->chao.getPosition();
	this->player.setPosition(this->xpos, this->ypos);

	//define para qual lado o player esta virado
	if (this->lado == 0) {
		this->player.setScale(Vector2f(-1, 1));
		this->lado = 2;
	}
	else if (this->lado == 1) {
		this->player.setScale(Vector2f(1, 1));
		this->lado = 2;
	}

	//defina para nao passar a velocidade maxima
	if (this->xvel >= this->velMax) 
		this->xvel = this->velMax;

	//andar para os 2 lados
	if (Keyboard::isKeyPressed(Keyboard::A)) 
		updatePlayerA();
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
		updatePlayerD();
	
	//se nao andar a velocidade é 0 // fica parado
	else 
		this->xvel = 0.f;

	//pulo
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		updatePlayerW();
	}

	else {
		this->pulo = false;
	}

	this->fdist = this->cPos.y - (this->ypos + this->pAltura);

	cair();

	if (this->pulo == true)
		this->aux = 0;

	//limita os frames do pulo
	if (this->aux <= 9) {

		this->player.setTexture(&tPlayerPula[this->aux]);
		if (this->frame % 3 == 0)
			this->aux++;

	}

	updatePlayerTex();

}

void Jogador::updatePlayerA() {

	this->player.setTexture(&tPlayerCorre[this->velTex]);
	this->lado = 0;
	if (this->xpos > this->player.getSize().x) { //Player nao passar dos limites da tela esquerda
		this->xpos -= this->xvel;
		this->xvel += 1.f;
	}


}

void Jogador::updatePlayerD() {

	this->player.setTexture(&tPlayerCorre[this->velTex]);

	this->lado = 1.f;
	if (this->xpos < (this->videoModeP.width - this->player.getSize().x)) {  //Player nao passar dos limites da tela direita
		this->xpos += xvel;
		this->xvel += 1.f;
	}

}

void Jogador::updatePlayerW() {

	if (this->aT <= 10) {
		this->yvel = this->gravidade;
		this->pulo = true;
		if (this->aT >= 10) {
			this->pulo = false;
		}
	}

}

void Jogador::cair() {

	//Atterrisar do pulo
	if (this->fdist <= 0.f && this->pulo == false) {
		this->yvel = 0.f;
		this->aT = 0.f;
		this->pulo = false;
		this->ypos = this->cPos.y - this->pAltura;
	}
	else {
		this->yvel += -1.f;
		this->ypos -= this->yvel;
		this->aT += 1.f;
	}

}

void Jogador::updatePlayerTex() {

	//muda para a proxima textura a cada 7 frames
	if (this->velTex == 9)
		this->velTex = 0;
	if (this->frame % 7 == 0)
		this->velTex++;
	this->frame++;

}


