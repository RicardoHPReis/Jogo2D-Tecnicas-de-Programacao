#include "Fase.h"


Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = Gerenciador_Colisoes::getInstancia_Colisoes();

Fase::Fase(int i, Jogador* player, JogadorDois* player2) :
	Ente(i),
	listaEntidades()
{
	jogador = player;
	jogador2 = player2;
	doisJogadores = false;
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogador(jogador);
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogadorDois(jogador2);
}

Fase::~Fase()
{
	deletarEntidades();
}

void Fase::gerenciaColisoes()
{
	Gerenciador_Colisoes::getInstancia_Colisoes()->executar();
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

void Fase::criarEsqueletos(Vector2f pos)
{
	Esqueleto* esqueleto = new Esqueleto(int(ID::esqueleto),pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(esqueleto));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(esqueleto);
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

void Fase::criarEspinhos(Vector2f pos, Vector2f tam)
{
	Espinho* espinho = new Espinho(int(ID::espinho), pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(espinho));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(espinho);
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
}

const bool Fase::getDoisJogadores() const
{
	return doisJogadores;
}

void Fase::setDoisJogadores(const bool dois)
{
	doisJogadores = dois;
}