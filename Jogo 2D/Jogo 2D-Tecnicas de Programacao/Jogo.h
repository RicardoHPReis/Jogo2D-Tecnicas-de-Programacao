#pragma once
#include "Jogador.h"
#include "Menu.h"
#include "FaseUm.h"
#include "FaseDois.h"
#include "Gerenciador_Grafico.h"
#include "stdafx.h"

class Jogo
{
private:
	Ente* Tela;
	Jogador jogador;
	Menu* menuP;

	int pontos; //Inimigo
	int frame1, velTex1, aux1; //Inimigo
	bool baixo; //Inimigo

	VideoMode videoMode;
	Texture tChao, tEnemy[11], tBg; //Texturas
	RectangleShape inimigo; //Objetivos jogo
	RectangleShape chao; //Mapa
	Sprite fundo; //Mapa
	Vector2i mousePos; //Posuções do mouse

	void inicializarVariaiveis();
	void inicializarMapa();
	void inicializarInimigos();
	void inicializarTexturas();

public:

	Jogo();
	virtual ~Jogo();

	const bool rodando() const;

	void atualizar();
	void spawnInimigo();
	void atualizarInimigos();
	//void atualizarMouse();
	//void renderizar();
};