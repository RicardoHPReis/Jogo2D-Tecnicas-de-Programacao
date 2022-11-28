#pragma once
#include "stdafx.h"
#include "Menu_Inicial.h"
//#include "Menu_Morte.h"
#include "Menu_Pause.h"
#include "Menu_Vencedor.h"
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
	//Menu_Morte Menu_Morte;
	Menu_Pause *menuPause;
	//Menu_Vencedor Menu_Vencedor;
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