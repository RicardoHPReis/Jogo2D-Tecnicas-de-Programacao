#include "menu.h"

void Menu::set_values()
{
	this->janela->create(VideoMode(1920, 1080), "Menu JOGO", Style::Titlebar | Style::Close);
	this->janela->setPosition(Vector2i(0, 0));

	this->posi = 0;
	this->pressed = this->theselect = false;

	this->font->loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/Font.otf");
	this->image->loadFromFile("C:/Users/migue/OneDrive/Documentos/FACUL/programação/JOGO SIMAO/texturas/mapa/menu.png");

	this->bg->setTexture(*image);

	this->posMouse = { 0,0 };
	this->cordMouse = { 0,0 };

	this->options = { "NOME DO JOGO","Jogar","Opcoes","Sobre","Sair" };
	this->texts.resize(5);
	coords = { { 610,250 } , { 610,400 }, { 610,500 }, { 610,600 }, { 610,700 } };
	sizes = { 100,50,50,50,50 };

	for (size_t i{}; i < texts.size(); ++i) {
		this->texts[i].setFont(*font);
		this->texts[i].setString(options[i]);
		this->texts[i].setCharacterSize(sizes[i]);
		this->texts[i].setOutlineColor(Color::Black);
		this->texts[i].setPosition(coords[i]);
	}
}

void Menu::loop_events()
{
	Event ev;
	while (this->janela->pollEvent(ev)) {
		if (ev.type == Event::Closed) {

			this->janela->close();
		}
	}
}

void Menu::draw_all()
{
	this->janela->clear();
	this->janela->draw(*bg);
	for (auto t : texts) {
		this->janela->draw(t);
	}
	this->janela->display();
}

Menu::Menu()
{
	this->janela = new RenderWindow();
	this->closeJanela = new RectangleShape();
	this->font = new Font();
	this->image = new Texture();
	this->bg = new Sprite();

	set_values();
}

Menu::~Menu()
{
	delete janela;
	delete closeJanela;
	delete font;
	delete image;
	delete bg;
}

void Menu::run_menu()
{
	while (this->janela->isOpen()) {
		loop_events();
		draw_all();

	}
}
