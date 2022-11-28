#pragma once
#include "Obstaculo.h"
//using namespace Entidades;

class Relampago : public Obstaculo
{
private:
	bool paralisar;
	int tempo, paralisacao, velocidade_Textura, frame1;
	Texture TRelampago[13];

	void iniciaTexturas();
	void atualizarTextura();

public:
	Relampago(int id = 101, Vector2f pos = { 0,0 }, Vector2f tam = { 50.f, 50.f });
	~Relampago();

	void setParalizar(bool aux);
	const bool getParalizar() const;

	void executar();
	void reageColisao(Entidade* outrao, Vector2f dist_colisao);
};

/*namespace Obstaculos
{
	class Relampago : public Obstaculo
	{
	private:
		bool paralisar;
		int tempo, paralisacao, velocidade_Textura, frame1;
		Texture TRelampago[13];

		void iniciaTexturas();
		void atualizarTextura();

	public:
		Relampago(int id = 101, Vector2f pos = { 0,0 }, Vector2f tam = { 50.f, 50.f });
		~Relampago();

		void setParalizar(bool aux);
		const bool getParalizar() const;

		void executar();
		void reageColisao(Entidade* outrao, Vector2f dist_colisao);
	};
}*/