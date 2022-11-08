#pragma once
#include "stdafx.h"

class Gerenciador_Grafico
{
private:
	//static Gerenciador_Grafico* instancia_grafico;

	RenderWindow* janela;
	VideoMode video;
	Event evento;
	//Texture textura;
	//Sprite sprite;

	//Gerenciador_Grafico();

public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();
	//static Gerenciador_Grafico* getInstancia_Grafico();

	void setJanela(RenderWindow *window);
	const RenderWindow* getJanela() const;

	void setVideo(const VideoMode vdm);
	const VideoMode getVideo() const;

	void setEvento(const Event ev);
	const Event getEvento() const;

	/*void setTextura(const Texture tx);
	const Texture getTextura() const;*/

	/*void setSprite(const Sprite sp);
	const Sprite getSprite() const;*/

	void pollEvents();
	int aberta();
	void desenhar(RectangleShape* tela);
	void fechar();
};