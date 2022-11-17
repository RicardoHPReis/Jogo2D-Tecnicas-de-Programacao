#pragma once
#include "stdafx.h"
#include "Ente.h"

class Menu : public Ente
{
private:
	Texture cursor;
	Sprite cursorSprite;

	Vector2i posMouse;
	Vector2f cordMouse;

	int delay, tempoDelay;
	int posi;
	bool apertou, selecao;

	RectangleShape play, fases, ranking, opcoes, sair;
	Font fonte;
	Texture imagem;
	Sprite fundo;
	vector<const char*> options;
	vector<Vector2f>coords;
	vector<Text> texts;
	vector<size_t>sizes;

	void inicVariaveis();
	void inicCursor();

public:
	Menu(int i = 3);
	~Menu();

	void run_menu();
	void imprimir();
};