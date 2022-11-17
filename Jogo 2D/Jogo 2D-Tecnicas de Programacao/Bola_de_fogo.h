#pragma once
#include "stdafx.h"
#include "Projetil.h"

class Bola_de_fogo : public Projetil
{
private:

public:
	Bola_de_fogo(int i = 0, Vector2f pos = { 0.f, 0.f }, Vector2f tam = { 0.f, 0.f });
	~Bola_de_fogo();

	
};

