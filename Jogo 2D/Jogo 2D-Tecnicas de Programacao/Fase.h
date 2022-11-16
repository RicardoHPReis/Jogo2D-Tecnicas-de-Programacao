#pragma once
#include "stdafx.h"
#include "Lista_Entidades.h"
#include "Jogador.h"
#include "Esqueleto.h"
#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Grafico.h"

class Fase
{
protected:
	Texture tChao;
	vector <RectangleShape> chao;

	Jogador* jogador;
	Esqueleto* esqueleto;

	vector<Sprite> vidasSp;
	Texture tVidas;

	Sprite fundo;
	Texture texturaFundo;
	Lista_Entidades listaEntidades;
	Lista_Entidades listaObstaculos;
	Lista_Entidades listaPersonagens;
	Gerenciador_Colisoes* colisao;
	Gerenciador_Grafico* grafico; //Atributo temporario

	float gravidade;

public:
	Fase(float grav);
	virtual ~Fase();

	virtual void iniciaFase() = 0;
	virtual void atualiza() = 0;
	virtual void desenha() = 0;
	void calculaQueda(Lista_Entidades LEntidades);
};
