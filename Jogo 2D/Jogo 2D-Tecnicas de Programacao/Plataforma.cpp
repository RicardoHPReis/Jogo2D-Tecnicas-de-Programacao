#include "Plataforma.h"

Plataforma::Plataforma(int id, Vector2f pos, Vector2f tam):
Obstaculo(id, pos, tam)
{
	forma.setFillColor(Color::Blue);
	posicao = pos;

	this->iniciarStatus();
	this->iniciarTexturas();

	forçaEmpuxo = gravidade * -1; //forca empuxo anula a gravidade
	cout << "Criou plataforma!" << endl;
}

Plataforma::~Plataforma()
{
	forçaEmpuxo = 0;
}

void Plataforma::executar()
{
	posicao.y = posicao.y + (gravidade + forçaEmpuxo); //aplicando gravidade nas plataformas voadoras que professor pediu
	forma.setPosition(posicao);
}

void Plataforma::iniciarTexturas()
{
	
}

void Plataforma::iniciarStatus()
{
	danoso = false;
	lado = 1;
	velocidade = { 0.f, gravidade};
}
