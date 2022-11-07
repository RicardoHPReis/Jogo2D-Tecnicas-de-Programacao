#include "Jogo.h"


Jogo::Jogo()
{
	this->inicializarVariaiveis();
	this->inicializarInimigos();
	this->inicializarMapa();
	this->inicializarTexturas();
}

Jogo::~Jogo()
{
	delete this->menuP;
}



void Jogo::inicializarVariaiveis()
{
	menuP = new Menu();
	//logica jogo


	this->pontos = 0;
	this->baixo = true;

}

void Jogo::inicializarTexturas()
{
	int i;

	//textura fundo
	this->tBg.loadFromFile("../../Texturas/Cenario/Fundo.jpg", IntRect(0, 0, this->videoMode.width, this->videoMode.height));
	this->tBg.setSmooth(true);
	this->fundo.setTexture(tBg);

	if (!this->tEnemy[0].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20, 0, 270, 386))) {
		std::cout << "ERROR";
	}
	tEnemy[0].setSmooth(true);

	//texturas Player
	for (i = 0; i < 10; i++) {

		//textura inimigo
		if (!this->tEnemy[i + 1].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20 + ((i + 1) * 290), 0, 270, 386))) {
			std::cout << "ERROR";
		}
		tEnemy[i + 1].setSmooth(true);
	}

}
/*
void Jogo::inicJanela()
{
	//roda o menu antes de abrir a janela do jogo
	this->menuP->run_menu();
	//janela do jogo
	this->videoMode.height = 1080; //RESOLUÇOES
	this->videoMode.width = 1920;
	this->janela = new RenderWindow(this->videoMode,
		"Game 1", Style::Titlebar |
		Style::Close);
	this->janela->setFramerateLimit(60); //limite FPS
}*/

void Jogo::inicializarMapa()
{
	//chao

	this->chao.setPosition(0, videoMode.height - 85.f);
	this->chao.setSize(Vector2f((videoMode.width), 85));
	chao.setFillColor(Color::White);

}

void Jogo::inicializarInimigos()
{
	this->inimigo.setPosition(10.f, 10.f);
	this->inimigo.setSize(Vector2f(150.f, 200.f));

}


const bool Jogo::rodando() const
{
	return (Tela->getAberta());
}


void Jogo::spawnInimigo()
{
	this->inimigo.setPosition(this->videoMode.width - 200.f, this->chao.getPosition().y - this->inimigo.getSize().y);
}

/*void Jogo::atualizarMouse()
{
	this->mousePos = Mouse::getPosition(*this->janela);
}*/

void Jogo::atualizarInimigos()
{
	/*
		@return void
		Update inimigo tempo de spawn e
		quando o total de inimigos é menor que o maximo
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

void Jogo::atualizar()
{
	//this->atualizaMouse();
	this->jogador.atualizarJogador();
	this->atualizarInimigos();
}