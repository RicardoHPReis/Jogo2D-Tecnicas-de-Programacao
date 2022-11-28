#pragma once
#include "stdafx.h"
#include "Jogador.h"
//using namespace Entidades;

class JogadorDois : public Jogador
{
private:
	Texture txJogadorMorre[10], txJogadorCorre[8], txJogadorPula[10], txJogadorParado[2], txJogadorAtaque[11];
	int frame1, limitadorTex_parado, limitadorTex_correndo, limitadorTex_pulando, limitadorTex_ataque;
	int delayAtaque, velocidadeMorte;

	void iniciarTexturas();

public:
	JogadorDois(int i = 6, Vector2f pos = { 600.f, 960.f }, Vector2f tam = { 125.f, 100.f });
	~JogadorDois();

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
	class JogadorDois : public Jogador
	{
	private:
		Texture txJogadorMorre[10], txJogadorCorre[8], txJogadorPula[10], txJogadorParado[2], txJogadorAtaque[11];
		int frame1, limitadorTex_parado, limitadorTex_correndo, limitadorTex_pulando, limitadorTex_ataque;
		int delayAtaque, velocidadeMorte;

		void iniciarTexturas();

	public:
		JogadorDois(int i = 6, Vector2f pos = { 600.f, 960.f }, Vector2f tam = { 125.f, 100.f });
		~JogadorDois();

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