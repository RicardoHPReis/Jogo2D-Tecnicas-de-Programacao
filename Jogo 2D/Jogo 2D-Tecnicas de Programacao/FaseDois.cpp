#include "FaseDois.h"

FaseDois::FaseDois(int i, Jogador* player, JogadorDois* player2) :
	Fase(i, player, player2)
{
	iniciaVariaveis();
	iniciaTexturas();
	iniciaFase();
}

FaseDois::~FaseDois()
{
	deletarEntidades();
	Gerenciador_Colisoes::getInstancia_Colisoes()->deletarListasColisoes();
}

void FaseDois::iniciaVariaveis()
{
}

void FaseDois::iniciaTexturas()
{
	if (!texturaFundo.loadFromFile("../../Texturas/Cenario/Fundo-Fase2.jpeg"))
	{
		cout << "Erro na textura do fundo do mapa.\n";
	}
	texturaFundo.setSmooth(true);
	fundo.setTexture(texturaFundo);

}

void FaseDois::iniciaFase()
{
	int chance;
	srand(time(NULL));
	criarJogador(Vector2f(960.f, 200.f));
	if (doisJogadores)
		criarJogadorDois(Vector2f(1000.f, 200.f));

	//chao	
	criarPlataformas(Vector2f{ 0.f , 980.f }, Vector2f(1920.f, 300.f));

	//plataformas medias laterais
	criarPlataformas(Vector2f{ 280.f, 450.f }, Vector2f(400.f, 100.f));
	criarPlataformas(Vector2f{ 1240.f, 450.f }, Vector2f(400.f, 100.f));

	//plataformas altas/baixa centralizads
	criarPlataformas(Vector2f{ 760.f, 200.f }, Vector2f(400.f, 100.f));
    criarPlataformas(Vector2f{ 760.f, 700.f }, Vector2f(400.f, 100.f));
	
	chance = rand() % 1 + 3;
	for (int i = 0; i < chance; i++)
	{
		//criarRelampagos(Vector2f{ (rand() % 10 + 1) * 100.f, 0.f }, Vector2f{ 50.f, 50.f });
	}
	chance = rand() % 1 + 3;
	for (int i = 0; i < chance; i++)
	{
		//criarFogos(Vector2f{ (rand() % 10 + 1) * 75.f, 0.f }, Vector2f{ 100.f, 50.f });
	}
	chance = rand() % 1 + 3;
	num_inimigos += chance;
	for (int i = 0; i < chance; i++)
	{
		criarMorcegos(Vector2f{ (rand() % 10 + 1) * 190.f, 0.f });
	}

	chance = rand() % 1 + 3;
	num_inimigos += chance;
	for (int i = 0; i < chance; i++)
	{
		criarSlimes(Vector2f{ (rand() % 10 + 1) * 190.f, 0.f });
	}
	//criarChefao(Vector2f{ 1500.f, 200.f });
	//num_inimigos++;
}

void FaseDois::executar()
{
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	gerenciaColisoes();
	listaEntidades.atualizarEntidade();
	remover();
	if (num_inimigos <= 0)
	{
		concluido = true;
	}
	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador->getForma());
	if (doisJogadores)
		Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador2->getForma());
	listaEntidades.desenharEntidades();
}