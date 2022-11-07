#pragma once
#include "Gerenciador_Grafico.h"
#include "stdafx.h"

class Ente
{
protected:
	int id;
	Vector2f posicao;
	Vector2f coordenada;
	Vector2f tamanho;
	bool estaImprimindo;
	Gerenciador_Grafico* grafico;
	RenderWindow* janela;

public:
	Ente();
	//Ente(int nr_id = 0, Vector2f pos = { 0,0 }, Vector2f coord = { 0,0 }, Vector2f tam = { 0,0 });
	virtual ~Ente();

	void setId(const int nr_id);
	const int getId() const;

	void setPosicao(const Vector2f pos);
	const Vector2f getPosicao() const;

	void setCoordenada(const Vector2f coord);
	const Vector2f getCoordenada() const;

	void setTamanho(const Vector2f tam);
	const Vector2f getTamanho() const;

	void setImprimindo(const bool imp);
	const bool getImprimindo() const;

	virtual void executar(RectangleShape* obj);
	RenderWindow* getJanela();
	bool getAberta();
};