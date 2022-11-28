#include "JogadorDois.h"
//using namespace Entidades;
//using namespace Personagens;

JogadorDois::JogadorDois(int i, Vector2f pos, Vector2f tam) :
	Jogador(i, pos, tam)
{
	
	delayAtaque = 0;
	vida = 500;
	lado = Lado::esquerda;
	atacou = false;
	dano = 100;
	velocidadeMorte = 0;
	velocidade_max = 14;
	velocidade = { 0.f, 0.f };
	levou_dano = false;
	jogador_pulou = false;
	forcaPulo = 25.f;

	limitadorTex_parado = 0;
	limitadorTex_correndo = 0;
	frame1 = 0;

	iniciarTexturas();

	cout << "Criou Jogador Dois" << endl;
}

JogadorDois::~JogadorDois()
{
}

void JogadorDois::iniciarVariaveis()
{
	delayAtaque = 0;
	vida = 500;
	lado = Lado::direita;
	atacou = false;
	dano = 1;
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
	for (int i = 0; i < 8; i++)
	{
	
		if (!txJogadorCorre[i].loadFromFile("../../Texturas/Personagens/Arqueiro/ParadoCorre.png", IntRect((i * 150), 170, 125, 100))) {
			std::cout << "Erro ao carregar textura da corrida do Arqueiro\n";
		}
		txJogadorCorre[i].setSmooth(true);

		if (!txJogadorPula[i].loadFromFile("../../Texturas/Personagens/Arqueiro/Pulo.png", IntRect((i * 150), 25, 125, 100))) {
			std::cout << "Erro ao carregar textura do pulo do Arqueiro\n";
		}
		txJogadorPula[i].setSmooth(true);
	
		if (!txJogadorAtaque[i].loadFromFile("../../Texturas/Personagens/Arqueiro/Ataque.png", IntRect((i * 150), 25, 125, 100))) {
			std::cout << "Erro ao carregar textura do ataque do Arqueiro\n";
		}
		txJogadorAtaque[i].setSmooth(true);

		if (!txJogadorMorre[i].loadFromFile("../../Texturas/Personagens/Arqueiro/Morte.png", IntRect((i * 150), 173, 125, 100))) {
			std::cout << "Erro ao carregar textura do ataque do Arqueiro\n";
		}
		txJogadorMorre[i].setSmooth(true);
	}

	for (int i = 0; i < 2; i++)
	{
		if (!txJogadorPula[i + 8].loadFromFile("../../Texturas/Personagens/Arqueiro/Pulo.png", IntRect((i * 150), 170, 125, 100))) {
			std::cout << "Erro ao carregar textura do pulo do Arqueiro\n";
		}
		txJogadorPula[i + 8].setSmooth(true);

		if (!txJogadorMorre[i + 8].loadFromFile("../../Texturas/Personagens/Arqueiro/Morte.png", IntRect((i * 150), 325, 125, 100))) {
			std::cout << "Erro ao carregar textura do ataque do Arqueiro\n";
		}
		txJogadorMorre[i + 8].setSmooth(true);

		if (!txJogadorParado[i].loadFromFile("../../Texturas/Personagens/Arqueiro/ParadoCorre.png", IntRect((i * 150), 25, 125, 100))) {
			std::cout << "Erro ao carregar textura do Arqueiro parado\n";
		}
		txJogadorParado[i].setSmooth(true);
	}

	for (int i = 0; i < 3; i++)
	{
		if (!txJogadorAtaque[i + 8].loadFromFile("../../Texturas/Personagens/Arqueiro/Ataque.png", IntRect((i * 150), 170, 125, 100))) {
			std::cout << "Erro ao carregar textura do ataque do Arqueiro\n";
		}
		txJogadorAtaque[i + 8].setSmooth(true);

	}
	spVida.resize(vida / 100);
	txVida.loadFromFile("../../Texturas/Cenario/Vida.png");
	txVida.setSmooth(true);
	for (int i=0; i < vida / 100; i++)
	{
		spVida[i].setTexture(txVida);
		spVida[i].setPosition(Vector2f((30.f) + (50 * i), 80.f));
	}
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
	else if (velocidade.x <= -velocidade_max)
		velocidade = { -velocidade_max, velocidade.y };

	//andar para os 2 lados

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		direcionalEsquerdo();
	}

	else if (Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direcionalDireito();
	}
	else
	{
		parar();
	}

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
	if (Mouse::isButtonPressed(Mouse::Left) && atacou == false)
	{
		atacou = true;
		limitadorTex_ataque = 0;
	}
	if (atacou == true)
	{
		ataque();
	}

	calculaQueda();

	posicao = forma.getPosition();
	posicao += velocidade;
	setPosicao(posicao);

	if (vida < 0)
		estaMorto = true;

	frame1++;
	atualizavida();
	if (levou_dano == true)
	{
		delayAtaque++;
		if (delayAtaque % 100 == 0) {
			levou_dano = false;
			delayAtaque = 0;
		}
	}
	if (vida <= 0)
		estaMorto = true;
	if (estaMorto == true)
	{
		if (frame1 % 7 == 0)
			velocidadeMorte++;
		forma.setTexture(&txJogadorMorre[velocidadeMorte]);
		if (velocidadeMorte == 11)
		{
			setPosicao(Vector2f{ 10000.f,10000.f });
		}
	}
}

void JogadorDois::ataque()
{
	if (limitadorTex_ataque < 11)
	{
		forma.setTexture(&txJogadorAtaque[limitadorTex_ataque]);
		if (frame1 % 6 == 0)
			limitadorTex_ataque++;
		atualizarTextura();
	}
	else
		atacou = false;
}

void JogadorDois::direcionalEsquerdo()
{
	if (lado == Lado::direita)
	{
		forma.setScale(Vector2f(-1, 1));
		forma.setOrigin(Vector2f{ forma.getOrigin().x + 110.f,forma.getOrigin().y });
	}

	lado = Lado::esquerda;
	if (posicao.x >= 0.f) //Player nao passar dos limites da tela esquerda
	{
		velocidade = { velocidade.x - 1.f, velocidade.y };
		posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	}
	else
	{
		velocidade.x = 0.f;
	}

	forma.setTexture(&txJogadorCorre[limitadorTex_correndo]);
	if (frame1 % 6 == 0)
	{
		limitadorTex_correndo++;
		atualizarTextura();
	}
}

void JogadorDois::direcionalDireito()
{
	if (lado == Lado::esquerda)
	{
		forma.setScale(Vector2f(1, 1));
		forma.setOrigin(Vector2f{ forma.getOrigin().x - 110.f,forma.getOrigin().y });
	}

	lado = Lado::direita;
	if (posicao.x <= 1920.f - tamanho.x) //Player nao passar dos limites da tela esquerda
	{
		velocidade = { velocidade.x + 1.f, velocidade.y };
		posicao = { posicao.x - velocidade.x, posicao.y + velocidade.y };
	}
	else
	{
		velocidade.x = 0.f;
	}
	forma.setTexture(&txJogadorCorre[limitadorTex_correndo]);
	if (frame1 % 6 == 0)
	{
		limitadorTex_correndo++;
		atualizarTextura();
	}
}

void JogadorDois::parar()
{
	velocidade = { 0.f, velocidade.y };
}

void JogadorDois::pulo()
{
	posicao = { posicao.x + velocidade.x, posicao.y - velocidade.y };
	forma.setTexture(&txJogadorPula[limitadorTex_pulando]);

	if (limitadorTex_pulando >= 10)
		limitadorTex_pulando = 0;
	if (frame1 % 10 == 0)
		limitadorTex_pulando++;
}

void JogadorDois::reageColisao(Entidade* outro, Vector2f dist_colisao)
{
	switch (outro->getId())
	{
	case(int(ID::plataforma)): //id da plataforma
	{
		Vector2f dist_centros;
		dist_centros = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
					  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

		if (dist_colisao.x > dist_colisao.y)
		{
			if (dist_centros.x > 0.f)
			{
				setPosicao(Vector2f(posicao.x + dist_colisao.x, posicao.y)); //Parede
				velocidade.x = 0.f;
				velocidade.y = 0.f;
			}
			else
			{
				setPosicao(Vector2f(posicao.x - dist_colisao.x, posicao.y));
				velocidade.x = 0.f;
				velocidade.y = 0.f;
			}
		}
		else
		{
			if (dist_centros.y > 0.f)
			{
				setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y)); // CHAO
				velocidade.y = 0.f;
				jogador_pulou = false;
			}
			else
			{
				setPosicao(Vector2f(posicao.x, posicao.y - dist_colisao.y)); // TETO
				velocidade.x = 0.f;
				velocidade.y = 0.f;
			}
		}
	}
	break;
	case(int(ID::relampago)): //id do relampago
	{
		velocidade.x = 0.f;
		velocidade.y = 0.f;
	}
	case(int(ID::fogo)): //id do fogo
	{
		if (levou_dano == false)
			operator--(outro->getDano());
	}
	break;
	case(int(ID::slime)): //id do Slime
	{
		Vector2f distancia;
		distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
					  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

		if (dist_colisao.x > dist_colisao.y)
		{
			velocidade.x = velocidade.x / 3.f;
			outro->setLado(lado);
		}
		else
		{
			outro->setLado(lado);
			outro->setVida(outro->getVida() - 20); //da dano
		}

		if (!atacou)
		{
			if (levou_dano == false)
				operator--(outro->getDano()); //recebe dano
		}
		else
			outro->setVida(outro->getVida() - dano); //da dano
	}
	break;
	case(int(ID::morcego)): //id do morcego
	{
		Vector2f distancia;
		distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
					  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

		if (dist_colisao.x > dist_colisao.y)
		{
			if (distancia.x > 0.f)
			{
				setPosicao(Vector2f(posicao.x + dist_colisao.x, posicao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x - dist_colisao.x, outro->getPosicao().y));
				outro->setVelocidade({ 0,0 });
			}
			else
			{
				setPosicao(Vector2f(posicao.x - dist_colisao.x, posicao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x + dist_colisao.x, outro->getPosicao().y));
				outro->setVelocidade({ 0,0 });
			}
		}
		else
		{
			if (distancia.y > 0.f)
			{
				setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y)); // CHAO
				outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y - dist_colisao.y));
				outro->setVelocidade({ outro->getVelocidade().x,0 });
			}
			else
			{
				setPosicao(Vector2f(posicao.x, posicao.y - dist_colisao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y + dist_colisao.y));
				outro->setVelocidade({ 0,0 });
			}
		}
		outro->setLado(lado);
		if (!atacou)
		{
			if (levou_dano == false)
				operator--(outro->getDano()); //recebe dano
		}
		else
			outro->setVida(outro->getVida() - dano); //da dano
	}
	break;
	case(int(ID::chefao)): //id do chefao
	{
		Vector2f distancia;
		distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
					  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

		if (dist_colisao.x > dist_colisao.y)
		{
			if (distancia.x > 0.f)
			{
				setPosicao(Vector2f(posicao.x + dist_colisao.x, posicao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x - dist_colisao.x, outro->getPosicao().y));
				outro->setVelocidade({ 0,0 });
			}
			else
			{
				setPosicao(Vector2f(posicao.x - dist_colisao.x, posicao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x + dist_colisao.x, outro->getPosicao().y));
				outro->setVelocidade({ 0,0 });
			}
		}
		else
		{
			if (distancia.y > 0.f)
			{
				setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y)); // CHAO
				outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y - dist_colisao.y));
				outro->setVelocidade({ outro->getVelocidade().x,0 });
			}
			else
			{
				setPosicao(Vector2f(posicao.x, posicao.y - dist_colisao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y + dist_colisao.y));
				outro->setVelocidade({ 0,0 });
			}
		}

		if (!atacou)
		{
			if (levou_dano == false)
				operator--(outro->getDano()); //recebe dano
		}
		else
			outro->setVida(outro->getVida() - dano); //da dano
	}
	break;
	case(int(ID::projetil)): //id do projetil
	{

		if (levou_dano == false)
			operator--(outro->getDano());
	}
	break;
	case(int(ID::jogador)): //id do jogador
	{
		Vector2f distancia;
		distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
					  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

		if (dist_colisao.x > dist_colisao.y)
		{
			if (distancia.x > 0.f)
			{
				setPosicao(Vector2f(posicao.x + dist_colisao.x, posicao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x - dist_colisao.x, outro->getPosicao().y));
				outro->setVelocidade({ 0,0 });
			}
			else
			{
				setPosicao(Vector2f(posicao.x - dist_colisao.x, posicao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x + dist_colisao.x, outro->getPosicao().y));
				outro->setVelocidade({ 0,0 });
			}
		}
		else
		{
			if (distancia.y > 0.f)
			{
				setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y)); // CHAO
				outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y - dist_colisao.y));
				outro->setVelocidade({ outro->getVelocidade().x,0 });
			}
			else
			{
				setPosicao(Vector2f(posicao.x, posicao.y - dist_colisao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y + dist_colisao.y));
				outro->setVelocidade({ 0,0 });
			}
		}
		if (!atacou)
		{
			if (levou_dano == false)
				operator--(outro->getDano()); //recebe dano
		}
		else
			outro->setVida(outro->getVida() - dano); //da dano
	}
	break;
	}
}

void JogadorDois::atualizarTextura()
{
	if (limitadorTex_parado >= 2)
		limitadorTex_parado = 0;
	if (limitadorTex_correndo >= 8)
		limitadorTex_correndo = 0;
}