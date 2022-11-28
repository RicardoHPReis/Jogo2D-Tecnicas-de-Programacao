#include "Projetil.h"


Projetil::Projetil(int i, Vector2f pos, Vector2f tam):
Entidade(i, pos, tam)
{
	iniciarTexturas();
	inicProjetil();
	cout << "Criou projetil!" << endl;
}

Projetil::~Projetil()
{
	atingiu = false;
	danoso = false;
	atirando = false;
}

void Projetil::setDanoso(const bool mal)
{
	danoso = mal;
}

const bool Projetil::getDanoso() const
{
	return danoso;
}

void Projetil::setAtirar(bool tir)
{
	atirando = tir;
}

void Projetil::iniciarTexturas()
{
	if (!this->bolaRoxa.loadFromFile("../../Texturas/Personagens/BolaFogo.png")) 
	{
		cout << "Erro ao carregar a textura do Chefao parado\n";
	}
	bolaRoxa.setSmooth(true);
}

void Projetil::executar()
{
	atirar();

	velocidade = { velocidade.x, velocidade.y + aerodinamica + gravidade };

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
}

void Projetil::atirar()
{
	//Movimentos do projétil

	if (lado == Lado::direita)
		dispararDireita();
	else if (lado == Lado::esquerda)
		dispararEsquerda();
}

void Projetil::dispararDireita()
{
	Vector2f pos = forma.getPosition();
	pos += velocidade;

	velocidade = { velocidade.x + 0.2f, velocidade.y };
	posicao = { posicao.x + velocidade.x, posicao.y + velocidade.y };
	if (pos.x > 1900)
	{
		velocidade.x = 0.f;
		setAtirar(false);
	}

}

void Projetil::dispararEsquerda()
{
	Vector2f pos = forma.getPosition();
	pos += velocidade;

	velocidade = { velocidade.x - 0.2f, velocidade.y };
	posicao = { posicao.x + velocidade.x, posicao.y + velocidade.y };
	if (pos.x < 50)
	{
		velocidade.x = 0.f;
		setAtirar(false);
	}

}

void Projetil::reageColisao(Entidade* outro, Vector2f dist_colisao)
{
	switch (outro->getId())
	{
		case(int (ID::plataforma)): //id da plataforma
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

bool Projetil::getAtirar()
{
	return atirando;
}

void Projetil::inicProjetil()
{
	danoso = true;
	atirando = false;
	atingiu = false;
	aerodinamica = gravidade * -1;
	setVelocidade({ 1.f, 0.f });
	forma.setTexture(&bolaRoxa);
}

void Projetil::setAtingiu(const bool atg)
{
	atingiu = atg;
}

const bool Projetil::getAtingiu() const
{
	return atingiu;
}