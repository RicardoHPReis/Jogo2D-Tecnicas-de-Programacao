#pragma once
#include "stdafx.h"
#include "Personagem.h"

class NovoJogador : public Personagem
{
private:
	bool jogador_pulou;

public:
	NovoJogador();
	~NovoJogador();

	void setPulou(const bool pulou);
	const bool getPulou() const;
};
