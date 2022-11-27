#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "JogadorDois.h"
#include "Projetil.h"
#include "Plataforma.h"
#include "stdafx.h"

class Gerenciador_Colisoes
{
private:
	Jogador* jogador;
	JogadorDois* jogador2;
	vector<Inimigo*> listaInimigos;
	list<Obstaculo*> listaObstaculos;
	vector<Projetil*> listaProjeteis;

	static Gerenciador_Colisoes* instancia_colisoes;

public:

	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();
	static Gerenciador_Colisoes* getInstancia_Colisoes();
	void deletarInstancia_Colisoes();

	void setJogador(Jogador* player);
	void setJogadorDois(JogadorDois* player2);

	void adicionarInimigo(Inimigo* inimigo);
	void adicionarObstaculo(Obstaculo* obstaculo);
	void adicionarProjetil(Projetil* projetil);
	
	void deletarInimigo(int num);
	void deletarListasColisoes();

	Vector2f calcularColisao(Entidade* ent1, Entidade* ent2);

	void colisaoJogadorInimigo();
	void colisaoJogadorObstaculo();
	void colisaoJogadorProjetil();
	void colisaoInimigoObstaculo();
	void colisaoProjetilObstaculo();
	void colisaoPlataformaObstaculo();

	void executar();
};