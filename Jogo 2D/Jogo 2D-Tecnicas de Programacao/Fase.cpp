#include "Fase.h"


Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Fase::Fase(int i):
	Ente(i),
	listaEntidades()
{
	Fase::setGerenciador_Colisoes(Gerenciador_Colisoes::getInstancia_Colisoes());
}

Fase::~Fase()
{
}

void Fase::gerenciaColisoes()
{
	colisao->colisaoJogadorInimigo();
	colisao->colisaoJogadorObstaculo();
	colisao->colisaoJogadorProjetil();
	colisao->colisaoInimigoObstaculo();
	colisao->colisaoProjetilObstaculo();
}

void Fase::setGerenciador_Colisoes(Gerenciador_Colisoes* gc)
{
	colisao = gc;
}

void Fase::criarEsqueletos(Vector2f pos)
{
	Esqueleto* esqueleto = new Esqueleto(10,pos);
	listaEntidades.adicionarEntidade(esqueleto);
	colisao->adicionarInimigo(esqueleto);
}

void Fase::criarMorcego(Vector2f pos)
{
	Morcego* morcego = new Morcego(11,pos);
	listaEntidades.adicionarEntidade(morcego);
	colisao->adicionarInimigo(esqueleto);
}

void Fase::criarPlataformas(Vector2f pos, Vector2f tam)
{
	Plataforma* plataforma = new Plataforma(pos, tam);
	listaEntidades.adicionarEntidade(plataforma);
	colisao->adicionarObstaculo(plataforma);
}


void Fase::deletarEntidades()
{
	delete morcego;
	delete esqueleto;
	delete jogador;
}