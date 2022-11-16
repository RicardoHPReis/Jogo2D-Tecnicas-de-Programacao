#pragma once
#include "Entidade.h"
#include "stdafx.h"

class Obstaculo :public Entidade
{
protected:

public:
	Obstaculo(int id = 0, bool mov = false, Vector2f pos = { 0,0 }, Vector2f tam = { 0,0 });
	virtual ~Obstaculo();

	virtual void executado()=0;
};