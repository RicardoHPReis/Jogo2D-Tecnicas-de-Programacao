#pragma once
#include "Obstaculo.h"

class Fogo : public Obstaculo
{
private:
	Texture fogo[8];
	int attTextura,frame;

	bool queimou;
	void iniciarTexturas();

public:
	Fogo(int id = 102, Vector2f pos = { 0,0 }, Vector2f tam = { 50.f, 100.f });
	~Fogo();

	void executar();
	void colisao(Entidade* outrao, Vector2f ds);
};