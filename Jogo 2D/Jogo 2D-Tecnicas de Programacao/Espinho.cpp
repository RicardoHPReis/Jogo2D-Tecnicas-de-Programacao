#include "Espinho.h"

Espinho::Espinho(int id, Vector2f pos, Vector2f tam) :
    Obstaculo(id, pos, tam)
{
    forma.setFillColor(Color::Red);
    dano = 1;
    danoso = true;
    quebra = false;
}

Espinho::~Espinho()
{
    quebra - true;
}

void Espinho::executar()
{
    forma.setPosition(posicao);
}