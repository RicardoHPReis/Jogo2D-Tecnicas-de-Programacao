#include "Gerenciador_Colisoes.h"



Gerenciador_Colisoes::Gerenciador_Colisoes() :
	jogador(),
	jogador2(),
	listaInimigos(),
	listaObstaculos(),
	listaProjeteis()
{
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	jogador = NULL;
	deletarListasColisoes();
}

Gerenciador_Colisoes* Gerenciador_Colisoes::getInstancia_Colisoes()
{
	if (!instancia_colisoes)
	{
		instancia_colisoes = new Gerenciador_Colisoes;
	}
	return instancia_colisoes;
}

void Gerenciador_Colisoes::deletarInstancia_Colisoes()
{
	if (instancia_colisoes)
		delete instancia_colisoes;
}

void Gerenciador_Colisoes::setJogador(Jogador* player)
{
	jogador = player;
}

void Gerenciador_Colisoes::setJogadorDois(JogadorDois* player2)
{
	jogador2 = player2;
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

void Gerenciador_Colisoes::deletarInimigo(Entidade* entidade)
{
	for (int i = 0; i< listaInimigos.size(); i++)
	{
		if(listaInimigos[i])
		{
			if (listaInimigos[i] == entidade)
			{
				listaInimigos.erase(listaInimigos.begin() + i);
			}
		}
	}
	listaInimigos.shrink_to_fit();
}

void Gerenciador_Colisoes::deletarListasColisoes()
{
	if (!listaInimigos.empty())
	{
		for (int i = 0; i < listaInimigos.size(); i++)
		{
			listaInimigos.pop_back();
		}
		listaInimigos.clear();
	}
	if (!listaObstaculos.empty())
	{
		Obstaculo* aux = NULL;
		list<Obstaculo*>::iterator it;

		it = listaObstaculos.begin();

		while (it != listaObstaculos.end())
		{
			aux = *it;
			if (aux)
			{
				delete aux;
				aux = NULL;
			}
			it++;
		}
		listaInimigos.clear();
	}
	if (!listaProjeteis.empty())
	{
		for (int i = 0; i < listaProjeteis.size(); i++)
		{
			listaProjeteis.pop_back();
		}
		listaProjeteis.clear();
	}
}

Vector2f Gerenciador_Colisoes::calcularColisao(Entidade* entidade, Entidade* ent)
{
	Vector2f distancia, metade_retangulo, colisao;
	distancia = { fabs((entidade->getPosicao().x + entidade->getTamanho().x / 2.0f) - (ent->getPosicao().x + ent->getTamanho().x/2.0f)) ,
				  fabs((entidade->getPosicao().y + entidade->getTamanho().y / 2.0f) - (ent->getPosicao().y + ent->getTamanho().y / 2.0f)) };
	metade_retangulo = { (entidade->getTamanho().x + ent->getTamanho().x)/2.0f,
						 (entidade->getTamanho().y + ent->getTamanho().y)/2.0f };
	colisao = distancia - metade_retangulo;
	return colisao;
}

void Gerenciador_Colisoes::colisaoJogadorInimigo()
{
	Vector2f colidiu;
	for (int i = 0; i < listaInimigos.size(); i++)
	{
		colidiu = calcularColisao(static_cast<Entidade*>(jogador), static_cast<Entidade*>(listaInimigos[i]));
		if (colidiu.x < 0.f && colidiu.y < 0.f)
		{
			jogador->reageColisao(static_cast<Entidade*>(listaInimigos[i]), colidiu);
			//cout << "Colidiu Jogador/Inimigo" << endl;
		}
		if (!jogador2)
		{
			colidiu = calcularColisao(static_cast<Entidade*>(jogador2), static_cast<Entidade*>(listaInimigos[i]));
			if (colidiu.x < 0.f && colidiu.y < 0.f)
			{
				//jogador2->colisao(static_cast<Entidade*>(listaInimigos[i]), colidiu);
				//cout << "Colidiu Jogador2/Inimigo" << endl;
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoJogadorObstaculo()
{
	Vector2f colidiu, distancia;
	list<Obstaculo*>::iterator it;
	for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
	{
		colidiu = calcularColisao(static_cast<Entidade*>(jogador), static_cast<Entidade*>(*it));
		if (colidiu.x < 0.0f && colidiu.y < 0.0f)
		{
			jogador->reageColisao(static_cast<Entidade*>(*it) , colidiu);
			//cout << "Colidiu Jogador/Obstaculo" << endl;
		}
		if (!jogador2)
		{
			colidiu = calcularColisao(static_cast<Entidade*>(jogador2), static_cast<Entidade*>(*it));
			if (colidiu.x < 0.0f && colidiu.y < 0.0f)
			{
				jogador2->reageColisao(static_cast<Entidade*>(*it), colidiu);
				//cout << "Colidiu Jogador2/Obstaculo" << endl;
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoPlataformaObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator itP;
	list<Obstaculo*>::iterator itO;
	for (itO = listaObstaculos.begin(); itO != listaObstaculos.end(); itO++)
	{
		if ((*itO)->getId() == int(ID::plataforma))
		{
			continue;
		}
		for (itP = listaObstaculos.begin(); itP != listaObstaculos.end(); itP++)
		{
			if ((*itP)->getId() == int(ID::relampago) || (*itP)->getId() == int(ID::fogo))
			{
				continue;
			}
			colidiu = calcularColisao(static_cast<Entidade*>(*itO), static_cast<Entidade*>(*itP));
			if (colidiu.x < 0.0f && colidiu.y < 0.0f)
			{
				(*itO)->reageColisao(static_cast<Entidade*>(*itP), colidiu);
				//cout << "Colidiu Plataforma/Obstaculo" << endl;
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoJogadorProjetil()
{
	Vector2f colidiu;
	for (int i = 0; i < listaProjeteis.size(); i++)
	{
		colidiu = calcularColisao(static_cast<Entidade*>(jogador), static_cast<Entidade*>(listaProjeteis[i]));
		if (colidiu.x < 0.f && colidiu.y < 0.f)
		{
			jogador->reageColisao(static_cast<Entidade*>(listaProjeteis[i]), colidiu);
			//cout << "Colidiu Jogador/Projetil" << endl;
		}
		if (!jogador2)
		{
			colidiu = calcularColisao(static_cast<Entidade*>(jogador2), static_cast<Entidade*>(listaProjeteis[i]));
			if (colidiu.x < 0.f && colidiu.y < 0.f)
			{
				jogador2->reageColisao(static_cast<Entidade*>(listaProjeteis[i]), colidiu);
				//cout << "Colidiu Jogador2/Projetil" << endl;
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
			colidiu = calcularColisao(static_cast<Entidade*>(listaInimigos[i]), static_cast<Entidade*>(*it));
			if (colidiu.x < 0.f && colidiu.y < 0.f)
			{
				listaInimigos[i]->reageColisao(static_cast<Entidade*>(*it), colidiu);
				//cout << "Colidiu Inimigo/Obstaculo" << endl;
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoProjetilObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator it;
	for (int i = 0; i < listaProjeteis.size(); i++)
	{
		for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
		{
			colidiu = calcularColisao(static_cast<Entidade*>(listaProjeteis[i]), static_cast<Entidade*>(*it));
			if (colidiu.x < 0.f && colidiu.y < 0.f)
			{
				listaProjeteis[i]->reageColisao(static_cast<Entidade*>(listaProjeteis[i]), colidiu);
				//cout << "Colidiu Projetil/Obstaculo" << endl;
			}
		}
	}
}

void Gerenciador_Colisoes::executar()
{
	colisaoJogadorInimigo();
	colisaoJogadorObstaculo();
	colisaoJogadorProjetil();
	colisaoPlataformaObstaculo();
	colisaoProjetilObstaculo();
	colisaoInimigoObstaculo();
}