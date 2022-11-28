#include "Jogador.h"
//using namespace Entidades;
//using namespace Personagens;

Jogador::Jogador(int i, Vector2f pos, Vector2f tam):
	Personagem(i, pos, tam)
{
	levou_dano = false;
	jogador_pulou = false;
	forcaPulo = 25.f;
	spVida.resize(vida / 100);
}

Jogador::~Jogador()
{
	levou_dano = false;
	jogador_pulou = false;
	forcaPulo = 0.f;

	for (int i = 0; i < vida/100; i++)
	{
		spVida.pop_back();
	}
}

void Jogador::atualizavida()
{
	for (int i = 0; i < (vida / 100); i++)
	{
		Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(spVida[i]);
	}
}


void Jogador::operator--(int dano)
{
	vida -= dano;
	levou_dano = true;
}

const bool Jogador::getLevouDano() const
{
	return levou_dano;
}

void Jogador::setLevouDano(const bool levou_dn)
{
	levou_dano = levou_dn;
}

const bool Jogador::getPulou() const
{
	return jogador_pulou;
}

void Jogador::setPulou(const bool pulou)
{
	jogador_pulou = pulou;
}

const float Jogador::getForcaPulo() const
{
	return forcaPulo;
}

void Jogador::setForcaPulo(const float force)
{
	forcaPulo = force;
}