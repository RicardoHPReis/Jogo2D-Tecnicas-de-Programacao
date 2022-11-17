#pragma once
#include "Ente.h"
#include "stdafx.h"

class Entidade : public Ente
{
protected:
	RectangleShape forma;
	Vector2f posicao;
	Vector2f tamanho;
	Vector2f velocidade;
	float velocidade_max;
	float gravidade;
	int dano;
	int lado;
	bool seMovimenta;

public:
	Entidade(int i = 0, Vector2f pos = {0.f, 0.f}, Vector2f tam = { 0.f, 0.f });
	virtual ~Entidade();

	//virtual void executar() = 0;
	//virtual void imprimir() = 0;

	RectangleShape getForma();

	void setPosicao(const Vector2f pos);
	const Vector2f getPosicao() const;

	void setTamanho(const Vector2f tam);
	const Vector2f getTamanho() const;

	void setSeMovimenta(const bool mov);
	const bool getSeMovimenta() const;

	void setDano(const int nr_dano);
	const int getDano() const;

	void setVelocidade(const Vector2f vel);
	const Vector2f getVelocidade() const;

	void setVelocidadeMaxima(const float vel_max);
	const float getVelocidadeMaxima() const;

    void setGravidade(const float grav);
    const float getGravidade() const;

	void setLado(const int ld);
	const int getLado() const;

    void calculaQueda();
};