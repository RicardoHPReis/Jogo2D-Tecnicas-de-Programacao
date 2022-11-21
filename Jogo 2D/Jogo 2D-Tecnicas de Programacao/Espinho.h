#pragma once
#include "Obstaculo.h"

class Espinho : public Obstaculo
{
private:
	bool quebra;

public:
	Espinho(int id = 101, Vector2f pos = { 0,0 }, Vector2f tam = { 50.f, 50.f });
	~Espinho();

	void executar();
};