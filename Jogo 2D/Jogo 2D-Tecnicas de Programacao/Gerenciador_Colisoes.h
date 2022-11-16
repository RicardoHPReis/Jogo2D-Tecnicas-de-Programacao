#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "stdafx.h"

class Gerenciador_Colisoes
{
private:
	vector<Inimigo*> listaInimigos;
	list<Obstaculo*> listaObstaculos;
	list<Obstaculo*>::iterator* it;

	static Gerenciador_Colisoes* instancia_colisoes;
	Gerenciador_Colisoes();

public:
	~Gerenciador_Colisoes();
	static Gerenciador_Colisoes* getInstancia_Colisoes();

	void gerenciaColisoes(Jogador* jogador, Inimigo* inimigo, Obstaculo* obstaculo);
	Vector2f calcularColisao(Entidade* entidade, Entidade* ent);
	bool colisaoJogadorInimigo(Jogador* jogador, Inimigo* inimigo);
	bool colisaoJogadorObstaculoTeste(Jogador* jogador, Obstaculo* obstaculo);
	bool colisaoJogadorObstaculo(Jogador* jogador, Obstaculo* obstaculo);
};