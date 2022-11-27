#include "Plataforma.h"

Plataforma::Plataforma(int id, Vector2f pos, Vector2f tam):
Obstaculo(id, pos, tam)
{
	iniciarStatus();
	iniciarTexturas();

	forcaEmpuxo = gravidade * -1; //forca empuxo anula a gravidade
	cout << "Criou plataforma!" << endl;
}

Plataforma::~Plataforma()
{
	forcaEmpuxo = 0;
}

void Plataforma::executar()
{
	//posicao.y = posicao.y + (gravidade + forçaEmpuxo); //aplicando gravidade nas plataformas voadoras que professor pediu
	calculaQueda();
	setPosicao(posicao);
}

void Plataforma::reageColisao(Entidade* outrao, Vector2f ds)
{
}

void Plataforma::iniciarTexturas()
{
	if (!this->textura_plataforma.loadFromFile("../../Texturas/Cenario/Plataforma.png", IntRect(  265, 195, 271, 40)))
	{
		std::cout << "Erro ao carregar textura da plataforma\n";
	}
	this->textura_plataforma.setSmooth(true);
	forma.setTexture(&textura_plataforma);
}

void Plataforma::iniciarStatus()
{
	danoso = false;
	lado = Lado::direita;
	velocidade = { 0.f, gravidade};
}

void Plataforma::calculaQueda()
{
	velocidade = { velocidade.x, velocidade.y + gravidade + forcaEmpuxo };
}