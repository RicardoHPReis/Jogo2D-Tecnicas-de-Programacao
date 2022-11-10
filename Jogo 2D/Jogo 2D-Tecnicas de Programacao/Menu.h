#pragma once
#include "Ente.h"
#include "stdafx.h"

class Menu : public Ente
{
private:
	int mouse;
	bool clicar, selecionar;
	bool clique;

	RectangleShape *play, *fases, *recordes, *opcoes, *sobre, *sair;
	Font *font;

	Vector2i posMouse;
	Vector2f cordMouse;

	vector<const char*> options;
	vector<Vector2f>coords;
	vector<Text> textos;
	vector<size_t>sizes;

public:
	Menu();
	~Menu();

	void selecionouOpcaoTeclas(bool &clique);
	void selecionouOpcaoMouse(bool& clique);
	void apertou(bool& clique);
	void rodar_menu();
};