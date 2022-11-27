#include "Menu.h"

Menu::Menu(int i):
	Ente(i),
	fonte(),
	imagem(),
	fundo()
{
	escolha = 1;
	apertou = false;
	selecao = false;
	rodando_menu = true;
	delay = 0;
	tempoDelay = 15;
}

Menu::~Menu()
{
	apertou = false;
	selecao = false;
	delay = 0;
	tempoDelay = 0;
	rodando_menu = false;

	if (!escrita.empty())
	{
		for (int i = 0; i < escrita.size(); i++)
		{
			delete &escrita[i];
		}
		escrita.clear();
	}
	if (!coordenadas.empty())
	{
		for (int i = 0; i < coordenadas.size(); i++)
		{
			delete & coordenadas[i];
		}
		coordenadas.clear();
	}
	if (!textos.empty())
	{
		for (int i = 0; i < textos.size(); i++)
		{
			delete & textos[i];
		}
		textos.clear();
	}
	if (!tamanhos.empty())
	{
		for (int i = 0; i < tamanhos.size(); i++)
		{
			delete &tamanhos[i];
		}
		tamanhos.clear();
	}
}

const bool Menu::getRodandoMenu() const
{
	return rodando_menu;
}

void Menu::setRodandoMenu(const bool mn)
{
	rodando_menu = mn;
}

const int Menu::getEscolha() const
{
	return escolha;
}