#include "Menu.h"
#include "Ente.h"

Menu::Menu()
{
	this->play = new RectangleShape();
	this->fases = new RectangleShape();
	this->opcoes = new RectangleShape();
	this->sobre = new RectangleShape();
	this->sair = new RectangleShape();
	this->font = new Font();
	this->image = new Texture();
	this->bg = new Sprite();
	this->Tela = new Ente();

	inicVariaveis();
}

Menu::~Menu()
{
	delete play;
	delete fases;
	delete opcoes;
	delete sobre;
	delete sair;
	delete font;
	delete image;
	delete bg;
	delete Tela;
}

void Menu::inicVariaveis()
{
	//inicializa todas variaveis

	this->pressed = this->theselect = false;

	this->font->loadFromFile("../../Fontes/Font.otf");
	this->image->loadFromFile("../../Texturas/Cenario/Menu.png");

	this->bg->setTexture(*image);

	this->posMouse = { 0,0 };
	this->cordMouse = { 0,0 };

	this->options = { "NOME DO JOGO","Jogar","Fases","Opcoes","Sobre","Sair" };
	this->texts.resize(6);
	coords = { { 610,200 } , { 610,350 }, { 610,450 }, { 610,550 }, { 610,650 }, { 610,750 } };
	sizes = { 100,50,50,50,50,50 };

	for (size_t i{}; i < texts.size(); ++i) {
		this->texts[i].setFont(*font);
		this->texts[i].setString(options[i]);
		this->texts[i].setCharacterSize(sizes[i]);
		this->texts[i].setOutlineColor(Color::Black);
		this->texts[i].setPosition(coords[i]);
	}

	this->texts[1].setOutlineThickness(4);
	posi = 1;

	this->play->setSize(Vector2f(110, 50));
	this->play->setPosition(610, 350);
	this->fases->setSize(Vector2f(120, 50));
	this->fases->setPosition(610, 450);
	this->opcoes->setSize(Vector2f(130, 50));
	this->opcoes->setPosition(610, 550);
	this->sobre->setSize(Vector2f(120, 50));
	this->sobre->setPosition(610, 650);
	this->sair->setSize(Vector2f(100, 50));
	this->sair->setPosition(610, 750);

}

void Menu::run_menu()
{
	bool clique = false;
	while (clique == false) {

		posMouse = Mouse::getPosition(*Tela->janela->janelaP);
		cordMouse = (Tela->getJanelaCoord())->mapPixelToCoords(posMouse);

		//Seleciona as opcoes usando seta para cima e para baixo

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
			if (posi < 5) {
				++posi;
				this->pressed = true;
				this->texts[posi].setOutlineThickness(4);
				this->texts[posi - 1].setOutlineThickness(0);
				this->pressed = false;
				this->theselect = false;
			}
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !pressed) {
			if (posi > 1) {
				--posi;
				this->pressed = true;
				this->texts[posi].setOutlineThickness(4);
				this->texts[posi + 1].setOutlineThickness(0);
				this->pressed = false;
				this->theselect = false;
			}
		}

		//Abre a opcao selecionada com o enter

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
			this->theselect = true;

			//realizar� as acoes de cada opcao

			if (posi == 1) { //RODA JOGO

				clique = true;
			}
			else if (posi == 2) { //COLOCAR AS FASES

			}
			else if (posi == 3) { //COLOCAR AS OPCOES

			}
			else if (posi == 4) { //COLOCAR SOBRE

			}
			else if (posi == 5) { //FECHA TUDO
				clique = true;
				exit(1);
			}
		}

		//Verifica se o mouse est� acima de alguma op�ao, se estiver marcara a op�ao e verificar� se foi realizado o clique com o mouse

		if (this->play->getGlobalBounds().contains(cordMouse)) {

			this->texts[posi].setOutlineThickness(0);
			this->posi = 1;
			this->texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) {

				clique = true;

			}
		}

		if (this->fases->getGlobalBounds().contains(cordMouse)) {

			this->texts[posi].setOutlineThickness(0);
			this->posi = 2;
			this->texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) {

			}
		}

		if (this->opcoes->getGlobalBounds().contains(cordMouse)) {

			this->texts[posi].setOutlineThickness(0);
			this->posi = 3;
			this->texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) {

			}
		}

		if (this->sobre->getGlobalBounds().contains(cordMouse)) {

			this->texts[posi].setOutlineThickness(0);
			this->posi = 4;
			this->texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) {

			}
		}

		if (this->sair->getGlobalBounds().contains(cordMouse)) {

			this->texts[posi].setOutlineThickness(0);
			this->posi = 5;
			this->texts[posi].setOutlineThickness(4);
			if (Mouse::isButtonPressed(Mouse::Left)) {

				clique = true;
				exit(1);
			}
		}
		imprimir();
	}
}

void Menu::imprimir()
{
	this->Tela->clear();

	Tela->executarSprite(*bg);
	Tela->executarTex(texts[0]);
	Tela->executarTex(texts[1]);
	Tela->executarTex(texts[2]);
	Tela->executarTex(texts[3]);
	Tela->executarTex(texts[4]);
	Tela->executarTex(texts[5]);

	this->Tela->display();
}

