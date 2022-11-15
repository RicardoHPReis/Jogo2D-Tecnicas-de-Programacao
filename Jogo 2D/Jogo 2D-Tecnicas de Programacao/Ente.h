#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

class Ente
{
protected:

	int id;
	Gerenciador_Grafico* janela;
	VideoMode videoMode;

public:
	Ente(int i=0);
	~Ente();

	virtual void executar(RectangleShape obj);
	virtual void executarTex(Text obj);
	virtual void executarSprite(Sprite obj);
	virtual void clear();
	virtual void display();
	
	RenderWindow* getJanelaCoord(void);

	void setId(int i);

	int getAberta(void);

};