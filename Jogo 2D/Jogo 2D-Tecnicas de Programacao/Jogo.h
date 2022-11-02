#pragma once

#include "stdafx.h"
#include "Jogador.h"

/*

	Classe do jogo

*/

class Jogo
{
private:
	//variaveis
	//janela
	RenderWindow* janela;
	VideoMode videoMode;
	Event ev;


	//texturas

	Texture tChao, tEnemy[11], tBg;

	//Player

	Jogador player;

	//inimigo

	int points;
	int frame1, velTex1, aux1;

	//direcao do inimigo

	bool baixo;


	//objetivos jogo

	RectangleShape inimigo;

	//mapa

	RectangleShape chao;
	Sprite fundo;

	//posicoes mouse

	Vector2i mousePos;


	//funcoes privadas

	void inicVariaiveis();
	void inicJanela();
	void inicMapa();
	void inicEnemies();
	void inicTexturas();


public:
	//construtores e destrutores
	Jogo();
	virtual ~Jogo();

	//acessos
	const bool rodando() const;

	//funcoes
	void spawnEnemy();

	void pollEvents();
	void atualizaMouse();

	void updateEnemies();
	void update();

	void render();
};


