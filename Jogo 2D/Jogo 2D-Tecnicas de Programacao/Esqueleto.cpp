#include "Esqueleto.h"


Esqueleto::Esqueleto(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	this->iniciarStatus();
	this->iniciarTexturas();
	this->inicEnemies();
	this->spawnInimigo();
	danoso = true;
}

Esqueleto::~Esqueleto()
{
	danoso = false;
}

void Esqueleto::iniciarStatus()
{
	setVelocidadeMaxima(6);
	setVelocidade({ 4.f, 0.f });
}

void Esqueleto::inicEnemies()
{
	posicao = { 1700.f, 795.f };
	tamanho = { 150.f, 200.f };
	forma.setSize(tamanho);

	//chao
	this->chao.setPosition(0.f, grafico->getVideo().height - 85.f);
	this->chao.setSize(Vector2f(grafico->getVideo().width, 85 ));
}

void Esqueleto::spawnInimigo()
{
	forma.setPosition(grafico->getVideo().width - 200.f, chao.getPosition().y - forma.getSize().y);
}

void Esqueleto::iniciarTexturas()
{
	if (!this->tEnemy[0].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20, 0, 270, 386))) {
		cout << "Erro ao carregar a textura do esqueleto parado\n";
	}
	tEnemy[0].setSmooth(true);

	for (int i = 0; i < 10; i++) 
	{
		if (!this->tEnemy[i + 1].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20 + ((i + 1) * 290), 0, 270, 386))) {
			cout << "Erro ao carregar a textura do esqueleto parado\n";
		}
		tEnemy[i + 1].setSmooth(true);
	}

	// Texturas inimigo Andando
	for (int i = 0; i < 13; i++) 
	{
		if (!this->tEnemyAnda[i].loadFromFile("../../Texturas/Personagens/Esqueleto/Andar.png", IntRect((i * 257), 0, 250, 385))) {
			cout << "Erro ao carregar a textura do esqueleto andando\n";
		}
		tEnemyAnda[i].setSmooth(true);
	}
}

void Esqueleto::atualizaInimigo()
{
	forma.setPosition(posicao);
	andar();

	atualizaTextura();
	forma.setTexture(&tEnemyAnda[velTex1]);
}

void Esqueleto::atualizaTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (frame1 % 7 == 0)
		velTex1++;
	if (velTex1 == 13)
		velTex1 = 0;
	frame1++;
}

void Esqueleto::andar()
{
	if (lado == 2)
	{
		forma.setScale(Vector2f(-1, 1));
		andarEsquerda();
	}

	else if (lado == 1)
	{
		forma.setScale(Vector2f(1, 1));
		andarDireita();
	}

}

void Esqueleto::andarDireita()
{
	if (posicao.x <= 1920.f - 250.f) //Player nao passar dos limites da tela esquerda
	{ 
		posicao.x = posicao.x + getVelocidade().x;
	}
	else
	{
		lado = 2;
	}
}

void Esqueleto::andarEsquerda()
{
	if (posicao.x >= 100.f) //Player nao passar dos limites da tela esquerda
	{ 
		posicao.x = posicao.x - getVelocidade().x;
	}
	else
	{
		lado = 1;
	}
}