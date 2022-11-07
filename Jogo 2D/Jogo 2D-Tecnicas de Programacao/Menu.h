#pragma once
#include "Ente.h"
#include "stdafx.h"

class Menu : public Ente
{
private:
	int mouse;
	bool clicar, selecionar;
	bool clique;

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

public:
	Menu();
	~Menu();

	void selecionouOpcaoTeclas(bool &clique);
	void selecionouOpcaoMouse(bool& clique);
	void apertou(bool& clique);
	void rodar_menu();
};