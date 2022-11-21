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
	

public:

	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();
	static Gerenciador_Colisoes* getInstancia_Colisoes();

	void setJogador(Jogador* player);
	void adicionarInimigo(Inimigo* inimigo);
	void adicionarObstaculo(Obstaculo* obstaculo);
	void adicionarProjetil(Projetil* projetil);
	Vector2f calcularColisao(Entidade* ent1, Entidade* ent2);
	void colisaoJogadorInimigo();
	void colisaoJogadorObstaculo();
	void colisaoJogadorProjetil();
	void colisaoInimigoObstaculo();
	void colisaoProjetilObstaculo();

	void executar();
};