#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "stdafx.h"

class Gerenciador_Colisoes
{
private:
	vector<Inimigo*> listaInimigos;
	list<Obstaculo*> listaObstaculos;

	static Gerenciador_Colisoes* instancia_colisoes;
	Gerenciador_Colisoes();

public:
	~Gerenciador_Colisoes();
	static Gerenciador_Colisoes* getInstancia_Colisoes();

	Vector2f calcularColisao(Entidade* entidade, Entidade* ent);
	void colisaoJogadorInimigo();
	void colisaoJogadorObstaculo();
};