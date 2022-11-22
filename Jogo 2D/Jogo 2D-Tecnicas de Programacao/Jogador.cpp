#include "Jogador.h"

Jogador::Jogador(int i, Vector2f pos, Vector2f tam):
	Personagem(i, pos, tam)
{
	this->iniciarVariaiveis();
	this->iniciarJogador();
	this->iniciarStatus();
	this->iniciarTexturas();
}

Jogador::~Jogador()
{
}

void Jogador::iniciarStatus()
{
	setVidas(5);
	setLado(Lado::direita);
	setPodeAtacar(true);
	setAtaque(false);
	setDano(1);
	setVelocidadeMaxima(13);
	setVelocidade({ 0.f, 0.f });
}

void Jogador::iniciarVariaiveis()
{
	this->limitadorTex = 0;

	//logica jogador

	levou_dano = false;
	jogador_pulou = false;
	forcaPulo = 25.f;
	frame = 0;
	velTex = 0;
}

void Jogador::iniciarJogador()
{
	VideoMode video;
	video.height = 1080; //RESOLU�OES
	video.width = 1920;

	this->forma.setSize(tamanho);
	this->forma.setPosition(50.f, 905.f);
	posicao = forma.getPosition();
}

void Jogador::iniciarTexturas()
{
	for (int i = 0; i < 10; i++) 
	{
		if (!this->txJogadorCorre[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Correr.png", IntRect(99 + (i * 580), 30, 460, 660))) {
			std::cout << "Erro ao carregar textura da corrida do cavaleiro\n";
		}
		this->txJogadorCorre[i].setSmooth(true);

		if (!this->txJogadorPula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Pular.png", IntRect(51 + (i * 588), 30, 470, 626))) {
			std::cout << "Erro ao carregar textura do pulo do cavaleiro\n";
		}
		this->txJogadorPula[i].setSmooth(true);

		if (!this->txJogadorParado[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Parado.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "Erro ao carregar textura do cavaleiro parado\n";
		}
		this->txJogadorParado[i].setSmooth(true);

		if (!this->txJogadorAtaque[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Atacar.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "Erro ao carregar textura do ataque do cavaleiro\n";
		}
		this->txJogadorAtaque[i].setSmooth(true);
		
		/*if (!this->txJogadorAtaquePula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/AtaquePulo.png", IntRect(51 + (i * 588), 30, 448, 626)))
		{
			std::cout << "Erro ao carregar textura do Pulo com Ataque do Cavaleiro\n";
		}
		this->txJogadorAtaquePula[i].setSmooth(true);*/
	}
}

void Jogador::executar()
{
	forma.setTexture(&txJogadorParado[this->velTex]);
	//forma.setPosition(posicao);

	if (lado == Lado::esquerda) //define para qual lado o forma esta virado
	{
		forma.setScale(Vector2f(-1, 1));
		lado = Lado::neutro;
	}
	else if (lado == Lado::direita)
	{
		forma.setScale(Vector2f(1, 1));
		lado = Lado::neutro;
	}



	//defina para nao passar a velocidade maxima
	if (velocidade.x >= velocidade_max)
		velocidade = { velocidade_max, velocidade.y};

	//andar para os 2 lados
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))

		direcionalEsquerdo();

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))

		direcionalDireito();

	else
		velocidade = { 0.f, velocidade.y};
	
	//pulo 
	if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && jogador_pulou == false)
	{
		velocidade = { velocidade.x, forcaPulo };
		jogador_pulou = true;
	}

	//cair
	if (jogador_pulou == true)
	{
		pulo();
	}
	
	//atacar
	if ((Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space)) && atacou == false) 
	{
		atacou = true;
		limitadorTex1 = 0;
	}
	if (atacou == true)
	{
		ataque();
	}
	if (atacou == true && jogador_pulou == true)
	{
		ataqueAereo();
	}
	atualizarTextura();
}

void Jogador::ataque()
{
	if (this->limitadorTex1 <= 9) 
	{
		this->forma.setTexture(&txJogadorAtaque[this->limitadorTex1]);
		if (this->frame % 3 == 0)
			this->limitadorTex1++;
	}
	else
		setAtaque(false);
}

void Jogador::ataqueAereo()
{
	if (limitadorTex1 <= 9)
	{
		forma.setTexture(&txJogadorAtaquePula[limitadorTex1]);
		if (frame % 3 == 0)
			limitadorTex1++;
	}
	else
		atacou = false;
}

void Jogador::direcionalEsquerdo() 
{
	forma.setTexture(&txJogadorCorre[velTex]);
	lado = Lado::esquerda;
	velocidade = {velocidade.x - 1.f, velocidade.y};
	forma.move(velocidade.x, velocidade.y);
	posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };

	//Gerenciador_Grafico::getInstancia_Grafico()->centralizar(forma.getPosition().x);
}

void Jogador::direcionalDireito() 
{
	forma.setTexture(&txJogadorCorre[velTex]);
	lado = Lado::direita;
	velocidade = { velocidade.x + 1.f, velocidade.y };
	forma.move(velocidade.x, velocidade.y);
	posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	//Gerenciador_Grafico::getInstancia_Grafico()->centralizar(forma.getPosition().x);
	
}

void Jogador::pulo()
{
	forma.move(velocidade.x, -velocidade.y);
	posicao = { posicao.x + velocidade.x, posicao.y - velocidade.y };

	calculaQueda();

	forma.setTexture(&txJogadorPula[limitadorTex]);
	if (frame % 6 == 0)
		limitadorTex++;
}

void Jogador::colisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
		case(int (ID::plataforma)): //id da plataforma
		{
			velocidade.x = 0.f;
			velocidade.y = 0.f;
		}
		break;
		case(int (ID::esqueleto)): //id do esqueleto
		{
			operator--(outro->getDano());
		}
		break;
	}
}


void Jogador::atualizarTextura() 
{
	if (frame % 7 == 0)
		velTex++;
	if (velTex == 10)
		velTex = 0;
	frame++;
}

void Jogador::operator--(int dano)
{
	vidas -= dano;
	levou_dano = true;
}

const bool Jogador::getLevouDano() const
{
	return levou_dano;
}