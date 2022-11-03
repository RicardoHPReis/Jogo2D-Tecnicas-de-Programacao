#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

/*

	classe abstrata ente, onde precisa incluir a classe do gerenciador grafico
	classe será chamada sempre que for preciso imprimir algo

*/


class Ente
{
protected:
	int id;
	Vector2f posicao;
	Vector2f coordenada;
	Vector2f tamanho;
	bool estaImprimindo;

public:
	Ente();
	Ente(int nr_id = 0, Vector2f pos = { 0,0 }, Vector2f coord = { 0,0 }, Vector2f tam = { 0,0 });
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

	void imprimir_se();
	virtual void executar() = 0;
};
