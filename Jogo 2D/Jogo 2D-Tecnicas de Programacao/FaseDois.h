#pragma once
#include "Fase.h"
#include "stdafx.h"

class FaseDois :public Fase
{
private:

public:
	FaseDois(int i = 1, Jogador* player = NULL, JogadorDois* player2 = NULL);
	~FaseDois();
};