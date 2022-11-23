#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "stdafx.h"

class Chefao : public Inimigo
{
private:
	int frame1, velTex1, aux1;
	Texture tEnemy[11], tEnemyAnda[13];

	Projetil *projetil;

	void iniciarTexturas();

public:
	void atualizaTextura();
	void andarDireita();
	void andarEsquerda();
	void andar();
	void disparar();

	void executar();
	void colisao(Entidade* outrao, Vector2f ds);

	Chefao(int i = 12, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 300.f, 200.f });
	~Chefao();

	Projetil* getProjetil();
	void setProjetil(Projetil* proj);
};