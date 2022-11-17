#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Personagem : public Entidade
{
protected:
	int vidas;
	bool podeAtacar;
	bool estaMorto;
	bool atacou;

public:
	Personagem(int i = 0, Vector2f pos = {0.f, 0.f}, Vector2f tam = { 0.f, 0.f });
	~Personagem();

	//virtual void atualizaJogador() = 0;

	void setAtaque(bool foiAtacado);
	bool getAtaque();

	void setVidas(const int nr_vd);
	const int getVidas() const;

	void setPodeAtacar(const bool atc);
	const bool getPodeAtacar() const;

	void setEstaMorto(const bool mrt);
	const bool getEstaMorto() const;
};