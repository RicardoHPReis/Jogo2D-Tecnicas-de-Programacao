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
	if(LEntidades[num] == NULL)
		cout << "VERIFICAR SE EH NULO";
	//cout << LEntidades[num]->getId() << endl;         //Testes para achar o erro com monitor
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

void Lista_Entidades::apagarNumEntidade(int num)
{
	if (num >= 0 && num < LEntidades.getNumeroElementos())
		cout << "Sla pq não ta pegando a funcao";
		//LEntidades.apagarNumEntidade(num);
}

void Lista_Entidades::limparEntidades()
{
	LEntidades.limpar();
}

void Lista_Entidades::desenharEntidades()
{
	for(int i=0; i< LEntidades.getNumeroElementos(); i++)
	{
		LEntidades.operator[](i)->desenhar(LEntidades.operator[](i)->getForma());
	}
	LEntidades.operator[](0)->mostrar();
}

void Lista_Entidades::atualizarEntidade()
{
	for(int i=0; i< LEntidades.getNumeroElementos(); i++)
	{
		LEntidades.operator[](i)->atualizar();
	}
}

/*void Lista_Entidades::salvarEntidades()
{
	ofstream Gravacao("SalvamentoJogo.txt", ios::out);
	if(!Gravacao)
	{
		cout << "Arquivo não pode ser aberto!" << endl;
		return;
	}

	Entidade* aux = NULL;
	for(int i = 0; i < LEntidades.getNumeroElementos(); i++)
	{
		aux = LEntidades.operator[](i);
		//Gravacao << aux->getId() << ' ' << aux->getPosicao() << ' ' << aux->getTamanho() << endl;
	}
	Gravacao.close();
}*/

/*void Lista_Entidades::recuperarEntidades()
{
	ifstream Recuperacao("SalvamentoJogo.txt", ios::in);
	if (!Recuperacao)
	{
		cout << "Arquivo não pode ser aberto" << endl;
		return;
	}

	while(!Recuperacao.eof())
	{
		int id;
		Vector2f pos, tam;
		Entidade* aux = NULL;

		//Recuperacao >> id >> pos >> tam >> endl;
		if(0 != strcmp)
		{

		}
	}
	Recuperacao.close();
}*/