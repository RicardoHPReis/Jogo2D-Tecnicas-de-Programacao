#pragma once
#include "Obstaculo.h"
#include "stdafx.h"

class Plataforma :public Obstaculo
{
private:

	int forçaEmpuxo;

	Texture plataformaIMG;

	void iniciarTexturas();
	void iniciarStatus();

public:
	Plataforma(Vector2f pos = { 0,0 }, Vector2f tam = { 85.f, 1920.f });
	~Plataforma();

	void executado();
	void atualizar();
	//Vector2f valorEmpuxo();
};