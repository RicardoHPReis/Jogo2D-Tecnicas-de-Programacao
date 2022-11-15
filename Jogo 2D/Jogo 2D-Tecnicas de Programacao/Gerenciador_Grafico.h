#pragma once
#include "stdafx.h"

class Gerenciador_Grafico
{
private:
	RenderWindow* janelaP;
	VideoMode videoMode;
	Event ev;

	static Gerenciador_Grafico* instancia_grafico;
	Gerenciador_Grafico();

public:
	void inicJanela();

	~Gerenciador_Grafico();

	void pollEvents();

	void desenhar(RectangleShape* tela);

	void desenharT(Text* tela);

	void desenharS(Sprite* tela);

	void limpar();

	void mostrar();
	
	void fechar();

	RenderWindow* getJanela();

	bool janelaEstaAberta();

	static Gerenciador_Grafico* getInstancia_Grafico();
};