#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "stdafx.h"

class Gerenciador_Colisoes
{
private:
	vector<Inimigo*> inimigos;
	list<Obstaculo*> obstaculos;
	bool colidiu;

public:
	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();

	bool colisao();
};
