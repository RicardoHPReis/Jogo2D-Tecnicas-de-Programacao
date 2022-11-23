#include "FaseUm.h"

FaseUm::FaseUm(int i, Jogador* player):
Fase(i, player)
{
	iniciaVariaveis();
	iniciaTexturas();
	iniciaFase();
}

FaseUm::~FaseUm()
{
	deletarEntidades();
}

void FaseUm::iniciaVariaveis()
{
	vidasSp.resize(5);
}

void FaseUm::iniciaTexturas()
{
	//Gerenciador_Grafico::getInstancia_Grafico()->centralizar(forma.getPosition().x);
	if (!texturaFundo.loadFromFile("../../Texturas/Cenario/Fundo-Fase1.jpeg"))
	{
		cout << "Erro na textura do fundo do mapa.\n";
	}
	texturaFundo.setSmooth(true);
	fundo.setTexture(texturaFundo);

	tVidas.loadFromFile("../../Texturas/Cenario/Vida.png");
	if (!tVidas.loadFromFile("../../Texturas/Cenario/Vida.png"))
	{
		cout << "Erro na textura dos corações da vida.\n";
	}
	tVidas.setSmooth(true);
	for (size_t i{}; i < 5; ++i)
	{
		vidasSp[i].setTexture(tVidas);
		vidasSp[i].setPosition(Vector2f((30.f) + (50 * i), 10.f));
	}
}

void FaseUm::iniciaFase()
{
	int chance;
	srand(time(NULL));
	criarJogador(Vector2f(960.f, 200.f), jogador);

	//chao
	for (int i = 0; i < 3; i++)
	{
		//chao
		criarPlataformas(Vector2f{ 0.f + (i * 1920.f), 980.f }, Vector2f(1920.f, 300.f));

		//plataformas baixas laterais

		criarPlataformas(Vector2f{ 300.f + (i * 1920.f), 675.f }, Vector2f(260.f, 100.f));
		criarPlataformas(Vector2f{ 1360.f + (i * 1920.f), 675.f }, Vector2f(260.f, 100.f));

		//plataformas altas centralizads

		criarPlataformas(Vector2f{ 660.f + (i * 1920.f), 370.f }, Vector2f(600.f, 100.f));
	}

	chance = rand() % 8 + 3;
	for (int i = 0; i < chance; i++)
	{
		criarEspinhos(Vector2f{ (rand() % 10 + 1) * 100.f, 0.f }, Vector2f{ 50.f, 50.f });
	}

	chance = rand() % 8 + 3;
	for (int i = 0; i < chance; i++)
	{
		criarFogos(Vector2f{ (rand() % 10 + 1) * 75.f, 0.f }, Vector2f{ 100.f, 50.f });
	}

	chance = rand() % 2 + 3;
	for (int i = 0; i < chance; i++)
	{
		criarMorcegos(Vector2f{ (rand() % 10 + 1) * 30.f, 0.f });
	}

	chance = rand() % 2 + 3;
	for (int i = 0; i < chance; i++)
	{
		criarEsqueletos(Vector2f{ (rand() % 10 + 1) * 60.f, 0.f });
	}
	criarChefao(Vector2f{ 1000.f, 0.f });
}

void FaseUm::executar()
{

	gerenciaColisoes();
	listaEntidades.atualizarEntidade();

	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador->getForma());
	//Gerenciador_Grafico::getInstancia_Grafico()->desenhar(esqueleto->getForma());
	listaEntidades.desenharEntidades();

	//Gerenciador_Colisoes::executar();
	atualizaVidas();
}

void FaseUm::atualizaVidas()
{
	for (int i = 0; i < 5; i++)
	{
		Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(vidasSp[i]);
	}

	//se sofrer dano
	//this->jogador->status.setVidas(this->jogador->status.getVidas()--);

	//se ganhar uma vida
	//this->jogador->status.setVidas(this->jogador->status.getVidas()++);
}
