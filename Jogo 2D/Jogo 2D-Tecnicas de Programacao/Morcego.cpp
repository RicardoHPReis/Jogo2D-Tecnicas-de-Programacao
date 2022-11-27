#include "Morcego.h"


Morcego::Morcego(int i, Vector2f pos, Vector2f tam) :
	Inimigo(i, pos, tam)
{
	iniciarTexturas();
	vida = 10;
	atacou = false;
	dano = 75;
	velocidade_Textura = 0;
	velocidade_max = 1;
	lado = Lado::direita;
	danoso = true;
	estaMorto = false;
	velocidade = { 0.f, 0.f };
	forcaVoar = gravidade * -1;
	cout << "Criou morcego!" << endl;
}

Morcego::~Morcego()
{
	danoso = false;
	forcaVoar = 0.f;
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
		if (!this->tEnemyVoa[i].loadFromFile("../../Texturas/Personagens/Morcego.png", IntRect(i * 100, 164, 100, 85))) {
			cout << "Erro ao carregar a textura do Morcego voando\n";
		}
		tEnemyVoa[i].setSmooth(true);
	}
}

void Morcego::executar()
{	
	if(estaMorto == false){
        atualizarTextura();
        forma.setTexture(&tEnemyVoa[velocidade_Textura]);
	}
	voar();
	atualizarTextura();

	calculaQueda();

	posicao = forma.getPosition();
	posicao += velocidade;
	setPosicao(posicao);
	
}

void Morcego::atualizarTextura()
{
	//muda para a proxima textura a cada 7 frames
	if (frame1 % 7 == 0)
        velocidade_Textura++;
	if (velocidade_Textura == 5)
        velocidade_Textura = 0;
	frame1++;
}

void Morcego::voar()
{
	if (lado == Lado::esquerda)
	{
		if (forma.getScale().x == 1) 
		{
			forma.setScale(Vector2f(-1, 1));
		}
		voarEsquerda();
	}

	else if (lado == Lado::direita)
	{
		if (forma.getScale().x == -1)
		{
			forma.setScale(Vector2f(1, 1));
		}
		voarDireita();
	}
	if (posicao.x > Gerenciador_Grafico::getInstancia_Grafico()->getVideo().width / 2.f)
	{
		velocidade.y = 0.f;
		voarBaixo();
		
	}
	if(posicao.x < Gerenciador_Grafico::getInstancia_Grafico()->getVideo().width / 2.f && posicao.y > 0)
	{
		velocidade.y = 0.f;
		voarCima();
	}
}

void Morcego::disparar()
{
	//tiro->setPosicao(getPosicao());
	//tiro->setLado(getLado());
	//tiro->setAtirar(true);
}

void Morcego::voarDireita()
{
	Vector2f pos = forma.getPosition();
	pos += velocidade;

	velocidade = { velocidade.x + 0.3f, velocidade.y };
	posicao = { posicao.x + velocidade.x, posicao.y + velocidade.y };
	if (pos.x > 1900) 
	{
		lado = Lado::esquerda;
		velocidade.x = 0.f;
	}
		
}

void Morcego::voarEsquerda()
{
	Vector2f pos = forma.getPosition();
	pos += velocidade;

	velocidade = { velocidade.x - 0.3f, velocidade.y };
	posicao = { posicao.x + velocidade.x, posicao.y + velocidade.y };
	if (pos.x < 50) 
	{

		lado = Lado::direita;
		velocidade.x = 0.f;
	}

}

void Morcego::voarCima()
{
	velocidade = { velocidade.x, velocidade.y - 1.50f};
}

void Morcego::voarBaixo()
{
	velocidade = { velocidade.x, velocidade.y + 1.50f };
}

void Morcego::reageColisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
	case(int(ID::plataforma)): //id da plataforma
	{
		/* Vector2f distancia;
		distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
					  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

		if (ds.x > ds.y)
		{
			if (distancia.x > 0.f)
			{
				setPosicao(Vector2f(posicao.x + ds.x, posicao.y));
				velocidade.x = 0;
			}
			else
			{
				setPosicao(Vector2f(posicao.x - ds.x, posicao.y));
				velocidade.x = 0;
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
				setPosicao(Vector2f(posicao.x, posicao.y - ds.y)); // TETO
			}
		}*/
	}
	break;
	case(int(ID::relampago)): //id do Slime
	{
		setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
		velocidade.x = 0.f;
		velocidade.y = 0.f;
	}
	break;
	case(int(ID::fogo)): //id do Slime
	{

	}
	break;
	case(int(ID::slime)): //id do Slime
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

void Morcego::calculaQueda()
{
	velocidade = { velocidade.x, velocidade.y + gravidade + forcaVoar };
}