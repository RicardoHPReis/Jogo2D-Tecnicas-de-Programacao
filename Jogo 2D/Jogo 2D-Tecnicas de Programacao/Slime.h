#pragma once
#include "Inimigo.h"
#include "stdafx.h"
//using namespace Entidades;

class Slime : public Inimigo
{
private:
	int frame1, velTex1, aux1;
	int velocidade_Morte, frame0;
	Texture tEnemyDie[5], tEnemyAnda[8];

	void iniciarTexturas();

public:
	void atualizaTextura();
	void andarDireita();
	void andarEsquerda();
	void andar();

	void executar();
	void reageColisao(Entidade* outrao, Vector2f dist_colisao);

	Slime(int i = 10, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 150.f, 100.f });
	~Slime();
};

/*namespace Personagens
{
	class Slime : public Inimigo
	{
	private:
		int frame1, velTex1, aux1;
		int velocidade_Morte, frame0;
		Texture tEnemyDie[5], tEnemyAnda[8];

		void iniciarTexturas();

	public:
		void atualizaTextura();
		void andarDireita();
		void andarEsquerda();
		void andar();

		void executar();
		void reageColisao(Entidade* outrao, Vector2f dist_colisao);

		Slime(int i = 10, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 150.f, 100.f });
		~Slime();
	};
}*/