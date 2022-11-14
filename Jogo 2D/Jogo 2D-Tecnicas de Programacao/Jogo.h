#pragma once
#include "stdafx.h"
#include "Jogador.h"
//#include "Inimigo.h"
#include "Menu.h"
/*#include "FaseUm.h"
#include "FaseDois.h"*/
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"

class Jogo
{
private:
	//janela
	Gerenciador_Grafico *grafico;
	Gerenciador_Colisoes* colisao;
	Jogador jogador;
	Menu menu;
	bool baixo;
	bool menuAbre;

	RectangleShape chao;

	void iniciaMapa();

public:
	Jogo();
	virtual ~Jogo();

	const bool rodando() const;
	void atualizaMenu();
	void atualizaJogo();
	void renderizar();
};