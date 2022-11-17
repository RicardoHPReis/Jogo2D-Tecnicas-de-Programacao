#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Obstaculo : public Entidade
{
protected:
	bool danoso;

public:
	Obstaculo(int i = 0, Vector2f pos = {0.f, 0.f}, Vector2f tam = { 0.f, 0.f });
	virtual ~Obstaculo();

	//virtual void executado()=0;
	void setDanoso(const bool mal);
	const bool getDanoso() const;

};