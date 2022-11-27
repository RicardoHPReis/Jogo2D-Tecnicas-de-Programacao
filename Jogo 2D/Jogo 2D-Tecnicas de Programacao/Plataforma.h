#pragma once
#include "Obstaculo.h"
#include "stdafx.h"

class Plataforma :public Obstaculo
{
private:
	Texture textura_plataforma;
	float forcaEmpuxo;

	void iniciarTexturas();
	void iniciarStatus();

public:
	Plataforma(int id = 100, Vector2f pos = { 0,0 }, Vector2f tam = { 85.f, 1920.f });
	~Plataforma();

	void executar();
	void reageColisao(Entidade* outrao, Vector2f ds);
	void calculaQueda();
};