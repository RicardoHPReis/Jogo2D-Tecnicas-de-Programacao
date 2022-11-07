#pragma once
#include "Ente.h"
#include "stdafx.h"

class Entidade : public Ente
{
protected:
	bool seMovimenta;
	Vector2f velocidade;
	float velocidade_max;
	bool tiraVida;

public:
	Entidade();
	//Entidade(bool mov = false, Vector2f vel = { 0,0 }, float vel_max = 0, bool danoso = false, int nr_id = 0, Vector2f pos = { 0,0 }, Vector2f coord = { 0,0 }, Vector2f tam = { 0,0 });
	~Entidade();

	void setSeMovimenta(const bool mov);
	const bool getSeMovimenta() const;

	void setVelocidade(const Vector2f vel);
	const Vector2f getVelocidade() const;

	void setVelocidadeMaxima(const float vel_max);
	const float getVelocidadeMaxima() const;

	void setTiraVida(const bool danoso);
	const bool getTiraVida() const;
};