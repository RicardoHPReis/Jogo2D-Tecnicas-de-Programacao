#pragma once
#include "Fase.h"
#include "stdafx.h"

class FaseUm :public Fase
{
private:
	void iniciaVariaveis();
	void iniciaTexturas();

public:
	FaseUm(int i = 1, Jogador* player = NULL, JogadorDois* player2 = NULL);
	~FaseUm();

	void iniciaFase();
	void executar();
};
