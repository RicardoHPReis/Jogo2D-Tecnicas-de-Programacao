#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Personagem : public Entidade
{
protected:
	int vidas;
	int dano;
	int lado;
	float vida;
	bool podeAtacar;
	bool estaMorto;
	bool atacou;
	bool estaAndando;
	bool estaParado;

public:

	Personagem();
	~Personagem();

	void setAtaque(bool nr_vd);
	bool getAtaque();

	void setVidas(const int nr_vd);
	const int getVidas() const;

	void setDano(const int nr_dano);
	const int getDano() const;

	void setLado(int ld);
	int getLado();

	void setPodeAtacar(const bool atc);
	const bool getPodeAtacar() const;

	void setEstaMorto(const bool mrt);
	const bool getEstaMorto() const;

	void setEstaAndando( bool mrt);
	bool getEstaAndando() ;

	void setEstaParado(bool mrt);
	bool getEstaParado()
};