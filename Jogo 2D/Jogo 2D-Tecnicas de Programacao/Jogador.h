#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	Texture txJogadorCorre[10], txJogadorPula[10], txJogadorParado[10],txJogadorAtaque[10],txJogadorAtaquePula[10];
	int frame, velTex, limitadorTex1 ,limitadorTex;

	vector<Sprite> vidasSp;
	Texture tVidas;

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
	Jogador(int id = 0, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 0,0 }, int nr_vidas = 0, int nr_dano = 0, int ld = 0, bool atacar = true, bool morreu = false, bool foiAtacado = false);
	~Jogador();

	void atualizaVidas();
	void atualizarJogador();
	void ataque();
	void ataqueAereo();
	void direcionalEsquerdo();
	void direcionalDireito();
	void pulo();
	void executar();
	void imprimeVidas();
	int getVidas();

	void atualizarTextura();

};