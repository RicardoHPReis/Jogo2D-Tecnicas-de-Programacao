#pragma once
#include "Fase.h"
#include "stdafx.h"

class FaseUm :public Fase
{
private:
	bool inicializada;

	void iniciaVariaveis();
	void iniciaTexturas();

public:
	FaseUm(int i = 1, Jogador* player = NULL, JogadorDois* player2 = NULL);
	~FaseUm();

	void setInicializada(bool aux);
	const bool getInicializada() const;

	void iniciaFase();
	void executar();
};

/*namespace Fases
{
	class FaseUm :public Fase
	{
	private:
		bool inicializada;

		void iniciaVariaveis();
		void iniciaTexturas();

	public:
		FaseUm(int i = 1, Jogador* player = NULL, JogadorDois* player2 = NULL);
		~FaseUm();

		void setInicializada(bool aux);
		const bool getInicializada() const;

		void iniciaFase();
		void executar();
	};
}*/