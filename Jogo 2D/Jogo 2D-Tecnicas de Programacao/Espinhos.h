#pragma once
#include "Obstaculo.h"
#include "stdafx.h"

class Espinhos :public Obstaculo
{
private:

public:
	Espinhos();
	~Espinhos();

	void executar();
	void imprimir();
};