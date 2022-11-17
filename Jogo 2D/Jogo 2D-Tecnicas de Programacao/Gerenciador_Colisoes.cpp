#include "Gerenciador_Colisoes.h"


Gerenciador_Colisoes::Gerenciador_Colisoes() :
	jogador(),
	listaInimigos(),
	listaObstaculos(),
	listaProjeteis()
{
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	jogador = NULL;
	listaInimigos.clear();
	//delete listaInimigos;
	listaObstaculos.clear();
	//delete listaObstaculos;
	listaProjeteis.clear();
	//delete listaProjeteis;
	if (instancia_colisoes)
		delete instancia_colisoes;
}

Gerenciador_Colisoes* Gerenciador_Colisoes::getInstancia_Colisoes()
{
	if (!instancia_colisoes)
	{
		instancia_colisoes = new Gerenciador_Colisoes;
	}
	return instancia_colisoes;
}

void Gerenciador_Colisoes::adicionarInimigo(Inimigo* inimigo)
{
	listaInimigos.push_back(inimigo);
}

void Gerenciador_Colisoes::adicionarObstaculo(Obstaculo* obstaculo)
{
	listaObstaculos.push_back(obstaculo);
}

void Gerenciador_Colisoes::adicionarProjetil(Projetil* projetil)
{
	listaProjeteis.push_back(projetil);
}

Vector2f Gerenciador_Colisoes::calcularColisao(Entidade* entidade, Entidade* ent)
{
	Vector2f distancia, metade_retangulo, colisao;
	distancia = { fabs((entidade->getPosicao().x + entidade->getTamanho().x) / 2.0f - (ent->getPosicao().x + ent->getTamanho().x) / 2.0f),
				  fabs((entidade->getPosicao().y + entidade->getTamanho().y) / 2.0f - (ent->getPosicao().y + ent->getTamanho().y) / 2.0f) };
	metade_retangulo = { entidade->getTamanho().x - ent->getTamanho().x,
						 entidade->getTamanho().y - ent->getTamanho().y };
	colisao = distancia - metade_retangulo;
	return colisao;
}


void Gerenciador_Colisoes::colisaoJogadorInimigo()
{
	Vector2f colidiu;
	for (int i = 0; i < listaInimigos.size(); i++)
	{
		colidiu = calcularColisao(jogador, listaInimigos[i]);
		if (jogador->getLevouDano())
			continue;
		if (colidiu.x < 0.f)
		{
			jogador->setVelocidade({ jogador->getVelocidade().x, 0.f });
			if (listaInimigos[i]->getDanoso())
			{
				jogador->operator--(listaInimigos[i]->getDano());
			}
		}
		if (colidiu.y < 0.f)
		{
			jogador->setVelocidade({ 0.f, jogador->getVelocidade().y });
			if (listaInimigos[i]->getDanoso())
			{
				jogador->operator--(listaInimigos[i]->getDano());
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoJogadorObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator it;
	Obstaculo* aux;
	for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
	{
		colidiu = calcularColisao(jogador, *it);
		if (jogador->getLevouDano())
			continue;
		if (colidiu.x < 0.f)
		{
			jogador->setVelocidade({ jogador->getVelocidade().x, 0.f });
			if((*it)->getDanoso())
			{
				jogador->operator--((*it)->getDano());
			}
		}
		if (colidiu.y < 0.f)
		{
			jogador->setVelocidade({ 0.f, jogador->getVelocidade().y });
			if ((*it)->getDanoso())
			{
				jogador->operator--((*it)->getDano());
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoJogadorProjetil()
{
	Vector2f colidiu;
	for (int i = 0; i < listaProjeteis.size(); i++)
	{
		colidiu = calcularColisao(jogador, listaProjeteis[i]);
		if (jogador->getLevouDano())
			continue;
		if (colidiu.x < 0.f)
		{
			jogador->setVelocidade({ jogador->getVelocidade().x, 0.f });
			if (listaProjeteis[i]->getDanoso())
			{
				jogador->operator--(listaProjeteis[i]->getDano());
			}
		}
		if (colidiu.y < 0.f)
		{
			jogador->setVelocidade({ 0.f, jogador->getVelocidade().y });
			if (listaProjeteis[i]->getDanoso())
			{
				jogador->operator--(listaProjeteis[i]->getDano());
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoInimigoObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator it;
	for (int i = 0; i < listaInimigos.size(); i++)
	{
		for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
		{
			colidiu = calcularColisao(listaInimigos[i], *it);
			if (colidiu.x < 0.f)
			{
				listaInimigos[i]->setVelocidade({ listaInimigos[i]->getVelocidade().x, 0.f });
				/*if(listaObstaculos.front()->getDanoso())
				{
					listaInimigos[i]->setVidas(listaInimigos[i]->getVidas() - listaObstaculos.front()->getDanoso());
				}*/
			}
			if (colidiu.y < 0.f)
			{
				listaInimigos[i]->setVelocidade({ 0.f, listaInimigos[i]->getVelocidade().y });
				/*if (listaObstaculos.front()->getDanoso())
				{
					listaInimigos[i]->setVidas(listaInimigos[i]->getVidas() - listaObstaculos.front()->getDanoso());
				}*/
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoProjetilObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator* it;
	for (int i = 0; i < listaProjeteis.size(); i++)
	{
		for (*it = listaObstaculos.begin(); *it != listaObstaculos.end(); it++)
		{
			colidiu = calcularColisao(listaProjeteis[i], listaObstaculos.front());
			if (colidiu.x < 0.f)
			{
				listaProjeteis[i]->setVelocidade({ listaProjeteis[i]->getVelocidade().x, 0.f });
			}
			if (colidiu.y < 0.f)
			{
				listaProjeteis[i]->setVelocidade({ 0.f, listaProjeteis[i]->getVelocidade().y });
			}
		}
	}
}