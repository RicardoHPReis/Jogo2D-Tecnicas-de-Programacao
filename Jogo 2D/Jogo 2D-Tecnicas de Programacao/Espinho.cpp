#include "Espinho.h"

Espinho::Espinho(int id, Vector2f pos, Vector2f tam) :
    Obstaculo(id, pos, tam)
{
	velocidade = Vector2f{ 0.f,0.f };
    forma.setFillColor(Color::Yellow);
    dano = 0;
    danoso = false;
    paralisar = false;
    paralisacao = 60;
    tempo = 0;
	cout << "Criou espinho!" << endl;
}

Espinho::~Espinho()
{
    paralisar = false;
    paralisacao = 0;
    tempo = 0;
}

void Espinho::executar()
{
    if (tempo == 0)
    {
        setPosicao(posicao);
    }

	calculaQueda();
    
	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
    /*if (tempo > 0)
    {
        tempo += 1;
        if (tempo >= 240)
            tempo = 0;
    }*/
}

void Espinho::colisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
		case(int(ID::plataforma)): //id da plataforma
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
		}
		break;
		case(int(ID::fogo)): //id do esqueleto
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
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