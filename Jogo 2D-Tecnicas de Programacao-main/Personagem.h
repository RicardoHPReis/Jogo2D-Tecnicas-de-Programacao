#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Personagem :public Entidade
{
protected:
	int vidas;
	int dano;
	int lado;
	bool podeAtacar;
	bool estaMorto;

public:
	Personagem();
	~Personagem();

	void setVidas(const int nr_vd);
	const int getVidas() const;

	void setDano(const int nr_dano);
	const int getDano() const;

	void setLado(const int ld);
	const int getLado() const;

	void setPodeAtacar(const bool atc);
	const bool getPodeAtacar() const;

	void setEstaMorto(const bool mrt);
	const bool getEstaMorto() const;
};