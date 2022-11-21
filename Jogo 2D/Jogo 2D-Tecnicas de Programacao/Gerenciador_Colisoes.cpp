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
	if (!listaInimigos.empty())
	{
		for (int i = 0; i < listaInimigos.size(); i++)
		{
			delete listaInimigos[i];
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
			delete listaProjeteis[i];
		}
		listaProjeteis.clear();
	}
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

void Gerenciador_Colisoes::setJogador(Jogador* player)
{
	jogador = player;
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

Vector2f Gerenciador_Colisoes::calcularColisao(Entidade* ent1, Entidade* ent2)
{
	Vector2f posicao1 = ent1->getPosicao();
	Vector2f posicao2 = ent2->getPosicao();

	Vector2f tamanho1 = ent1->getTamanho();
	Vector2f tamanho2 = ent2->getTamanho();
	
	Vector2f distanciaEntreCentros(
		fabs((posicao1.x + tamanho1.x/2.0f) - (posicao2.x + tamanho2.x/2.0f)),
		fabs((posicao1.y + tamanho1.y / 2.0f) - (posicao2.y + tamanho2.y / 2.0f))
	);
	Vector2f somaMetadeRetangulo(tamanho1.x / 2.0f + tamanho2.x / 2.0f, tamanho1.y / 2.0f + tamanho2.y / 2.0f);

	return Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
}

void Gerenciador_Colisoes::colisaoJogadorInimigo()
{
	Vector2f colidiu;
	for (int i = 0; i < listaInimigos.size() - 1; i++)
	{
		colidiu = calcularColisao(static_cast<Entidade*>(jogador), static_cast<Entidade*>(listaInimigos[i]));
		if (jogador->getLevouDano())
			continue;
		if (colidiu.x < 0.f && colidiu.y < 0.f)
		{
			jogador->setVelocidade({ 0.f, 0.f });
			if (listaInimigos[i]->getDanoso())
			{
				jogador->operator--(listaInimigos[i]->getDano());
			}
			cout << "Colidiu Jogador/Inimigo" << endl;
		}
	}
}

void Gerenciador_Colisoes::colisaoJogadorObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator it;
	for (int i = 0; i < listaObstaculos.size() - 1; i++)
	{
		colidiu = calcularColisao(jogador, *it);
		if (colidiu.x < 0.0f && colidiu.y < 0.0f)
		{
			jogador->colisao(*it , colidiu);
			cout << "Colidiu Jogador/Obstaculo" << endl;
		}
	}
}

void Gerenciador_Colisoes::colisaoJogadorProjetil()
{
	Vector2f colidiu;
	for (int i = 0; i < listaProjeteis.size() - 1; i++)
	{
		colidiu = calcularColisao(jogador, listaProjeteis[i]);
		if (jogador->getLevouDano())
			continue;
		if (colidiu.x < 0.f && colidiu.y < 0.f)
		{
			jogador->setVelocidade({ jogador->getVelocidade().x, 0.f });
			if (listaProjeteis[i]->getDanoso())
			{
				jogador->operator--(listaProjeteis[i]->getDano());
			}
			cout << "Colidiu Jogador/Projetil" << endl;
		}
	}
}

void Gerenciador_Colisoes::colisaoInimigoObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator it;
	for (int i = 0; i < listaInimigos.size() - 1; i++)
	{
		for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
		{
			colidiu = calcularColisao(listaInimigos[i], *it);
			if (colidiu.x < 0.f && colidiu.y < 0.f)
			{
				listaInimigos[i]->setVelocidade({ listaInimigos[i]->getVelocidade().x, 0.f });
				cout << "Colidiu Inimigo/Obstaculo" << endl;
			}
		}
	}
}

void Gerenciador_Colisoes::colisaoProjetilObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator it;
	for (int i = 0; i < listaProjeteis.size() - 1; i++)
	{
		for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
		{
			colidiu = calcularColisao(listaProjeteis[i], listaObstaculos.front());
			if (colidiu.x < 0.f && colidiu.y < 0.f)
			{
				listaProjeteis[i]->setVelocidade({ listaProjeteis[i]->getVelocidade().x, 0.f });
				cout << "Colidiu Projetil/Obstaculo" << endl;
			}
		}
	}
}

void Gerenciador_Colisoes::executar()
{
	colisaoInimigoObstaculo();
	colisaoJogadorInimigo();
	colisaoJogadorObstaculo();
	colisaoJogadorProjetil();
	colisaoProjetilObstaculo();
}
