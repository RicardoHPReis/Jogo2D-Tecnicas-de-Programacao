#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "FaseUm.h"
//#include "Jogador.h"
//#include "FaseDois.h"
#include "Gerenciador_Grafico.h"


class Jogo 
{
private:

	//fases
	FaseUm *fase1;
	int numFase;

	Menu* menuP;

	Gerenciador_Grafico* grafico;

	//fases
	int faseAtual;

	//Fase 1
	bool menuAbre;

	//posicoes mouse
	Vector2i mousePos;

	//funcoes privadas
	void inicVariaveis();

public:
	Jogo();
	virtual ~Jogo();

	//acessos
	const bool rodando() const;

	//funcoes
	void atualizaMenu();
	void update();
};