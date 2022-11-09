#include "Menu.h"
#include "Ente.h"


Menu::Menu():
Ente()
{
	this->play = new RectangleShape();
	this->fases = new RectangleShape();
	this->recordes = new RectangleShape();
	this->opcoes = new RectangleShape();
	this->sobre = new RectangleShape();
	this->sair = new RectangleShape();
	this->font = new Font();
	this->textura = new Texture();
	this->sprite = new Sprite();

	this->clicar = this->selecionar = false;

	this->font->loadFromFile("../../Fontes/Font.otf");
	this->textura->loadFromFile("../../Texturas/Cenario/Menu.png");

	this->sprite->setTexture(*textura);

	this->posMouse = { 0,0 };
	this->cordMouse = { 0,0 };

	this->options = { "NOME DO JOGO","Jogar","Fases","Recordes","Opcoes","Sobre","Sair"};
	this->textos.resize(7);
	coords = { { 610,200 } , { 610,350 }, { 610,450 }, { 610,550 }, { 610,650 }, { 610,750 }, { 610,850 } };
	sizes = { 100,50,50,50,50,50,50};

	for (size_t i{}; i < textos.size(); ++i) {
		this->textos[i].setFont(*font);
		this->textos[i].setString(options[i]);
		this->textos[i].setCharacterSize(sizes[i]);
		this->textos[i].setOutlineColor(Color::Black);
		this->textos[i].setPosition(coords[i]);
	}

	this->textos[1].setOutlineThickness(4);
	mouse = 1;

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

Menu::~Menu()
{
	delete play;
	delete fases;
	delete opcoes;
	delete sobre;
	delete sair;
	delete font;
	delete textura;
	delete sprite;
}

void Menu::selecionouOpcaoMouse(bool &clique)
{
	if (this->play->getGlobalBounds().contains(cordMouse)) {

		this->textos[mouse].setOutlineThickness(0);
		this->mouse = 1;
		this->textos[mouse].setOutlineThickness(4);
		if (Mouse::isButtonPressed(Mouse::Left)) {
			clique = true;
		}
	}

	if (this->fases->getGlobalBounds().contains(cordMouse)) {

		this->textos[mouse].setOutlineThickness(0);
		this->mouse = 2;
		this->textos[mouse].setOutlineThickness(4);
		if (Mouse::isButtonPressed(Mouse::Left)) {
			//clique = true;
		}
	}

	if (this->opcoes->getGlobalBounds().contains(cordMouse)) {

		this->textos[mouse].setOutlineThickness(0);
		this->mouse = 3;
		this->textos[mouse].setOutlineThickness(4);
		if (Mouse::isButtonPressed(Mouse::Left)) {
			//clique = true;
		}
	}

	if (this->sobre->getGlobalBounds().contains(cordMouse)) {

		this->textos[mouse].setOutlineThickness(0);
		this->mouse = 4;
		this->textos[mouse].setOutlineThickness(4);
		if (Mouse::isButtonPressed(Mouse::Left)) {
			//clique = true;
		}
	}

	if (this->sair->getGlobalBounds().contains(cordMouse)) {

		this->textos[mouse].setOutlineThickness(0);
		this->mouse = 5;
		this->textos[mouse].setOutlineThickness(4);
		if (Mouse::isButtonPressed(Mouse::Left)) {
			clique = true;
			exit(1);
		}
	}
}

void Menu::selecionouOpcaoTeclas(bool& clique)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !clicar) {
		if (mouse < 5) {
			++mouse;
			this->clicar = true;
			this->textos[mouse].setOutlineThickness(4);
			this->textos[mouse - 1].setOutlineThickness(0);
			this->clicar = false;
			this->selecionar = false;
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !clicar) {
		if (mouse > 1) {
			--mouse;
			this->clicar = true;
			this->textos[mouse].setOutlineThickness(4);
			this->textos[mouse + 1].setOutlineThickness(0);
			this->clicar = false;
			this->selecionar = false;
		}
	}
}

void Menu::apertou(bool &clique)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !selecionar) {
		this->selecionar = true;
		if (mouse == 1) {					//RODA JOGO
			clique = true;
		}
		else if (mouse == 2) {				//COLOCAR AS FASES
			//clique = true;
		}
		else if (mouse == 3) {				//COLOCAR AS OPCOES
			//clique = true;
		}
		else if (mouse == 4) {				//COLOCAR SOBRE
			//clique = true;
		}
		else if (mouse == 5) {				//FECHA TUDO
			clique = true;
			exit(1);
		}
	}
}

void Menu::rodar_menu()
{
	while (clique == false) {
		//posMouse = Mouse::getmousetion(Tela.getJanela());
		cordMouse = getJanela()->mapPixelToCoords(posMouse);

		selecionouOpcaoMouse(clique);
		selecionouOpcaoTeclas(clique);
		apertou(clique);

		executar(play);
		executar(fases);
		executar(opcoes);
		executar(sobre);
		executar(sair);
	}
}