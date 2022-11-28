#pragma once
#include "stdafx.h"
#include "Lista_Encadeada.h"
#include "Entidade.h"
//using namespace Entidades;

class Lista_Entidades
{
private:
	Lista_Encadeada<Entidade> LEntidades;

public:
	Lista_Entidades();
	~Lista_Entidades();

	Entidade* operator[](int num);
	int getNumeroEntidades();
	void adicionarEntidade(Entidade* entidade);
	void apagarEntidade(Entidade* entidade);
	void apagarNumEntidade(int num);
	void limparEntidades();
	void desenharEntidades();
	void atualizarEntidade();
};

/*namespace Listas
{
	class Lista_Entidades
	{
	private:
		Lista_Encadeada<Entidade> LEntidades;

	public:
		Lista_Entidades();
		~Lista_Entidades();

		Entidade* operator[](int num);
		int getNumeroEntidades();
		void adicionarEntidade(Entidade* entidade);
		void apagarEntidade(Entidade* entidade);
		void apagarNumEntidade(int num);
		void limparEntidades();
		void desenharEntidades();
		void atualizarEntidade();
	};
}*/