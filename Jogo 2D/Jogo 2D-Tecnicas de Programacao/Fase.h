#pragma once
#include "Ente.h"
#include "stdafx.h"
#include "Jogador.h"
#include "Inimigo.h"

class Fase : public Ente
{
protected:

	//vidas 
	int vidasN;
	vector<Sprite> vidas;
	
	Texture tVidas;

	//Player
	Jogador* jogador;

	//inimigo
	Inimigo* inimigo;

	//Texturas
	Texture tChao, tBg;

	//mapa
	Sprite fundo;

	vector < RectangleShape > chao;

	void inicVariaveis();
	void inicVidas();
	void imprimeVidas();
	void inicTexturas();

public:

	//janela
	Ente* Tela;
	VideoMode videoMode;

	Fase();
	~Fase();

	void iniciaFase();

	void atualiza();

	void desenha();

};
