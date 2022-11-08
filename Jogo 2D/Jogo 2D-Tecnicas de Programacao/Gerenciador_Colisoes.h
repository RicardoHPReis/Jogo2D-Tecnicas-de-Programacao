#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "stdafx.h"

class Gerenciador_Colisoes
{
private:
	//static Gerenciador_Colisoes* instancia_colisoes;

	vector<Inimigo*> inimigos;
	list<Obstaculo*> obstaculos;
	bool colidiu;

	//Gerenciador_Colisoes();

public:
	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();
	//static Gerenciador_Colisoes* getInstancia_Colisoes();

	bool colisao();
};