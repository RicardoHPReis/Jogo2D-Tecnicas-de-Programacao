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

		void setInfo(E* informacao) { this->info = informacao; }
		E* getInfo() { return info; }
		void setAnterior(Elemento<E>* ant) { this->anterior = ant; }
		Elemento<E>* getAnterior() { return anterior; }
		void setProximo(Elemento<E>* prox) { this->proximo = prox; }
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
	int i = 0;
	bool encontrou = false;
	atual = primeiro;
	while (atual != NULL)
	{
		if (i == num)
		{
			encontrou = true;
			return atual->getInfo();
		}
		atual = atual->getProximo();
		i++;
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
	int i = 0;
	bool apagou = false;
	atual = primeiro;
	aux = atual;
	while (atual != NULL)
	{
		if (atual->getInfo() == informacao)
		{
			if (i == 0)
			{
				aux = primeiro;
				atual->getProximo();
				atual->setAnterior(NULL);
				primeiro = atual;
				delete aux;
				apagou = true;
				aux = NULL;
				num_elementos--;
			}
			else if (i == num_elementos - 1)
			{
				aux = atual->getAnterior();
				aux->setProximo(NULL);
				aux = atual;
				ultimo = atual;
				delete aux;
				apagou = true;
				aux = NULL;
				num_elementos--;
			}
			else
			{
				aux = atual->getAnterior();
				atual = atual->getProximo();
				aux->setProximo(atual);
				atual->setAnterior(aux);
				aux = aux->getProximo();
				delete aux;
				apagou = true;
				aux = NULL;
				num_elementos--;	
			}
		}
		else
		{
			atual = atual->getProximo();
			i++;
		}
	}
}

template<class L>
void Lista_Encadeada<L>::apagarNum(int num)
{
	int i = 0;
	Elemento<L>* aux = NULL;
	bool apagou = false;
	atual = primeiro;
	cout << "IF ANTES" << endl;
	if (num < 0 || num > num_elementos)
	{
		cout << "Ultrapassou o limite de elementos na lista encadeada" << endl;
		return;
	}

	if (num == 0)
	{
		cout << "i = 0" << endl;
		aux = primeiro;
		atual->getProximo();
		atual->setAnterior(NULL);
		primeiro = atual;
		delete aux;
		apagou = true;
		aux = NULL;
		num_elementos--;
	}
	else if (num == num_elementos - 1)
	{
		cout << "i = 11" << endl;
		aux = atual->getAnterior();
		aux->setProximo(NULL);
		aux = atual;
		ultimo = atual;
		delete aux;
		apagou = true;
		aux = NULL;
		num_elementos--;
	}
	else
	{
		while (atual != NULL && apagou == false)
		{
			if (i == num)
			{
				cout << "i = outro" << endl;
				aux = atual->getAnterior();
				atual = atual->getProximo();
				aux->setProximo(atual);
				atual->setAnterior(aux);
				aux = aux->getProximo();
				delete aux;
				apagou = true;
				aux = NULL;
				num_elementos--;
			}
			else
			{
				atual = atual->getProximo();
				i++;
			}
		}
	}



	/*cout << "While ANTES" << endl;
	while (atual != NULL)
	{
		cout << "primeiro IF" << endl;
		cout << num << endl;
		cout << i << endl;
		if (i == num)
		{
			if (i == 0)
			{
				cout << "i = 0" << endl;
				aux = primeiro;
				atual->getProximo();
				atual->setAnterior(NULL);
				primeiro = atual;
				delete aux;
				apagou = true;
				aux = NULL;
				num_elementos--;
			}
			else if (i == num_elementos - 1)
			{
				cout << "i = 11" << endl;
				aux = atual->getAnterior();
				aux->setProximo(NULL);
				aux = atual;
				ultimo = atual;
				delete aux;
				apagou = true;
				aux = NULL;
				num_elementos--;
			}
			else
			{
				cout << "i = outro" << endl;
				aux = atual->getAnterior();
				atual = atual->getProximo();
				aux->setProximo(atual);
				atual->setAnterior(aux);
				aux = aux->getProximo();
				delete aux;
				apagou = true;
				aux = NULL;
				num_elementos--;
			}
			i++;
		}
		else
		{
			atual = atual->getProximo();
			i++;
		}
	}*/
	cout << "Saiu" << endl;
}

template<class L>
void Lista_Encadeada<L>::limpar()
{
	Elemento<L>* aux = NULL;
	atual = primeiro;
	while (aux != NULL)
	{
		aux = atual;
		atual = atual->getProximo();
		aux->setProximo(NULL);
		aux->setAnterior(NULL);
		aux->setInfo(NULL);
		delete aux;
	}
	num_elementos = 0;
	primeiro = NULL;
	atual = NULL;
	ultimo = NULL;
}