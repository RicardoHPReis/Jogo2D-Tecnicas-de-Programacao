#pragma once
#include "Gerenciador_Grafico.h"
#include "stdafx.h"

class Ente
{
protected:
	Gerenciador_Grafico* grafico;
	int id;
	bool estaImprimindo;
	Vector2f posicao;
	Vector2f coordenada;
	Vector2f tamanho;
	Texture* textura;
	Sprite* sprite;

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

	void setTextura(Texture *tx);
	const Texture* getTextura() const;

	void setSprite(Sprite *sp);
	const Sprite* getSprite() const;

	virtual void executar(RectangleShape* obj);
	bool getAberta();
};