#pragma once
#include "Fase.h"
#include "stdafx.h"

class FaseDois :public Fase
{
private:
	bool inicializada;

	void iniciaVariaveis();
	void iniciaTexturas();

public:
	FaseDois(int i = 2, Jogador* player = NULL, JogadorDois* player2 = NULL);
	~FaseDois();

	void setInicializada(bool aux);
	const bool getInicializada() const;

	void iniciaFase();
	void executar();
};
