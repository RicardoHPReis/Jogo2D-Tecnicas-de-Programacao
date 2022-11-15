#pragma once
#include "Obstaculo.h"
#include "stdafx.h"

class Plano :public Obstaculo
{
private:

public:
	Plano(int id = 10, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 85.f, 192.f });
	~Plano();

	void executado();
	//Vector2f valorEmpuxo();
};