#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Player : public Personagem
{
protected:
	bool nocivo;

public:
	Player(int id = 0, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 0,0 }, int nr_vidas = 0, int nr_dano = 0, int ld = 0, bool atacar = true, bool morreu = false, bool foiAtacado = false, bool nocv = true);
	virtual ~Player();

	virtual void atualizaJogador() = 0;
};