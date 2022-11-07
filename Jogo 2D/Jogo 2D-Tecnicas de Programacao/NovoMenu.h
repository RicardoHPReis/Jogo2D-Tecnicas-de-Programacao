#pragma once
#include "Ente.h"
#include "stdafx.h"

class NMenu :public Ente
{

	int posi;
	bool pressed, theselect;
	RenderWindow* janela;
	RectangleShape* fundo, * play, * fases, * opcoes, * sobre, * sair;
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
	NMenu();
	~NMenu();

	void run_menu();
	void set_values();
	void loop_events();
	void draw_all();
};