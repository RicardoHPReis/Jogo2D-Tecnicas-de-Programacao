#include "Plataforma.h"

Plataforma::Plataforma(int id, Vector2f pos, Vector2f tam):
Obstaculo(id, pos, tam)
{
	//forma.setFillColor(Color::Blue);

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

void Plataforma::colisao(Entidade* outrao, Vector2f ds)
{

}

void Plataforma::iniciarTexturas()
{
	//if (!this->textura_plataforma.loadFromFile("../../Texturas/Cenario/Plataforma.png", IntRect( 1025 , 995 , 870 , 600))) {
		//std::cout << "Erro ao carregar textura da plataforma\n";
	//}
	this->textura_plataforma.setSmooth(true);
	forma.setTexture(&textura_plataforma);
}

void Plataforma::iniciarStatus()
{
	danoso = false;
	lado = Lado::direita;
	velocidade = { 0.f, gravidade};
}
