#include "Fase.h"


Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = Gerenciador_Colisoes::getInstancia_Colisoes();

Fase::Fase(int i, Jogador* player) :
	Ente(i),
	listaEntidades()
{
	jogador = player;
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogador(jogador);
}

Fase::~Fase()
{
	deletarEntidades();
}

void Fase::gerenciaColisoes()
{
	Gerenciador_Colisoes::getInstancia_Colisoes()->executar();
}

void Fase::criarJogador(Vector2f pos, Jogador *player)
{
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(jogador));
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogador(jogador);
}

void Fase::criarEsqueletos(Vector2f pos)
{
	Esqueleto* esqueleto = new Esqueleto(10,pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(esqueleto));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(esqueleto);
}

void Fase::criarMorcegos(Vector2f pos)
{
	Morcego* morcego = new Morcego(11,pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(morcego));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(morcego);
}

void Fase::criarPlataformas(Vector2f pos, Vector2f tam)
{
	Plataforma* plataforma = new Plataforma(100, pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(plataforma));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(plataforma);
}

void Fase::criarEspinhos(Vector2f pos, Vector2f tam)
{
	Espinho* espinho = new Espinho(101, pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(espinho));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(espinho);
}

void Fase::criarFogos(Vector2f pos, Vector2f tam)
{
	Fogo* fogo = new Fogo(102, pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(fogo));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(fogo);
}

void Fase::criarChefao(Vector2f pos)
{
	Chefao* chefao = new Chefao(13, pos);
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