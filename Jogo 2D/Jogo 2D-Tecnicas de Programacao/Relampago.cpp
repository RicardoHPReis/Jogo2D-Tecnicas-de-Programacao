#include "Relampago.h"

Relampago::Relampago(int id, Vector2f pos, Vector2f tam) :
    Obstaculo(id, pos, tam)
{
	velocidade = Vector2f{ 0.f,0.f };
    dano = 0;
    danoso = false;
    paralisar = false;
    paralisacao = 60;
    tempo = 0;
    frame1 = 0;
    velocidade_Textura = 0;
	cout << "Criou relampago!" << endl;
	iniciaTexturas();
}

Relampago::~Relampago()
{
    paralisar = false;
    paralisacao = 0;
    tempo = 0;
}

void Relampago::iniciaTexturas()
{
    for (int i = 0; i < 13; i++)
    {
        if (!this->TRelampago[i].loadFromFile("../../Texturas/Obstaculo/Relampago.png", IntRect(i * 64, 0, 64, 64))) {
            cout << "Erro ao carregar a textura do Morcego voando\n";
        }
        TRelampago[i].setSmooth(true);
    }
}

void Relampago::executar()
{
    if (tempo == 0)
    {
        setPosicao(posicao);
    }

    atualizarTextura();
    forma.setTexture(&TRelampago[velocidade_Textura]);

	calculaQueda();
    
	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
    /*if (tempo > 0)
    {
        tempo += 1;
        if (tempo >= 240)
            tempo = 0;
    }*/
}

void Relampago::atualizarTextura()
{
    //muda para a proxima textura a cada 7 frames
    if (frame1 % 7 == 0)
        velocidade_Textura++;
    if (velocidade_Textura == 13)
        velocidade_Textura = 0;
    frame1++;
}


void Relampago::reageColisao(Entidade* outro, Vector2f ds)
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
		case(int(ID::fogo)): //id do fogo
		{
			setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
			velocidade.x = 0.f;
			velocidade.y = 0.f;
		}
		break;
	}
}