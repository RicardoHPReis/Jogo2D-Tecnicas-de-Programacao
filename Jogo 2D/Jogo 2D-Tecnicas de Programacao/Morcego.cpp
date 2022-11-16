#include "Morcego.h"


Morcego::Morcego(int id, bool mov, Vector2f pos, Vector2f tam, int nr_vidas, int nr_dano, int ld, bool atacar, bool morreu, bool foiAtacado, bool nocv) :
	Inimigo(2, true, pos, tam, 1, 1, 2, true, false, false)
{
	this->iniciarStatus();
	this->iniciarTexturas();
	this->inicEnemies();

	nocivo = true;
}

Morcego::~Morcego()
{
	nocivo = false;
}

void Morcego::iniciarStatus()
{
	setVelocidade({ 8.f, 3.f });
}

void Morcego::inicEnemies()
{
	posicao = { 150.f, 300.f };
	tamanho = { 110.f, 85.f };
	forma.setSize(tamanho);
	forma.setPosition(posicao);

	//chao
	this->chao.setPosition(0.f, grafico->getVideo().height - 85.f);
	this->chao.setSize(Vector2f(grafico->getVideo().width, 85));
}

void Morcego::iniciarTexturas()
{
	//texturas morcego morrendo
	for (int i = 0; i < 5; i++)
	{
		if (!this->tEnemy[i].loadFromFile("../../Texturas/Personagens/Morcego.png", IntRect(i * 290, 0, 270, 386))) {
			cout << "Erro ao carregar a textura do Morcego parado\n";
		}
		tEnemy[i].setSmooth(true);
	}

	// Texturas inimigo Voando
	for (int i = 0; i < 5; i++)
	{
		if (!this->tEnemyVoa[i].loadFromFile("../../Texturas/Personagens/Morcego.png", IntRect(i * 100, 164, 100, 80))) {
			cout << "Erro ao carregar a textura do Morcego andando\n";
		}
		tEnemyVoa[i].setSmooth(true);
	}
}

void Morcego::atualizaInimigo()
{
	forma.setPosition(posicao);
	voar();

	atualizaTextura();
	forma.setTexture(&tEnemyVoa[velTex1]);
}

void Morcego::atualizaTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (frame1 % 7 == 0)
		velTex1++;
	if (velTex1 == 5)
		velTex1 = 0;
	frame1++;
}

void Morcego::voar()
{
	if (lado == 2)
	{
		if (forma.getScale().x == 1) 
		{
			forma.setScale(Vector2f(-1, 1));
			posicao.x = posicao.x - tamanho.x;
		}
		voarEsquerda();
	}

	else if (lado == 1)
	{
		if (forma.getScale().x == -1)
		{
			forma.setScale(Vector2f(1, 1));
			posicao.x = posicao.x + tamanho.x;
		}
		voarDireita();
	}
	if (posicao.x > grafico->getVideo().width / 2.f)
		voarBaixo();
	else if(posicao.x < grafico->getVideo().width / 2.f && posicao.y > 0)
		voarCima();
}

void Morcego::voarDireita()
{
	if (posicao.x <= 1920.f - 150.f) //Player nao passar dos limites da tela esquerda
	{
		posicao.x = posicao.x + getVelocidade().x;
	}
	else
	{
		lado = 2;
	}
}

void Morcego::voarEsquerda()
{
	if (posicao.x >= 150.f) //Player nao passar dos limites da tela esquerda
	{
		posicao.x = posicao.x - getVelocidade().x;
	}
	else
	{
		lado = 1;
	}
}

void Morcego::voarCima()
{
	posicao.y = posicao.y - getVelocidade().y;
}

void Morcego::voarBaixo()
{
	posicao.y = posicao.y + getVelocidade().y;
}

