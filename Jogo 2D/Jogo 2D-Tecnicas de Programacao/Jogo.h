#pragma once
#include "stdafx.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Menu.h"
/*#include "FaseUm.h"
#include "FaseDois.h"*/
#include "Gerenciador_Grafico.h"

#include "Ente.h"

class Jogo : public Ente
{
private:
	//janela

	Ente *Tela;

	VideoMode videoMode;

	//vidas

	int vidasN;
	vector<Sprite> vidas;

	//texturas

	Texture tChao,tBg,tVidas;

	//Player

	Jogador *jogador;

	//inimigo

	Inimigo *inimigo;


	int points;

	//direcao do inimigo

	bool baixo;
	bool menuAbre;

	//mapa

	RectangleShape chao;
	Sprite fundo;

	//posicoes mouse

	Vector2i mousePos;

	//menu

	Menu* menuP;

	//funcoes privadas

	void inicVariaiveis();

	//void inicJanela();

	void inicMapa();
	void inicTexturas();

public:

	//construtores e destrutores
	Jogo();
	virtual ~Jogo();

	//acessos
	const bool rodando() const;

	//funcoes

	void atualizaMenu();

	void imprimeVidas();

	void update();
	void render();

};