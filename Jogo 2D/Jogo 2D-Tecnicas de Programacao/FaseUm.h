#pragma once
#include "Fase.h"
#include "stdafx.h"

class FaseUm :public Fase
{
private:
	void iniciaVariaveis();
	void iniciaTexturas();
public:
	FaseUm();
	~FaseUm();

	void iniciaFase();
	void atualiza();
	void atualizaVidas();
	void desenha();
};
