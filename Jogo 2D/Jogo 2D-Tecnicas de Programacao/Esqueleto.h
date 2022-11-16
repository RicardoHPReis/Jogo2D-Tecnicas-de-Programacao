#pragma once
#include "Inimigo.h"
#include "stdafx.h"

class Esqueleto : public Inimigo
{
private:
	int frame1, velTex1, aux1;
	Texture tEnemy[11], tEnemyAnda[13];
	RectangleShape chao;

	void iniciarTexturas();
	void iniciarStatus();
	void inicEnemies();
public:
	void spawnInimigo();
	void atualizaTextura();
	void andarDireita();
	void andarEsquerda();
	void andar();

	void atualizaInimigo();

	Esqueleto(int id = 0, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 0,0 }, int nr_vidas = 0, int nr_dano = 0, int ld = 0, bool atacar = true, bool morreu = false, bool foiAtacado = false, bool nocv = true);
	~Esqueleto();
};