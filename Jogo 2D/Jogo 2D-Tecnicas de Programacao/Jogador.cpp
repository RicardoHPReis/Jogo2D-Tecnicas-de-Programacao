#include "Jogador.h"

Jogador::Jogador()
{
	this->Tela = new Ente();
	this->iniciarVariaiveis();
	this->iniciarJogador();
	this->iniciarStatus();
	this->iniciarTexturas();
}

Jogador::~Jogador()
{
	delete this->Tela;
}

void Jogador::iniciarStatus()
{
	this->status.setVidas(5);
	this->status.setLado(1);
	this->status.setPodeAtacar(true);
	this->status.setAtaque(false);
	this->status.setDano(1);
	this->status.setVelocidadeMaxima(13);

	this->status.setVelocidadeX(0.f);
	this->status.setVelocidadeY(0.f);
}

void Jogador::iniciarVariaiveis()
{

	//VideoMode

	this->videoModeP.height = 1080; //RESOLU�OES
	this->videoModeP.width = 1920;


	//chao

	this->chao.setPosition(0.f, this->videoModeP.height - 85.f);
	this->chao.setSize(Vector2f(this->videoModeP.width, 85));

	//logica player

	this->jogador_pulou = false;
	this->xpos = 50.f;
	this->ypos = 50.f;
	this->gravidade = 15.f;
	this->aT = 0.f;
	this->pAltura = 150.f;
	this->cPos = chao.getPosition();
	this->pPos = player.getPosition();
	this->frame = 0;
	this->velTex = 0;

	this->tempoDelay = 10;
}

void Jogador::iniciarJogador()
{
	this->player.setSize(Vector2f(100.f, pAltura));
	this->player.setPosition(50.f, 600.f - player.getSize().y);

}

void Jogador::iniciarTexturas()
{
	int i;

	//texturas Player
	for (i = 0; i < 10; i++) {
		if (!this->txJogadorCorre[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Correr.png", IntRect(99 + (i * 580), 30, 460, 660))) {
			std::cout << "ERROR";
		}
		this->txJogadorCorre[i].setSmooth(true);

		if (!this->txJogadorPula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Pular.png", IntRect(51 + (i * 588), 30, 470, 626))) {
			std::cout << "ERROR";
		}
		this->txJogadorPula[i].setSmooth(true);

		if (!this->txJogadorParado[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Parado.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "ERROR";
		}
		this->txJogadorParado[i].setSmooth(true);

		if (!this->txJogadorAtaque[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Atacar.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "ERROR";
		}

		this->txJogadorAtaque[i].setSmooth(true);
		if (!this->txJogadorAtaquePula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/AtaquePulo.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "ERROR";
		}
		this->txJogadorAtaquePula[i].setSmooth(true);
	}
}

void Jogador::atualizarJogador()
{

	//textura no frame
	this->player.setTexture(&txJogadorParado[this->velTex]);

	//oega posicoes importantes
	this->cPos = this->chao.getPosition();
	this->player.setPosition(this->xpos, this->ypos);

	//define para qual lado o player esta virado
	if (this->status.getLado() == 0) {
		this->player.setScale(Vector2f(-1, 1));
		this->status.setLado(2);
	}
	else if (this->status.getLado() == 1) {
		this->player.setScale(Vector2f(1, 1));
		this->status.setLado(2);
	}

	//defina para nao passar a velocidade maxima
	if (this->status.getVelocidadeX() >= this->status.getVelocidadeMaxima())
		this->status.setVelocidadeX(this->status.getVelocidadeMaxima());

	//andar para os 2 lados
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		direcionalEsquerdo();

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		direcionalDireito();

	//se nao andar a velocidade � 0 // fica parado
	else
		this->status.setVelocidadeX(0.f);
	
	//atacar

	if (Mouse::isButtonPressed(Mouse::Left) && this->delay == 0) {
		delay = 1;
	}

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

		this->player.setTexture(&txJogadorPula[this->limitadorTex]);
		if (this->frame % 3 == 0)
			this->limitadorTex++;

	}

	if (this->status.getAtaque() == true && this->jogador_pulou == true) 
	{
		ataqueAereo();
	}

	if (this->status.getAtaque() == true && this->jogador_pulou == false)
	{
		ataque();
	}

	if (this->delay > 0) {
		this->status.setAtaque(true);
		this->delay += 1;
		if (this->delay >= this->tempoDelay) {
			this->delay = 0;
			this->status.setAtaque(false);
		}
	}

	atualizarTextura();

}

void Jogador::ataque()
{
	this->player.setTexture(&txJogadorAtaque[this->velTex]);
}

void Jogador::ataqueAereo()
{
	this->player.setTexture(&txJogadorAtaquePula[this->velTex]);
}

void Jogador::direcionalEsquerdo() {

	this->player.setTexture(&txJogadorCorre[this->velTex]);
	this->status.setLado(0);
	if (this->xpos > this->player.getSize().x) { //Player nao passar dos limites da tela esquerda
		this->xpos -= this->status.getVelocidadeX();
		this->status.setVelocidadeX(this->status.getVelocidadeX() + 1.f);
	}


}

void Jogador::direcionalDireito() {

	this->player.setTexture(&txJogadorCorre[this->velTex]);

	this->status.setLado(1);
	if (this->xpos < (this->videoModeP.width - this->player.getSize().x)) {  //Player nao passar dos limites da tela direita
		this->xpos += this->status.getVelocidadeX();
		this->status.setVelocidadeX(this->status.getVelocidadeX() + 1.f);
	}

}

void Jogador::direcionalCima() {

	if (this->aT <= 10) {
		this->status.setVelocidadeY(gravidade);
		this->jogador_pulou = true;
		if (this->aT >= 10) {
			this->jogador_pulou = false;
		}
	}

}

void Jogador::cair() {

	//Atterrisar do pulo
	if (this->fdist <= 0.f && this->jogador_pulou == false) {
		this->status.setVelocidadeY(0.f);
		this->aT = 0.f;
		this->jogador_pulou = false;
		this->ypos = this->cPos.y - this->pAltura;
		this->delay = 0;
	}
	else {
		this->status.setVelocidadeY(status.getVelocidadeY() - 1.f);
		this->ypos -= this->status.getVelocidadeY();
		this->aT += 1.f;
	}

}

void Jogador::executar()
{
	this->Tela->executar(this->player);
}

void Jogador::atualizarTextura() {

	//muda para a proxima textura a cada 7 frames
	if (this->velTex == 9)
		this->velTex = 0;
	if (this->frame % 7 == 0)
		this->velTex++;
	this->frame++;
}