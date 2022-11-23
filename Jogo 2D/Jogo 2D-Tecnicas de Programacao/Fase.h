#pragma once
#include "stdafx.h"
#include "Lista_Entidades.h"
#include "Jogador.h"
#include "Esqueleto.h"
#include "Morcego.h"
#include "Plataforma.h"
#include "Espinho.h"
#include "Fogo.h"
#include "Projetil.h"
#include "Chefao.h"
#include "Gerenciador_Colisoes.h"

class Fase: public Ente
{
protected:
	Jogador* jogador;

	vector<Sprite> vidasSp;
	Texture tVidas;

	Sprite fundo;
	Texture texturaFundo;
	Lista_Entidades listaEntidades;

public:
	Fase(int i = 0, Jogador* player = NULL);
	virtual ~Fase();

	virtual void iniciaFase() = 0;
	virtual void executar() = 0;

	void gerenciaColisoes();

	void criarJogador(Vector2f pos, Jogador *player);
	void criarPlataformas(Vector2f pos, Vector2f tam);
	void criarEspinhos(Vector2f pos, Vector2f tam);
	void criarFogos(Vector2f pos, Vector2f tam);
	void criarEsqueletos(Vector2f pos);
	void criarMorcegos(Vector2f pos);
	void criarChefao(Vector2f pos);
	void criarProjetil(Vector2f pos, Projetil* projetil);
	void deletarEntidades();
};
