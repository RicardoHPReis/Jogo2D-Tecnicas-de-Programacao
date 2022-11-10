#pragma once
#include "stdafx.h"

class Gerenciador_Grafico
{
private:
	RenderWindow* janela;
	VideoMode video;

	static Gerenciador_Grafico* instancia_grafico;
	Gerenciador_Grafico();

public:
	~Gerenciador_Grafico();
	static Gerenciador_Grafico* getInstancia_Grafico();
	const RenderWindow* getJanela() const;

	const bool janelaEstaAberta();
	void desenhar(RectangleShape* figura);
	void fechar();
	void executarJanela();
};

Gerenciador_Grafico* Gerenciador_Grafico::instancia_grafico = NULL;