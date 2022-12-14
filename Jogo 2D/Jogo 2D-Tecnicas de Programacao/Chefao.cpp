#include "Chefao.h"
//using namespace Entidades;
//using namespace Personagens;

Chefao::Chefao(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	projetil = new Projetil();

	iniciarTexturas();
	vida = 500;
	lado = Lado::direita;
	atacou = false;
	dano = 300;
	danoso = true;
	velocidade_max = 6;
	velocidade = { 4.f, 0.f };
	velTex1 = 0;
	cout << "Criou Chefao!" << endl;
}

Chefao::~Chefao()
{
	danoso = false;
	delete projetil;
}

void Chefao::iniciarTexturas()
{

	for (int i = 0; i < 8; i++)
	{
		if (!this->tEnemy[i].loadFromFile("../../Texturas/Personagens/Necromancer.png", IntRect(100 + (i * 353), 115, 140, 160))) {
			cout << "Erro ao carregar a textura do Chefao parado\n";
		}
		tEnemy[i].setSmooth(true);
	}
}

void Chefao::executar()
{
	setPosicao(posicao);
	andar();
	atualizaTextura();

	calculaQueda();

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);

	forma.setTexture(&tEnemy[velTex1]);

	if (projetil->getAtirar() == false)
	{
		disparar();
	}
	else
	{
		projetil->executar();
	}
}

void Chefao::reageColisao(Entidade* outro, Vector2f dist_colisao)
{
	switch (outro->getId())
	{
		case(int(ID::plataforma)): //id da plataforma
		{
			Vector2f distancia;
			distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
						  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

			if (dist_colisao.x > dist_colisao.y)
			{
				/*if (distancia.x > 0.f)
				{
					setPosicao(Vector2f(posicao.x + dist_colisao.x, posicao.y));
				}
				else
				{
					setPosicao(Vector2f(posicao.x - dist_colisao.x, posicao.y));
				}*/
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
					setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y));
				}
			}
		}
		break;

	}
}

void Chefao::atualizaTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (frame1 % 7 == 0)
		velTex1++;
	if (velTex1 == 8)
		velTex1 = 0;
	frame1++;
}

void Chefao::andar()
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
	if (velocidade.x >= velocidade_max)
		velocidade = { velocidade_max, velocidade.y };
	else if (velocidade.x <= -velocidade_max)
		velocidade = { -velocidade_max, velocidade.y };

}

void Chefao::andarDireita()
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

void Chefao::andarEsquerda()
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

void Chefao::disparar()
{
	if(lado == Lado::esquerda)
		projetil->setPosicao(Vector2f(posicao.x - tamanho.x,posicao.y + 50));
	else
		projetil->setPosicao(Vector2f(posicao.x + tamanho.x, posicao.y + 50));
	projetil->setLado(lado);
	projetil->setAtirar(true);
}

Projetil* Chefao::getProjetil()
{
	return projetil;
}

void Chefao::setProjetil(Projetil* proj)
{
	projetil = proj;
}