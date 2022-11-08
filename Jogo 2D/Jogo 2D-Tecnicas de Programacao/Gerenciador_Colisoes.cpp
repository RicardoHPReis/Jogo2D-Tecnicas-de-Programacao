#include "Gerenciador_Colisoes.h"

//Gerenciador_Colisoes* Gerenciador_Colisoes::instancia_colisoes = NULL;

Gerenciador_Colisoes::Gerenciador_Colisoes():
inimigos(),
obstaculos()
{
	colidiu = false;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	//delete instancia_colisoes;
}

/*static Gerenciador_Colisoes* getInstancia_Colisoes()
{
	if (!instancia_colisoes)
	{
		instancia_colisoes = new Gerenciador_Colisoes;
	}
	return instancia_colisoes;
}*/


bool Gerenciador_Colisoes::colisao()
{
	return true;
}