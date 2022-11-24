#include "Chefao.h"


Chefao::Chefao(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	iniciarTexturas();
	podeAtacar = true;
	vida = 10000;
	lado = Lado::direita;
	atacou = false;
	dano = 3000;
	danoso = true;
	velocidade_max = 6;
	velocidade = { 4.f, 0.f };
	projetil = new Projetil();
	cout << "Criou Chefao!" << endl;
}

Chefao::~Chefao()
{
	danoso = false;
	delete projetil;
}

void Chefao::iniciarTexturas()
{
	/*if (!this->tEnemy[0].loadFromFile("../../Texturas/Personagens/Chefao/Parado.png", IntRect(20, 0, 270, 386))) {
		cout << "Erro ao carregar a textura do Chefao parado\n";
	}
	tEnemy[0].setSmooth(true);

	for (int i = 0; i < 10; i++)
	{
		if (!this->tEnemy[i + 1].loadFromFile("../../Texturas/Personagens/Chefao/Parado.png", IntRect(20 + ((i + 1) * 290), 0, 270, 386))) {
			cout << "Erro ao carregar a textura do Chefao parado\n";
		}
		tEnemy[i + 1].setSmooth(true);
	}

	// Texturas inimigo Andando
	for (int i = 0; i < 13; i++)
	{
		if (!this->tEnemyAnda[i].loadFromFile("../../Texturas/Personagens/Chefao/Andar.png", IntRect((i * 257), 0, 250, 385))) {
			cout << "Erro ao carregar a textura do Chefao andando\n";
		}
		tEnemyAnda[i].setSmooth(true);
	}*/
	forma.setFillColor(Color::Magenta);
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

	//forma.setTexture(&tEnemyAnda[velTex1]); // Erro
}

void Chefao::colisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
		case(int(ID::plataforma)): //id da plataforma
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
		case(int(ID::espinho)): //id do Relampago
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
		}
		break;
		case(int(ID::fogo)): //id do Fogo
		{
			vida -= outro->getDano();
		}
		break;
		case(int(ID::esqueleto)): //id do Esqueleto
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
		case(int(ID::morcego)): //id do Morcego
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

void Chefao::atualizaTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (frame1 % 7 == 0)
		velTex1++;
	if (velTex1 == 13)
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

}

void Chefao::andarDireita()
{
	if (posicao.x <= 1920.f - 250.f) //Player nao passar dos limites da tela esquerda
	{
		posicao.x = posicao.x + velocidade.x;
	}
	else
	{
		lado = Lado::esquerda;
	}
}

void Chefao::andarEsquerda()
{
	if (posicao.x >= 100.f) //Player nao passar dos limites da tela esquerda
	{
		posicao.x = posicao.x - velocidade.x;
	}
	else
	{
		lado = Lado::direita;
	}
}

void Chefao::disparar()
{
	projetil->setPosicao(getPosicao());
	projetil->setLado(getLado());
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