#pragma once
#include "stdafx.h"
#include "Obstaculo.h"

class Chao :public Obstaculo
{
protected:


public:
	Chao();
	~Chao();

	void executar();
	void imprimir();
};
