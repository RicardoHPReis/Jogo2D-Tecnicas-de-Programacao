#pragma once
#include "Inimigo.h"
#include "stdafx.h"

class Morcego : public Inimigo
{
private:
	int frame1, velTex1, aux1;
	Texture tEnemy[5], tEnemyVoa[5];
	RectangleShape chao;

	void iniciarTexturas();
	void iniciarStatus();
	void inicEnemies();
public:
	
	void atualizaTextura();
	void voarDireita();
	void voarEsquerda();
	void voarCima();
	void voarBaixo();
	void voar();

	void atualizaInimigo();

	Morcego(int id = 0, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 0,0 }, int nr_vidas = 0, int nr_dano = 0, int ld = 0, bool atacar = true, bool morreu = false, bool foiAtacado = false, bool nocv = true);
	~Morcego();
};