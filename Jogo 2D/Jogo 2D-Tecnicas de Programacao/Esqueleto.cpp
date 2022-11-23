#include "Esqueleto.h"


Esqueleto::Esqueleto(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	iniciarTexturas();
	podeAtacar = true;
	vida = 3000;
	atacou = false;
	dano = 1000;
	lado = Lado::esquerda;
	danoso = true;
	velocidade_max = 6;
	velocidade = { 4.f, 0.f };

	cout << "Criou esqueleto!" << endl;
}

Esqueleto::~Esqueleto()
{
	danoso = false;
}

void Esqueleto::iniciarTexturas()
{
	/*if (!this->tEnemy[0].loadFromFile("../../Texturas/Personagens/Esqueleto/Parado.png", IntRect(20, 0, 270, 386))) {
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
	}*/
	forma.setFillColor(Color::Green);
}

void Esqueleto::executar()
{
	setPosicao(posicao);
	
	andar();
	atualizaTextura();
	//forma.setTexture(&tEnemyAnda[velTex1]); // Erro

	calculaQueda();

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);

}

void Esqueleto::colisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
		case(int (ID::plataforma)): //id da plataforma
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
		}
		break;
		case(int(ID::espinho)): //id do esqueleto
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
		}
		break;
		case(int (ID::fogo)): //id do esqueleto
		{

		}
		break;
		case(int(ID::esqueleto)): //id do esqueleto
		{

		}
		break;
		case(int(ID::morcego)): //id do morcego
		{

		}
		break;
		case(int(ID::mago)): //id do mago
		{

		}
		break;
		case(int(ID::jogador)): //id do primeiro jogador
		{

		}
		break;
		case(int(ID::jogador2)): //id do segundo jogador
		{

		}
		break;
	}
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
	if (lado == Lado::esquerda)
	{
		forma.setScale(Vector2f(-1, 1));
		andarEsquerda();
	}

	else if (lado == Lado::direita)
	{
		forma.setScale(Vector2f(1, 1));
		andarDireita();
	}

}

void Esqueleto::andarDireita()
{
	if (posicao.x <= 1920.f - 250.f) //Player nao passar dos limites da tela esquerda
	{ 
		velocidade = { velocidade.x + 1.f, velocidade.y };
		posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	}
	else
	{
		lado = Lado::esquerda;
	}
}

void Esqueleto::andarEsquerda()
{
	if (posicao.x >= 100.f) //Player nao passar dos limites da tela esquerda
	{ 
		velocidade = { velocidade.x - 1.f, velocidade.y };
		posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	}
	else
	{
		lado = Lado::direita;
	}
}