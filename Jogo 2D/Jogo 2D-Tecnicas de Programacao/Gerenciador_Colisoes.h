#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "Projetil.h"
#include "stdafx.h"

class Gerenciador_Colisoes
{
private:
	Jogador* jogador;
	vector<Inimigo*> listaInimigos;
	list<Obstaculo*> listaObstaculos;
	vector<Projetil*> listaProjeteis;

	static Gerenciador_Colisoes* instancia_colisoes;
	Gerenciador_Colisoes();

public:
	~Gerenciador_Colisoes();
	static Gerenciador_Colisoes* getInstancia_Colisoes();

	void adicionarInimigo(Inimigo* inimigo);
	void adicionarObstaculo(Obstaculo* obstaculo);
	void adicionarProjetil(Projetil* projetil);
	Vector2f calcularColisao(Entidade* entidade, Entidade* ent);
	void colisaoJogadorInimigo();
	void colisaoJogadorObstaculo();
	void colisaoJogadorProjetil();
	void colisaoInimigoObstaculo();
	void colisaoProjetilObstaculo();
};