#pragma once
#include "stdafx.h"
#include "Ente.h"

class Fase : public Ente
{
protected:
	float gravidade;
	//lista<Entidade*> N�o foi feito ainda

public:
	Fase();
	~Fase();

	void setGravidade(const float grav);
	const float getGravidade() const;
};
