#pragma once
#include "Entidade.h"
#include "stdafx.h"
//using namespace Entidades;

class Personagem : public Entidade
{
protected:
	bool estaMorto;
	bool atacou;

public:
	Personagem(int i = 0, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 0.f, 0.f });
	~Personagem();

	virtual void executar() = 0;
	virtual void reageColisao(Entidade* outro, Vector2f dist_colisao) = 0;

	void setAtacou(bool foiAtacado);
	const bool getAtacou() const;

	void setEstaMorto(const bool mrt);
	const bool getEstaMorto() const;
};

/*namespace Personagens
{
	class Personagem : public Entidade
	{
	protected:
		bool estaMorto;
		bool atacou;

	public:
		Personagem(int i = 0, Vector2f pos = {0.f, 0.f}, Vector2f tam = { 0.f, 0.f });
		~Personagem();

		virtual void executar() = 0;
		virtual void reageColisao(Entidade* outro, Vector2f dist_colisao) = 0;

		void setAtacou(bool foiAtacado);
		const bool getAtacou() const;

		void setEstaMorto(const bool mrt);
		const bool getEstaMorto() const;
	};
};*/