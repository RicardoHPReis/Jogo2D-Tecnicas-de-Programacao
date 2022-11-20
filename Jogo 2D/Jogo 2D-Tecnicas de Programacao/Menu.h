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
	bool rodando_menu;

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

	void executar();
	void imprimir();
	const bool getRodandoMenu() const;
	void setRodandoMenu(const bool rodMen);
};