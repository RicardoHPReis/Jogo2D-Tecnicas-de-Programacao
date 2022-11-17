#pragma once
#include "stdafx.h"

class Gerenciador_Grafico
{
private:
	RenderWindow* janela;
	VideoMode video;
	//View visao;

	static Gerenciador_Grafico* instancia_grafico;

	Gerenciador_Grafico();

public:
	~Gerenciador_Grafico();

	void pollEvents();
	void desenhar(RectangleShape retangulo);
	void desenharTexto(Text texto);
	void desenharSprite(Sprite sprite);
	void limpar();
	void mostrar();
	void fechar();

	RenderWindow* getJanela();
	VideoMode getVideo();
	static Gerenciador_Grafico* getInstancia_Grafico();
};