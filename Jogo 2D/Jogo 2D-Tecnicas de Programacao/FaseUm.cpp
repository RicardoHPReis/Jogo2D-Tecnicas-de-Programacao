#include "FaseUm.h"

FaseUm::FaseUm(int i, Jogador* player, JogadorDois* player2):
Fase(i, player, player2)
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
	vidaSp.resize(5);
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

	tvida.loadFromFile("../../Texturas/Cenario/Vida.png");
	if (!tvida.loadFromFile("../../Texturas/Cenario/Vida.png"))
	{
		cout << "Erro na textura dos corações da vida.\n";
	}
	tvida.setSmooth(true);
	for (size_t i{}; i < 5; ++i)
	{
		vidaSp[i].setTexture(tvida);
		vidaSp[i].setPosition(Vector2f((30.f) + (50 * i), 10.f));
	}
}

void FaseUm::iniciaFase()
{
	int chance;
	srand(time(NULL));
	criarJogador(Vector2f(960.f, 200.f));
	if(doisJogadores)
		criarJogadorDois(Vector2f(1000.f, 200.f));

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

	criarPlataformas(Vector2f{ 0.f, 0.f }, Vector2f(10.f, 1080.f)); // Temporario
	criarPlataformas(Vector2f{ 1920.f, 0.f }, Vector2f(10.f, 1080.f)); // Temporario

	chance = rand() % 1 + 3;
	for (int i = 0; i < chance; i++)
	{
		//criarPlataformas(Vector2f{ (rand() % 10 + 1), 980.f }, Vector2f(1920.f, 100.f));
	}

	chance = rand() % 1 + 3;
	for (int i = 0; i < chance; i++)
	{
		//criarEspinhos(Vector2f{ (rand() % 10 + 1) * 100.f, 0.f }, Vector2f{ 50.f, 50.f });
	}
	chance = rand() % 1 + 3;
	for (int i = 0; i < chance; i++)
	{
		//criarFogos(Vector2f{ (rand() % 10 + 1) * 75.f, 0.f }, Vector2f{ 100.f, 50.f });
	}
	chance = rand() % 1 + 3;
	for (int i = 0; i < chance; i++)
	{
		criarMorcegos(Vector2f{ (rand() % 10 + 1) * 30.f, 0.f });
	}
	chance = rand() % 1 + 3;
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
	atualizavida();
	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador->getForma());
	if(doisJogadores)
		Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador2->getForma());
	listaEntidades.desenharEntidades();
}

void FaseUm::atualizavida()
{
	for (int i = 0; i < (jogador->getVida() / 1000); i++)
	{
		Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(vidaSp[i]);
	}
}
