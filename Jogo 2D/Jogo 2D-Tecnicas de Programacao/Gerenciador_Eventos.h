#pragma once
/*#include "stdafx.h"
#include "Menu_Inicial.h"
#include "Menu_Morte.h"
#include "Menu_Pause.h"
#include "Menu_Vencedor.h"
#include "Jogador.h"
#include "JogadorDois.h"
#include "Gerenciador_Grafico.h"

class Gerenciador_Eventos
{
private:
	Menu_Inicial *menuInicial;
	//Menu_Morte *menuMorte;
	Menu_Pause *menuPause;
	//Menu_Vencedor *menuVencedor;
	Jogador *jogador;
	JogadorDois *jogador2;

	static Gerenciador_Eventos* instancia_eventos;
	Gerenciador_Eventos();

public:
	~Gerenciador_Eventos();
	static Gerenciador_Eventos* getInstancia_Eventos();
	void deletarInstancia_Eventos();

	void setJogador(Jogador* player);
	void setJogadorDois(JogadorDois* player2);
	void setMenuInicial(Menu_Inicial* mnI);
	//void setMenuMorte(Menu_Morte* mnM);
	void setMenuPause(Menu_Pause* mnP);
	//void setMenuVencedor(Menu_Vencedor* mnV);


	void teclasJogadorUm(Keyboard::Key tecla);
	void teclasJogadorDois(Keyboard::Key tecla);
	void teclasMenuInicial(Keyboard::Key tecla);
	//void teclasMenuMorte(Keyboard::Key tecla);
	void teclasMenuVencedor(Keyboard::Key tecla);
	//void teclasMenuPause(Keyboard::Key tecla);

	void verificaTeclaPressionada(Keyboard::Key tecla);
	void verificaTeclaSolta(Keyboard::Key tecla);
	void executar();
};*/