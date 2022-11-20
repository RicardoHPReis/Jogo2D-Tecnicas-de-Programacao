#include "Projetil.h"


Projetil::Projetil(int i, Vector2f pos, Vector2f tam):
Entidade(i, pos, tam)
{
	inicProjetil();
	danoso = true;
	tiro = false;
	atingiu = false;
}

Projetil::~Projetil()
{
	atingiu = false;
	danoso = false;
	tiro = false;
}

void Projetil::setDanoso(const bool mal)
{
	danoso = mal;
}

const bool Projetil::getDanoso() const
{
	return danoso;
}

void Projetil::setAtirar(bool tir)
{
	tiro = tir;
}

void Projetil::iniciarTexturas()
{

}

void Projetil::executar()
{
	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(forma);
	forma.setPosition(posicao);
	atirar();
	if ((posicao.x <= 0 || posicao.x >= 1920) || posicao.y >= 1000) //Modificar depois para gerenciador de colisoes
		setAtirar(false);

	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(forma);
}

void Projetil::atirar()
{
	//Movimentos do projétil

	posicao.y = posicao.y + velocidade.y;
	if (lado == 1)
		posicao.x = posicao.x + velocidade.x;
	else if (lado == 2)
		posicao.x = posicao.x - velocidade.x;
}

bool Projetil::getAtirar()
{
	return tiro;
}

void Projetil::inicProjetil()
{
	atingiu = false;
	tiro = false;
	setVelocidade({ 5.f, 15.f });
}

void Projetil::setAtingiu(const bool atg)
{
	atingiu = atg;
}

const bool Projetil::getAtingiu() const
{
	return atingiu;
}