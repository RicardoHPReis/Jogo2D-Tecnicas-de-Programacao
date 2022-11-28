#include "Fogo.h"

Fogo::Fogo(int id, Vector2f pos, Vector2f tam) :
	Obstaculo(id, pos, tam)
{
	iniciarTexturas();
	attTextura = 0;
	frame = 0;
	velocidade = Vector2f{ 0.f,0.f };
	dano = 100;
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
	for (int i = 0; i < 8; i++)
	{
		if (!fogo[i].loadFromFile("../../Texturas/Obstaculo/Fogo.png", IntRect(i * 68.75f, 20.f, 68.f, 72.f))) {
			std::cout << "Erro ao carregar textura do pulo do cavaleiro\n";
		}
		fogo[i].setSmooth(true);
	}

}
void Fogo::executar()
{
	atualizarTextura();
	forma.setTexture(&fogo[attTextura]);

	setPosicao(posicao);

	calculaQueda(); //aplicando gravidade nas plataformas voadoras que professor pediu

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
	frame++;
}

void Fogo::reageColisao(Entidade* outro, Vector2f dist_colisao)
{
	switch (outro->getId())
	{
		case(int(ID::plataforma)): //id da plataforma
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
		}
		break;
	}
}

void Fogo::atualizarTextura()
{
    //muda para a proxima textura a cada 7 frames
    if (frame % 7 == 0)
		attTextura++;
    if (attTextura == 8)
		attTextura = 0;
    frame++;
}
