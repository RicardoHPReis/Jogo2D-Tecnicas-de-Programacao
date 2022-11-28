#include "FaseUm.h"

FaseUm::FaseUm(int i, Jogador* player, JogadorDois* player2):
	Fase(i, player, player2)
{
	iniciaVariaveis();
	iniciaTexturas();
}

FaseUm::~FaseUm()
{
	deletarEntidades();
	Gerenciador_Colisoes::getInstancia_Colisoes()->deletarListasColisoes();
}

void FaseUm::iniciaVariaveis()
{
	inicializada = false;
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

}

void FaseUm::iniciaFase()
{
	int chance;
	srand(time(NULL));

	criarJogadorDois(Vector2f(600.f, 960.f));
	criarJogador(Vector2f(100.f, 960.f));
	

	//chao
	criarPlataformas(Vector2f{ 0.f, 980.f }, Vector2f(1920.f, 300.f));

	//plataformas baixas laterais
	criarPlataformas(Vector2f{ 300.f , 675.f }, Vector2f(260.f, 100.f));
	criarPlataformas(Vector2f{ 1360.f , 675.f }, Vector2f(260.f, 100.f));

	//plataformas altas centralizads
	criarPlataformas(Vector2f{ 660.f, 370.f }, Vector2f(600.f, 100.f));
	

	chance = rand() % 4 + 1;
	for (int i = 0; i < chance; i++)
	{
		criarRelampagos(Vector2f{ 0.f, 0.f }, Vector2f{ 100.f, 980.f });
	}
	chance = rand() % 5 + 1;
	for (int i = 0; i < chance; i++)
	{
		//criarFogos(Vector2f{ (rand() % 1820 + 1) * 1.f, 0.f }, Vector2f{ 100.f, 100.f });
	}
	chance = rand() % 2 + 3;
	num_inimigos += chance;
	for (int i = 0; i < chance; i++)
	{
		criarMorcegos(Vector2f{ (rand() % 1820 + 1) * 1.f, (rand() % 400 + 1) * 1.f });
	}

	chance = rand() % 2 + 3;
	num_inimigos += chance;
	for (int i = 0; i < chance; i++)
	{
		criarSlimes(Vector2f{ (rand() % 1820 + 1) * 1.f, 0.f });
	}
	//criarChefao(Vector2f{ 1500.f, 200.f });
	//num_inimigos++;
}

void FaseUm::executar()
{
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	gerenciaColisoes();
	listaEntidades.atualizarEntidade();

	//remover(); //ERRO

	if (num_inimigos <= 0)
	{
		concluido = true;
	}

	//Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador2->getForma());

	//Gerenciador_Grafico::getInstancia_Grafico()->desenhar(jogador->getForma());
	
	listaEntidades.desenharEntidades();
}

void FaseUm::setInicializada(bool aux)
{
	inicializada = aux;
}

const bool FaseUm::getInicializada() const
{
	return inicializada;;
}
