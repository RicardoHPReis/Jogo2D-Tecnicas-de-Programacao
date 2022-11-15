#include "Lista_Entidades.h"

Lista_Entidades::Lista_Entidades() :
	LEntidades()
{
}

Lista_Entidades::~Lista_Entidades()
{
	LEntidades.limpar();
}

Entidade* Lista_Entidades::operator[](int num)
{
	return LEntidades[num];
}

int Lista_Entidades::getNumeroEntidades()
{
	return LEntidades.getNumeroElementos();
}

void Lista_Entidades::adicionarEntidade(Entidade *entidade)
{
	if (!entidade)
		cout << "Erro ao adicionar entidade.\n";
	LEntidades.adicionar(entidade);
}

void Lista_Entidades::apagarEntidade(Entidade *entidade)
{
	if (!entidade)
		cout << "Erro ao apagar entidade.\n";
	LEntidades.apagar(entidade);
}

void Lista_Entidades::limparEntidades()
{
	LEntidades.limpar();
}