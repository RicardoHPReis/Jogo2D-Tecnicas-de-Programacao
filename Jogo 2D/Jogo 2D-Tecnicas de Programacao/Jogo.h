#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "Pause.h"
#include "Jogador.h"
#include "FaseUm.h"
//#include "FaseDois.h"
#include "Gerenciador_Grafico.h"
//#include "Gerenciador_Eventos.h"

class Jogo
{
private:
	Menu menu;
	Pause pause;
	Jogador jogador;
	FaseUm fase1;
	//FaseDois fase2;

	int numFase;
	int faseAtual;
	bool menuAbre;
	bool pausou;

public:
	Jogo();
	virtual ~Jogo();

	const bool rodando() const;
	void rodando_menu();
	void update();
};