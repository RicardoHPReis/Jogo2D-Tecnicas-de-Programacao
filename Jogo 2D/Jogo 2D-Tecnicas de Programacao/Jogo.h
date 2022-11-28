#pragma once
#include "stdafx.h"
#include "Menu_Inicial.h"
#include "Menu_Pause.h"
#include "JogadorUm.h"
#include "JogadorDois.h"
#include "FaseUm.h"
#include "FaseDois.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"

class Jogo
{
private:
	Menu_Inicial *menuInicial;
	Menu_Pause *menuPause;
	JogadorUm *jogador1;
	JogadorDois *jogador2;
	FaseUm *fase1;
	FaseDois *fase2;

	bool menuAbre;
	bool pausou;

public:
	Jogo();
	virtual ~Jogo();

	const bool rodando() const;
	void update();
	void inicializar();
};