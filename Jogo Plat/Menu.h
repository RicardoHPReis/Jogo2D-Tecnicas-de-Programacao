#pragma once
#include "stdafx.h"
#include "jogo.h"

class Menu
{

	int posi;
	bool pressed, theselect;

	RenderWindow *janela; 
	RectangleShape *play,*fases, *opcoes, *sobre, *sair;
	Font* font;
	Texture* image;
	Sprite* bg;

	Vector2i posMouse;
	Vector2f cordMouse;

	vector<const char*> options;
	vector<Vector2f>coords;
	vector<Text> texts;
	vector<size_t>sizes;


	Jogo jogo;

protected:

	//define valores para cada objeto
	void set_values();

	//armazena eventos : clique do mouse
	void loop_events();

	//desenha tudo na tela
	void draw_all();

public:

	Menu();

	~Menu();

	void run_menu();


};

