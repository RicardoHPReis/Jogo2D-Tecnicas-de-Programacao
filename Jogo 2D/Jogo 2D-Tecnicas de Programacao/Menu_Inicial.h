#pragma once
#include "stdafx.h"
#include "Menu.h"
//#include "Jogo.h"

class Menu_Inicial : public Menu
{
private:
	int escFase, escOpcoes;
	int numFase, numJogadores;
	int delay,frame;

	Texture previa1, previa2;
	vector<RectangleShape> escolhaFases;

public:
	Menu_Inicial(int i = 3);
	~Menu_Inicial();

	void executar();
	void imprimir();
	void imprimirOpcoesFases();
	void imprimirOpcoes();
	void escolhaFase();
	void escolhaOpcoes();

	const int getNumFase() const;
	void setNumFase(const int n_fase);

	const int getNumJogadores() const;
	void setNumJogadores(const int n_jogadores);
};