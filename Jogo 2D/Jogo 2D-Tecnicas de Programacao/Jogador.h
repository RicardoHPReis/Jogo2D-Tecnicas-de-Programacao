#pragma once
#include "stdafx.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	Texture txJogadorCorre[6], txJogadorPula[10], txJogadorParado[4],txJogadorAtaque[10];
	int frame1, limitadorTex_parado ,limitadorTex_correndo, limitadorTex_pulando, limitadorTex_ataque;

	bool jogador_pulou;
	bool levou_dano;
	float fdist, forcaPulo;

	void iniciarTexturas();

public:
	Jogador(int i = 4, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 125.f, 100.f });
	~Jogador();

	void executar();
	void ataque();
	void direcionalEsquerdo();
	void direcionalDireito();
	void pulo();

	void colisao(Entidade* outrao,Vector2f ds);

	void atualizarTextura();
	void operator--(int dano);

	void iniciarVariaiveis();
	const bool getLevouDano() const;
};