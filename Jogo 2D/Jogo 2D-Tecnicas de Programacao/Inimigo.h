#pragma once
#include "Personagem.h"
#include "stdafx.h"

class Inimigo :public Personagem
{
protected:
	bool nocivo;

public:
	Inimigo();
	~Inimigo();
};