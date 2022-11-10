#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes():
inimigos(),
obstaculos()
{
	colidiu = false;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{

}

bool Gerenciador_Colisoes::colisao()
{
	return true;
}