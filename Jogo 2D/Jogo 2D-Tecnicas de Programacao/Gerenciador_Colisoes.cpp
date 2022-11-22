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

Vector2f Gerenciador_Colisoes::calcularColisao(Entidade* entidade, Entidade* ent)
{
	Vector2f distancia, metade_retangulo, colisao;
	distancia = { fabs((entidade->getPosicao().x + entidade->getTamanho().x / 2.0f) - (ent->getPosicao().x + ent->getTamanho().x/2.0f)) ,
				  fabs((entidade->getPosicao().y + entidade->getTamanho().y / 2.0f) - (ent->getPosicao().y + ent->getTamanho().y / 2.0f)) };
	metade_retangulo = { (entidade->getTamanho().x + ent->getTamanho().x)/2.0f,
						 (entidade->getTamanho().y + ent->getTamanho().y)/2.0f };
	colisao = distancia - metade_retangulo;
	cout << colisao.x <<"    " << colisao.y << "\n";
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
			jogador->colisao(static_cast<Entidade*>(listaInimigos[i]), colidiu);
			cout << "Colidiu Jogador/Inimigo" << endl;
		}
	}
}

void Gerenciador_Colisoes::colisaoJogadorObstaculo()
{
	Vector2f colidiu;
	list<Obstaculo*>::iterator it = listaObstaculos.begin();
	for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
	{
		//cout << "%f\n" << jogador->getPosicao().y;
		colidiu = calcularColisao(static_cast<Entidade*>(jogador), static_cast<Entidade*>(*it));
		if (colidiu.x < 0.0f && colidiu.y < 0.0f)
		{
			cout << "Colidiu Jogador/Obstaculo" << endl;
			jogador->colisao(static_cast<Entidade*>(*it) , colidiu);
			//jogador->setPosicao(Vector2f{ 1000.f, 50.f });
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
			jogador->colisao(static_cast<Entidade*>(listaProjeteis[i]), colidiu);
			cout << "Colidiu Jogador/Projetil" << endl;
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
	for (int i = 0; i < listaProjeteis.size(); i++)
	{
		for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++)
		{
			colidiu = calcularColisao(static_cast<Entidade*>(listaProjeteis[i]), static_cast<Entidade*>(*it));
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
