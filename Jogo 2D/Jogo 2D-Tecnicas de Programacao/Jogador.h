#pragma once
#include "Personagem.h"
#include "Ente.h"
#include "stdafx.h"

class Jogador : protected Ente
{
private:


	Ente Tela;

	//videomode
	VideoMode videoModeP;

	//texturas player
	Texture txJogadorCorre[10], txJogadorPula[10], txJogadorParado[10];
	int frame, velTex, limitadorTex;


	//estat Player
	int lado;
	bool jogador_pulou;
	float gravidade, xvel, yvel, fdist, pAltura, pLargura, aT, xpos, ypos, velMax;
	Vector2f cPos;
	Vector2f pPos;

	//objetivos jogo
	RectangleShape chao;

	//funcoes privadas
	void iniciarVariaiveis();
	void iniciarJogador();
	void iniciarTexturas();

public:

	RectangleShape *obj;

	Jogador();
	~Jogador();

	void atualizarJogador();
	void direcionalEsquerdo();
	void direcionalDireito();
	void direcionalCima();
	void cair();
	void atualizarTextura();
};