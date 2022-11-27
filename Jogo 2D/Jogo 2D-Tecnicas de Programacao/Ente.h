#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

enum class ID 
{
	fase1 = 1,
	fase2 = 2,
	menu = 3,
	jogador = 4,
	pause = 5,
	jogador2 = 6,
	slime = 10,
	morcego = 11,
	mago = 12,
	chefao = 13,
	plataforma = 100,
	relampago = 101,
	fogo = 102,
	projetil = 1000
};

class Ente 
{
protected:
	const int id;

public:
	Ente(int i = 0);
	virtual ~Ente();

	virtual void executar() = 0;

	const int getId() const;
};