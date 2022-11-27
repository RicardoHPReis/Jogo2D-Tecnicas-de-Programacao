#include "Jogador.h"


//Gerenciador_Eventos* Gerenciador_Eventos::instancia_eventos = Gerenciador_Eventos::getInstancia_Eventos();

Jogador::Jogador(int i, Vector2f pos, Vector2f tam):
	Personagem(i, pos, tam),
	spVida(),
	txVida()
{
	levou_dano = false;
	jogador_pulou = false;
	forcaPulo = 25.f;
}

Jogador::~Jogador()
{
	levou_dano = false;
	jogador_pulou = false;
	forcaPulo = 0.f;
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