#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Ente.h"

class Jogador : public Personagem
{
private:
	Texture txJogadorCorre[10], txJogadorPula[10], txJogadorParado[10], txJogadorAtaque[10], txJogadorAtaquePula[10];
	int frame, velocidadeTextura, limitadorTex1, limitadorFrames, delay, tempoDelay;
	
	float gravidade, aT;
	int pontuacao;
	bool jogador_pulou;

	void iniciarStatus();
	void iniciarVariaiveis();
	void iniciarJogador();
	void iniciarTexturas();

public:
	Jogador();
	~Jogador();

	void executar();
	void imprimir();

	void ataque();
	void ataqueAereo();
	void direcionalEsquerdo();
	void direcionalDireito();
	void direcionalCima();
	void cair();

	void atualizarTextura();
};