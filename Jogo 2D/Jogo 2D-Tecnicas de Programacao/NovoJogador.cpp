#include "NovoJogador.h"

NovoJogador::NovoJogador():
Personagem()
{
	jogador_pulou = false;
}

NovoJogador::~NovoJogador()
{
	jogador_pulou = false;
}

void NovoJogador::setPulou(const bool pulou)
{
	jogador_pulou = pulou;
}

const bool NovoJogador::getPulou() const
{
	return jogador_pulou;
}