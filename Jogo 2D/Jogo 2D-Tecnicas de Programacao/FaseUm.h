#pragma once
#include "Fase.h"
#include "stdafx.h"

class FaseUm :public Fase
{
private:
	void iniciaVariaveis();
	void iniciaTexturas();
public:
	FaseUm(int i = 1);
	~FaseUm();

	void iniciaFase();
	void atualiza();
	void atualizaVidas();
	void desenhar();
};
