#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

/*

	classe abstrata ente, onde precisa incluir a classe do gerenciador grafico
	classe ser� chamada sempre que for preciso imprimir algo

*/


class Ente
{
protected:

	int id;

	VideoMode videoMode;

public:

	Gerenciador_Grafico* janela;

	void inicEnte();

	virtual void executar(RectangleShape obj);

	virtual void executarTex(Text obj);

	virtual void executarSprite(Sprite obj);

	virtual void clear();

	virtual void display();
	
	RenderWindow* getJanelaCoord(void);

	void setId(int i);

	int getAberta(void);

	Ente();

	Ente(int i);

	~Ente();

};