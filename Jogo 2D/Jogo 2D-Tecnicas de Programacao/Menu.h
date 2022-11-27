#pragma once
#include "stdafx.h"
#include "Ente.h"

class Menu : public Ente
{
protected:
	int delay, tempoDelay;
	int escolha;
	bool apertou, selecao;
	bool rodando_menu;

	Font fonte;
	Texture imagem;
	Sprite fundo;

	vector<string> escrita;
	vector<Vector2f> coordenadas;
	vector<Text> textos;
	vector<size_t> tamanhos;

public:
	Menu(int i = 3);
	virtual ~Menu();

	virtual void executar() = 0;
	virtual void imprimir() = 0;
	void setRodandoMenu(const bool mn);
	const bool getRodandoMenu() const;
	const int getEscolha() const;
};