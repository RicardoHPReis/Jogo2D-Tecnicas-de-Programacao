#pragma once
#include "Obstaculo.h"

class Fogo : public Obstaculo
{
private:
	Texture fogo[8];
	int attTextura,frame;

	bool queimou;
	void iniciarTexturas();
	void atualizarTextura();

public:
	Fogo(int id = 102, Vector2f pos = { 0,0 }, Vector2f tam = { 68.f, 72.f });
	~Fogo();

	void executar();
	void reageColisao(Entidade* outrao, Vector2f ds);
};