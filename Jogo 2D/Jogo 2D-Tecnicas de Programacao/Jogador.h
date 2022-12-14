#pragma once
#include "stdafx.h"
#include "Personagem.h"
//using namespace Entidades;

class Jogador : public Personagem
{
protected:
	bool jogador_pulou;
	bool levou_dano;
	float forcaPulo;

	//vidas
	vector<Sprite> spVida;
	Texture txVida;

public:
	Jogador(int i = 0, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 0.f, 0.f });
	virtual ~Jogador();

	virtual void executar() = 0;
	void atualizavida();

	virtual void reageColisao(Entidade* outrao, Vector2f dist_colisao) = 0;

	void operator--(int dano);

	const bool getLevouDano() const;
	void setLevouDano(const bool levou_dn);

	const bool getPulou() const;
	void setPulou(const bool pulou);

	const float getForcaPulo() const;
	void setForcaPulo(const float force);
};

/*namespace Personagens
{
	class Jogador : public Personagem
	{
	protected:
		bool jogador_pulou;
		bool levou_dano;
		float forcaPulo;

		//vidas
		vector<Sprite> spVida;
		Texture txVida;

	public:
		Jogador(int i = 0, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 0.f, 0.f });
		virtual ~Jogador();

		virtual void executar() = 0;
		void atualizavida();

		virtual void reageColisao(Entidade* outrao, Vector2f dist_colisao) = 0;

		void operator--(int dano);

		const bool getLevouDano() const;
		void setLevouDano(const bool levou_dn);

		const bool getPulou() const;
		void setPulou(const bool pulou);

		const float getForcaPulo() const;
		void setForcaPulo(const float force);
	};
}*/