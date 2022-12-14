#pragma once
#include "Inimigo.h"
#include "stdafx.h"

class Esqueleto : public Inimigo
{
private:
	int frame1, velTex1, aux1;
	Texture tEnemy[11], tEnemyAnda[8];

	void iniciarTexturas();

public:
	void atualizaTextura();
	void andarDireita();
	void andarEsquerda();
	void andar();

	void executar();
	void colisao(Entidade* outrao,Vector2f ds);

	Esqueleto(int i = 10, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 150.f, 100.f });
	~Esqueleto();
};