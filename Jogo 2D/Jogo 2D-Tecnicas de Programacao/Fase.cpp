#include "Fase.h"
/*using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Listas;*/

Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = Gerenciador_Colisoes::getInstancia_Colisoes();

Fase::Fase(int i, Jogador* player, JogadorDois* player2) :
	Ente(i),
	listaEntidades()
{
	jogador = player;
	jogador2 = player2;
	num_inimigos = 0;
	doisJogadores = false;
	concluido = false;
	removerTela = { 10000.f , 10000.f };
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogador(jogador);
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogadorDois(jogador2);
}

Fase::~Fase()
{
	deletarEntidades();
	num_inimigos = 0;
	doisJogadores = false;
	concluido = false;
}

void Fase::gerenciaColisoes()
{
	Gerenciador_Colisoes::getInstancia_Colisoes()->executar();
	num_inimigos = Gerenciador_Colisoes::getInstancia_Colisoes()->verificaInimigosVivos();
}

void Fase::criarJogador(Vector2f pos)
{
	jogador->setPosicao(pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(jogador));
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogador(jogador);
}

void Fase::criarJogadorDois(Vector2f pos)
{
	jogador2->setPosicao(pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(jogador2));
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogadorDois(jogador2);
}

void Fase::criarSlimes(Vector2f pos)
{
	Slime* slime = new Slime(int(ID::slime),pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(slime));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(slime);
}

void Fase::criarMorcegos(Vector2f pos)
{
	Morcego* morcego = new Morcego(int(ID::morcego),pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(morcego));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(morcego);
}

void Fase::criarPlataformas(Vector2f pos, Vector2f tam)
{
	Plataforma* plataforma = new Plataforma(int(ID::plataforma), pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(plataforma));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(plataforma);
}

void Fase::criarRelampagos(Vector2f pos, Vector2f tam)
{
	Relampago* relampago = new Relampago(int(ID::relampago), pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(relampago));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(relampago);
}

void Fase::criarFogos(Vector2f pos, Vector2f tam)
{
	Fogo* fogo = new Fogo(int(ID::fogo), pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(fogo));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(fogo);
}

void Fase::criarChefao(Vector2f pos)
{
	Chefao* chefao = new Chefao(int(ID::chefao), pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(chefao));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(chefao);
	criarProjetil(pos, chefao->getProjetil());
}

void Fase::criarProjetil(Vector2f pos, Projetil* projetil)
{
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(projetil));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarProjetil(projetil);
}

void Fase::deletarEntidades()
{
	listaEntidades.limparEntidades();
	Gerenciador_Colisoes::getInstancia_Colisoes()->deletarListasColisoes();
}

void Fase::verifica2jogadores()
{
	if (getDoisJogadores() == false)
	{
		jogador2->setPosicao(removerTela);
		jogador2->setVida(0.f);
		jogador2->setEstaMorto(true);
	}
}

const int Fase::getNumInimigos() const
{
	return num_inimigos;
}

void Fase::setNumInimigos(const int n_inimigos)
{
	num_inimigos = n_inimigos;
}

const bool Fase::getDoisJogadores() const
{
	return doisJogadores;
}

void Fase::setDoisJogadores(const bool dois)
{
	doisJogadores = dois;
}

const bool Fase::getConcluido() const
{
	return concluido;
}

void Fase::setConcluido(const bool concluiu)
{
	concluido = concluiu;
}

void Fase::remover()
{
	for (int i = 0; i < listaEntidades.getNumeroEntidades(); i++)
	{
		if(listaEntidades.operator[](i))
		{
			if (listaEntidades.operator[](i)->getVida() <= 0)
			{
				if (listaEntidades.operator[](i)->getId() != int(ID::jogador) && listaEntidades.operator[](i)->getId() != int(ID::jogador2))
				{
					listaEntidades.apagarNumEntidade(i);
					if ((listaEntidades.operator[](i)->getId() == int(ID::chefao) || listaEntidades.operator[](i)->getId() == int(ID::slime)) || listaEntidades.operator[](i)->getId() == int(ID::morcego))
						//Gerenciador_Colisoes::getInstancia_Colisoes()->deletarInimigo(listaEntidades.operator[](i));
					i--;
				}
				else
				{
					if (listaEntidades.operator[](i)->getId() == int(ID::jogador))
						Gerenciador_Colisoes::getInstancia_Colisoes()->setJogador(NULL);
					else if (listaEntidades.operator[](i)->getId() == int(ID::jogador2))
						Gerenciador_Colisoes::getInstancia_Colisoes()->setJogadorDois(NULL);
				}
			}
		}
		else
		{
			cout << "Não existe " << i << endl;
		}
	}
	cout << listaEntidades.getNumeroEntidades() << endl;
}