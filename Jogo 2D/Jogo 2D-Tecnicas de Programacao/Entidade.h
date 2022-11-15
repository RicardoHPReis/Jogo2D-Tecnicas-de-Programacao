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
	bool seMovimenta;

public:
	Entidade(int id = 0, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 0,0 });
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

	void setVelocidade(const Vector2f vel);
	const Vector2f getVelocidade() const;

	void setVelocidadeMaxima(const float vel_max);
	const float getVelocidadeMaxima() const;
};