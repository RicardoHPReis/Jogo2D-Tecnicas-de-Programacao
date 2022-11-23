#pragma once
#include "stdafx.h"
#include "Lista_Entidades.h"
#include "Jogador.h"
#include "JogadorDois.h"
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
	JogadorDois* jogador2;

	vector<Sprite> vidaSp;
	Texture tvida;

	Sprite fundo;
	Texture texturaFundo;
	Lista_Entidades listaEntidades;

	bool doisJogadores;

public:
	Fase(int i = 0, Jogador* player = NULL, JogadorDois* player2 = NULL);
	virtual ~Fase();

	virtual void iniciaFase() = 0;
	virtual void executar() = 0;

	void gerenciaColisoes();

	void criarJogador(Vector2f pos);
	void criarJogadorDois(Vector2f pos);
	void criarPlataformas(Vector2f pos, Vector2f tam);
	void criarEspinhos(Vector2f pos, Vector2f tam);
	void criarFogos(Vector2f pos, Vector2f tam);
	void criarEsqueletos(Vector2f pos);
	void criarMorcegos(Vector2f pos);
	void criarChefao(Vector2f pos);
	void criarProjetil(Vector2f pos, Projetil* projetil);
	void deletarEntidades();

	const bool getDoisJogadores() const;
	void setDoisJogadores(const bool dois);
};
