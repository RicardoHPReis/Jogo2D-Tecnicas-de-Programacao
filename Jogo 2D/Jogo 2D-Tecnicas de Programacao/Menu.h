#pragma once
#include "stdafx.h"
#include "Ente.h"

class Menu : public Ente
{
private:
	int delay, tempoDelay;
	int escolha, escFase, escOpcoes;
	bool apertou, selecao;
	bool rodando_menu;
	int numFase;
	int numJogadores;

	Font fonte;
	Texture imagem;
	Sprite fundo;

	Texture previa1, previa2;

	vector<string> escrita;
	vector<Vector2f> coordenadas;
	vector<Text> textos;
	vector<size_t> tamanhos;
	vector<RectangleShape> escolhaFases;

	void inicVariaveis();

public:
	Menu(int i = 3);
	~Menu();

	void executar();
	void imprimir();
	void imprimirOpcoesFases();
	void imprimirOpcoes();
	void setRodandoMenu(const bool mn);
	const bool getRodandoMenu() const;
	const int getEscolha() const;
	void escolhaFase();
	void escolhaOpcoes();
	const int getNumFase() const;
	const int getNumJogadores() const;
};