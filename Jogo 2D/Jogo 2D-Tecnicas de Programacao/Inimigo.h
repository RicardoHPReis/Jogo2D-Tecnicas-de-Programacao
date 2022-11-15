#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Ente.h"

class Inimigo : public Personagem
{
protected:

	bool nocivo;

	int frame1, velTex1, aux1;

	Ente* Tela;

	Texture tEnemy[11];

	RectangleShape chao;

	VideoMode videoModeE;

	void inicEnemies();

	void spawnInimigo();

	void iniciarTexturas();

	void iniciarStatus();

public:
	RectangleShape inimigo;

	void atualizaInimigo();

	Inimigo();
	~Inimigo();
};