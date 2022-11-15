#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Ente.h"

class Inimigo : public Ente
{
protected:

	bool nocivo;

	int frame1, velTex1, aux1;

	float xpos, ypos;

	Ente* Tela;

	Texture tEnemy[11], tEnemyAnda[13];

	RectangleShape chao;

	VideoMode videoModeE;

	void inicEnemies();

	void spawnInimigo();

	void iniciarTexturas();

	void iniciarStatus();

	void atualizaTextura();

	void andarDir();

	void andarEsq();

	void andar();

public:

	Personagem* status;

	RectangleShape esqueleto;

	void atualizaInimigo();

	Inimigo();
	~Inimigo();
};
