#include "stdafx.h"
#include "Jogo.h"

// funcoes privadas
void Jogo::inicVariaiveis()
{
	this->janela = nullptr;

	//logica jogo


	this->points = 0;
	this->baixo = true;

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
	this->velTex1 = 0;
}

void Jogo::inicTexturas()
{
	int i;
	//Textura chao
	/*if (!this->tChao.loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/mapa/2.png")) {
		std::cout << "ERROR";
	}
	tChao.setSmooth(true);
	chao.setTexture(&tChao);*/
	
	//textura fundo
	this->tBg.loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/mapa/fundo.jpg", IntRect(0.f , 0.f, this->videoMode.width, this->videoMode.height));
	this->tBg.setSmooth(true);
	this->fundo.setTexture(tBg);

	if (!this->tEnemy[0].loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/Skeleton/Skeleton Idle.png", IntRect(20.f, 0.f, 270.f, 386.f))) {
		std::cout << "ERROR";
	}
	tEnemy[0].setSmooth(true);

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

		if (!this->tPlayerParado[i].loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/cavaleiro/Idle.png",IntRect(51.f + (i * 588.f),30.f,448.f,626.f))) {
			std::cout << "ERROR";
		}
		this->tPlayerParado[i].setSmooth(true);

		//textura inimigo
		if (!this->tEnemy[i+1].loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/Skeleton/Skeleton Idle.png", IntRect(20.f + ((i+1) * 290.f), 0.f, 270.f, 386.f))) {
			std::cout << "ERROR";
		}
		tEnemy[i+1].setSmooth(true);
	}
	
}

void Jogo::inicJanela()
{
	this->videoMode.height = 1080.f; //RESOLUÇOES
	this->videoMode.width = 1920.f;
	this->janela = new RenderWindow(this->videoMode,
        "Game 1", Style::Titlebar |
        Style::Close);

	this->janela->setFramerateLimit(60); //limite FPS
}

void Jogo::inicMapa()
{
	//chao

	this->chao.setPosition(0.f, this->videoMode.height - 85.f);
	this->chao.setSize(Vector2f(this->videoMode.width, 85.f));
	chao.setFillColor(Color::White);
	
	

	//fundo

	//this->fundo.setScale(Vector2f(this->videoMode.width / 1000.f, this->videoMode.height / 750.f));
	
}

void Jogo::inicEnemies()
{
	this->inimigo.setPosition(10.f, 10.f);
	this->inimigo.setSize(Vector2f(150.f, 200.f));
	
}

void Jogo::inicPlayer()
{
	this->player.setSize(Vector2f(100.f, pAltura));
	this->player.setPosition(50.f, 600.f - player.getSize().y);

}

//contrutores / destrutores
Jogo::Jogo()
{
	this->inicVariaiveis();
	this->inicJanela();
	this->inicPlayer();
	this->inicEnemies();
	this->inicMapa();
	this->inicTexturas();
}

Jogo::~Jogo()
{
	delete this->janela;
}

//accesos

const bool Jogo::rodando() const
{
	return this->janela->isOpen();
}

//funcoes

void Jogo::spawnEnemy()
{
	/*
		@return void

		Spawna inimigo e diz a cor e posicao do inimigo
	*/

	this->inimigo.setPosition(this->videoMode.width-200.f, this->chao.getPosition().y - this->inimigo.getSize().y);
	
	//spawn inimigo
	//this->inimigos.push_back(this->inimigo);

}

void Jogo::atualizaMouse()
{
	/*
		Atualiza as posicoes do mouse 
		*atualiza as posicoes do mouse em relacao a janela (vector2i)
	*/

	this->mousePos = Mouse::getPosition(*this->janela);

}

void Jogo::pollEvents()
{
	//evento
	while (this->janela->pollEvent(this->ev))
	{
		switch (this->ev.type) 
		{
		case Event::Closed:
			this->janela->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
				this->janela->close();
			break;
		}
	}

}

void Jogo::updatePlayer()
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
	if (this->xvel >= this->velMax) {
		this->xvel = this->velMax;
	}

	//andar para os 2 lados
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		this->player.setTexture(&tPlayerCorre[this->velTex]);
		this->lado = 0;
		if (this->xpos > this->player.getSize().x) { //Player nao passar dos limites da tela esquerda
			this->xpos -= this->xvel;
			this->xvel += 1.f;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->player.setTexture(&tPlayerCorre[this->velTex]);
	
		this->lado = 1.f;
		if (this->xpos < (this->videoMode.width - this->player.getSize().x)){  //Player nao passar dos limites da tela direita
			this->xpos += xvel;
			this->xvel += 1.f;
		}
	}

	//se nao andar a velocidade é 0 // fica parado
	else {
		this->xvel = 0.f;
	}
	
	//pulo
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (this->aT <= 10) {
			this->yvel = this->gravidade;
			this->pulo = true;
			if (this->aT >= 10) {
				this->pulo = false;
			}
		}
	}

	else {
		this->pulo = false;
	}

	this->fdist = this->cPos.y - (this->ypos + this->pAltura);

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
	if (this->pulo == true)
		this->aux = 0;
	
	//limita os frames do pulo
	if(this->aux <= 9) {
		
		this->player.setTexture(&tPlayerPula[this->aux]);
		if (this->frame % 3 == 0)
			this->aux++;

	}
	
	//muda para a proxima textura a cada 7 frames
	if (this->velTex == 9)
		this->velTex = 0;
	if (this->frame % 7 == 0)
		this->velTex++;
	this->frame++;
}

void Jogo::updateEnemies()
{
	/*
		@return void

		Update inimigo tempo de spawn e 
		quando o total de inimigos é menor que o maximo
		-mover inimigos para baixo e cima
		-remover inimigos no limite da tela
	*/

	this->spawnEnemy();
			
	this->inimigo.setTexture(&tEnemy[velTex1]);

	//muda para a proxima textura a cada 7 frames
	if (this->velTex1 == 10)
		this->velTex1 = 0;
	if (this->frame1 % 7 == 0)
		this->velTex1++;
	this->frame1++;
}

void Jogo::update()
{
	this->pollEvents();

	this->atualizaMouse();

	this->updatePlayer();

	this->updateEnemies();
	
}

void Jogo::render()
{
	/*
		@return void

		-limpar frames antigos
		-renderizar objetos
		-display frame na janela

		rendereizar objetos jogo
	*/

	this->janela->clear();

	//desenhar jogo
	
	this->janela->draw(this->chao);
	this->janela->draw(this->fundo);
	this->janela->draw(this->player);
	this->janela->draw(this->inimigo);
	

	this->janela->display();
}