#include "FaseUm.h"

FaseUm::FaseUm(int i):
Fase(i)
{
	jogador = new Jogador();
	//esqueleto = new Esqueleto();
	
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
	if (!texturaFundo.loadFromFile("../../Texturas/Cenario/Fundo.jpg"))
	{
		cout << "Erro na textura do fundo do mapa.\n";
	}
	texturaFundo.setSmooth(true);
	fundo.setTexture(texturaFundo);

	if (!this->tChao.loadFromFile("../../Texturas/Cenario/Texturas_mapa.png", IntRect(184, 18, 77, 77)))
	{
		cout << "Erro na textura do mapa.\n";
	}
	this->tChao.setSmooth(true);

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
		//criarEspinhos(Vector2f{ (rand() % 8)*100.f, (rand() % 8)*980.f }, Vector2f((rand() % 8)*1920.f, (rand() % 8)*100.f));
	}
	
	//criarEsqueletos(Vector2f(900, 795));
	//criarMorcego(Vector2f(365 * (i + 1), 400));
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
