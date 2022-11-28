#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Projetil : public Entidade
{
protected:

	Texture bolaRoxa;

	bool atingiu;
	bool atirando;
	bool danoso;

	float aerodinamica;

	//Texture tiro[], acerto[];

	void inicProjetil();

	void iniciarTexturas();

public:
	Projetil(int i = 1000, Vector2f pos = { 0.f,0.f }, Vector2f tam = { 60.f, 60.f });
	~Projetil();

	void setAtirar(bool tir);
	bool getAtirar();

	void setAtingiu(const bool atg);
	const bool getAtingiu() const;

	void executar();
	void atirar();
	void dispararDireita();
	void dispararEsquerda();
	void reageColisao(Entidade* outrao, Vector2f dist_colisao);

	void setDanoso(const bool mal);
	const bool getDanoso() const;
};