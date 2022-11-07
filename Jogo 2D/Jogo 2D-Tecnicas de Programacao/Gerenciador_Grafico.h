#pragma once
#include "stdafx.h"

class Gerenciador_Grafico
{
private:
	Texture textura;
	RenderWindow* janela;
	VideoMode video;
	Event evento;

	void inicJanela();


public:

	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	void setTextura(const Texture tx);
	const Texture getTextura() const;

	void setJanela(const RenderWindow *window);
	const RenderWindow* getJanela() const;

	void setVideo(const VideoMode vdm);
	const VideoMode getVideo() const;

	void setEvento(const Event ev);
	const Event getEvento() const;

	void pollEvents();
	int aberta();
	void desenhar(RectangleShape* tela);
	void fechar();
};