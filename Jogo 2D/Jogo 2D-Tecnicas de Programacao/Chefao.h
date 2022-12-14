#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "stdafx.h"
//using namespace Entidades;

class Chefao : public Inimigo
{
private:
	int frame1, velTex1;
	Texture tEnemy[8], tEnemyAnda[13];

	Projetil* projetil;

	void iniciarTexturas();

public:
	void atualizaTextura();
	void andarDireita();
	void andarEsquerda();
	void andar();
	void disparar();

	void executar();

	void reageColisao(Entidade* outrao, Vector2f dist_colisao);

	Chefao(int i = 12, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 250.f, 275.f });
	~Chefao();

	Projetil* getProjetil();
	void setProjetil(Projetil* proj);
};

/*namespace Personagens
{
	class Chefao : public Inimigo
	{
	private:
		int frame1, velTex1;
		Texture tEnemy[8], tEnemyAnda[13];

		Projetil* projetil;

		void iniciarTexturas();

	public:
		void atualizaTextura();
		void andarDireita();
		void andarEsquerda();
		void andar();
		void disparar();

		void executar();

		void reageColisao(Entidade* outrao, Vector2f dist_colisao);

		Chefao(int i = 12, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 250.f, 275.f });
		~Chefao();

		Projetil* getProjetil();
		void setProjetil(Projetil* proj);
	};
}*/