#pragma once
#include "stdafx.h"
#include "Lista_Entidades.h"
#include "Jogador.h"
#include "JogadorDois.h"
#include "Slime.h"
#include "Morcego.h"
#include "Plataforma.h"
#include "Relampago.h"
#include "Fogo.h"
#include "Projetil.h"
#include "Chefao.h"
#include "Gerenciador_Colisoes.h"
//using namespace Entidades;
//using namespace Personagens;
//using namespace Obstaculos;
//using namespace Listas;

class Fase : public Ente
{
protected:
	Jogador* jogador;
	JogadorDois* jogador2;

	Sprite fundo;
	Texture texturaFundo;
	Vector2f removerTela;
	Lista_Entidades listaEntidades;

	int num_inimigos;
	bool doisJogadores;
	bool concluido;

public:
	Fase(int i = 0, Jogador* player = NULL, JogadorDois* player2 = NULL);
	virtual ~Fase();

	virtual void iniciaFase() = 0;
	virtual void executar() = 0;

	void gerenciaColisoes();
	void remover();

	void criarJogador(Vector2f pos);
	void criarJogadorDois(Vector2f pos);
	void criarPlataformas(Vector2f pos, Vector2f tam);
	void criarRelampagos(Vector2f pos, Vector2f tam);
	void criarFogos(Vector2f pos, Vector2f tam);
	void criarSlimes(Vector2f pos);
	void criarMorcegos(Vector2f pos);
	void criarChefao(Vector2f pos);
	void criarProjetil(Vector2f pos, Projetil* projetil);
	void deletarEntidades();
	void verifica2jogadores();

	const int getNumInimigos() const;
	void setNumInimigos(const int n_inimigos);

	const bool getDoisJogadores() const;
	void setDoisJogadores(const bool dois);

	const bool getConcluido() const;
	void setConcluido(const bool concluiu);
};

/*namespace Fases
{
	class Fase: public Ente
	{
	protected:
		Jogador* jogador;
		JogadorDois* jogador2;

		Sprite fundo;
		Texture texturaFundo;
		Vector2f removerTela;
		Lista_Entidades listaEntidades;

		int num_inimigos;
		bool doisJogadores;
		bool concluido;

	public:
		Fase(int i = 0, Jogador* player = NULL, JogadorDois* player2 = NULL);
		virtual ~Fase();

		virtual void iniciaFase() = 0;
		virtual void executar() = 0;

		void gerenciaColisoes();
		void remover();

		void criarJogador(Vector2f pos);
		void criarJogadorDois(Vector2f pos);
		void criarPlataformas(Vector2f pos, Vector2f tam);
		void criarRelampagos(Vector2f pos, Vector2f tam);
		void criarFogos(Vector2f pos, Vector2f tam);
		void criarSlimes(Vector2f pos);
		void criarMorcegos(Vector2f pos);
		void criarChefao(Vector2f pos);
		void criarProjetil(Vector2f pos, Projetil* projetil);
		void deletarEntidades();
		void verifica2jogadores();

		const int getNumInimigos() const;
		void setNumInimigos(const int n_inimigos);

		const bool getDoisJogadores() const;
		void setDoisJogadores(const bool dois);

		const bool getConcluido() const;
		void setConcluido(const bool concluiu);
	};
}*/