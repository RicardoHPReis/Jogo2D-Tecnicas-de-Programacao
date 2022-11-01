#pragma once

#include "stdafx.h"


/*

		Classe Do Jogador

*/

class Jogador
{
private:

	//videomode

	VideoMode videoModeP;

	//texturas player

	Texture tPlayerCorre[10], tPlayerPula[10], tPlayerParado[10];
	int frame, velTex, aux;


	//estat Player

	int lado; 
	bool pulo;
	float gravidade, xvel, yvel, fdist, pAltura, pLargura, aT, xpos, ypos, velMax;
	Vector2f cPos;
	Vector2f pPos;

	//objetivos jogo

	//RectangleShape player;
	RectangleShape chao;

	//funcoes privadas

	void inicVariaiveisP();
	void inicPlayerP();
	void inicTexturasP();

public:

	RectangleShape player;

	Jogador();
	~Jogador();

	void updatePlayer();
	void updatePlayerA();
	void updatePlayerD();

	void updatePlayerW();
	void cair();

	void updatePlayerTex();

};

