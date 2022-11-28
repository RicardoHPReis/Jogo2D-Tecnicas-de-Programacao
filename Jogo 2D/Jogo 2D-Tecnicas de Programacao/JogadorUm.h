#pragma once
#include "stdafx.h"
#include "Jogador.h"
//using namespace Entidades;

class JogadorUm : public Jogador
{
private:
	Texture txJogadorCorre[6], txJogadorPula[10], txJogadorParado[4], txJogadorAtaque[10], txJogadorMorre[5];
	int frame1, limitadorTex_parado, limitadorTex_correndo, limitadorTex_pulando, limitadorTex_ataque, velocidadeTextura;
	int delayAtaque;

	void iniciarTexturas();

public:
	JogadorUm(int i = 5, Vector2f pos = { 100.f, 960.f }, Vector2f tam = { 125.f, 100.f });
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

/*namespace Personagens
{
	class JogadorUm : public Jogador
	{
	private:
		Texture txJogadorCorre[6], txJogadorPula[10], txJogadorParado[4], txJogadorAtaque[10], txJogadorMorre[5];
		int frame1, limitadorTex_parado, limitadorTex_correndo, limitadorTex_pulando, limitadorTex_ataque,velocidadeTextura;
		int delayAtaque;

		void iniciarTexturas();

	public:
		JogadorUm(int i = 5, Vector2f pos = { 100.f, 960.f }, Vector2f tam = { 125.f, 100.f });
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
}*/