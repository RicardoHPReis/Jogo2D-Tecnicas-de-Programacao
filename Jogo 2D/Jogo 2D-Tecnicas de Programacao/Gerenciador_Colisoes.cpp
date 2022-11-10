#include "Gerenciador_Colisoes.h"


Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Gerenciador_Colisoes::Gerenciador_Colisoes():
listaInimigos(),
listaObstaculos()
{
	
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	//if (listaInimigos)
		//delete listaInimigos;
	//if (listaObstaculos)
		//delete listaObstaculos;
	if (instancia_colisoes)
		delete instancia_colisoes;
}

static Gerenciador_Colisoes* Gerenciador_Colisoes::getInstancia_Colisoes()
{
	if (!instancia_colisoes)
	{
		instancia_colisoes = new Gerenciador_Colisoes;
	}
	return instancia_colisoes;
}

Vector2f Gerenciador_Colisoes::calcularColisao(Ente* entidade, Ente* ent)
{
	Vector2f distancia, metade_retangulo, colisao;
	distancia = { fabs((entidade->getPosicao().x + entidade->getTamanho().x) / 2.0f - (ent->getPosicao().x + ent->getTamanho().x) / 2.0f), 
				  fabs((entidade->getPosicao().y + entidade->getTamanho().y) / 2.0f - (ent->getPosicao().y + ent->getTamanho().y) / 2.0f) };
	metade_retangulo = { entidade->getTamanho().x - ent->getTamanho().x,
						 entidade->getTamanho().y - ent->getTamanho().y };
	colisao = distancia - metade_retangulo;
	return colisao;
}

void Gerenciador_Colisoes::executar()
{
	list<Obstaculo*>::iterator *it;
	Vector2f colidiu;
	for (int i = 0; i < listaInimigos.size(); i++)
	{
		colidiu = calcularColisao(, listaInimigos[i]);
		if (colidiu.x >= -1.f && colidiu.y >= -1.f)
		{

		}
	}
	for (*it = listaObstaculos.begin(); *it != listaObstaculos.end(); *it++)
	{
		colidiu = calcularColisao(, it);
		if (colidiu.x >= -1.f && colidiu.y >= -1.f)
	}
	/*for (int j = 0; j < listaInimigos.size(); j++)
	{
		for (*it = listaObstaculos.begin(); *it != listaObstaculos.end(); *it++)
		{
			colidiu = calcularColisao(listaInimigos[j], it);
			if (colidiu.x >= -1.f && colidiu.y >= -1.f)
		}
	}*/
}