#include "Menu.h"
#include "Ente.h"

Menu::Menu(int i):
Ente(i),
	play(),
	fases(),
	ranking(),
	opcoes(),
	sair(),
	fonte(),
	imagem(),
	fundo(),
	cursorSprite()
{
	inicCursor();
	inicVariaveis();
}

Menu::~Menu()
{
	apertou = false;
	selecao = false;
	delay = 0;
	tempoDelay = 0;
	posMouse = { 0,0 };
	cordMouse = { 0,0 };
	posi = 0;
}

void Menu::inicVariaveis()
{
	apertou = false;
	selecao = false;

	delay = 0;
	tempoDelay = 15;

	fonte.loadFromFile("../../Fontes/Font.otf");
	imagem.loadFromFile("../../Texturas/Cenario/Menu.png");

	fundo.setTexture(imagem);

	posMouse = { 0,0 };
	cordMouse = { 0,0 };

	options = { "A Floresta","Jogar","Fases","Ranking","Opcoes","Sair" };
	texts.resize(6);
	coords = { { 610,200 } , { 610,350 }, { 610,450 }, { 610,550 }, { 610,650 }, { 610,750 } };
	sizes = { 100,50,50,50,50,50 };

	for (size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(fonte);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(Color::Black);
		texts[i].setPosition(coords[i]);
	}

	texts[1].setOutlineThickness(4);
	posi = 1;

	play.setSize(Vector2f(110, 50));
	play.setPosition(610, 350);
	fases.setSize(Vector2f(120, 50));
	fases.setPosition(610, 450);
	ranking.setSize(Vector2f(130, 50));
	ranking.setPosition(610, 550);
	opcoes.setSize(Vector2f(120, 50));
	opcoes.setPosition(610, 650);
	sair.setSize(Vector2f(100, 50));
	sair.setPosition(610, 750);

}

void Menu::inicCursor()
{
	if (cursor.loadFromFile("../../Texturas/Cenario/Cursor.png"))
		cursorSprite.setTexture(cursor);
}

void Menu::run_menu()
{
	bool clique = false;
	while (clique == false) 
	{
		posMouse = Mouse::getPosition(*grafico->getJanela());
		cordMouse = (grafico->getJanela())->mapPixelToCoords(posMouse);

		//Seleciona as opcoes usando seta para cima e para baixo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && delay == 0) 
		{
			delay++;
			if (posi < 5 && apertou == false) 
			{
				++posi;
				apertou = true;
				texts[posi].setOutlineThickness(4);
				texts[posi - 1].setOutlineThickness(0);		
				selecao = false;
				apertou = false;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && delay == 0) 
		{
			delay++;
			if (posi > 1 && apertou == false)
			{
				--posi;
				apertou = true;
				texts[posi].setOutlineThickness(4);
				texts[posi + 1].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}

		//Abre a opcao selecionada com o enter

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !selecao) 
		{
			selecao = true;

			if (posi == 1) { //RODA JOGO

				clique = true;
			}
			else if (posi == 2) { //COLOCAR AS FASES

			}
			else if (posi == 3) { //COLOCAR O RANKING

			}
			else if (posi == 4) { //COLOCAR AS OPCOES

			}
			else if (posi == 5) { //FECHA TUDO
				clique = true;
				exit(1);
			}
		}

		//Verifica se o mouse est� acima de alguma op�ao, se estiver marcara a op�ao e verificar� se foi realizado o clique com o mouse
		if (play.getGlobalBounds().contains(cordMouse)) 
		{
			texts[posi].setOutlineThickness(0);
			posi = 1;
			texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) 
			{
				clique = true;
			}
		}
		if (fases.getGlobalBounds().contains(cordMouse)) 
		{
			texts[posi].setOutlineThickness(0);
			posi = 2;
			texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) 
			{

			}
		}
		if (ranking.getGlobalBounds().contains(cordMouse)) 
		{
			texts[posi].setOutlineThickness(0);
			posi = 3;
			texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) 
			{

			}
		}
		if (opcoes.getGlobalBounds().contains(cordMouse)) 
		{
			texts[posi].setOutlineThickness(0);
			posi = 4;
			texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) 
			{

			}
		}
		if (sair.getGlobalBounds().contains(cordMouse)) 
		{
			texts[posi].setOutlineThickness(0);
			posi = 5;
			texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) 
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

		cursorSprite.setPosition(Mouse::getPosition(*grafico->getJanela()).x, Mouse::getPosition(*grafico->getJanela()).y);
		imprimir();
	}
}

void Menu::imprimir()
{
	grafico->limpar();
	grafico->desenharSprite(fundo);
	grafico->desenharTexto(texts[0]);
	grafico->desenharTexto(texts[1]);
	grafico->desenharTexto(texts[2]);
	grafico->desenharTexto(texts[3]);
	grafico->desenharTexto(texts[4]);
	grafico->desenharTexto(texts[5]);
	grafico->desenharSprite(cursorSprite);
	grafico->mostrar();
}