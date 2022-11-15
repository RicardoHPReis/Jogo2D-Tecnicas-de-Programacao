#include "Jogador.h"

Jogador::Jogador(int id, bool mov, Vector2f pos, Vector2f tam, int nr_vidas, int nr_dano, int ld, bool atacar, bool morreu, bool foiAtacado):
	Personagem(1, true, pos, tam, 5, nr_dano, 1, true, false, false)
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
	setLado(1);
	setPodeAtacar(true);
	setAtaque(false);
	setDano(1);
	setVelocidadeMaxima(13);
	setVelocidade({ 0.f, 0.f });
}

void Jogador::iniciarVariaiveis()
{
	this->limitadorTex = 0;

	//VideoMode

	VideoMode video;
	video.height = 1080; //RESOLU�OES
	video.width = 1920;

	//chao

	this->chao.setPosition(0.f, video.height - 85.f);
	this->chao.setSize(Vector2f(video.width, 85.f));

	//logica jogador

	this->jogador_pulou = false;

	this->gravidade = 1.f;
	this->forcaPulo = 25.f;

	this->pAltura = 90.f;
	this->pLargura = (pAltura / 3) * 2;
	this->cPos = chao.getPosition();
	this->pPos = forma.getPosition();
	this->frame = 0;
	this->velTex = 0;

	vidasSp.resize(vidas);
}

void Jogador::iniciarJogador()
{
	VideoMode video;
	video.height = 1080; //RESOLU�OES
	video.width = 1920;

	this->forma.setSize(Vector2f(pLargura, pAltura));
	this->forma.setPosition(50.f, (video.height - forma.getSize().y) - chao.getSize().y);
	this->xpos = this->forma.getPosition().x;
	this->ypos = this->forma.getPosition().y;
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
		
		/*if (!this->txJogadorAtaquePula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/AtaquePulo.png", IntRect(51 + (i * 588), 30, 448, 626))) {
			std::cout << "Erro ao carregar textura do Pulo com Ataque do Cavaleiro\n";
		}
		this->txJogadorAtaquePula[i].setSmooth(true);*/
	}
	tVidas.loadFromFile("../../Texturas/Cenario/Vida.png");
	if (!tVidas.loadFromFile("../../Texturas/Cenario/Vida.png"))
	{
		cout << "Erro na textura dos corações da vida.\n";
	}
	tVidas.setSmooth(true);
	for (size_t i{}; i < vidasSp.size(); ++i)
	{
		vidasSp[i].setTexture(tVidas);
		vidasSp[i].setPosition(Vector2f((30.f) + (50 * i), 10.f));
	}
}

void Jogador::imprimeVidas()
{
	for (int i = 0; i < vidas; i++)
	{
		executarSprite(vidasSp[i]);
	}
}

void Jogador::atualizarJogador()
{
	//textura no frame
	this->forma.setTexture(&txJogadorParado[this->velTex]);

	//oega posicoes importantes
	this->cPos = this->chao.getPosition();
	this->forma.setPosition(this->xpos, this->ypos);

	//define para qual lado o forma esta virado
	if (getLado() == 0) 
	{
		forma.setScale(Vector2f(-1, 1));
		lado = 2;
	}
	else if (getLado() == 1) 
	{
		forma.setScale(Vector2f(1, 1));
		lado = 2;
	}

	//defina para nao passar a velocidade maxima
	if (getVelocidade().x >= getVelocidadeMaxima())
		setVelocidade({ getVelocidadeMaxima(), getVelocidade().y});

	//andar para os 2 lados
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		direcionalEsquerdo();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		direcionalDireito();
	else
		setVelocidade({ 0.f, getVelocidade().y});
	
	//pulo 
	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) {
		jogador_pulou = true;
	}

	this->fdist = this->cPos.y - (this->ypos + this->pAltura);

	//cair();
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
	atualizaVidas();
}

void Jogador::atualizaVidas()
{
	//se sofrer dano
	//this->jogador->status.setVidas(this->jogador->status.getVidas()--);

	//se ganhar uma vida
	//this->jogador->status.setVidas(this->jogador->status.getVidas()++);
}

void Jogador::pulo() 
{
	VideoMode video;
	video.height = 1080; //RESOLU�OES
	video.width = 1920;

	setVelocidade({ getVelocidade().x, forcaPulo});
	forcaPulo -= gravidade;
	ypos -= getVelocidade().y;

	this->forma.setTexture(&txJogadorPula[this->limitadorTex]);
	if (this->frame % 6 == 0)
		this->limitadorTex++;

	if(this->ypos >= (video.height - forma.getSize().y) - chao.getSize().y)
	{
		this->forcaPulo = 25.f;
		this->jogador_pulou = false;
		setVelocidade({ getVelocidade().x, 0.f });
		this->limitadorTex = 0;
	}
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
	if (this->limitadorTex1 <= 9) 
	{
		this->forma.setTexture(&txJogadorAtaquePula[this->limitadorTex1]);
		if (this->frame % 3 == 0)
			this->limitadorTex1++;
	}
	else
		setAtaque(false);
}

void Jogador::direcionalEsquerdo() {

	forma.setTexture(&txJogadorCorre[velTex]);
	setLado(0);
	if (xpos > forma.getSize().x) //forma nao passar dos limites da tela esquerda
	{
		xpos -= getVelocidade().x;
		setVelocidade({getVelocidade().x + 1.f, getVelocidade().y});
	}
}

void Jogador::direcionalDireito() {

	VideoMode video;
	video.height = 1080; //RESOLU�OES
	video.width = 1920;

	forma.setTexture(&txJogadorCorre[velTex]);
	setLado(1);
	if (xpos < (video.width - forma.getSize().x)) {  //forma nao passar dos limites da tela direita
		xpos += getVelocidade().x;
		setVelocidade({ getVelocidade().x + 1.f, getVelocidade().y });
	}
}

void Jogador::executar()
{
	janela->desenhar(&forma);
}

int Jogador::getVidas()
{
	return getVidas();
}

void Jogador::atualizarTextura() 
{
	if (velTex == 9)
		velTex = 0;
	if (frame % 7 == 0)
		velTex++;
	frame++;
}