#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "stdafx.h"

class Morcego : public Inimigo
{
private:
	int frame1, velTex1, aux1;
	Texture tEnemy[5], tEnemyVoa[5];
	RectangleShape chao;

	Projetil *tiro;

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
	void disparar();

	void atualizaInimigo();

	Morcego(int i = 11, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 110.f, 85.f });
	~Morcego();
};