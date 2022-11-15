#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Personagem : public Entidade
{
protected:
	int vidas;
	int dano;
	int lado;
	bool podeAtacar;
	bool estaMorto;
	bool atacou;

public:
	Personagem(int id = 0, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 0,0 }, int nr_vidas = 0, int nr_dano = 0, int ld = 0, bool atacar = true, bool morreu = false, bool foiAtacado = false);
	~Personagem();

	void setAtaque(bool foiAtacado);
	bool getAtaque();

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