#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "stdafx.h"

class Morcego : public Inimigo
{
private:

	float forcaVoar;
	int frame1, velTex1, aux1;
	Texture tEnemyDie[5], tEnemyVoa[5];

	void iniciarTexturas();
public:
	
	void atualizaTextura();
	void voarDireita();
	void voarEsquerda();
	void voarCima();
	void voarBaixo();
	void voar();
	void disparar();

	void executar();
	void colisao(Entidade* outrao,Vector2f ds);

	Morcego(int i = 11, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 110.f, 85.f });
	~Morcego();
};