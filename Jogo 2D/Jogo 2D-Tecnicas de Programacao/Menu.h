#pragma once
#include "stdafx.h"
#include "Ente.h"

class Menu : public Ente
{

	Texture cursor;
	Sprite* cursorSprite;

	//Ente

	Ente *Tela;

	//
	int delay, tempoDelay;
	int posi;
	bool pressed, theselect;

	RectangleShape* play, * fases, * opcoes, * sobre, * sair;
	Font* font;
	Texture* image;
	Sprite* bg;

	Vector2i posMouse;
	Vector2f cordMouse;

	vector<const char*> options;
	vector<Vector2f>coords;
	vector<Text> texts;
	vector<size_t>sizes;

protected:

	//define valores para cada objeto
	void inicVariaveis();
	void inicCursor();

public:
	Menu();
	~Menu();

	void run_menu();
	void imprimir();
};