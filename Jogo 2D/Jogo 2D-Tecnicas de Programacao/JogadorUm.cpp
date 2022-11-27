#include "JogadorUm.h"


//Gerenciador_Eventos* Gerenciador_Eventos::instancia_eventos = Gerenciador_Eventos::getInstancia_Eventos();

JogadorUm::JogadorUm(int i, Vector2f pos, Vector2f tam) :
	Jogador(i, pos, tam)
{
	delay = 0;
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

	iniciarTexturas();

	cout << "Criou Jogador Um" << endl;
}

JogadorUm::~JogadorUm()
{
}

void JogadorUm::iniciarVariaveis()
{
	delay = 0;
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

void JogadorUm::iniciarTexturas()
{
	for (int i = 0; i < 10; i++)
	{
		if (!txJogadorPula[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect((i * 150), 220, 125, 100))) {
			std::cout << "Erro ao carregar textura do pulo do cavaleiro\n";
		}
		txJogadorPula[i].setSmooth(true);

		if (!txJogadorAtaque[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect((i * 150), 440, 125, 100))) {
			std::cout << "Erro ao carregar textura do ataque do cavaleiro\n";
		}
		txJogadorAtaque[i].setSmooth(true);
	}

	for (int i = 0; i < 6; i++)
	{
		if (!txJogadorCorre[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect((i * 150), 110, 125, 100))) {
			std::cout << "Erro ao carregar textura da corrida do cavaleiro\n";
		}
		txJogadorCorre[i].setSmooth(true);
	}

	for (int i = 0; i < 4; i++)
	{
		if (!txJogadorParado[i].loadFromFile("../../Texturas/Personagens/Cavaleiro/Cavaleiro Dark.png", IntRect((i * 150), 0, 125, 100))) {
			std::cout << "Erro ao carregar textura do cavaleiro parado\n";
		}
		txJogadorParado[i].setSmooth(true);
	}

	spVida.resize(vida / 100);
	txVida.loadFromFile("../../Texturas/Cenario/Vida.png");
	txVida.setSmooth(true);
	for (int i=0; i < vida/100; i++)
	{
		spVida[i].setTexture(txVida);
		spVida[i].setPosition(Vector2f((30.f) + (50 * i), 10.f));
	}
}

void JogadorUm::executar()
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

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		direcionalEsquerdo();
	}

	else if (Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direcionalDireito();
	}
	else
	{
		parar();
	}

	//pulo 
	if (Keyboard::isKeyPressed(Keyboard::W) && jogador_pulou == false)
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
	if (Keyboard::isKeyPressed(Keyboard::Space) && atacou == false)
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
		delay++;
		if (delay % 100 == 0) {
			levou_dano = false;
			delay = 0;
		}
	}
}

void JogadorUm::ataque()
{
	if (limitadorTex_ataque <= 9)
	{
		forma.setTexture(&txJogadorAtaque[limitadorTex_ataque]);
		if (frame1 % 5 == 0)
			limitadorTex_ataque++;
		atualizarTextura();
	}
	else
		atacou = false;
}

void JogadorUm::direcionalEsquerdo()
{
	if (lado == Lado::direita)
	{
		forma.setScale(Vector2f(-1, 1));
		forma.setOrigin(Vector2f{ forma.getOrigin().x + 100.f,forma.getOrigin().y });
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

void JogadorUm::direcionalDireito()
{
	if (lado == Lado::esquerda)
	{
		forma.setScale(Vector2f(1, 1));
		forma.setOrigin(Vector2f{ forma.getOrigin().x - 100.f,forma.getOrigin().y });
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

void JogadorUm::parar()
{
	velocidade = { 0.f, velocidade.y };
}

void JogadorUm::pulo()
{
	posicao = { posicao.x + velocidade.x, posicao.y - velocidade.y };
	forma.setTexture(&txJogadorPula[limitadorTex_pulando]);

	if (limitadorTex_pulando > 10)
		limitadorTex_pulando = 0;
	if (frame1 % 10 == 0)
		limitadorTex_pulando++;
}

void JogadorUm::reageColisao(Entidade* outro, Vector2f dist_colisao)
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
				//jogador_pulou = false;
			}
			else
			{
				setPosicao(Vector2f(posicao.x - dist_colisao.x, posicao.y));
				velocidade.x = 0.f;
				velocidade.y = 0.f;
				//jogador_pulou = false;
			}
		}
		else
		{
			if (dist_centros.y > 0.f)
			{
				setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y)); // CHAO
				//velocidade.x = 0.f;
				velocidade.y = 0.f;
				jogador_pulou = false;
			}
			else
			{
				setPosicao(Vector2f(posicao.x, posicao.y + dist_colisao.y)); // TETO
				velocidade.x = 0.f;
				velocidade.y = 0.f;
				//jogador_pulou = false;
			}
		}
	}
	break;
	case(int(ID::relampago)): //id do Relampago
	{
	
	}
	case(int(ID::fogo)): //id do Slime
	{
		if (levou_dano == false)
			operator--(outro->getDano());
	}
	break;
	case(int(ID::slime)): //id do Slime
	{
		/*Vector2f distancia;
		distancia = { fabs((posicao.x + tamanho.x / 2.0f) - (outro->getPosicao().x + outro->getTamanho().x / 2.0f)) ,
					  fabs((posicao.y + tamanho.y / 2.0f) - (outro->getPosicao().y + outro->getTamanho().y / 2.0f)) };

		if (dist_colisao.x > dist_colisao.y)
		{
			if (distancia.x > 0.f)
			{
				setPosicao(Vector2f(posicao.x + dist_colisao.x, posicao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x - dist_colisao.x, outro->getPosicao().y));
				outro->setVelocidade({0,0});

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
				outro->setVelocidade({ outro->getVelocidade().x,0});

			}
			else
			{
				setPosicao(Vector2f(posicao.x, posicao.y - dist_colisao.y));
				outro->setPosicao(Vector2f(outro->getPosicao().x, outro->getPosicao().y + dist_colisao.y));
				outro->setVelocidade({ 0,0 });

			}
		}


		if (atacou == false)
		{
			if(levou_dano == false)
				operator--(outro->getDano());
		}
		else
			outro->setVida(outro->getVida() - dano);*/
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


		if (!atacou) {
			if (levou_dano == false)
				operator--(outro->getDano());
		}
		else
			outro->setVida(outro->getVida() - dano);
	}
	break;
	case(int(ID::chefao)): //id do mago
	{
		/*Vector2f distancia;
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
		}*/
	}
	break;
	case(int(ID::projetil)): //id do mago
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
		if (levou_dano == false)
			operator--(outro->getDano());
		outro->setVida(outro->getVida() - dano);
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

void JogadorUm::atualizarTextura()
{
	if (limitadorTex_parado > 4)
		limitadorTex_parado = 0;
	if (limitadorTex_correndo > 6)
		limitadorTex_correndo = 0;
}