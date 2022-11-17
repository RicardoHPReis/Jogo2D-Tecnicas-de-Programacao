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
	Projetil(int i = 1000, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 50.f, 80.f });
	~Projetil();
	
	void atualizar();

	void setAtirar(bool tir);
	bool getAtirar();

	void setAtingiu(const bool atg);
	const bool getAtingiu() const;

	void atualizaProjetil();
	void atirar();

	void setDanoso(const bool mal);
	const bool getDanoso() const;
};