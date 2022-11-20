#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	Texture txJogadorCorre[10], txJogadorPula[10], txJogadorParado[10],txJogadorAtaque[10],txJogadorAtaquePula[10];
	int frame, velTex, limitadorTex1 ,limitadorTex;

	//estat Player
	bool jogador_pulou;
	bool levou_dano;
	float fdist, forcaPulo;

	//funcoes privadas
	void iniciarStatus();
	void iniciarVariaiveis();
	void iniciarJogador();
	void iniciarTexturas();

public:
	Jogador(int i = 4, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 60.f, 90.f });
	~Jogador();

	void executar();
	void ataque();
	void ataqueAereo();
	void direcionalEsquerdo();
	void direcionalDireito();
	void pulo();

	void colisao(Entidade* ent);
	void atualizarTextura();
	void operator--(int dano);

	const bool getLevouDano() const;
};