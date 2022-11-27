#pragma once
#include "stdafx.h"
#include "Jogador.h"
#include "Gerenciador_Eventos.h"

class JogadorUm : public Jogador
{
private:
	Texture txJogadorCorre[6], txJogadorPula[10], txJogadorParado[4], txJogadorAtaque[10];
	int frame1, limitadorTex_parado, limitadorTex_correndo, limitadorTex_pulando, limitadorTex_ataque;
	int delay;

	void iniciarTexturas();

public:
	JogadorUm(int i = 4, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 125.f, 100.f });
	~JogadorUm();

	void executar();
	void reageColisao(Entidade* outrao, Vector2f dist_colisao);

	void ataque();
	void direcionalEsquerdo();
	void direcionalDireito();
	void pulo();
	void parar();

	void atualizarTextura();
	void iniciarVariaveis();
};