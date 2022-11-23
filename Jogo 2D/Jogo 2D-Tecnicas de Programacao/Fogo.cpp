#include "Fogo.h"

Fogo::Fogo(int id, Vector2f pos, Vector2f tam) :
	Obstaculo(id, pos, tam)
{
	iniciarTexturas();
	attTextura = 0;
	frame = 0;
	velocidade = Vector2f{ 0.f,0.f };
	forma.setFillColor(Color::Red);
	dano = 1;
	danoso = true;
	queimou = false;
	cout << "Criou fogo!" << endl;
}

Fogo::~Fogo()
{
	queimou = false;
}

void Fogo::iniciarTexturas()
{
	for (int i = 0; i < 10; i++)
	{
		if (!fogo[i].loadFromFile("../../Texturas/Obstaculo/Fogo.png", IntRect(i * 68.75f, 68.75f, 125.f, 92.f))) {
			std::cout << "Erro ao carregar textura do pulo do cavaleiro\n";
		}
		fogo[i].setSmooth(true);
	}

}
void Fogo::executar()
{

	if (frame % 10 == 0)
		attTextura++;
	forma.setTexture(&fogo[attTextura]);

	setPosicao(posicao);

	calculaQueda(); //aplicando gravidade nas plataformas voadoras que professor pediu

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
	frame++;
}

void Fogo::colisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
		case(int(ID::plataforma)): //id da plataforma
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
			//jogador_pulou = false;
		}
		break;
	}
}