#pragma once
#include "Ente.h"
#include "stdafx.h"

class Entidade : public Ente
{
protected:
	RectangleShape *forma;
	Vector2f posicao;
	Vector2f tamanho;
	Vector2f velocidade;
	float velocidade_max;
	float empuxo;
	bool seMovimenta;
	bool tiraVida;

public:
	Entidade();
	//Entidade(bool mov = false, Vector2f vel = { 0,0 }, float vel_max = 0, bool danoso = false, int nr_id = 0, Vector2f pos = { 0,0 }, Vector2f coord = { 0,0 }, Vector2f tam = { 0,0 });
	virtual ~Entidade();

	virtual void executar() = 0;
	virtual void imprimir() = 0;

	const RectangleShape* getForma() const;

	void setPosicao(const Vector2f pos);
	const Vector2f getPosicao() const;

	void setTamanho(const Vector2f tam);
	const Vector2f getTamanho() const;

	void setSeMovimenta(const bool mov);
	const bool getSeMovimenta() const;

	void setVelocidadeY(const float vel);
	const float getVelocidadeY() const;

	void setVelocidadeX(const float vel);
	const float getVelocidadeX() const;

	void setVelocidadeMaxima(const float vel_max);
	const float getVelocidadeMaxima() const;

	void setEmpuxo(const float empx);
	const float getEmpuxo() const;

	void setTiraVida(const bool danoso);
	const bool getTiraVida() const;
};