#pragma once

#include "stdafx.h"

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

	//texturas player

	Texture tPlayerCorre[10], tPlayerPula[10], tPlayerParado[10];
	int frame, velTex,aux;

	//Logica jogoad

	int points;
	int frame1, velTex1,aux1;

	//estat Player

	
	int lado,velMax;
	bool pulo;
	float gravidade, xvel, yvel, fdist, pAltura,pLargura, aT, xpos, ypos;
	Vector2f cPos;
	Vector2f pPos;

	//direcao do inimigo
	bool baixo;


	//objetivos jogo

	RectangleShape inimigo;
	RectangleShape player;

	//mapa

	RectangleShape chao;
	Sprite fundo;

	//posicoes mouse

	Vector2i mousePos;
	

	//funcoes privadas

	void inicVariaiveis();
	void inicJanela();
	void inicMapa();
	void inicPlayer();
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
	
	void updatePlayer();
	void updateEnemies();
	void update();

	void render();
};

