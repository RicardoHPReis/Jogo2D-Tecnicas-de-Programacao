#include "Inimigo.h"

Inimigo::Inimigo(int id, bool mov, Vector2f pos, Vector2f tam, int nr_vidas, int nr_dano, int ld, bool atacar, bool morreu, bool foiAtacado, bool nocv) :
	Personagem(1, true, pos, tam, 5, nr_dano, 1, true, morreu, foiAtacado)
{
	nocivo = nocv;
}

Inimigo::~Inimigo()
{
	nocivo = false;
}
