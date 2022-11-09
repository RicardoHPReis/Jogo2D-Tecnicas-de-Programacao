#pragma once
#include "stdafx.h"

class Gerenciador_Grafico
{
private:
	//Texture textura;

	VideoMode videoMode;
	Event ev;

	Gerenciador_Grafico();

public:
	
	RenderWindow* janelaP;

	void inicJanela();

	~Gerenciador_Grafico();

	void pollEvents();

	void desenhar(RectangleShape* tela);

	void desenharT(Text* tela);

	void desenharS(Sprite* tela);

	void clear();

	static Gerenciador_Grafico& getInstancia();
};