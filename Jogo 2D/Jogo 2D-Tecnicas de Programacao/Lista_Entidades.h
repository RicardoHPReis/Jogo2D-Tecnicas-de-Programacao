#pragma once
#include "stdafx.h"
#include "Lista.h"
#include "Entidade.h"

class Lista_Entidades
{
private:
	Lista_Encadeada<Entidade> LEntidades;

public:
	Lista_Entidades();
	~Lista_Entidades();

	Entidade* operator[](int num);
	int getNumeroEntidades();
	void adicionarEntidade(Entidade *entidade);
	void apagarEntidade(Entidade *entidade);
	void limparEntidades();
};