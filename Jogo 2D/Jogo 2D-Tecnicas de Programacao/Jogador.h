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

	Texture txJogadorCorre[10], txJogadorPula[10], txJogadorParado[10],txJogadorAtaque[10],txJogadorAtaquePula[10];
	int frame, velTex, limitadorTex1 ,limitadorTex;



	//estat Player

	bool jogador_pulou;
	float gravidade, fdist, pAltura, pLargura, forcaPulo, xpos, ypos;
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
	void ataque();
	void ataqueAereo();
	void direcionalEsquerdo();
	void direcionalDireito();
	void pulo();
	void cair();
	void executar();

	void atualizarTextura();

};