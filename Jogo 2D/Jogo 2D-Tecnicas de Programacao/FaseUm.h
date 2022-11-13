#pragma once
#include "Fase.h"
#include "stdafx.h"

class FaseUm :public Fase
{
private:
	
public:

	Fase *principal;

	FaseUm();
	~FaseUm();

	void inicVariaveis();
	void inicMapa();

};
