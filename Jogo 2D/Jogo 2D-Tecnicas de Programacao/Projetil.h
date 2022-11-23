#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Projetil : public Entidade
{
protected:

	bool atingiu;
	bool tiro;

	bool danoso;

	//Texture tiro[], acerto[];

	void inicProjetil();

	void iniciarTexturas();

public:
	Projetil(int i = 1000, Vector2f pos = { 900.f, 900.f }, Vector2f tam = { 40.f, 20.f });
	~Projetil();

	void setAtirar(bool tir);
	bool getAtirar();

	void setAtingiu(const bool atg);
	const bool getAtingiu() const;

	void executar();
	void atirar();
	void colisao(Entidade* outrao, Vector2f ds);

	void setDanoso(const bool mal);
	const bool getDanoso() const;
};