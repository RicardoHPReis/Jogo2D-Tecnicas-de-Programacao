#include "Morcego.h"


Morcego::Morcego(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	this->iniciarStatus();
	this->iniciarTexturas();
	this->inicEnemies();

	//tiro->setAtirar(false);

	danoso = true;
}

Morcego::~Morcego()
{
	danoso = false;
}

void Morcego::iniciarStatus()
{
	velocidade = { 8.f, 3.f };
}

void Morcego::inicEnemies()
{
	posicao = { 150.f, 300.f };
	tamanho = { 110.f, 85.f };
	forma.setSize(tamanho);
	forma.setPosition(posicao);

}

void Morcego::iniciarTexturas()
{
	//texturas morcego morrendo
	for (int i = 0; i < 5; i++)
	{
		if (!this->tEnemyDie[i].loadFromFile("../../Texturas/Personagens/Morcego.png", IntRect(i * 100, 322, 100, 80))) {
			cout << "Erro ao carregar a textura do Morcego morrendo\n";
		}
		tEnemyDie[i].setSmooth(true);
	}

	// Texturas inimigo Voando
	for (int i = 0; i < 5; i++)
	{
		if (!this->tEnemyVoa[i].loadFromFile("../../Texturas/Personagens/Morcego.png", IntRect(i * 100, 164, 100, 125))) {
			cout << "Erro ao carregar a textura do Morcego voando\n";
		}
		tEnemyVoa[i].setSmooth(true);
	}
}

void Morcego::atualizar()
{
	forma.setPosition(posicao);
	voar();
	atualizaTextura();

	//if (tiro->getAtirar() == false)
	//	disparar();

	//tiro->atualizar();

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

void Morcego::disparar()
{
	//tiro->setPosicao(getPosicao());
	//tiro->setLado(getLado());
	//tiro->setAtirar(true);
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

