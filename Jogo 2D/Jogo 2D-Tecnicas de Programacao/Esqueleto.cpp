#include "Esqueleto.h"


Esqueleto::Esqueleto(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	iniciarTexturas();
	podeAtacar = true;
	vida = 3000;
	atacou = false;
	dano = 50;
	lado = Lado::esquerda;
	danoso = true;
	velocidade_max = 1;
	velocidade = { 1.f, 0.f };
	velTex1 = 0;

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
	}*/

	// Texturas inimigo Andando
	for (int i = 0; i < 8; i++) 
	{
		if (!this->tEnemyAnda[i].loadFromFile("../../Texturas/Personagens/Slime.png", IntRect((i * 111), 0, 111, 85))) {
			cout << "Erro ao carregar a textura do esqueleto andando\n";
		}
		tEnemyAnda[i].setSmooth(true);
	}
}

void Esqueleto::executar()
{
	setPosicao(posicao);
	
	andar();
	atualizaTextura();
	forma.setTexture(&tEnemyAnda[velTex1]);

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
			Vector2f distancia;
			distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
						  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

			if (ds.x > ds.y)
			{
				if (distancia.x > 0.f)
				{
					setPosicao(Vector2f(posicao.x + ds.x, posicao.y));
				}
				else
				{
					setPosicao(Vector2f(posicao.x - ds.x, posicao.y));
				}
			}
			else
			{
				if (distancia.y > 0.f)
				{
					setPosicao(Vector2f(posicao.x, posicao.y + ds.y)); // CHAO
					velocidade.y = 0.f;
				}
				else
				{
					setPosicao(Vector2f(posicao.x, posicao.y - ds.y));
				}
			}
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
			Vector2f distancia;
			distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
						  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

			if (ds.x > ds.y)
			{
				if (distancia.x > 0.f)
				{
					setPosicao(Vector2f(posicao.x + ds.x, posicao.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x - ds.x, outro->getPosicao().y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
				else
				{
					setPosicao(Vector2f(posicao.x - ds.x, posicao.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x + ds.x, outro->getPosicao().y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
			}
			else
			{
				if (distancia.y > 0.f)
				{
					setPosicao(Vector2f(posicao.x, posicao.y + ds.y)); // CHAO
					outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y - ds.y));
					outro->setVelocidade({ outro->getVelocidade().x,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
				else
				{
					setPosicao(Vector2f(posicao.x, posicao.y - ds.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y + ds.y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
			}
		}
		break;
		case(int(ID::morcego)): //id do morcego
		{
			Vector2f distancia;
			distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
						  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

			if (ds.x > ds.y)
			{
				if (distancia.x > 0.f)
				{
					setPosicao(Vector2f(posicao.x + ds.x, posicao.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x - ds.x, outro->getPosicao().y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
				else
				{
					setPosicao(Vector2f(posicao.x - ds.x, posicao.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x + ds.x, outro->getPosicao().y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
			}
			else
			{
				if (distancia.y > 0.f)
				{
					setPosicao(Vector2f(posicao.x, posicao.y + ds.y)); // CHAO
					outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y - ds.y));
					outro->setVelocidade({ outro->getVelocidade().x,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
				else
				{
					setPosicao(Vector2f(posicao.x, posicao.y - ds.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y + ds.y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
			}
		}
		break;
		case(int(ID::mago)): //id do mago
		{
			Vector2f distancia;
			distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
						  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

			if (ds.x > ds.y)
			{
				if (distancia.x > 0.f)
				{
					setPosicao(Vector2f(posicao.x + ds.x, posicao.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x - ds.x, outro->getPosicao().y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
				else
				{
					setPosicao(Vector2f(posicao.x - ds.x, posicao.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x + ds.x, outro->getPosicao().y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
			}
			else
			{
				if (distancia.y > 0.f)
				{
					setPosicao(Vector2f(posicao.x, posicao.y + ds.y)); // CHAO
					outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y - ds.y));
					outro->setVelocidade({ outro->getVelocidade().x,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
				else
				{
					setPosicao(Vector2f(posicao.x, posicao.y - ds.y));
					outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y + ds.y));
					outro->setVelocidade({ 0,0 });
					if (outro->getLado() == Lado::esquerda)
						outro->setLado(Lado::direita);
					else
						outro->setLado(Lado::esquerda);
				}
			}
		}
		break;
	}
}

void Esqueleto::atualizaTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (frame1 % 7 == 0)
		velTex1++;
	if (velTex1 == 8)
		velTex1 = 0;
	frame1++;
}

void Esqueleto::andar()
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

void Esqueleto::andarDireita()
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

void Esqueleto::andarEsquerda()
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