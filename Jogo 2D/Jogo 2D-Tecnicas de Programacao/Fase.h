#pragma once
#include "stdafx.h"
#include "Lista_Entidades.h"
#include "Jogador.h"
#include "Esqueleto.h"
#include "Morcego.h"
#include "Plataforma.h"
#include "Espinho.h"
#include "Gerenciador_Colisoes.h"

class Fase: public Ente
{
protected:
	Texture tChao;

	Jogador* jogador;


	vector<Sprite> vidasSp;
	Texture tVidas;

	Sprite fundo;
	Texture texturaFundo;
	Lista_Entidades listaEntidades;

public:
	Fase(int i = 0);
	virtual ~Fase();

	virtual void iniciaFase() = 0;
	virtual void executar() = 0;
	void gerenciaColisoes();
	//static void setGerenciador_Colisoes(Gerenciador_Colisoes* gc);

	void criarJogador(Vector2f pos, Jogador *player);
	void criarPlataformas(Vector2f pos, Vector2f tam);
	void criarEspinhos(Vector2f pos, Vector2f tam);
	//void criarEsqueletos(Vector2f pos);
	//void criarMorcego(Vector2f pos);
	void deletarEntidades();
};
