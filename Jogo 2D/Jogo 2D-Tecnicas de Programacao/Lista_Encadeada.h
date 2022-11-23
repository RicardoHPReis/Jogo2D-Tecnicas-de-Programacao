#pragma once
#include "stdafx.h"

template <class L>
class Lista_Encadeada
{
private:
	template<class E>
	class Elemento
	{
	private:
		Elemento<E>* anterior;
		E* info;
		Elemento<E>* proximo;

	public:
		Elemento()
		{
			anterior = NULL;
			info = NULL;
			proximo = NULL;
		}
		~Elemento()
		{
			anterior = NULL;
			info = NULL;
			proximo = NULL;
		}

		void setInfo(E* informacao) { info = informacao; }
		E* getInfo() { return info; }
		void setAnterior(Elemento<E>* ant) { anterior = ant; }
		Elemento<E>* getAnterior() { return anterior; }
		void setProximo(Elemento<E>* prox) { proximo = prox; }
		Elemento<E>* getProximo() { return proximo; }
	};

	Elemento<L>* primeiro;
	Elemento<L>* atual;
	Elemento<L>* ultimo;
	int num_elementos;

public:
	Lista_Encadeada();
	~Lista_Encadeada();

	void setPrimeiro(const Elemento<L>* prim);
	const Elemento<L>* getPrimeiro() const;

	void setUltimo(const Elemento<L>* ult);
	const Elemento<L>* getUltimo() const;

	void setNumeroElementos(const int num_el);
	const int getNumeroElementos() const;

	L* operator[](int num);
	void adicionar(L* informacao);
	void apagar(L* informacao);
	void apagarNum(int num);
	void limpar();
};

template<class L>
Lista_Encadeada<L>::Lista_Encadeada():
	primeiro(),
	atual(),
	ultimo()
{
	num_elementos = 0;
}

template<class L>
Lista_Encadeada<L>::~Lista_Encadeada()
{
	limpar();
	primeiro = NULL;
	atual = NULL;
	ultimo = NULL;
	num_elementos = 0;
}

template<class L>
void Lista_Encadeada<L>::setPrimeiro(const Elemento<L>* prim)
{
	primeiro = prim;
}

template<class L>
const Lista_Encadeada<L>::Elemento<L>* Lista_Encadeada<L>::getPrimeiro() const
{
	return primeiro;
}

template<class L>
void Lista_Encadeada<L>::setUltimo(const Elemento<L>* ult)
{
	ultimo = ult;
}

template<class L>
const Lista_Encadeada<L>::Elemento<L>* Lista_Encadeada<L>::getUltimo() const
{
	return ultimo;
}

template<class L>
void Lista_Encadeada<L>::setNumeroElementos(const int num_el)
{
	num_elementos = num_el;
}

template<class L>
const int Lista_Encadeada<L>::getNumeroElementos() const
{
	return num_elementos;
}

template<class L>
L* Lista_Encadeada<L>::operator[](int num)
{
	bool encontrou = false;
	atual = primeiro;
	for (int i = 0; i <= num || i < num_elementos; i++)
	{
		if (i == num)
		{
			encontrou = true;
			return atual->getInfo();
		}
		atual = atual->getProximo();
	}
	if (encontrou == false)
	{
		cout << "Não foi encontrado o elemento do operador!\n";
	}
	return NULL;
}

template<class L>
void Lista_Encadeada<L>::adicionar(L* informacao)
{
	Elemento<L>* novo = NULL;
	novo = new Elemento<L>;
	if (num_elementos == 0)
	{
		novo->setInfo(informacao);
		novo->setAnterior(NULL);
		novo->setProximo(NULL);
		primeiro = novo;
		ultimo = novo;
		num_elementos++;
	}
	else if (num_elementos == 1)
	{
		novo->setInfo(informacao);
		novo->setAnterior(primeiro);
		novo->setProximo(NULL);
		primeiro->setProximo(novo);
		ultimo = novo;
		num_elementos++;
	}
	else
	{
		ultimo->setProximo(novo);
		novo->setInfo(informacao);
		novo->setAnterior(ultimo);
		novo->setProximo(NULL);
		ultimo = novo;
		num_elementos++;
	}
}

template<class L>
void Lista_Encadeada<L>::apagar(L* informacao)
{
	Elemento<L>* aux = NULL;
	bool apagou = false;
	atual = primeiro;
	for (int i = 0; apagou != false || i < num_elementos; i++)
	{
		if (atual->getInfo() == informacao)
		{
			aux = atual;
			atual = aux->getProximo();
			aux->setProximo(atual->getProximo());
			atual = atual->getProximo();
			atual->setAnterior(aux);
			aux = aux->getProximo();
			aux = NULL;
			delete aux;
			apagou = true;
		}
		atual = atual->getProximo();
	}
}

template<class L>
void Lista_Encadeada<L>::apagarNum(int num)
{
	Elemento<L>* aux = NULL;
	bool apagou = false;
	atual = primeiro;
	if (num < 0 || num > num_elementos)
	{
		cout << "Ultrapassou o limite de elementos na lista encadeada" << endl;
		return;
	}
	for (int i = 0; i < num_elementos; i++)
	{
		if (i == num)
		{
			aux = atual;
			atual = aux->getProximo();
			aux->setProximo(atual->getProximo());
			atual = atual->getProximo();
			atual->setAnterior(aux);
			aux = aux->getProximo();
			aux = NULL;
			delete aux;
			apagou = true;
		}
		atual = atual->getProximo();
	}
}

template<class L>
void Lista_Encadeada<L>::limpar()
{
	Elemento<L>* aux = NULL;
	atual = primeiro;
	for (int i = 0; i < num_elementos; i++)
	{
		//atual[i]
		aux = atual;
		atual = aux->getProximo();
		aux->setProximo(NULL);
		aux->setAnterior(NULL);
		delete aux;
		aux = NULL;
	}
	primeiro = NULL;
	atual = NULL;
	ultimo = NULL;
}