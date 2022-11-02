
#include "Jogo.h"

// funcoes privadas
void Jogo::inicVariaiveis()
{
	this->janela = nullptr;

	//logica jogo


	this->points = 0;
	this->baixo = true;

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
	this->tBg.loadFromFile("C:/Users/Usuario/source/repos/Jogo 2D-Tecnicas de Programacao/Texturas/Cenario/Fundo.jpg", IntRect(0.f, 0.f, this->videoMode.width, this->videoMode.height));
	this->tBg.setSmooth(true);
	this->fundo.setTexture(tBg);

	if (!this->tEnemy[0].loadFromFile("C:/Users/Usuario/source/repos/Jogo 2D-Tecnicas de Programacao/Texturas/Personagens/Esqueleto/Parado.png", IntRect(20.f, 0.f, 270.f, 386.f))) {
		std::cout << "ERROR";
	}
	tEnemy[0].setSmooth(true);

	//texturas Player
	for (i = 0; i < 10; i++) {

		//textura inimigo
		if (!this->tEnemy[i + 1].loadFromFile("C:/Users/Usuario/source/repos/Jogo 2D-Tecnicas de Programacao/Texturas/Personagens/Esqueleto/Parado.png", IntRect(20.f + ((i + 1) * 290.f), 0.f, 270.f, 386.f))) {
			std::cout << "ERROR";
		}
		tEnemy[i + 1].setSmooth(true);
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


//contrutores / destrutores
Jogo::Jogo()
{
	this->inicVariaiveis();
	this->inicJanela();
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

	this->inimigo.setPosition(this->videoMode.width - 200.f, this->chao.getPosition().y - this->inimigo.getSize().y);

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

	this->player.updatePlayer();

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
	this->janela->draw(this->player.player);
	this->janela->draw(this->inimigo);


	this->janela->display();
}