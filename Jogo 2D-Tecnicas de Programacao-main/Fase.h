#pragma once
#include "Ente.h"
#include "stdafx.h"

class Fase : public Ente
{
protected:
	float gravidade;

public:
	Fase();
	~Fase();

	void setGravidade(const float grav);
	const float getGravidade() const;
};
