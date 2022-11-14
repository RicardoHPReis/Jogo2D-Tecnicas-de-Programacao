#include "Jogador.h"

Jogador::Jogador():
Personagem()
{
	iniciarVariaiveis();
	iniciarJogador();
	iniciarStatus();
	iniciarTexturas();
}

Jogador::~Jogador()
{
	
}

void Jogador::iniciarStatus()
{
	setVidas(5);
	setLado(1);
	setPodeAtacar(true);
	setAtaque(false);
	setDano(1);
	setVelocidadeMaxima(13);
	setVelocidadeX(0.f);
	setVelocidadeY(0.f);
}

void Jogador::iniciarVariaiveis()
{
	//Videomode video;
	//video.height = 1080; //RESOLU�OES
	//video.width = 1920;

	jogador_pulou = false;
	posicao = { 50.f,50.f };
	gravidade = 20.f;
	aT = 0.f;
	tamanho = { 90.f, (tamanho.x / 3) * 2 };
	posicao = forma->getPosition();
	frame = 0;
	velocidadeTextura = 0;

	delay = 0;
	tempoDelay = 10;
}

void Jogador::iniciarJogador()
{
	forma->setSize(tamanho);
	forma->setPosition(50.f, 600.f - forma->getSize().y);
}

void Jogador::iniciarTexturas()
{
	for (int i = 0; i < 10; i++) 
	{
		if (!txJogadorCorre[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Correr.png", IntRect(99 + (i * 580), 30, 460, 660))) {
			std::cout << "ERROR";
		}
		txJogadorCorre[i].setSmooth(true);

		if (!txJogadorPula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Pular.png", IntRect(51 + (i * 588), 30, 470, 626))) {
			std::cout << "ERROR";
		}
		txJogadorPula[i].setSmooth(true);

		if (!txJogadorParado[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Parado.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "ERROR";
		}
		txJogadorParado[i].setSmooth(true);

		if (!txJogadorAtaque[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Atacar.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "ERROR";
		}

		txJogadorAtaque[i].setSmooth(true);
		if (!txJogadorAtaquePula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/AtaquePulo.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "ERROR";
		}
		txJogadorAtaquePula[i].setSmooth(true);
	}
}

void Jogador::ataque()
{
	if (getAtaque() == true)
		limitadorTex1 = 0;

	if (limitadorTex1 <= 9)
	{
		forma->setTexture(&txJogadorAtaque[limitadorTex1]);
		if (frame % 3 == 0)
			limitadorTex1++;
	}
}

void Jogador::ataqueAereo()
{
	if (getAtaque() == true)
		limitadorTex1 = 0;

	if (limitadorTex1 <= 9) 
	{
		forma->setTexture(&txJogadorAtaquePula[limitadorTex1]);
		if (frame % 3 == 0)
			limitadorTex1++;
	}
}

void Jogador::direcionalEsquerdo() {

	forma->setTexture(&txJogadorCorre[velocidadeTextura]);
	setLado(0);
	if (posicao.x > forma->getSize().x) //Player nao passar dos limites da tela esquerda
	{
		posicao.x -= getVelocidadeX();
		setVelocidadeX(getVelocidadeX() + 1.f);
	}
}

void Jogador::direcionalDireito() 
{
	forma->setTexture(&txJogadorCorre[velocidadeTextura]);

	setLado(1);
	if (posicao.x < (1920.f - forma->getSize().x)) {  //Player nao passar dos limites da tela direita
		posicao.x += getVelocidadeX();
		setVelocidadeX(getVelocidadeX() + 1.f);
	}

}

void Jogador::direcionalCima() 
{
	if (aT <= 10) 
	{
		setVelocidadeY(gravidade);
		jogador_pulou = true;
		if (aT >= 10) 
		{
			jogador_pulou = false;
		}
	}

}

void Jogador::cair() 
{
	//Atterrisar do pulo
	if (/*fdist <= 0.f &&*/ jogador_pulou == false)
	{
		setVelocidadeY(0.f);
		aT = 0.f;
		jogador_pulou = false;
		delay = 0;
	}
	else 
	{
		setVelocidadeY(getVelocidadeY() - 1.f);
		posicao.y -= getVelocidadeY();
		aT += 1.f;
	}
}

void Jogador::imprimir()
{

}

void Jogador::executar()
{
	//textura no frame
	forma->setTexture(&txJogadorParado[velocidadeTextura]);

	//oega posicoes importantes
	forma->setPosition(posicao.x, posicao.y);

	//define para qual lado o player esta virado
	if (getLado() == 0) {
		forma->setScale(Vector2f(-1, 1));
		setLado(2);
	}
	else if (getLado() == 1) {
		forma->setScale(Vector2f(1, 1));
		setLado(2);
	}

	//defina para nao passar a velocidade maxima
	if (getVelocidadeX() >= getVelocidadeMaxima())
		setVelocidadeX(getVelocidadeMaxima());

	//andar para os 2 lados
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		direcionalEsquerdo();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		direcionalDireito();
	else	//se nao andar a velocidade � 0 // fica parado
		setVelocidadeX(0.f);

	//pulo 
	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
		direcionalCima();
	else
		jogador_pulou = false;

	cair();

	if (jogador_pulou == true)
		limitadorFrames = 0;

	
	if (limitadorFrames <= 9) //limita os frames do pulo
	{
		forma->setTexture(&txJogadorPula[limitadorFrames]);
		if (frame % 3 == 0)
			limitadorFrames++;
	}

	//atacar

	if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space))
		setAtaque(true);
	else 
		setAtaque(false);
	
	ataque();
	
	if (jogador_pulou == true)
		ataqueAereo();

	atualizarTextura();
}

void Jogador::atualizarTextura() 
{
	//muda para a proxima textura a cada 7 frames
	if (velocidadeTextura == 9)
		velocidadeTextura = 0;
	if (frame % 7 == 0)
		velocidadeTextura++;
	frame++;
}