#pragma once
#include "stdafx.h"
#include "Jogador.h"
#include "Menu.h"
/*#include "FaseUm.h"
#include "FaseDois.h"*/
#include "Gerenciador_Grafico.h"

class Jogo
{
private:
	//janela
	RenderWindow* janela;
	VideoMode videoMode;
	Event ev;


	//texturas

	Texture tChao, tEnemy[11], tBg;

	//Player

	Jogador jogador;

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

	//menu

	Menu* menuP;

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