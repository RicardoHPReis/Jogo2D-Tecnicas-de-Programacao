#include "Fase.h"


Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Fase::Fase(int i) :
	Ente(i),
	listaEntidades(),
	jogador()
{
}

Fase::~Fase()
{
	delete jogador;
	deletarEntidades();
}

void Fase::gerenciaColisoes()
{
	
	Gerenciador_Colisoes::getInstancia_Colisoes()->colisaoJogadorInimigo();
	Gerenciador_Colisoes::getInstancia_Colisoes()->colisaoJogadorObstaculo();
	Gerenciador_Colisoes::getInstancia_Colisoes()->colisaoJogadorProjetil();
	Gerenciador_Colisoes::getInstancia_Colisoes()->colisaoInimigoObstaculo();
	Gerenciador_Colisoes::getInstancia_Colisoes()->colisaoProjetilObstaculo();
	
}

void Fase::criarJogador(Vector2f pos, Jogador *player)
{
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(jogador));
	Gerenciador_Colisoes::getInstancia_Colisoes()->setJogador(jogador);
}

/*void Fase::criarEsqueletos(Vector2f pos)
{
	Esqueleto* esqueleto = new Esqueleto(10,pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(esqueleto));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(esqueleto);
}*/

/*void Fase::criarMorcego(Vector2f pos)
{
	Morcego* morcego = new Morcego(11,pos);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(morcego));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarInimigo(morcego);
}*/

void Fase::criarPlataformas(Vector2f pos, Vector2f tam)
{
	Plataforma* plataforma = new Plataforma(100, pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(plataforma));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(plataforma);
}

void Fase::criarEspinhos(Vector2f pos, Vector2f tam)
{
	Espinho* espinho = new Espinho(100, pos, tam);
	listaEntidades.adicionarEntidade(static_cast<Entidade*>(espinho));
	Gerenciador_Colisoes::getInstancia_Colisoes()->adicionarObstaculo(espinho);
}

void Fase::deletarEntidades()
{
	listaEntidades.limparEntidades();
}