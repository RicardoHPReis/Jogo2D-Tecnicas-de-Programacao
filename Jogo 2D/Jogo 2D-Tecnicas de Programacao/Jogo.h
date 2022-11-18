#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "Jogador.h"
#include "FaseUm.h"
//#include "FaseDois.h"
#include "Gerenciador_Grafico.h"

class Jogo
{
private:
	Menu menu;
	Jogador jogador;
	FaseUm fase1;
	//FaseDois fase2;
	Gerenciador_Grafico* grafico;

	int numFase;
	int faseAtual;
	bool menuAbre;

public:
	Jogo();
	virtual ~Jogo();

	const bool rodando() const;
	void atualizaMenu();
	void update();
};