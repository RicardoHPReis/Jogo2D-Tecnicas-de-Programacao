#pragma once
#include "Lista_Entidades.h"
#include "stdafx.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Gerenciador_Colisoes.h"

class Fase
{
protected:
	Texture tChao;
	vector <RectangleShape> chao;

	Jogador* jogador;
	Inimigo* inimigo;

	Sprite fundo;
	Texture TexturaFundo;
	Lista_Entidades listaEntidades;
	Lista_Entidades listaObstaculos;
	Lista_Entidades listaPersonagens;
	Gerenciador_Colisoes* colisao;
	float gravidade;

	void inicVariaveis();
	void inicTexturas();

public:

	//janela
	Ente* Tela;
	VideoMode videoMode;

	Fase();
	~Fase();

	void iniciaFase();

	void atualiza();

	void desenha();

	//void calculaQueda();
};
