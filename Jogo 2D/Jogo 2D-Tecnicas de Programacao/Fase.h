#pragma once
#include "Gerenciador_Colisoes.h"
#include "stdafx.h"

class Fase
{
protected:
	Gerenciador_Colisoes* colisao;
	float gravidade;

public:
	Fase();
	~Fase();

	void setGravidade(const float grav);
	const float getGravidade() const;

	virtual void iniciarFase() = 0;
};
