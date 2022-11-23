#include "Projetil.h"


Projetil::Projetil(int i, Vector2f pos, Vector2f tam):
Entidade(i, pos, tam)
{
	inicProjetil();
	forma.setFillColor(Color::Cyan);
	danoso = true;
	tiro = false;
	atingiu = false;
	cout << "Criou projetil!" << endl;
}

Projetil::~Projetil()
{
	atingiu = false;
	danoso = false;
	tiro = false;
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
	tiro = tir;
}

void Projetil::iniciarTexturas()
{

}

void Projetil::executar()
{
	setPosicao(posicao);
	calculaQueda();
	atirar();
	if ((posicao.x <= 0 || posicao.x >= 1920) || posicao.y >= 1000) //Modificar depois para gerenciador de colisoes
		setAtirar(false);
}

void Projetil::atirar()
{
	//Movimentos do projétil

	posicao.y = posicao.y + velocidade.y;
	if (lado == Lado::direita)
		posicao.x = posicao.x + velocidade.x;
	else if (lado == Lado::esquerda)
		posicao.x = posicao.x - velocidade.x;
}

void Projetil::colisao(Entidade* outro, Vector2f ds)
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

bool Projetil::getAtirar()
{
	return tiro;
}

void Projetil::inicProjetil()
{
	atingiu = false;
	tiro = false;
	setVelocidade({ 5.f, 15.f });
}

void Projetil::setAtingiu(const bool atg)
{
	atingiu = atg;
}

const bool Projetil::getAtingiu() const
{
	return atingiu;
}