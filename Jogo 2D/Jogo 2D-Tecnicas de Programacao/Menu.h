#pragma once
#include "stdafx.h"
#include "Ente.h"

class Menu : public Ente
{
private:
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

	void iniciaVariaveis();

public:
	Menu();
	~Menu();

	void executar();
	void imprimir();
};