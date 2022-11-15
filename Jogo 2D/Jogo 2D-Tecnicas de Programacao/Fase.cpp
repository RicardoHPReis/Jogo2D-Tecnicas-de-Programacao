#include "Fase.h"


Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Fase::Fase(float grav):
	colisao(colisao->getInstancia_Colisoes()),
	listaEntidades(),
	listaObstaculos(),
	listaPersonagens(),
	grafico(grafico->getInstancia_Grafico())
{
	gravidade = grav;
}

Fase::~Fase()
{
	delete esqueleto;
	delete jogador;
}

void Fase::calculaQueda(Lista_Entidades LEntidades)
{

}