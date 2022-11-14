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
	void executarJanela();

	const bool janelaEstaAberta();
	Vector2u getTamanhoJanela();
	void desenhar(Drawable* figura);
	void limpar();
	void mostrar();
	void fechar();
};