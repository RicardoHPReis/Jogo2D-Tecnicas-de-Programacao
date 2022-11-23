#include "JogadorDois.h"

JogadorDois::JogadorDois(int i, Vector2f pos, Vector2f tam) :
	Personagem(i, pos, tam)
{
	cout << "Criou Jogador 2" << endl;
	iniciarVariaiveis();
	iniciarTexturas();
}

JogadorDois::~JogadorDois()
{
}

void JogadorDois::iniciarVariaiveis()
{
	//forma.setSize(tamanho);
	//forma.setPosition(400.f, 400.f);
	//posicao = forma.getPosition();

	podeAtacar = true;
	vida = 5000;
	lado = Lado::direita;
	atacou = false;
	dano = 1000;
	velocidade_max = 14;
	velocidade = { 0.f, 0.f };
	levou_dano = false;
	jogador_pulou = false;
	forcaPulo = 25.f;

	limitadorTex_parado = 0;
	limitadorTex_correndo = 0;
	frame1 = 0;
}

void JogadorDois::iniciarTexturas()
{
	/*for (int i = 0; i < 10; i++)
	{
		if (!txJogadorPula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect(30 + (i * 150), 220, 125, 100))) {
			std::cout << "Erro ao carregar textura do pulo do cavaleiro\n";
		}
		txJogadorPula[i].setSmooth(true);

		if (!txJogadorAtaque[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect(30 + (i * 150), 440, 125, 100))) {
			std::cout << "Erro ao carregar textura do ataque do cavaleiro\n";
		}
		txJogadorAtaque[i].setSmooth(true);
	}

	for (int i = 0; i < 6; i++)
	{
		if (!txJogadorCorre[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect(30 + (i * 150), 110, 125, 100))) {
			std::cout << "Erro ao carregar textura da corrida do cavaleiro\n";
		}
		txJogadorCorre[i].setSmooth(true);
	}

	for (int i = 0; i < 4; i++)
	{
		if (!txJogadorParado[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect(30 + (i * 150), 0, 125, 100))) {
			std::cout << "Erro ao carregar textura do cavaleiro parado\n";
		}
		txJogadorParado[i].setSmooth(true);
	}*/
	forma.setFillColor(Color::Blue);
}

void JogadorDois::executar()
{
	if (frame1 % 10 == 0)
		limitadorTex_parado++;
	atualizarTextura();
	forma.setTexture(&txJogadorParado[limitadorTex_parado]);

	//defina para nao passar a velocidade maxima
	if (velocidade.x >= velocidade_max)
		velocidade = { velocidade_max, velocidade.y };

	//andar para os 2 lados

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (lado == Lado::direita)
		{
			forma.setScale(Vector2f(-1, 1));
			forma.setOrigin(Vector2f{ forma.getOrigin().x + 100.f,forma.getOrigin().y });
		}
		direcionalEsquerdo();
	}

	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (lado == Lado::esquerda)
		{
			forma.setScale(Vector2f(1, 1));
			forma.setOrigin(Vector2f{ forma.getOrigin().x - 100.f,forma.getOrigin().y });
		}
		direcionalDireito();
	}
	else
		velocidade = { 0.f, velocidade.y };

	//pulo 
	if (Keyboard::isKeyPressed(Keyboard::Up) && jogador_pulou == false)
	{
		limitadorTex_pulando = 0;
		velocidade = { velocidade.x,velocidade.y - forcaPulo };
		jogador_pulou = true;
	}

	//cair
	if (jogador_pulou == true)
	{
		pulo();
	}

	//atacar
	if ((Mouse::isButtonPressed(Mouse::Left) || Mouse::isButtonPressed(Mouse::Right)) && atacou == false)
	{
		atacou = true;
		limitadorTex_ataque = 0;
	}
	if (atacou == true)
	{
		ataque();
	}

	calculaQueda();

	Vector2f pos = forma.getPosition();
	pos += velocidade;

	setPosicao(pos);
	frame1++;

	cout << vida << endl;
}

void JogadorDois::ataque()
{
	if (limitadorTex_ataque <= 9)
	{
		forma.setTexture(&txJogadorAtaque[limitadorTex_ataque]);
		if (frame1 % 5 == 0)
			limitadorTex_ataque++;
		atualizarTextura();
	}
	else
		setAtaque(false);
}

void JogadorDois::direcionalEsquerdo()
{
	lado = Lado::esquerda;
	velocidade = { velocidade.x - 1.f, velocidade.y };
	posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	forma.setTexture(&txJogadorCorre[limitadorTex_correndo]);
	if (frame1 % 6 == 0) {
		limitadorTex_correndo++;
		atualizarTextura();
	}
	//Gerenciador_Grafico::getInstancia_Grafico()->centralizar(forma.getPosition().x);
}

void JogadorDois::direcionalDireito()
{
	lado = Lado::direita;
	velocidade = { velocidade.x + 1.f, velocidade.y };
	posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	forma.setTexture(&txJogadorCorre[limitadorTex_correndo]);
	if (frame1 % 6 == 0)
	{
		limitadorTex_correndo++;
		atualizarTextura();
	}
	//Gerenciador_Grafico::getInstancia_Grafico()->centralizar(forma.getPosition().x);	
}

void JogadorDois::pulo()
{

	posicao = { posicao.x + velocidade.x, posicao.y - velocidade.y };
	forma.setTexture(&txJogadorPula[limitadorTex_pulando]);

	if (limitadorTex_pulando > 10)
		limitadorTex_pulando = 0;
	if (frame1 % 10 == 0)
		limitadorTex_pulando++;
}

void JogadorDois::colisao(Entidade* outro, Vector2f ds)
{
	switch (outro->getId())
	{
	case(int(ID::plataforma)): //id da plataforma
	{
		setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
		velocidade.x = 0.f;
		velocidade.y = 0.f;
		jogador_pulou = false;
	}
	break;
	case(int(ID::espinho)): //id do esqueleto
	{
		setPosicao(Vector2f{ posicao.x , posicao.y });
		velocidade.x = 0.f;
		velocidade.y = 0.f;
	}
	case(int(ID::fogo)): //id do esqueleto
	{
		operator--(outro->getDano());
	}
	break;
	case(int(ID::esqueleto)): //id do esqueleto
	{
		if (!atacou)
			operator--(outro->getDano());
		else
			outro->setVida(outro->getVida() - dano);
	}
	break;
	case(int(ID::morcego)): //id do morcego
	{
		if (!atacou)
			operator--(outro->getDano());
		else
			outro->setVida(outro->getVida() - dano);
	}
	break;
	case(int(ID::mago)): //id do mago
	{
		setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
		velocidade.x = 0.f;
		velocidade.y = 0.f;
		if (!atacou)
			operator--(outro->getDano());
		else
			outro->setVida(outro->getVida() - dano);
	}
	break;
	case(int(ID::projetil)): //id do mago
	{
		operator--(outro->getDano());
	}
	break;
	case(int(ID::jogador2)): //id do segundo jogador
	{
		setPosicao(Vector2f{ posicao.x - velocidade.x, posicao.y - velocidade.y });
		velocidade.x = 0.f;
		velocidade.y = 0.f;
	}
	break;
	}
}

void JogadorDois::atualizarTextura()
{
	if (limitadorTex_parado > 4)
		limitadorTex_parado = 0;
	if (limitadorTex_correndo > 6)
		limitadorTex_correndo = 0;
}

void JogadorDois::operator--(int dano)
{
	vida -= dano;
	levou_dano = true;
}

const bool JogadorDois::getLevouDano() const
{
	return levou_dano;
}