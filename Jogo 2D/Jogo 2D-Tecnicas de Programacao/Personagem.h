#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Personagem : public Entidade
{
protected:
	bool estaMorto;
	bool atacou;

public:
	Personagem(int i = 0, Vector2f pos = {0.f, 0.f}, Vector2f tam = { 0.f, 0.f });
	~Personagem();

	virtual void executar() = 0;
	virtual void reageColisao(Entidade* outro, Vector2f ds) = 0;

	void setAtacou(bool foiAtacado);
	const bool getAtacou() const;

	void setEstaMorto(const bool mrt);
	const bool getEstaMorto() const;
};