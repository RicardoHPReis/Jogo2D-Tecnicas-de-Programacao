#include "Plataforma.h"

Plataforma::Plataforma( Vector2f pos, Vector2f tam):
Obstaculo(id, pos, tam)
{
	posicao = pos;

	this->iniciarStatus();
	this->iniciarTexturas();

	forçaEmpuxo = gravidade * -1; //forca empuxo anula a gravidade
}

Plataforma::~Plataforma()
{
	forçaEmpuxo = 0;
}

void Plataforma::executado()
{

}

void Plataforma::atualizar()
{
	posicao.y = posicao.y + (gravidade + forçaEmpuxo); //aplicando gravidade nas plataformas voadoras que professor pediu
	forma.setPosition(posicao);
}

void Plataforma::iniciarTexturas()
{
	if (!this->plataformaIMG.loadFromFile("../../Texturas/Cenario/Plataforma.png", IntRect(1025, 987, 865, 600))) {
		cout << "Erro ao carregar a textura do Morcego morrendo\n";
	}
}

void Plataforma::iniciarStatus()
{
	danoso = false;
	lado = 1;
	velocidade = { 0.f, gravidade};
}
