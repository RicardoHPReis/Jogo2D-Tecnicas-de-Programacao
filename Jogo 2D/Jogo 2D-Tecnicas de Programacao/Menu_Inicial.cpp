#include "Menu_Inicial.h"

Menu_Inicial::Menu_Inicial(int i) :
	Menu(i),
	previa1(),
	previa2()
{
	numFase = 0;
	numJogadores = 1;

	fonte.loadFromFile("../../Fontes/Font.otf");
	imagem.loadFromFile("../../Texturas/Cenario/Menu.png");
	fundo.setTexture(imagem);

	escolhaFases.resize(2);
	escrita = { "A Floresta","Jogar","Fases","Ranking","Opcoes","Sair", "Fase Um", "Fase Dois", "Um Jogador", "Dois Jogadores", "Voltar" };
	textos.resize(11);
	coordenadas = { { 960,100 }, { 610,350 }, { 610,450 }, { 610,550 }, { 610,650 }, { 610,750 }, { 310,890 }, { 1010,890 }, { 610,650 }, { 610,750 }, { 960,950 } };
	tamanhos = { 100,50,50,50,50,50,50,50,50,50,50 };

	for (int i = 0; i < textos.size(); i++)
	{
		textos[i].setFont(fonte);
		textos[i].setString(escrita[i]);
		textos[i].setCharacterSize(tamanhos[i]);
		textos[i].setOutlineColor(Color::Red);
		textos[i].setPosition(coordenadas[i]);
	}

	textos[1].setOutlineThickness(4);
	escolha = 1;
	escFase = 1;
	escOpcoes = 1;

    previa1.loadFromFile("../../Texturas/Cenario/Fundo-Fase1.jpeg");
	escolhaFases[0].setTexture(&previa1);
	escolhaFases[0].setSize(Vector2f(500, 500));
	escolhaFases[0].setPosition(310, 290);

	previa2.loadFromFile("../../Texturas/Cenario/Fundo-Fase2.jpeg");
	escolhaFases[1].setTexture(&previa2);
	escolhaFases[1].setSize(Vector2f(500, 500));
	escolhaFases[1].setPosition(1010, 290);
}

Menu_Inicial::~Menu_Inicial()
{
	escFase = 0;
	escOpcoes = 0;
	numFase = 0;
	numJogadores = 0;

	if (!escolhaFases.empty())
	{
		for (int i = 0; i < escolhaFases.size(); i++)
		{
			delete& escolhaFases[i];
		}
		escolhaFases.clear();
	}
}

void Menu_Inicial::executar()
{
	apertou = false;
	bool clique = false;
	if (clique == false)
	{
		if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && delay == 0)
		{
			delay++;
			if (escolha > 1 && apertou == false)
			{
				--escolha;
				textos[escolha].setOutlineThickness(4);
				textos[escolha + 1].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && delay == 0)
		{
			delay++;
			if (escolha < 5 && apertou == false)
			{
				++escolha;
				textos[escolha].setOutlineThickness(4);
				textos[escolha - 1].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && !selecao)
		{
			selecao = true;
			if (escolha == 1) //RODA JOGO
			{
				if (numFase != 2)
					numFase = 1;
				rodando_menu = false;
				clique = true;
			}
			else if (escolha == 2) //COLOCAR AS FASES
			{
				escolhaFase();
				clique = true;
			}
			else if (escolha == 3) //COLOCAR O RANKING
			{

			}
			else if (escolha == 4) //COLOCAR AS OPCOES
			{
				escolhaOpcoes();
				clique = true;
			}
			else if (escolha == 5) //FECHA TUDO
			{
				clique = true;
				exit(1);
			}
		}
		if (delay > 0)
		{
			delay += 1;
			if (delay >= tempoDelay)
				delay = 0;
		}
		imprimir();
	}
}

void Menu_Inicial::escolhaFase()
{
	apertou = false;
	escFase = 1;
	selecao = false;

	while (!apertou)
	{
		if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && delay == 0)
		{
			delay++;
			if (escFase != 1)
			{
				escFase = 1;
				textos[6].setOutlineThickness(4);
				textos[7].setOutlineThickness(0);
				textos[10].setOutlineThickness(0);
			}
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && delay == 0)
		{
			delay++;
			if (escFase != 2)
			{
				escFase = 2;
				textos[7].setOutlineThickness(4);
				textos[6].setOutlineThickness(0);
				textos[10].setOutlineThickness(0);
			}
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && delay == 0)
		{
			delay++;
			if (escFase != 3)
			{
				escFase = 3;
				textos[10].setOutlineThickness(4);
				textos[6].setOutlineThickness(0);
				textos[7].setOutlineThickness(0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) && !apertou)
		{
			apertou = true;
			if (escFase == 1) //SELECIONA FASE 1
			{
				numFase = 1;
			}
			else if (escFase == 2) //SELECIONA FASE 2
			{
				numFase = 2;
			}
			else if (escFase == 3) //VOLTA
			{
			}
		}
		if (delay > 0)
		{
			delay += 1;
			if (delay >= tempoDelay)
				delay = 0;
		}
		imprimirOpcoesFases();
	}

}

void Menu_Inicial::escolhaOpcoes()
{
	apertou = false;
	escOpcoes = 1;
	selecao = false;
	while (!selecao)
	{
		if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && delay == 0)
		{
			delay++;
			if (escOpcoes != 1 && apertou == false)
			{
				escOpcoes = 1;
				textos[8].setOutlineThickness(4);
				textos[9].setOutlineThickness(0);
				textos[10].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && delay == 0)
		{
			delay++;
			if (escOpcoes != 2 && apertou == false)
			{
				escOpcoes = 2;
				textos[9].setOutlineThickness(4);
				textos[8].setOutlineThickness(0);
				textos[10].setOutlineThickness(0);
			}
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && delay == 0)
		{
			delay++;
			if (escOpcoes != 3 && apertou == false)
			{
				escOpcoes = 3;
				textos[10].setOutlineThickness(4);
				textos[8].setOutlineThickness(0);
				textos[9].setOutlineThickness(0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) && !selecao)
		{
			selecao = true;
			if (escOpcoes == 1) //RODA 1 JOGADOR
			{
				numJogadores = 1;
			}
			else if (escOpcoes == 2) //RODA 2 JOGADORES
			{
				numJogadores = 2;
			}
			else if (escOpcoes == 3) //VOLTA
			{
			}
		}
		if (delay > 0)
		{
			delay += 1;
			if (delay >= tempoDelay)
				delay = 0;
		}
		imprimirOpcoes();
	}

}

void Menu_Inicial::imprimir()
{
	Gerenciador_Grafico::getInstancia_Grafico()->limpar();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[1]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[2]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[3]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[4]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[5]);
	Gerenciador_Grafico::getInstancia_Grafico()->mostrar();
}

void Menu_Inicial::imprimirOpcoesFases()
{
	Gerenciador_Grafico::getInstancia_Grafico()->limpar();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[6]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[7]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[10]);
    Gerenciador_Grafico::getInstancia_Grafico()->desenhar(escolhaFases[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(escolhaFases[1]);
	Gerenciador_Grafico::getInstancia_Grafico()->mostrar();
}

void Menu_Inicial::imprimirOpcoes()
{
	Gerenciador_Grafico::getInstancia_Grafico()->limpar();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[8]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[9]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[10]);
	Gerenciador_Grafico::getInstancia_Grafico()->mostrar();
}

const int Menu_Inicial::getNumFase() const
{
	return numFase;
}

void Menu_Inicial::setNumFase(const int n_fase)
{
	numFase = n_fase;
}

const int Menu_Inicial::getNumJogadores() const
{
	return numJogadores;
}

void Menu_Inicial::setNumJogadores(const int n_jogadores)
{
	numJogadores = n_jogadores;
}