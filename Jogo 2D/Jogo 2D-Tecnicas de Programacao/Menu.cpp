#include "Menu.h"

Menu::Menu(int i):
	Ente(i),
	fonte(),
	imagem(),
	fundo(),
	previa1(),
	previa2()
{
	inicVariaveis();
}

Menu::~Menu()
{
	apertou = false;
	selecao = false;
	delay = 0;
	tempoDelay = 0;
	escolha = 0;
	escFase = 0;
	escOpcoes = 0;
	rodando_menu = true;
	numFase = 0;
	numJogadores = 0;

	if (!escrita.empty())
	{
		for (int i = 0; i < escrita.size(); i++)
		{
			delete &escrita[i];
		}
		escrita.clear();
	}
	if (!coordenadas.empty())
	{
		for (int i = 0; i < coordenadas.size(); i++)
		{
			delete & coordenadas[i];
		}
		coordenadas.clear();
	}
	if (!textos.empty())
	{
		for (int i = 0; i < textos.size(); i++)
		{
			delete & textos[i];
		}
		textos.clear();
	}
	if (!tamanhos.empty())
	{
		for (int i = 0; i < tamanhos.size(); i++)
		{
			delete &tamanhos[i];
		}
		tamanhos.clear();
	}
	if (!escolhaFases.empty())
	{
		for (int i = 0; i < escolhaFases.size(); i++)
		{
			delete &escolhaFases[i];
		}
		escolhaFases.clear();
	}
}

void Menu::inicVariaveis()
{
	escolha = 1;
	apertou = false;
	selecao = false;
	rodando_menu = true;
	numFase = 1;
	numJogadores = 1;

	delay = 0;
	tempoDelay = 15;

	fonte.loadFromFile("../../Fontes/Font.otf");
	imagem.loadFromFile("../../Texturas/Cenario/Menu.png");
	fundo.setTexture(imagem);

	escolhaFases.resize(2);
	escrita = { "A Floresta","Jogar","Fases","Ranking","Opcoes","Sair", "Fase Um", "Fase Dois", "Um Jogador", "Dois Jogadores", "Voltar"};
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

	previa1.loadFromFile("../../Texturas/Cenario/Fundo.jpg");
	escolhaFases[0].setTexture(&previa1);
	escolhaFases[0].setSize(Vector2f(500, 500));
	escolhaFases[0].setPosition(310, 290);

	previa2.loadFromFile("../../Texturas/Cenario/FaseDois.jpg");
	escolhaFases[1].setTexture(&previa2);
	escolhaFases[1].setSize(Vector2f(500, 500));
	escolhaFases[1].setPosition(1010, 290);
}

void Menu::executar()
{
	apertou = false;
	bool clique = false;
	if(clique == false) 
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

void Menu::escolhaFase()
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

void Menu::escolhaOpcoes()
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

void Menu::imprimir()
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

void Menu::imprimirOpcoesFases()
{
	Gerenciador_Grafico::getInstancia_Grafico()->limpar();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[6]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[7]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[10]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenhar(escolhaFases[1]);
	Gerenciador_Grafico::getInstancia_Grafico()->mostrar();
}

void Menu::imprimirOpcoes()
{
	Gerenciador_Grafico::getInstancia_Grafico()->limpar();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[8]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[9]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[10]);
	Gerenciador_Grafico::getInstancia_Grafico()->mostrar();
}

const bool Menu::getRodandoMenu() const
{
	return rodando_menu;
}

void Menu::setRodandoMenu(const bool mn)
{
	rodando_menu = mn;
}

const int Menu::getEscolha() const
{
	return escolha;
}

const int Menu::getNumFase() const
{
	return numFase;
}

const int Menu::getNumJogadores() const
{
	return numJogadores;
}