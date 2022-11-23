#include "Fogo.h"

Fogo::Fogo(int id, Vector2f pos, Vector2f tam) :
	Obstaculo(id, pos, tam)
{
	velocidade = Vector2f{ 0.f,0.f };
	forma.setFillColor(Color::Red);
	dano = 1;
	danoso = true;
	queimou = false;
	cout << "Criou fogo!" << endl;
}

Fogo::~Fogo()
{
	queimou = false;
}

void Fogo::executar()
{
	setPosicao(posicao);

	calculaQueda(); //aplicando gravidade nas plataformas voadoras que professor pediu

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
}

void Fogo::colisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
	case(int(ID::plataforma)): //id da plataforma
	{
		setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
		velocidade.x = 0.f;
		velocidade.y = 0.f;
		//jogador_pulou = false;
	}
	break;
	case(int(ID::espinho)): //id do esqueleto
	{

	}
	break;
	case(int(ID::esqueleto)): //id do esqueleto
	{
		//outro->
	}
	break;
	case(int(ID::morcego)): //id do morcego
	{
		//outro->
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