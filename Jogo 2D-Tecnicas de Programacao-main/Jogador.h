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

	bool jogador_pulou;
	float gravidade, fdist, pAltura, pLargura, aT, xpos, ypos;
	Vector2f cPos;
	Vector2f pPos;

	//objetivos jogo

	RectangleShape chao;

	//funcoes privadas

	void iniciarStatus();
	void iniciarVariaiveis();
	void iniciarJogador();
	void iniciarTexturas();

public:

	//Estatisticas de Personagem

	Personagem status;

	Ente* Tela;

	RectangleShape player;

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