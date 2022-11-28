#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "stdafx.h"

class Morcego : public Inimigo
{
private:
	float forcaVoar;
	int frame1, velocidade_Textura, aux1;
	bool voar_Cima;
	Texture tEnemyDie[5], tEnemyVoa[5];

	void iniciarTexturas();
public:
	Morcego(int i = 11, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 110.f, 85.f });
	~Morcego();

	void atualizarTextura();
	void voarDireita();
	void voarEsquerda();
	void voarCima();
	void voarBaixo();
	void voar();

	void executar();
	void reageColisao(Entidade* outrao,Vector2f dist_colisao);
	void calculaQueda();
};