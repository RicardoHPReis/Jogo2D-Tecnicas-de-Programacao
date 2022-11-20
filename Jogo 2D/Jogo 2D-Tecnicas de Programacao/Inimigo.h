#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:
	bool danoso;
	short movimento;
	sf::Clock relogio;

public:
	Inimigo(int i = 0, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 0.f, 0.f });
	virtual ~Inimigo();

	virtual void executar() = 0;
	void setDanoso(const bool mal);
	const bool getDanoso() const;
};