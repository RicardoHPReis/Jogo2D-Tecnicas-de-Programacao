#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Ente.h"

class Jogador : public Ente
{
private:

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

	Ente* Tela;

	RectangleShape obj;

	Jogador();
	~Jogador();

	void atualizarJogador();
	void direcionalEsquerdo();
	void direcionalDireito();
	void direcionalCima();
	void cair();
	void executar();

	void atualizarTextura();

};