#include "Slime.h"
//using namespace Entidades;
//using namespace Personagens;

Slime::Slime(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	iniciarTexturas();
	vida = 200;
	velocidade_Morte = 0;
	frame0 = 0;
	atacou = false;
	dano = 100;
	lado = Lado::esquerda;
	danoso = true;
	velocidade_max = 1;
	velocidade = { 1.f, 0.f };
	velTex1 = 0;

	cout << "Criou Slime!" << endl;
}

Slime::~Slime()
{
	danoso = false;
}

void Slime::iniciarTexturas()
{
	/*if (!this->tEnemy[0].loadFromFile("../../Texturas/Personagens/Slime/Parado.png", IntRect(20, 0, 270, 386))) {
		cout << "Erro ao carregar a textura do Slime parado\n";
	}
	tEnemy[0].setSmooth(true);

	for (int i = 0; i < 10; i++) 
	{
		if (!this->tEnemy[i + 1].loadFromFile("../../Texturas/Personagens/Slime/Parado.png", IntRect(20 + ((i + 1) * 290), 0, 270, 386))) {
			cout << "Erro ao carregar a textura do Slime parado\n";
		}
		tEnemy[i + 1].setSmooth(true);
	}*/

	// Texturas inimigo Andando
	for (int i = 0; i < 8; i++) 
	{
		if (!this->tEnemyAnda[i].loadFromFile("../../Texturas/Personagens/Slime.png", IntRect((i * 111), 0, 111, 85))) {
			cout << "Erro ao carregar a textura do Slime andando\n";
		}
		tEnemyAnda[i].setSmooth(true);
	}
	for (int i = 0; i < 5; i++)
	{
		if (!this->tEnemyDie[i].loadFromFile("../../Texturas/Personagens/Slime.png", IntRect((i * 111), 177, 111, 85))) {
			cout << "Erro ao carregar a textura do Slime andando\n";
		}
		tEnemyDie[i].setSmooth(true);
	}
}

void Slime::executar()
{
	setPosicao(posicao);
	
	andar();
	atualizaTextura();
	forma.setTexture(&tEnemyAnda[velTex1]);

	calculaQueda();

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
	if (vida <= 0)
		estaMorto = true;

	if (estaMorto == true)
	{
		if (frame1 % 7 == 0)
			velocidade_Morte++;
		frame0++;
		forma.setTexture(&tEnemyDie[velocidade_Morte]);
		if (velTex1 == 6)
		{
			setPosicao(Vector2f{ 10000.f,10000.f });
			setVelocidade(Vector2f{ 0.f,0.f });
		}
	}

}

void Slime::reageColisao(Entidade* outro, Vector2f dist_colisao)
{
	switch (outro->getId())
	{
		case(int (ID::plataforma)): //id da plataforma
		{
			Vector2f distancia;
			distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
						  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

			if (dist_colisao.x > dist_colisao.y)
			{
				if (distancia.x > 0.f)
				{
					setPosicao(Vector2f(posicao.x + dist_colisao.x, posicao.y));
				}
				else
				{
					setPosicao(Vector2f(posicao.x - dist_colisao.x, posicao.y));
				}
			}
			else
			{
				if (distancia.y > 0.f)
				{
					setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y)); // CHAO
					velocidade.y = 0.f;
				}
				else
				{
					setPosicao(Vector2f(posicao.x, posicao.y - dist_colisao.y));
				}
			}
		}
		break;
	}
}

void Slime::atualizaTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (frame1 % 7 == 0)
		velTex1++;
	if (velTex1 == 8)
		velTex1 = 0;
	frame1++;
}

void Slime::andar()
{
	if (lado == Lado::esquerda)
	{
		forma.setScale(Vector2f(1, 1));
		andarEsquerda();
	}

	else if (lado == Lado::direita)
	{
		forma.setScale(Vector2f(-1, 1));
		andarDireita();
	}
	if (velocidade.x >= velocidade_max)
		velocidade = { velocidade_max, velocidade.y };
	else if (velocidade.x <= -velocidade_max)
		velocidade = { -velocidade_max, velocidade.y };
}

void Slime::andarDireita()
{
	if (posicao.x <= 1920.f - 250.f) //Player nao passar dos limites da tela esquerda
	{ 
		velocidade = { velocidade.x + 1.f, velocidade.y };
		posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	}
	else
	{
		velocidade = { 0.f,0.f };
		lado = Lado::esquerda;
	}
}

void Slime::andarEsquerda()
{
	if (posicao.x >= 100.f) //Player nao passar dos limites da tela esquerda
	{ 
		velocidade = { velocidade.x - 1.f, velocidade.y };
		posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	}
	else
	{
		velocidade = { 0.f,0.f };
		lado = Lado::direita;
	}
}