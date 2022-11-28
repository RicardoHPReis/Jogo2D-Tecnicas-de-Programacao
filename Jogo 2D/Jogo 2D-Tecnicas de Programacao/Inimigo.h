#pragma once
#include "stdafx.h"
#include "Personagem.h"
//using namespace Entidades;

class Inimigo : public Personagem
{
protected:
	bool danoso;

public:
	Inimigo(int i = 0, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 0.f, 0.f });
	virtual ~Inimigo();

	virtual void executar() = 0;
	virtual void reageColisao(Entidade* outro, Vector2f dist_colisao) = 0;

	void setDanoso(const bool mal);
	const bool getDanoso() const;
};

/*namespace Personagens
{
	class Inimigo : public Personagem
	{
	protected:
		bool danoso;

	public:
		Inimigo(int i = 0, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 0.f, 0.f });
		virtual ~Inimigo();

		virtual void executar() = 0;
		virtual void reageColisao(Entidade* outro, Vector2f dist_colisao) = 0;

		void setDanoso(const bool mal);
		const bool getDanoso() const;
	};
}*/