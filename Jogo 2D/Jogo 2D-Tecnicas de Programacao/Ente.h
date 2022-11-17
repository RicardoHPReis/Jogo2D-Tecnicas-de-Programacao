#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"


Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;

class Ente
{
protected:
	const int id;
	static Gerenciador_Grafico* grafico;

public:
	Ente(int i = 0);
	virtual ~Ente();

	const int getId() const;
	static void setGerenciador_Grafico(Gerenciador_Grafico* gg);

	void desenhar(RectangleShape retangulo);
	void desenharTexto(Text texto);
	void desenharSprite(Sprite sprite);
	void limpar();
	void mostrar();
	bool janelaEstaAberta();
};